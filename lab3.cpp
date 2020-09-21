// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "conio.h"
#include "locale.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "Windows.h"
#include "stdio.h"
#include "time.h"
#include "iostream"
#define N 100

struct item {
    char code[N];
    char name[N];
    double price;
    int amount;
};

struct store {
    char name[N];
    char adress[N];
    int numberOfItems;
    struct item item[N];
};


void read(struct store* store1) {
    char f;
    int i;
    printf("Введите название магазина\n");
    gets_s(store1->name);
    printf("Введите адрес магазина\n");
    gets_s(store1->adress);
    store1->numberOfItems = i = 0;;
    printf("Добавить товар?(1 - да, все остальные символы - нет)\n");
    f = _getche();
    while (f == '1') {
        printf("\nВведите название товара\n");
        gets_s(store1->item[store1->numberOfItems].name);
        printf("Введите код товара\n");
        gets_s(store1->item[store1->numberOfItems].code);
        do {
            printf("Введите цену\n");
            scanf_s("%lf", &store1->item[store1->numberOfItems].price);
        } while (store1->item[store1->numberOfItems].price < 0);
        do {
            printf("Введите колличество товара\n");
            scanf_s("%d", &store1->item[store1->numberOfItems].amount);
        } while (store1->item[store1->numberOfItems].amount < 0);
        store1->numberOfItems++;
        printf("Добавить еще один товар?(1 - да, все остальные символы -нет)\n");
        f = _getche();
        getchar();
    }
}

void init(struct store* store1, char name[], char adress[], int numberOfItems, char itemName[][N], char itemCode[][N], double itemPrice[], int itemAmount[]) {
    int i;
    strcpy_s(store1->name, name);
    strcpy_s(store1->adress, adress);
    store1->numberOfItems = numberOfItems;
    for (i = 0; i < numberOfItems; i++) {
        strcpy_s(store1->item[i].name, itemName[i]);
        strcpy_s(store1->item[i].code, itemCode[i]);
        store1->item[i].price = itemPrice[i];
        store1->item[i].amount = itemAmount[i];
    }
}

void display(struct store store1) {
    int i;
    printf("\nНазвание магазина: %s\n", store1.name);
    printf("Адрес: %s\n", store1.adress);
    printf("Колличество уникальных товаров: %d\n", store1.numberOfItems);
    for (i = 0; i < store1.numberOfItems; i++) {
        printf("\nТовар %d\n", i + 1);
        printf("Код товара: %s\n", store1.item[i].code);
        printf("Название товара: %s\n", store1.item[i].name);
        printf("Цена: %lf\n", store1.item[i].price);
        printf("Колличество: %d\n", store1.item[i].amount);
    }
}

void add(struct store* store1) {
    printf("\nВведите название нового товара\n");
    gets_s(store1->item[store1->numberOfItems].name);
    printf("Введите код нового товара\n");
    gets_s(store1->item[store1->numberOfItems].code);
    do {
        printf("Введите цену нового товара\n");
        scanf_s("%lf", &store1->item[store1->numberOfItems].price);
    } while (store1->item[store1->numberOfItems].price < 0);
    do {
        printf("Введите колличество нового товара\n");
        scanf_s("%d", &store1->item[store1->numberOfItems].amount);
    } while (store1->item[store1->numberOfItems].amount < 0);
    store1->numberOfItems++;
    getchar();
}

void priceChange(struct store* store1, char item1[], double price) {
    int i = 0;
    while (i < store1->numberOfItems) {
        if (strcmp(store1->item[i].code, item1) == 0) {
            store1->item[i].price = price;
            i = store1->numberOfItems;
        }
        i++;
    }
}

