#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
// Added required libraries

int main()
{
    // created tree
    tree *binaryTree = NULL; // main() fonksiyonunda arama agaclarında kullanmak icin binaryTree data yapisindan bir pointer olusturdum ve NULL ile isaretledim.

    int process = 1, sum = 0, choice, number, j, avg, f; // Secimi, girilen degeri, sum, ortalama ve sayma sayaci icin degisken atadim.

    while (process == 1) // Islem degiskeni 1 oldugu surece islemleri sonlandirmayacak while() dongusu olusturdum.
    {                    // Kullaniciya process seceneklerini sundum ve process numaralarini belirttim.
        printf("1: Ekle(Add)\n2: Eleman search(Find node)\n3: Yaprak Ortalamasi(Average of Leaves)\n4: Girilen degerden buyuk verileri bul(Find larger values than the entered value)\n5: Girilen seviyedeki elemanlari bul(Find data of entered level)\n6: Cikis(Exit)\n");
        scanf("%d", &choice); // Kullanicinin sectigi islemi tutmak icin daha once atadigim degiskeni kullandim.
        switch (choice)       // Islemleri birbirinden ayirabilmek icin switch-case yapisini kullandim. Girddi olarak kulanicinin secimini aldim.
        {
        case 1: // "1" girilmesi sonucu Kullanicidan eklemek istedigi sayiyi aldim.
            printf("Eklemek istediginiz veriyi girin...\n");
            scanf("%d", &number);
            binaryTree = add(binaryTree, number); // ekleme fonksiyonunu binaryTree pointeri ve deger girdisi ile calistirarak ekleme islemi tamamlaninca ekrani temizledim.
            system("clear");
            break;

        case 2:
            stepCount = 1; // "2" girilmesi sonucu stepCount degiskenini "1" e esitleyip kullanicidan aramak istedigi elemani girmesini istedim ve girdigi elemani tarayarak aldim.
            printf("Aramak istediginiz veriyi girin...\n");
            scanf("%d", &number);
            search(binaryTree, number); // search() fonksiyonunu binaryTree pointeri ve kullanicinin girdigi deger ile calistirdim
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana process menusune donmeden once  ekrani temizledim.
            break;

        case 3: // "3" girilmesi sonucu sayaclari ve sum degiskenini "0"a esitleyerek :
            i = 0;
            j = 0;
            sum = 0;
            leaf(binaryTree); // leaf() fonksiyonunu binaryTree pointeri ile calistirarak :
            if (i == 0)       // Agac bos ise kullaniciya bildirip ana menuye yonlendirdim
            {
                printf("Agac bos!\n");
                // getch();
                getchar();
                fflush(stdin);
                getchar();
                break;
            }
            while (j < i) // Agac bos degil ise agactaki leaf sayisina ulasincaya kadar :
            {
                sum = sum + leaves[j]; // Yapraklari topladim ve eleman sayisini tutan degeri artirdim.
                j++;
            }
            avg = sum / j; // ortalama degiskenine leaf degiskenlerinin toplaminin leaf sayisina bolumunu esitleyerek ekrana yazdirdim.
            printf("Yaprak dugumlerinin ortalamasi : %d\n", avg);
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana menuye donmeden once ekrani temizledim.
            break;

        case 4: // "4" girilmesi sonucu Kullanicidan , kendisinden buyuk sayilari gormek istedigi degeri girmesini istedim.
            printf("Kendisinden buyuk olan sayilari bulmak istedigin sayiyi gir...\n");
            scanf("%d", &number); // Kullanicinin girdigi sayiyi tarayarak :
            printf("%d degerinden buyuk elemanlar : ", number);
            control = 0;
            k = 0;
            findBigElements(binaryTree, number); // findBigElements() fonksiyonunu binaryTree pointeri ve girilen number ile calistirarak.
            if (control == 0)
                printf("Yoktur.\n"); // control degiskeni degismemisse girilen degerden buyuk elemanin olmadigini ;
            else                     // control degiskeni degismisse :
            {
                for (int i = 0; i < k; i++)
                {
                    if (i == k - 1) // dizinin son elemaninin sonrasinda "-" isareti koymayacak ;
                        printf("%d", bigElementsArray[i]);
                    else // Dizinin search elemanlari icin eleman arasina "-" koyacak sekilde diziyi yazdirdim.
                        printf("%d - ", bigElementsArray[i]);
                }
            }
            printf("\n");
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana menuye donmeden once ekrani temizledim.
            break;

        case 5: // "5" girilmesi sonucu Kullanicidan , hangi seviyedeki elemanlari gormek istedigi sordum.
            printf("Hangi seviyedeki elemanlari gormek istersiniz...\n");
            scanf("%d", &number); // Gormek istedigi seviyeyi tarayarak degiskene atadim ve :
            f = 0;                // sayac egiskenlerini "0"a esitleyip :
            k = 0;
            printf("%d. Seviyedeki elemanlar : ", number);
            level(binaryTree, number); // level() fonksiyonunu binaryTree pointeri ve kullanicinin girdigi deger ile calistirdim.
            if (k == 0)                // kullanicinin girdigi seviyede eleman yok ise olmadigini ;
                printf(" Yok !");
            for (int i = 0; i < k; i++) // eleman var ise :
            {
                if (i == k - 1) // sonuncu elemani sonrasina "-" koymadan
                    printf("%d", levelArray[i]);
                else // search elemanlari ise aralarina "-" yerlesitrilecek sekilde ekrana yazdirdim.
                    printf("%d - ", levelArray[i]);
            }
            printf("\n");
            // getch();                                        // Sonucu ekrana yazdirinca kullanici herhangi bir tusa basana kadar bilgilerin ekranda kalmasi icin getch() kullandim.
            getchar();
            fflush(stdin);
            getchar();
            system("clear"); // Ana menuye donmeden once ekrani temizledim.
            break;

        case 6: // "6" girilmesi sonucu cikis yapmak icin while dongusunun devamini asglayan degeri "0" a esitleyerek ana menuden cikisi sagladim.
            process = 0;
            break;

        default:
            system("clear"); // Islem menusunde gecersiz giris yapildigi takdirde ekrani temizleyerel kullnaiciyi ana menuye tekrar yonlendirdim.
            break;
        }
    }

    return 0;
}
