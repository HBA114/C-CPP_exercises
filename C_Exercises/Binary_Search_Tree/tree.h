#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree // Ikili arama agaci yapisini struct yardimiyla olusturdum.
{                   // Agacin sayisal veri tutmasi icin bir int degisken atadim.
    int veri;
    Tree *sol, *sag; // Agaci iki kola ayirabilmek icin sag ve sol pointerlarini agac veri cinsinden olusturdum.
} tree;

tree *ekle(tree *agac, int x) // Agaca eleman ekleyebilmek icin ekle() fonksiyonunu agac veri cinsinden olusturdum ve girdi olarak agac pointeri ve sayisal veri aldim.
{
    if (agac == NULL) // Agac bos olmasi durumunu if() baglaci ile kontrol ederek bos ise :
    {
        tree *root = (tree *)malloc(sizeof(tree)); // Agacın kokunu olusturmak icin bellekten yer ayirma amaciyla malloc fonksiyonu kullandim.
        root->sol = NULL;                          // Agacin sag ve sol dallari bos olacagindan bunlari NULL ile isaretledim.
        root->sag = NULL;
        root->veri = x; // Agacin kok degerine kullanicinin girdigi veriyi atadim.
        return root;
    }                   // Agac bos degil ise :
    if (agac->veri < x) // Kullanicinin girmek istedigi veri Agacin kok verisinden buyuk ise agacin sag dalina gitmesi
    {
        agac->sag = ekle(agac->sag, x);
        return agac;
    }
    agac->sol = ekle(agac->sol, x); // Kullanicinin girdigi deger Agacin kok verisinden kucuk ise agacin sol dalina gitmesi icin ekle() fonksiyonunu tekrar cagirarak,
    return agac;                    // Recursive (oz yinelemeli) sekilde veriye uygun yer bulunana kadar ilereleyen bir fonksiyon yapisi olusturdum.
}

// Aranan seviyedeki elemanlari listeleyebilmek icin dizi olusturdum.
int seviyeDizi[100]; /*10*/
int f = 0;           // Seviyeyi belirleyebilmek icin iki degisken olusturdum.
int k = 0;
void seviye(tree *agac, int sayi) // Aranan seviyedeki elemanlari bulup onlari diziye aktaracak fonksiyonu yazdim.
{
    if (agac == NULL) // Agac bos ise fonksiyonu durdurdum. Islem yapilirken aranan seviye bos ise bos oldugunu belirtmek icin buradaki degiskenlerden faydalandim.
        return;
    if (f == sayi) // Aranan seviye seviye sayacina esit olunca o seviyedeki elemani diziye aktardim.
    {
        seviyeDizi[k] = agac->veri;
        k++; // Sonraki elemani dizinin sonraki elemanina aktarabilmek icin dizinin eleman sayacini 1 artirdim.(Her bir arama icin dizi eleman sayaci 0'dan baslar.)
    }
    f++; // Agacin soluna veya sagina gitmesi icin tekrar cagirilan fonksiyon icin seviye sayacini 1 artirdim.
    seviye(agac->sol, sayi);
    seviye(agac->sag, sayi);
    f--; // Bulunulan dalin solu ve sagi bossa bir onceki dala donerken seviyeyi 1 eksilttim.
}

int yapraklar[100];     // Yapraklardaki verileri tutup ortalamalarini alabilmek icin bir dizi olusturdum.
int i = 0;              // Diziye eleman ekleyebilmek icin bir degisken atadim.
void yaprak(tree *agac) // Yapraklari bulan ve yaprakları tutacak diziye aktaran yaprak() fonksiyonunu olusturdum. Fonksiyon girdisi olarak agac veri tipinden pointer aldim.
{
    tree *iter;       //  Agacta gezebilmek icin agac veri tipinden bir gezici pointer olusturdum ve recursive yapida bu pointeri kullandim.
    if (agac == NULL) // Agac bos ise fonksiyonu durdurdum.
        return;
    if (agac->sol == NULL && agac->sag == NULL) // Agac bos degilse ama bulunulan elemanin sagi ve solu bos ise o eleman yaprak olarak tanimlandigindan o elemani diziye aktardim.
    {
        yapraklar[i] = agac->veri; // Dizinin eleman sayacini 1 arttirarak sonraki yapragin dizinin sonraki alanina atanmasini sagladim.
        i++;
        iter = agac; // Yaprak bulunduktan sonra gezici pointeri tekrar basa alarak diger yapraklari aramasini sagladim.
    }
    if (agac->sag != NULL) // Bulunulan elemanin sagi bos degil ise :
    {
        iter = agac->sag; // Gezici pointeri agacin sag elemanini gosterecek sekilde atayip fonksiyonu gezici pointer ile tekrar cagirdim.
        yaprak(iter);
    }
    if (agac->sol != NULL) // Bulunulan elemanin sagi bos degil ise :
    {
        iter = agac->sol; // Gezici pointeri agacin sol elemanini gosterecek sekilde atayip fonksiyonu gezici pointer ile tekrar cagirdim.
        yaprak(iter);     // Bu sayede yapraklar diziye aktarilip diziden ortalamalarini almak uzere kullaniliyor.
    }
}

