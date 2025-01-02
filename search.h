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
char * getValidChar();


//批量查询系统目录
void searchmune() {
    printf("\t+-------------------欢迎进入------------------+\n");
    printf("\t|                图书管理系统                  |\n");
    printf("\t|                批量查询系统                  |\n");
    printf("\t|                                            |\n");
    printf("\t|                1.查询指定作者的所有图书        |\n");
    printf("\t|                2.查询指定出版社的所有图书      |\n");
    printf("\t|                3.查询指定借书证借阅的所有书籍   |\n");
    printf("\t|                0.返回主菜单                  |\n");
    printf("\t+--------------------------------------------+\n");
    printf("\n");
    printf("                 请选择 (0-3):");
}

void searchall() {
    int choice;
    searchmune();
    choice = getValidChoice();
    switch (choice) {       //选择功能，输入0退出系统
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

//查询指定作者的所有图书
void searchallbookauther() {
    struct books *head=readbooks();
    if (head==NULL) {
        return;
    }
    struct books *p=head;
    char auther[30];
    int f=1;
    printf("请输入要查询的作者：");
    wscanf(L"%ls", auther);
    wcstombs(auther, auther, 31);
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
        printf("书库里没有目标作者\n");
        return;
    }
}

//查询指定出版社的所有图书
void searchallbookpublish() {
    struct books *head=readbooks();
    if (head==NULL) {
        return;
    }
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
        printf("书库里没有目标出版社\n");
        return;
    }
}

//查询指定借书证借阅的所有书籍
void searchallreaderborrow() {
    struct borrow *head;
    head=readborrow();
    if (head==NULL) {
        return;
    }
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
        printf("库里没有目标读者\n");
        return;
    }
}

#endif //SEARCH_H
