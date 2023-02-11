#include <stdio.h>
#include <stdlib.h> // Gerekli kutuphaneleri ekledim.
#include "tree.h"   // added required and writed libraries

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