int adimsay;                    // Aranan elemanin kac adimda bulundugunu tespit edip kullaniciya bildirmek icin adimsay degskeni olusturdum.
int ara(tree *agac, int aranan) // Kullanicidan alinan veriyi agacta aramak icin ara() fonksiyonunu olusturdum ve girdi olarak agac veri tipinden pointer ve aranan elemani aldim.
{
    if (agac == NULL) // Aranan eleman bulunamadi ise fonksiyon "-1" degeri dondurerek sonlaniyor ve kullaniciya aranan elemanin bulunamadigini bildiriyor.
    {
        printf("%d elemani bulunamadi.\n", aranan);
        return -1;
    }
    if (agac->veri == aranan) // Aranan eleman bulundu ise kullaniciya elemanin kac adimda bulundugu bildiriliyor ve fonksiyon "1" degeri dondurerek sonlaniyor.
    {
        printf("%d elemani %d adimda bulundu.\n", aranan, adimsay);
        return 1;
    }

    adimsay++;               // Aranan eleman bakilan yerde bulunamadi ise adim sayacini bir artirarak :
    if (aranan < agac->veri) // Aranan deger bakilan degerden kucuk ise agacin sol tarafina bakilmasi icin fonksşyonu tekrar calistirdim.(recursive)
    {
        agac = agac->sol;
        ara(agac, aranan); /*iter*/
    }
    else // Aranan deger bakilan degerden buyuk ise agacin sag tarafina bakilmasi icin fonksşyonu tekrar calistirdim.(recursive)
    {
        agac = agac->sag;
        ara(agac, aranan); /*iter*/
    }                      // Bu sekilde aranan eleman bulunana kadar gerekli yyone gidildi ve eleman bulununca adim sayisi kullaniciya bildirildi ve fonksiyon sonlandirildi.
    return -1;
} // Eleman bulunamadi ise kullaniciya elemanin bulunamadigini bildirerek fonksiyonu sonlandirdim.

int buyukleriBulDizi[100];           // Kullanicidan alinan belirli bir degerden buyuk elemanlari tutabilmek ve duzgun listeleybilmek icin bir dizi tanimladim.
int kontrol = 0;                     // Bulunamamasi durumunda kullaniciya bildirebilmek icin kontrol degiskeni olusturdum.
void buyukleriBul(tree *agac, int x) // Kullanicinin istedigi bir degerden buyuk elemanlari listeleyebilmesi icin buyukleriBul() fonksiyonu olusturdum.
{                                    // fonksiyon girdisi olarak agac veri tipinden pointer ve kullanicinin girdigi degeri aldim.
    if (agac == NULL)                // Eger agac bos ise veya kullanicinin girdigi degerden buyuk deger yok ise fonksiyonu sonlandirdim.
        return;
    if (agac->veri > x) // Eger bakilan veri kullanicinin girdigi degerden buyuk ise veriyi daha sonra duzgun sekilde listeleyebilmek icin diziye aktardim.
    {
        buyukleriBulDizi[k] = agac->veri;
        kontrol = 1; // Eger kullanicinin girdigi degerden buyuk herhangi bir veri var ise kontrol degiskeninin degerini degistirdim.
        k++;         // Daha once tanimladigim dizi eleman sayacini burada tekrar kullandim. Islem yapilrken degeri 0'dan baslatarak diziyi tekrar bastan yazmis oldum.
    }
    buyukleriBul(agac->sol, x); // Odev bilgilendirmesinde verildigi sekilde preorder olarak arattım.
    buyukleriBul(agac->sag, x);
}

#endif