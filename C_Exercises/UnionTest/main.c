#include <stdio.h>
#include <stdbool.h>

typedef struct MyStr
{
    int stock;
    float price;
    char character;
} myStr;

typedef union MyUnion
{
    int stock;
    float price;
    char character;
} myUnion;

typedef struct Character
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
    printf("%lu\n", sizeof(myStr));
    printf("%lu\n", sizeof(myUnion));

    myStr myStr;
    myStr.stock = 10;
    myStr.price = 15.75;
    myStr.character = 'A';

    myUnion myUnion;
    myUnion.stock = 10;
    myUnion.price = 15.75;
    myUnion.character = 'A';

    printf("myStr values: %d , %f , %c\n", myStr.stock, myStr.price, myStr.character);
    printf("myStr size: %lu bytes\n", sizeof(myStr));
    printf("myUnion values: %d , %f , %c\n", myUnion.stock, myUnion.price, myUnion.character);
    printf("myUnion size: %lu bytes\n", sizeof(myUnion));

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
