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

class Item {
public:
    char code[N];
    char name[N];
    double price;
    int amount;
};

class Store {
private:
    char name[N];
    char adress[N];
    int numberOfItems;
    class Item item[N];
public:
    void read();
    void init(char name1[], char adress1[], int numberOfItems1, char itemName1[][N], char itemCode1[][N], double itemPrice1[], int itemAmount1[]);
    void display();
    void add();
    void priceChange(char item1[], double price);
    void amountChange(char item1[], int amountDifference);
    void displayName();
    int storecmp(char name1[]);
};


void Store::read() {
    char f;
    int i;
    printf("\nВведите название магазина\n");
    gets_s(name);
    printf("Введите адрес магазина\n");
    gets_s(adress);
    numberOfItems = i = 0;;
    printf("Добавить товар?(1 - да, все остальные символы - нет)\n");
    f = _getche();
    while (f == '1') {
        printf("\nВведите название товара\n");
        gets_s(item[numberOfItems].name);
        printf("Введите код товара\n");
        gets_s(item[numberOfItems].code);
        do {
            printf("Введите цену\n");
            scanf_s("%lf", &item[numberOfItems].price);
        } while (item[numberOfItems].price < 0);
        do {
            printf("Введите колличество товара\n");
            scanf_s("%d", &item[numberOfItems].amount);
        } while (item[numberOfItems].amount < 0);
        numberOfItems++;
        printf("Добавить еще один товар?(1 - да, все остальные символы -нет)\n");
        f = _getche();
        getchar();
    }
}

void Store::init(char name1[], char adress1[], int numberOfItems1, char itemName1[][N], char itemCode1[][N], double itemPrice1[], int itemAmount1[]) {
    int i;
    strcpy_s(name, name1);
    strcpy_s(adress, adress1);
    numberOfItems = numberOfItems1;
    for (i = 0; i < numberOfItems; i++) {
        strcpy_s(item[i].name, itemName1[i]);
        strcpy_s(item[i].code, itemCode1[i]);
        item[i].price = itemPrice1[i];
        item[i].amount = itemAmount1[i];
    }
}

void Store::display() {
    int i;
    printf("\nНазвание магазина: %s\n", name);
    printf("Адрес: %s\n", adress);
    printf("Колличество уникальных товаров: %d\n", numberOfItems);
    for (i = 0; i < numberOfItems; i++) {
        printf("\nТовар %d\n", i + 1);
        printf("Код товара: %s\n", item[i].code);
        printf("Название товара: %s\n", item[i].name);
        printf("Цена: %lf\n", item[i].price);
        printf("Колличество: %d\n", item[i].amount);
    }
}

void Store::add() {
    printf("\nВведите название нового товара\n");
    gets_s(item[numberOfItems].name);
    printf("Введите код нового товара\n");
    gets_s(item[numberOfItems].code);
    do {
        printf("Введите цену нового товара\n");
        scanf_s("%lf", &item[numberOfItems].price);
    } while (item[numberOfItems].price < 0);
    do {
        printf("Введите колличество нового товара\n");
        scanf_s("%d", &item[numberOfItems].amount);
    } while (item[numberOfItems].amount < 0);
    numberOfItems++;
    getchar();
}

void Store::priceChange(char item1[], double price) {
    int i = 0;
    while (i < numberOfItems) {
        if (strcmp(item[i].code, item1) == 0) {
            item[i].price = price;
            i = numberOfItems;
        }
        i++;
    }
}

void Store::amountChange(char item1[], int amountDifference) {
    int i = 0;
    while (i < numberOfItems) {
        if (strcmp(item[i].code, item1) == 0) {
            item[i].amount = item[i].amount + amountDifference;
            i = numberOfItems;
        }
        i++;
    }
}

void Store::displayName() {
    printf("\nМагазин: %s\n", name);
}

