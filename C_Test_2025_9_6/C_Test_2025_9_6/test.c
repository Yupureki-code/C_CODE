#define _CRT_SECURE_NO_WARNINGS 1
#include "Contacts.h"

void menu() {
    printf("1.首部添加联系人  2.尾部添加联系人\n");
    printf("3.删除首部联系人  4.删除尾部联系人\n");
    printf("5.插入指定联系人  6删除指定联系人\n");
    printf("7.修改指定联系人  8.查找联系人\n");
    printf("0.退出");
}

int main() {
    con test;
    void (*parr[9])(con*) = { 0, ContactsPushFront, ContactsPushBack, ContactsPopFront,
                             ContactsPopBack, ContactsInsert, ContactsErase, ContactsChange, ContactsFind };

    InitContacts(&test);
    ContactsPrint(&test);

    int input = 0;
    do {
        menu();
        printf("请选择->");
        scanf("%d", &input);

        if (input >= 1 && input <= 8) {
            parr[input](&test);
            system("cls");
            ContactsPrint(&test);
        }
        else if (input != 0) {
            printf("输入错误\n");
        }
    } while (input != 0);

    ContactsSave(&test);
    ContactsBreak(&test);

    return 0;
}
