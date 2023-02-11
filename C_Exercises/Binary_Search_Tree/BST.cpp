#include <stdio.h>
#include <stdlib.h> // Gerekli kutuphaneleri ekledim.
// #include <conio.h> // removed os specific library

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

int main()
{
    tree *agac = NULL; // main() fonksiyonunda arama agaclarında kullanmak icin agac veri yapisindan bir pointer olusturdum ve NULL ile isaretledim.

    int islem = 1;                          // Islem dongusu olusturabilmek icin islem degiskeni olusturdum.
    int secim, sayi, j, toplam = 0, ort, f; // Secimi, girilen degeri, toplam, ortalama ve sayma sayaci icin degisken atadim.
    while (islem == 1)                      // Islem degiskeni 1 oldugu surece islemleri sonlandirmayacak while() dongusu olusturdum.
    {                                       // Kullaniciya islem seceneklerini sundum ve islem numaralarini belirttim.
        printf("1: Ekle(Add)\n2: Eleman ara(Find node)\n3: Yaprak Ortalamasi(Average of Leaves)\n4: Girilen degerden buyuk verileri bul(Find larger values than the entered value)\n5: Girilen seviyedeki elemanlari bul(Find data of entered level)\n6: Cikis(Exit)\n");
        scanf("%d", &secim); // Kullanicinin sectigi islemi tutmak icin daha once atadigim degiskeni kullandim.
        switch (secim)       // Islemleri birbirinden ayirabilmek icin switch-case yapisini kullandim. Girddi olarak kulanicinin secimini aldim.
        {
        case 1: // "1" girilmesi sonucu Kullanicidan eklemek istedigi sayiyi aldim.
            printf("Eklemek istediginiz veriyi girin...\n");
            scanf("%d", &sayi);
            agac = ekle(agac, sayi); // ekleme fonksiyonunu agac pointeri ve deger girdisi ile calistirarak ekleme islemi tamamlaninca ekrani temizledim.
            system("clear");
            break;
        case 2:
            adimsay = 1; // "2" girilmesi sonucu adimsay degiskenini "1" e esitleyip kullanicidan aramak istedigi elemani girmesini istedim ve girdigi elemani tarayarak aldim.
            printf("Aramak istediginiz veriyi girin...\n");
            scanf("%d", &sayi);
            ara(agac, sayi); // ara() fonksiyonunu agac pointeri ve kullanicinin girdigi deger ile calistirdim
            // getch();                                        // fonksiyon sonucu ekrana yazdirinca kullanici herhangi bir tusa basana kadar bilgilerin ekranda kalmasi icin getch() kullandim.
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana islem menusune donmeden once  ekrani temizledim.
            break;
        case 3: // "3" girilmesi sonucu sayaclari ve toplam degiskenini "0"a esitleyerek :
            i = 0;
            j = 0;
            toplam = 0;
            yaprak(agac); // yaprak() fonksiyonunu agac pointeri ile calistirarak :
            if (i == 0)   // Agac bos ise kullaniciya bildirip ana menuye yonlendirdim
            {
                printf("Agac bos!\n");
                // getch();
                getchar();
                fflush(stdin);
                getchar();
                break;
            }
            while (j < i) // Agac bos degil ise agactaki yaprak sayisina ulasincaya kadar :
            {
                toplam = toplam + yapraklar[j]; // Yapraklari topladim ve eleman sayisini tutan degeri artirdim.
                j++;
            }
            ort = toplam / j; // ortalama degiskenine yaprak degiskenlerinin toplaminin yaprak sayisina bolumunu esitleyerek ekrana yazdirdim.
            printf("Yaprak dugumlerinin ortalamasi : %d\n", ort);
            // getch();                                        // Sonucu ekrana yazdirinca kullanici herhangi bir tusa basana kadar bilgilerin ekranda kalmasi icin getch() kullandim.
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana menuye donmeden once ekrani temizledim.
            break;
        case 4: // "4" girilmesi sonucu Kullanicidan , kendisinden buyuk sayilari gormek istedigi degeri girmesini istedim.
            printf("Kendisinden buyuk olan sayilari bulmak istedigin sayiyi gir...\n");
            scanf("%d", &sayi); // Kullanicinin girdigi sayiyi tarayarak :
            printf("%d degerinden buyuk elemanlar : ", sayi);
            kontrol = 0;
            k = 0;
            buyukleriBul(agac, sayi); // buyukleriBul() fonksiyonunu agac pointeri ve girilen sayi ile calistirarak.
            if (kontrol == 0)
                printf("Yoktur.\n"); // kontrol degiskeni degismemisse girilen degerden buyuk elemanin olmadigini ;
            else                     // kontrol degiskeni degismisse :
            {
                for (int i = 0; i < k; i++)
                {
                    if (i == k - 1) // dizinin son elemaninin sonrasinda "-" isareti koymayacak ;
                        printf("%d", buyukleriBulDizi[i]);
                    else // Dizinin ara elemanlari icin eleman arasina "-" koyacak sekilde diziyi yazdirdim.
                        printf("%d - ", buyukleriBulDizi[i]);
                }
            }
            printf("\n");
            // getch();                                        // Sonucu ekrana yazdirinca kullanici herhangi bir tusa basana kadar bilgilerin ekranda kalmasi icin getch() kullandim.
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana menuye donmeden once ekrani temizledim.
            break;
        case 5: // "5" girilmesi sonucu Kullanicidan , hangi seviyedeki elemanlari gormek istedigi sordum.
            printf("Hangi seviyedeki elemanlari gormek istersiniz...\n");
            scanf("%d", &sayi); // Gormek istedigi seviyeyi tarayarak degiskene atadim ve :
            f = 0;              // sayac egiskenlerini "0"a esitleyip :
            k = 0;
            printf("%d. Seviyedeki elemanlar : ", sayi);
            seviye(agac, sayi); // seviye() fonksiyonunu agac pointeri ve kullanicinin girdigi deger ile calistirdim.
            if (k == 0)         // kullanicinin girdigi seviyede eleman yok ise olmadigini ;
                printf(" Yok !");
            for (int i = 0; i < k; i++) // eleman var ise :
            {
                if (i == k - 1) // sonuncu elemani sonrasina "-" koymadan
                    printf("%d", seviyeDizi[i]);
                else // ara elemanlari ise aralarina "-" yerlesitrilecek sekilde ekrana yazdirdim.
                    printf("%d - ", seviyeDizi[i]);
            }
            printf("\n");
            // getch();                                        // Sonucu ekrana yazdirinca kullanici herhangi bir tusa basana kadar bilgilerin ekranda kalmasi icin getch() kullandim.
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana menuye donmeden once ekrani temizledim.
            break;
        case 6: // "6" girilmesi sonucu cikis yapmak icin while dongusunun devamini asglayan degeri "0" a esitleyerek ana menuden cikisi sagladim.
            islem = 0;
            break;
        default:
            system("clear"); // Islem menusunde gecersiz giris yapildigi takdirde ekrani temizleyerel kullnaiciyi ana menuye tekrar yonlendirdim.
            break;
        }
    }
    // getch();
    // getchar();
    // fflush(stdin);
    // getchar();
    // system("clear"); // Ekrani temizleyerek programi sonlandirdim.
    return 0;
}