#define _CRT_SECURE_NO_WARNINGS 1
#include "Contacts.h"

// 创建新节点
ContactNode* CreateNode(Peo data) {
    ContactNode* newNode = (ContactNode*)malloc(sizeof(ContactNode));
    if (newNode == NULL) {
        perror("malloc");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InitContacts(con* pc) {
    FILE* pr = fopen("Contacts.txt", "r");
    pc->head = NULL;
    pc->size = 0;

    if (pr == NULL) {
        return;
    }

    size_t size, capacity;
    fscanf(pr, "%zu %zu\n", &size, &capacity);

    for (int i = 0; i < size; i++) {
        Peo newPeo;
        fscanf(pr, "%s %zu %s %s\n", newPeo.name, &(newPeo.age), newPeo.sex, newPeo.tele);

        ContactNode* newNode = CreateNode(newPeo);
        if (pc->head == NULL) {
            pc->head = newNode;
        }
        else {
            ContactNode* cur = pc->head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
        pc->size++;
    }

    fclose(pr);
    pr = NULL;
}

void ContactsBreak(con* pc) {
    ContactNode* cur = pc->head;
    while (cur != NULL) {
        ContactNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pc->head = NULL;
    pc->size = 0;
}

void ContactsPushFront(con* pc) {
    Peo newPeo;
    printf("请输入->名字 年龄 性别 电话号码\n");
    scanf("%s %zu %s %s", newPeo.name, &(newPeo.age), newPeo.sex, newPeo.tele);

    ContactNode* newNode = CreateNode(newPeo);
    newNode->next = pc->head;
    pc->head = newNode;
    pc->size++;
}

void ContactsPrint(con* pc) {
    if (pc->size == 0) {
        printf("通讯录为空\n");
        return;
    }

    printf("*********************************************\n");
    ContactNode* cur = pc->head;
    int i = 1;
    while (cur != NULL) {
        printf("%d.       %s %zu %s %s\n", i, cur->data.name, cur->data.age, cur->data.sex, cur->data.tele);
        cur = cur->next;
        i++;
    }
    printf("*********************************************\n");
}

void ContactsPushBack(con* pc) {
    Peo newPeo;
    printf("请输入->名字 年龄 性别 电话号码\n");
    scanf("%s %zu %s %s", newPeo.name, &(newPeo.age), newPeo.sex, newPeo.tele);

    ContactNode* newNode = CreateNode(newPeo);

    if (pc->head == NULL) {
        pc->head = newNode;
    }
    else {
        ContactNode* cur = pc->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    pc->size++;
}

void ContactsInsert(con* pc) {
    size_t pose;
    printf("请输入->插入序号 名字 年龄 性别 电话号码\n");

    Peo newPeo;
    scanf("%zu %s %zu %s %s", &pose, newPeo.name, &(newPeo.age), newPeo.sex, newPeo.tele);

    if (pose < 1 || pose > pc->size + 1) {
        printf("输入错误\n");
        return;
    }

    ContactNode* newNode = CreateNode(newPeo);

    if (pose == 1) {
        newNode->next = pc->head;
        pc->head = newNode;
    }
    else {
        ContactNode* cur = pc->head;
        for (size_t i = 1; i < pose - 1; i++) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    pc->size++;
}

void ContactsErase(con* pc) {
    size_t pose;
    printf("请输入删除序号->");
    scanf("%zu", &pose);

    if (pose < 1 || pose > pc->size) {
        printf("输入错误\n");
        return;
    }

    if (pose == 1) {
        ContactNode* toDelete = pc->head;
        pc->head = pc->head->next;
        free(toDelete);
    }
    else {
        ContactNode* cur = pc->head;
        for (size_t i = 1; i < pose - 1; i++) {
            cur = cur->next;
        }
        ContactNode* toDelete = cur->next;
        cur->next = toDelete->next;
        free(toDelete);
    }
    pc->size--;
}

void ContactsPopFront(con* pc) {
    if (pc->head == NULL) {
        return;
    }

    ContactNode* toDelete = pc->head;
    pc->head = pc->head->next;
    free(toDelete);
    pc->size--;
}

void ContactsPopBack(con* pc) {
    if (pc->head == NULL) {
        return;
    }

    if (pc->head->next == NULL) {
        free(pc->head);
        pc->head = NULL;
    }
    else {
        ContactNode* cur = pc->head;
        while (cur->next->next != NULL) {
            cur = cur->next;
        }
        free(cur->next);
        cur->next = NULL;
    }
    pc->size--;
}

void ContactsSave(con* pc) {
    FILE* ps = fopen("Contacts.txt", "w");
    assert(ps);

    fprintf(ps, "%zu 0\n", pc->size); // 第二个参数保持为0，因为链表不需要容量

    ContactNode* cur = pc->head;
    while (cur != NULL) {
        fprintf(ps, "%s %zu %s %s\n", cur->data.name, cur->data.age, cur->data.sex, cur->data.tele);
        cur = cur->next;
    }

    fclose(ps);
    ps = NULL;
}

void ContactsChange(con* pc) {
    size_t pose;
    printf("请输入->修改序号 名字 年龄 性别 电话号码\n");

    Peo newPeo;
    scanf("%zu %s %zu %s %s", &pose, newPeo.name, &(newPeo.age), newPeo.sex, newPeo.tele);

    if (pose < 1 || pose > pc->size) {
        printf("输入错误\n");
        return;
    }

    ContactNode* cur = pc->head;
    for (size_t i = 1; i < pose; i++) {
        cur = cur->next;
    }

    cur->data = newPeo;
}

void ContactsFind(con* pc) {
    int input = 0;
    int found = 0;

    do {
        printf("1名字查找 2电话号码查找 0退出\n");
        scanf("%d", &input);

        switch (input) {
        case 1: {
            printf("请输入名字->\n");
            char name[30];
            scanf("%s", name);

            ContactNode* cur = pc->head;
            int index = 1;
            found = 0;

            while (cur != NULL) {
                if (strcmp(name, cur->data.name) == 0) {
                    printf("第%d位: %s %zu %s %s\n", index, cur->data.name, cur->data.age, cur->data.sex, cur->data.tele);
                    found = 1;
                }
                cur = cur->next;
                index++;
            }

            if (!found) {
                printf("不存在\n");
            }
            break;
        }
        case 2: {
            printf("请输入号码->\n");
            char tel[12];
            scanf("%s", tel);

            ContactNode* cur = pc->head;
            int index = 1;
            found = 0;

            while (cur != NULL) {
                if (strcmp(tel, cur->data.tele) == 0) {
                    printf("第%d位: %s %zu %s %s\n", index, cur->data.name, cur->data.age, cur->data.sex, cur->data.tele);
                    found = 1;
                }
                cur = cur->next;
                index++;
            }

            if (!found) {
                printf("不存在\n");
            }
            break;
        }
        case 0:
            break;
        default:
            printf("输入错误\n");
            break;
        }
    } while (input != 0);
}
