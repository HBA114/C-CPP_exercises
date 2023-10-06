#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree // Ikili arama agaci yapisini struct yardimiyla olusturdum.
{                   // Agacin sayisal data tutmasi icin bir int degisken atadim.
    int data;
    Tree *left, *right; // Agaci iki kola ayirabilmek icin right ve left pointerlarini binaryTree data cinsinden olusturdum.
} tree;

tree *add(tree *binaryTree, int number) // Agaca eleman ekleyebilmek icin add() fonksiyonunu binaryTree data cinsinden olusturdum ve girdi olarak binaryTree pointeri ve sayisal data aldim.
{
    if (binaryTree == NULL) // Agac bos olmasi durumunu if() baglaci ile control ederek bos ise :
    {
        tree *root = (tree *)malloc(sizeof(tree)); // Agacın kokunu olusturmak icin bellekten yer ayirma amaciyla malloc fonksiyonu kullandim.
        root->left = NULL;                          // Agacin right ve left dallari bos olacagindan bunlari NULL ile isaretledim.
        root->right = NULL;
        root->data = number; // Agacin kok degerine kullanicinin girdigi veriyi atadim.
        return root;
    }                   // Agac bos degil ise :
    if (binaryTree->data < number) // Kullanicinin girmek istedigi data Agacin kok verisinden buyuk ise agacin right dalina gitmesi
    {
        binaryTree->right = add(binaryTree->right, number);
        return binaryTree;
    }
    binaryTree->left = add(binaryTree->left, number); // Kullanicinin girdigi deger Agacin kok verisinden kucuk ise agacin left dalina gitmesi icin add() fonksiyonunu tekrar cagirarak,
    return binaryTree;                    // Recursive (oz yinelemeli) sekilde veriye uygun yer bulunana kadar ilereleyen bir fonksiyon yapisi olusturdum.
}

// Aranan seviyedeki elemanlari listeleyebilmek icin dizi olusturdum.
int levelArray[100]; /*10*/
int f = 0;           // Seviyeyi belirleyebilmek icin iki degisken olusturdum.
int k = 0;
void level(tree *binaryTree, int number) // Aranan seviyedeki elemanlari bulup onlari diziye aktaracak fonksiyonu yazdim.
{
    if (binaryTree == NULL) // Agac bos ise fonksiyonu durdurdum. Islem yapilirken wanted level bos ise bos oldugunu belirtmek icin buradaki degiskenlerden faydalandim.
        return;
    if (f == number) // Aranan level level sayacina esit olunca o seviyedeki elemani diziye aktardim.
    {
        levelArray[k] = binaryTree->data;
        k++; // Sonraki elemani dizinin sonraki elemanina aktarabilmek icin dizinin eleman sayacini 1 artirdim.(Her bir arama icin dizi eleman sayaci 0'dan baslar.)
    }
    f++; // Agacin soluna veya sagina gitmesi icin tekrar cagirilan fonksiyon icin level sayacini 1 artirdim.
    level(binaryTree->left, number);
    level(binaryTree->right, number);
    f--; // Bulunulan dalin solu ve sagi bossa bir onceki dala donerken seviyeyi 1 eksilttim.
}

int leaves[100];     // Yapraklardaki verileri tutup ortalamalarini alabilmek icin bir dizi olusturdum.
int i = 0;              // Diziye eleman ekleyebilmek icin bir degisken atadim.
void leaf(tree *binaryTree) // Yapraklari bulan ve yaprakları tutacak diziye aktaran leaf() fonksiyonunu olusturdum. Fonksiyon girdisi olarak binaryTree data tipinden pointer aldim.
{
    tree *iter;       //  Agacta gezebilmek icin binaryTree data tipinden bir gezici pointer olusturdum ve recursive yapida bu pointeri kullandim.
    if (binaryTree == NULL) // Agac bos ise fonksiyonu durdurdum.
        return;
    if (binaryTree->left == NULL && binaryTree->right == NULL) // Agac bos degilse ama bulunulan elemanin sagi ve solu bos ise o eleman leaf olarak tanimlandigindan o elemani diziye aktardim.
    {
        leaves[i] = binaryTree->data; // Dizinin eleman sayacini 1 arttirarak sonraki yapragin dizinin sonraki alanina atanmasini sagladim.
        i++;
        iter = binaryTree; // Yaprak bulunduktan sonra gezici pointeri tekrar basa alarak diger yapraklari aramasini sagladim.
    }
    if (binaryTree->right != NULL) // Bulunulan elemanin sagi bos degil ise :
    {
        iter = binaryTree->right; // Gezici pointeri agacin right elemanini gosterecek sekilde atayip fonksiyonu gezici pointer ile tekrar cagirdim.
        leaf(iter);
    }
    if (binaryTree->left != NULL) // Bulunulan elemanin sagi bos degil ise :
    {
        iter = binaryTree->left; // Gezici pointeri agacin left elemanini gosterecek sekilde atayip fonksiyonu gezici pointer ile tekrar cagirdim.
        leaf(iter);     // Bu sayede leaves diziye aktarilip diziden ortalamalarini almak uzere kullaniliyor.
    }
}

