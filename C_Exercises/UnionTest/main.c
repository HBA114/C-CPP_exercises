#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int stock;
    float price;
    char character;
} mystr;

typedef union
{
    int stock;
    float price;
    char character;
} myunion;

typedef struct
{
    char *name;
    bool isRobot;
    union // never both
    {
        char *personality;
        int firmwareVersion;
    };
} character;

typedef struct
{
    char *name;
    bool isRobot;
    char *personality;
    int firmwareVersion;
} character_just_struct;

void printCharacter(character *character)
{
    printf("Character: %s -- ", character->name);
    if (character->isRobot)
    {
        printf("Version: %d", character->firmwareVersion);
    }
    else
    {
        printf("Personality: %s", character->personality);
    }
    printf("\n");
}

int main()
{
    printf("%lu\n", sizeof(mystr));
    printf("%lu\n", sizeof(myunion));

    mystr mystr1;
    mystr1.stock = 10;
    mystr1.price = 15.75;
    mystr1.character = 'A';

    myunion myunion1;
    myunion1.stock = 10;
    myunion1.price = 15.75;
    myunion1.character = 'A';

    printf("mystr1 values: %d , %f , %c\n", mystr1.stock, mystr1.price, mystr1.character);
    printf("mystr1 size: %lu bytes\n", sizeof(mystr1));
    printf("myunion1 values: %d , %f , %c\n", myunion1.stock, myunion1.price, myunion1.character);
    printf("myunion1 size: %lu bytes\n", sizeof(myunion1));

    printf("\nsizeof character with union: %lu bytes\n", sizeof(character));
    printf("sizeof character just struct: %lu bytes\n\n", sizeof(character_just_struct));

    character hasan;
    hasan.name = "Hasan";
    hasan.isRobot = false;
    hasan.personality = "Happy Coder";

    character alexa;
    alexa.name = "Alexa";
    alexa.isRobot = true;
    alexa.firmwareVersion = 3;

    printCharacter(&hasan);
    printCharacter(&alexa);

    return 0;
}