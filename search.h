//
// Created by 123456 on 24-12-24.
//

#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>

#include "book.h"
#include "reader.h"


void searchmune();
void searchall();
void searchallbookauther();
void searchallbookpublish();
void searchallreaderborrow();

void searchmune() {
    printf("\t+-------------------欢迎进入-------------------+\n");
    printf("\t|                图书管理系统                  |\n");
    printf("\t|                批量查询系统                  |\n");
    printf("\t|                                              |\n");
    printf("\t|                1.查询指定作者的所有图书          |\n");
    printf("\t|                2.查询指定出版社的所有图书        |\n");
    printf("\t|                3.查询指定借书证借阅的所有书籍     |\n");
    printf("\t|                0.返回主菜单                  |\n");
    printf("\t+----------------------------------------------+\n");
    printf("\n");
    printf("                 请选择 (0-3):");
}
void searchall() {
    int choice;
    searchmune();
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            searchallbookauther();
            break;
        case 2:
            searchallbookpublish();
            break;
        case 3:
            searchallreaderborrow();
            break;
        default:
            printf("您输入的数字有误，请重新输入！\n");
    }
}


void searchallbookauther() {
    struct books *head=readbooks();
    struct books *p=head;
    char auther[30];
    int f=1;
    printf("请输入要查询的作者：");
    scanf("%s",auther);
    while(p!=NULL)
    {
        if(strcmp(p->auther,auther)==0)
        {
            printf("图书编号是：%d\n",p->number);
            printf("ISBN号是：%s\n",p->ISBN);
            printf("书名是：%s\n",p->name);
            printf("作者姓名是：%s\n",p->auther);
            printf("出版社是：%s\n",p->publish);
            f=0;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
}

void searchallbookpublish() {
    struct books *head=readbooks();
    struct books *p=head;
    char publish[30];
    int f=1;
    printf("请输入要查询的出版社：");
    scanf("%s",publish);
    while(p!=NULL)
    {
        if(strcmp(p->publish,publish)==0)
        {
            printf("图书编号是：%d\n",p->number);
            printf("ISBN号是：%s\n",p->ISBN);
            printf("书名是：%s\n",p->name);
            printf("作者姓名是：%s\n",p->auther);
            printf("出版社是：%s\n",p->publish);
            f=0;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
}

void searchallreaderborrow() {
    struct borrow *head=readborrow();
    struct borrow *p=head;
    int readernumber;
    int f=1;
    printf("请输入要查询的读者编号：");
    scanf("%d",&readernumber);
    while (p!=NULL) {
        if (p->readernumber==readernumber) {
            printf("读者编号是：%d\n",p->readernumber);
            printf("图书编号是：%d\n",p->booknumber);
            printf("借阅时间是：%s\n",p->time);
            f=0;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的读者不在借阅信息里\n");
        return;
    }
}
#endif //SEARCH_H