int stepCount;                    // Aranan elemanin kac adimda bulundugunu tespit edip kullaniciya bildirmek icin stepCount degskeni olusturdum.
int search(tree *binaryTree, int wanted) // Kullanicidan alinan veriyi agacta aramak icin search() fonksiyonunu olusturdum ve girdi olarak binaryTree data tipinden pointer ve wanted elemani aldim.
{
    if (binaryTree == NULL) // Aranan eleman bulunamadi ise fonksiyon "-1" degeri dondurerek sonlaniyor ve kullaniciya wanted elemanin bulunamadigini bildiriyor.
    {
        printf("%d elemani bulunamadi.\n", wanted);
        return -1;
    }
    if (binaryTree->data == wanted) // Aranan eleman bulundu ise kullaniciya elemanin kac adimda bulundugu bildiriliyor ve fonksiyon "1" degeri dondurerek sonlaniyor.
    {
        printf("%d elemani %d adimda bulundu.\n", wanted, stepCount);
        return 1;
    }

    stepCount++;               // Aranan eleman bakilan yerde bulunamadi ise adim sayacini bir artirarak :
    if (wanted < binaryTree->data) // Aranan deger bakilan degerden kucuk ise agacin left tarafina bakilmasi icin fonksşyonu tekrar calistirdim.(recursive)
    {
        binaryTree = binaryTree->left;
        search(binaryTree, wanted); /*iter*/
    }
    else // Aranan deger bakilan degerden buyuk ise agacin right tarafina bakilmasi icin fonksşyonu tekrar calistirdim.(recursive)
    {
        binaryTree = binaryTree->right;
        search(binaryTree, wanted); /*iter*/
    }                      // Bu sekilde wanted eleman bulunana kadar gerekli yyone gidildi ve eleman bulununca adim sayisi kullaniciya bildirildi ve fonksiyon sonlandirildi.
    return -1;
} // Eleman bulunamadi ise kullaniciya elemanin bulunamadigini bildirerek fonksiyonu sonlandirdim.

int bigElementsArray[100];           // Kullanicidan alinan belirli bir degerden buyuk elemanlari tutabilmek ve duzgun listeleybilmek icin bir dizi tanimladim.
int control = 0;                     // Bulunamamasi durumunda kullaniciya bildirebilmek icin control degiskeni olusturdum.
void findBigElements(tree *binaryTree, int number) // Kullanicinin istedigi bir degerden buyuk elemanlari listeleyebilmesi icin findBigElements() fonksiyonu olusturdum.
{                                    // fonksiyon girdisi olarak binaryTree data tipinden pointer ve kullanicinin girdigi degeri aldim.
    if (binaryTree == NULL)                // Eger binaryTree bos ise veya kullanicinin girdigi degerden buyuk deger yok ise fonksiyonu sonlandirdim.
        return;
    if (binaryTree->data > number) // Eger bakilan data kullanicinin girdigi degerden buyuk ise veriyi daha sonra duzgun sekilde listeleyebilmek icin diziye aktardim.
    {
        bigElementsArray[k] = binaryTree->data;
        control = 1; // Eger kullanicinin girdigi degerden buyuk herhangi bir data var ise control degiskeninin degerini degistirdim.
        k++;         // Daha once tanimladigim dizi eleman sayacini burada tekrar kullandim. Islem yapilrken degeri 0'dan baslatarak diziyi tekrar bastan yazmis oldum.
    }
    findBigElements(binaryTree->left, number); // Odev bilgilendirmesinde verildigi sekilde preorder olarak arattım.
    findBigElements(binaryTree->right, number);
}

#endif
