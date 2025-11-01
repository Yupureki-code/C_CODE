#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

typedef struct PeoInfo {
    char name[30];
    size_t age;
    char sex[10];
    char tele[12];
} Peo;

// 链表节点结构
typedef struct ContactNode {
    Peo data;
    struct ContactNode* next;
} ContactNode;

// 通讯录结构（使用链表）
typedef struct Contacts {
    ContactNode* head;
    size_t size;
} con;

void InitContacts(con* pc);
void ContactsBreak(con* pc);
void ContactsPushFront(con* pc);
void ContactsPrint(con* pc);
void ContactsPushBack(con* pc);
void ContactsInsert(con* pc);
void ContactsErase(con* pc);
void ContactsPopFront(con* pc);
void ContactsPopBack(con* pc);
void ContactsSave(con* pc);
void ContactsFind(con* pc);
void ContactsChange(con* pc);
void menu();