void amountChange(struct store* store1, char item1[], int amountDifference) {
    int i = 0;
    while (i < store1->numberOfItems) {
        if (strcmp(store1->item[i].code, item1) == 0) {
            store1->item[i].amount = store1->item[i].amount + amountDifference;
            i = store1->numberOfItems;
        }
        i++;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct store store1, * store2;
    int amountDifference, numberOfItems, itemAmount[N];
    double price, itemPrice[N];
    char f, s[N], s1[N][N], code[N], name[N], adress[N], itemCode[N][N], itemName[N][N];
    printf("Работать с переменной или с указателем?(1 - переменная, все остальные символы - указатель)\n");
    f = _getche();
    printf("\n");
    if (f == '1') {
        strcpy_s(s, "-");
        strcpy_s(s1[0], "-");
        printf("Использовать или read чтобы ввести данные(1 - init, все остальные символы - read)\n");
        f = _getche();
        if (f == '0') {
            read(&store1);
        }
        else {
            printf("\nВведите название магазина\n");
            gets_s(name);
            printf("Введите адрес магазина\n");
            gets_s(adress);
            numberOfItems = 0;;
            printf("Добавить товар?(1-да,0-нет)\n");
            f = _getche();
            while (f == '1') {
                printf("\nВведите название товара\n");
                gets_s(itemName[numberOfItems]);
                printf("Введите код товара\n");
                gets_s(itemCode[numberOfItems]);
                do {
                    printf("Введите цену\n");
                    scanf_s("%lf", &itemPrice[numberOfItems]);
                } while (itemPrice[numberOfItems] < 0);
                do {
                    printf("Введите колличество товара\n");
                    scanf_s("%d", &itemAmount[numberOfItems]);
                } while (itemAmount[numberOfItems] < 0);
                numberOfItems++;
                printf("Добавить еще один товар?(1 - да, все остальные символы - нет)\n");
                f = _getche();
                getchar();
            }
            init(&store1, name, adress, numberOfItems, itemName, itemCode, itemPrice, itemAmount);
        }
        while (f != '5') {
            printf("\nВведите номер следующего действия:\n");
            printf("1 - показать информацию о магазине\n");
            printf("2 - добавить новый вид товара\n");
            printf("3 - изменить цену товара\n");
            printf("4 - изменить колличество товара\n");
            printf("5 - выйти\n");
            f = _getche();
            if (f == '1') {
                display(store1);
            }
            else if (f == '2') {
                add(&store1);
            }
            else if (f == '3') {
                printf("\nВведите код товара\n");
                gets_s(code);
                do {
                    printf("Введите новую цену\n");
                    scanf_s("%lf", &price);
                } while (price < 0);
                getchar();
                priceChange(&store1, code, price);
            }
            else if (f == '4') {
                printf("\nВведите код товара\n");
                gets_s(code);
                printf("Введите на сколько изменилось колличество товара(если увеличилость - положительное число, если уменьшилось - отрицательное)\n");
                scanf_s("%d", &amountDifference);
                getchar();
                amountChange(&store1, code, amountDifference);
            }
        }
    }
    else {
        store2 = (struct store*)malloc(sizeof(store));
        strcpy_s(s, "-");
        strcpy_s(s1[0], "-");
        printf("Использовать или read чтобы ввести данные(1 - init, все остальные символы - read)\n");
        f = _getche();
        if (f == '0') {
            read(store2);
        }
        else {
            printf("\nВведите название магазина\n");
            gets_s(name);
            printf("Введите адрес магазина\n");
            gets_s(adress);
            numberOfItems = 0;;
            printf("Добавить товар?(1-да,0-нет)\n");
            f = _getche();
            while (f == '1') {
                printf("\nВведите название товара\n");
                gets_s(itemName[numberOfItems]);
                printf("Введите код товара\n");
                gets_s(itemCode[numberOfItems]);
                do {
                    printf("Введите цену\n");
                    scanf_s("%lf", &itemPrice[numberOfItems]);
                } while (itemPrice[numberOfItems] < 0);
                do {
                    printf("Введите колличество товара\n");
                    scanf_s("%d", &itemAmount[numberOfItems]);
                } while (itemAmount[numberOfItems] < 0);
                numberOfItems++;
                printf("Добавить еще один товар?(1 - да, все остальные символы - нет)\n");
                f = _getche();
                getchar();
            }
            init(store2, name, adress, numberOfItems, itemName, itemCode, itemPrice, itemAmount);
        }
        while (f != '5') {
            printf("\nВведите номер следующего действия:\n");
            printf("1 - показать информацию о магазине\n");
            printf("2 - добавить новый вид товара\n");
            printf("3 - изменить цену товара\n");
            printf("4 - изменить колличество товара\n");
            printf("5 - выйти\n");
            f = _getche();
            if (f == '1') {
                display(*store2);
            }
            else if (f == '2') {
                add(store2);
            }
            else if (f == '3') {
                printf("\nВведите код товара\n");
                gets_s(code);
                do {
                    printf("Введите новую цену\n");
                    scanf_s("%lf", &price);
                } while (price < 0);
                getchar();
                priceChange(store2, code, price);
            }
            else if (f == '4') {
                printf("\nВведите код товара\n");
                gets_s(code);
                printf("Введите на сколько изменилось колличество товара(если увеличилость - положительное число, если уменьшилось - отрицательное)\n");
                scanf_s("%d", &amountDifference);
                getchar();
                amountChange(store2, code, amountDifference);
            }
        }
        free(store2);
    }
    return 0;
}