int Store::storecmp(char name1[]) {
    return strcmp(name1, name);
}
int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    class Store store1[10],  *store2;
    int amountDifference, numberOfItems, itemAmount[N], i, max, n;
    double price, itemPrice[N];
    char f, s[N], s1[N][N], code[N], name[N], adress[N], itemCode[N][N], itemName[N][N];
    printf("Работать с переменной или с указателем?(1 - переменная, все остальные символы - указатель)\n");
    f = _getche();
    printf("\n");
    if (f == '1') {
        strcpy_s(s, "-");
        strcpy_s(s1[0], "-");
        printf("Использовать или read чтобы ввести данные(1 - read, все остальные символы - init)\n");
        f = _getche();
        if (f == '1') {
            store1[0].read();
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
            store1[0].init(name, adress, numberOfItems, itemName, itemCode, itemPrice, itemAmount);
        }
        i = 0;
        max = 1;
        f = '1';
        while (f != '8') {
            store1[i].displayName();
            printf("\nВведите номер следующего действия:\n");
            printf("1 - показать информацию о магазине\n");
            printf("2 - добавить новый вид товара\n");
            printf("3 - изменить цену товара\n");
            printf("4 - изменить колличество товара\n");
            printf("5 - Добавить магазин\n");
            printf("6 - показать все магазины\n");
            printf("7 - сменить магазин\n");
            printf("8 - выйти\n");
            f = _getche();
            if (f == '1') {
                store1[i].display();
            }
            else if (f == '2') {
                store1[i].add();
            }
            else if (f == '3') {
                printf("\nВведите код товара\n");
                gets_s(code);
                do {
                    printf("Введите новую цену\n");
                    scanf_s("%lf", &price);
                } while (price < 0);
                getchar();
                store1[i].priceChange(code, price);
            }
            else if (f == '4') {
                printf("\nВведите код товара\n");
                gets_s(code);
                printf("Введите на сколько изменилось колличество товара(если увеличилость - положительное число, если уменьшилось - отрицательное)\n");
                scanf_s("%d", &amountDifference);
                getchar();
                store1[i].amountChange(code, amountDifference);
            }
            else if (f == '5') {
                store1[max].read();
                i = max;
                max++;
                
            }
            else if (f == '6') {
                for (n = 0; n < max; n++) {
                    store1[n].displayName();
                }
            }
            else if (f == '7') {
                printf("\nВведите название магазина\n");
                gets_s(name);
                for (n = 0; n < max; n++) {
                    if (store1[n].storecmp(name) == 0) {
                        i = n;
                        n = max;
                    }
                }
            }
        }
    }
    else {
        store2 = new Store;
        strcpy_s(s, "-");
        strcpy_s(s1[0], "-");
        printf("Использовать или read чтобы ввести данные(1 - read, все остальные символы - init)\n");
        f = _getche();
        if (f == '1') {
            store2[0].read();
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
            store2[0].init(name, adress, numberOfItems, itemName, itemCode, itemPrice, itemAmount);
        }
        i = 0;
        max = 1;
        f = '1';
        while (f != '8') {
            printf("\nВведите номер следующего действия:\n");
            printf("1 - показать информацию о магазине\n");
            printf("2 - добавить новый вид товара\n");
            printf("3 - изменить цену товара\n");
            printf("4 - изменить колличество товара\n");
            printf("5 - Добавить магазин\n");
            printf("6 - показать все магазины\n");
            printf("7 - сменить магазин\n");
            printf("8 - выйти\n");
            f = _getche();
            if (f == '1') {
                store2[i].display();
            }
            else if (f == '2') {
                store2[i].add();
            }
            else if (f == '3') {
                printf("\nВведите код товара\n");
                gets_s(code);
                do {
                    printf("Введите новую цену\n");
                    scanf_s("%lf", &price);
                } while (price < 0);
                getchar();
                store2[i].priceChange(code, price);
            }
            else if (f == '4') {
                printf("\nВведите код товара\n");
                gets_s(code);
                printf("Введите на сколько изменилось колличество товара(если увеличилость - положительное число, если уменьшилось - отрицательное)\n");
                scanf_s("%d", &amountDifference);
                getchar();
                store2[i].amountChange(code, amountDifference);
            }
            else if (f == '5') {
                store2[max].read();
                i = max;
                max++;

            }
            else if (f == '6') {
                for (n = 0; n < max; n++) {
                    store2[n].displayName();
                }
            }
            else if (f == '7') {
                printf("Введите название магазина\n");
                gets_s(name);
                for (n = 0; n < max; n++) {
                    if (store2[n].storecmp(name) == 0) {
                        i = n;
                        n = max;
                    }
                }
            }
        }
        free(store2);
    }
    return 0;
}


