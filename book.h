//
// Created by 123456 on 24-12-19.
//

#ifndef BOOKS_H
#define BOOKS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct books
{

    int number;
    char ISBN[30];
    char name[20];
    char auther[20];
    char publish[20];
    struct books *next;
};
struct books* readbooks();
void printbooks(struct books *head);
void inputbook();
void booksmune();
void bookmain();
void changebook();
void changebooknumber();
void changebookISBN();
void changebookname();
void changebookauther();
void changebookpublish();
void searchbook();
void searchbooknumber();
void searchbookISBN();
void searchbookname();
void searchbookauther();
void searchbookpublish();
void deletebook();
void deletebooknumber();
void deletebookpublish();
void deletebookauther();
void deletebookname();;
void deletebookISBN();



void booksmune()
{
    printf("\t+-------------------欢迎进入-------------------+\n");
    printf("\t|                图书管理系统                  |\n");
    printf("\t|                管理员管理系统                |\n");
    printf("\t|                                              |\n");
    printf("\t|                1.修改图书信息                |\n");
    printf("\t|                2.删除图书信息                |\n");
    printf("\t|                3.添加图书信息                |\n");
    printf("\t|                4.显示图书信息                |\n");
    printf("\t|                5.查询指定图书信息             |\n");
    printf("\t|                0.返回主菜单                  |\n");
    printf("\t+----------------------------------------------+\n");
    printf("\n");
    printf("                 请选择 (0-5):");
}

void bookmain() {
    booksmune();
    int choice;
    scanf("%d",&choice);
    while (choice!=0) {
        switch (choice) {
            case 1:
                changebook();
                break;
            case 2:
                deletebook();
                break;
            case 3:
                inputbook();
                break;
            case 4:
                printbooks(readbooks());
                break;
            case 5:
                searchbook();
                break;
            default:
                printf("您输入的数字有误，请重新输入！\n");

        }
        booksmune();
        scanf("%d",&choice);
    }
    printf("\t退出成功！\n");
}

void deletebook() {
    struct books *head=readbooks();
    struct books *p=head;
    int choice;
    printf("1.指定图书编号\n");
    printf("2.指定ISBM号\n");
    printf("3.指定书名\n");
    printf("4.指定作者姓名\n");
    printf("5.指定出版社\n");
    printf("请输入要删除的图书信息：");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            deletebooknumber();
            break;
        case 2:
            deletebookISBN();
            break;
        case 3:
            deletebookname();
            break;
        case 4:
            deletebookauther();
            break;
        case 5:
            deletebookpublish();
            break;
        default:
            printf("您输入的数字有误，请重新输入！\n");
    }

}


void deletebookpublish() {
    struct books *head=readbooks();
    struct books *p=head,*pre=head;
    char publish[30];
    int f=1;
    printf("请输入要删除书的出版社：");
    scanf("%s",publish);
    while(p!=NULL)
    {
        if(strcmp(p->publish,publish)==0)
        {
            printf("%s 是这本吗？y/n:",p->name);
            char choice;
            scanf(" %c",&choice);
            if (choice=='n') {
                p=p->next;
                continue;
            }

            if (p==head) {
                head=p->next;
            }else{
                pre->next=p->next;
            }
            f=0;
            break;
        }
        pre=p;
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}

void deletebookauther() {
    struct books *head=readbooks();
    struct books *p=head,*pre=head;
    char auther[30];
    int f=1;
    printf("请输入要删除书的作者：");
    scanf("%s",auther);
    while(p!=NULL)
    {
        if(strcmp(p->auther,auther)==0)
        {
            printf("%s 是这本吗？y/n:",p->name);
            char choice;
            scanf(" %c",&choice);
            if (choice=='n') {
                p=p->next;
                continue;
            }

            if (p==head) {
                head=p->next;
            }else{
                pre->next=p->next;
            }
            f=0;
            break;
        }
        pre=p;
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}

void deletebookname() {
    struct books *head=readbooks();
    struct books *p=head,*pre=head;
    char name[30];
    int f=1;
    printf("请输入要修改书的名字：");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            if (p==head) {
                head=p->next;
            }else{
                pre->next=p->next;
            }
            f=0;
            break;
        }
        pre=p;
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}

void deletebooknumber()
{
    struct books *head=readbooks();
    struct books *p=head,*pre=head;
    int number,f=1;
    printf("请输入要修改书的编号：");
    scanf("%d",&number);
    while(p!=NULL)
    {
        if(p->number==number)
        {
            if (p==head) {
                head=p->next;
            }else{
                pre->next=p->next;
            }
            f=0;
            break;
        }
        pre=p;
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}

void deletebookISBN(){
    struct books *head=readbooks();
    struct books *p=head,*pre=head;
    int f=1;
    char ISBN[30];
    printf("请输入要修改书的ISBN：");
    scanf("%s",ISBN);
    while(p!=NULL)
    {
        if(strcmp(p->ISBN,ISBN)==0)
        {
            if (p==head) {
                head=p->next;
            }else{
                pre->next=p->next;
            }
            f=0;
            break;
        }
        pre=p;
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}

void searchbook()
{
    struct books *head=readbooks();
    struct books *p=head;
    int choice;
    printf("1.指定图书编号\n");
    printf("2.指定ISBN号\n");
    printf("3.指定书名\n");
    printf("4.指定作者姓名\n");
    printf("5.指定出版社\n");
    printf("请输入要修改的图书信息：");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            searchbooknumber();
            break;
        case 2:
            searchbookISBN();
            break;
        case 3:
            searchbookname();
            break;
        case 4:
            searchbookauther();
            break;
        case 5:
            searchbookpublish();
            break;
        default:
            printf("您输入的数字有误，请重新输入！\n");
    }

}

void searchbookpublish() {
    struct books *head=readbooks();
    struct books *p=head;
    char publish[30];
    int f=1;
    printf("请输入要查询书的出版社：");
    scanf("%s",publish);
    while(p!=NULL)
    {
        if(strcmp(p->publish,publish)==0)
        {
            printf("%s 是这本吗？y/n:",p->name);
            char choice;
            scanf(" %c",&choice);
            if (choice=='n') {
                p=p->next;
                continue;
            }

            printf("图书编号是：%d\n",p->number);
            printf("ISBN号是：%s\n",p->ISBN);
            printf("书名是：%s\n",p->name);
            printf("作者姓名是：%s\n",p->auther);
            printf("出版社是：%s\n",p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
}

void searchbookauther() {
    struct books *head=readbooks();
    struct books *p=head;
    char auther[30];
    int f=1;
    printf("请输入要查询书的作者：");
    scanf("%s",auther);
    while(p!=NULL)
    {
        if(strcmp(p->auther,auther)==0)
        {
            printf("%s 是这本吗？y/n:",p->name);
            char choice;
            scanf(" %c",&choice);
            if (choice=='n') {
                p=p->next;
                continue;
            }

            printf("图书编号是：%d\n",p->number);
            printf("ISBN号是：%s\n",p->ISBN);
            printf("书名是：%s\n",p->name);
            printf("作者姓名是：%s\n",p->auther);
            printf("出版社是：%s\n",p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
}

void searchbookname() {
    struct books *head=readbooks();
    struct books *p=head;
    char name[30];
    int f=1;
    printf("请输入要查询书的名字：");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            printf("图书编号是：%d\n",p->number);
            printf("ISBN号是：%s\n",p->ISBN);
            printf("书名是：%s\n",p->name);
            printf("作者姓名是：%s\n",p->auther);
            printf("出版社是：%s\n",p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
}

void searchbooknumber()
{
    struct books *head=readbooks();
    struct books *p=head;
    int number,f=1;
    printf("请输入要查询书的编号：");
    scanf("%d",&number);
    while(p!=NULL)
    {
        if(p->number==number)
        {
            printf("图书编号是：%d\n",p->number);
            printf("ISBN号是：%s\n",p->ISBN);
            printf("书名是：%s\n",p->name);
            printf("作者姓名是：%s\n",p->auther);
            printf("出版社是：%s\n",p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
}

void searchbookISBN(){
    struct books *head=readbooks();
    struct books *p=head;
    int f=1;
    char ISBM[30];
    printf("请输入要查询书的ISBN：");
    scanf("%s",ISBM);
    while(p!=NULL)
    {
        if(strcmp(p->ISBN,ISBM)==0)
        {
            printf("图书编号是：%d\n",p->number);
            printf("ISBN号是：%s\n",p->ISBN);
            printf("书名是：%s\n",p->name);
            printf("作者姓名是：%s\n",p->auther);
            printf("出版社是：%s\n",p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
}

void changebook()
{
    struct books *head=readbooks();
    struct books *p=head;
    int choice;
    printf("1.指定图书编号\n");
    printf("2.指定ISBN号\n");
    printf("3.指定书名\n");
    printf("4.指定作者姓名\n");
    printf("5.指定出版社\n");
    printf("请输入要修改的图书信息：");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            changebooknumber();
            break;
        case 2:
            changebookISBN();
            break;
        case 3:
            changebookname();
            break;
        case 4:
            changebookauther();
            break;
        case 5:
            changebookpublish();
            break;
        default:
            printf("您输入的数字有误，请重新输入！\n");
    }

}

void changebookpublish() {
    struct books *head=readbooks();
    struct books *p=head;
    char publish[30];
    int f=1;
    printf("请输入要修改书的出版社：");
    scanf("%s",publish);
    while(p!=NULL)
    {
        if(strcmp(p->publish,publish)==0)
        {
            printf("%s 是这本吗？y/n:",p->name);
            char choice;
            scanf(" %c",&choice);
            if (choice=='n') {
                p=p->next;
                continue;
            }

            printf("请输入新的图书编号：");
            scanf("%d",&p->number);
            printf("请输入新的ISBN号：");
            scanf("%s",&p->ISBN);
            printf("请输入新的书名：");
            scanf("%s",&p->name);
            printf("请输入新的作者姓名：");
            scanf("%s",&p->auther);
            printf("请输入新的出版社：");
            scanf("%s",&p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
}

void changebookauther() {
    struct books *head=readbooks();
    struct books *p=head;
    char auther[30];
    int f=1;
    printf("请输入要修改书的作者：");
    scanf("%s",auther);
    while(p!=NULL)
    {
        if(strcmp(p->auther,auther)==0)
        {
            printf("%s 是这本吗？y/n:",p->name);
            char choice;
            scanf(" %c",&choice);
            if (choice=='n') {
                p=p->next;
                continue;
            }

            printf("请输入新的图书编号：");
            scanf("%d",&p->number);
            printf("请输入新的ISBN号：");
            scanf("%s",&p->ISBN);
            printf("请输入新的书名：");
            scanf("%s",&p->name);
            printf("请输入新的作者姓名：");
            scanf("%s",&p->auther);
            printf("请输入新的出版社：");
            scanf("%s",&p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
}

void changebookname() {
    struct books *head=readbooks();
    struct books *p=head;
    char name[30];
    int f=1;
    printf("请输入要修改书的名字：");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            printf("请输入新的图书编号：");
            scanf("%d",&p->number);
            printf("请输入新的ISBN号：");
            scanf("%s",&p->ISBN);
            printf("请输入新的书名：");
            scanf("%s",&p->name);
            printf("请输入新的作者姓名：");
            scanf("%s",&p->auther);
            printf("请输入新的出版社：");
            scanf("%s",&p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
}

void changebooknumber()
{
    struct books *head=readbooks();
    struct books *p=head;
    int number,f=1;
    printf("请输入要修改书的编号：");
    scanf("%d",&number);
    while(p!=NULL)
    {
        if(p->number==number)
        {
            printf("请输入新的图书编号：");
            scanf("%d",&p->number);
            printf("请输入新的ISBN号：");
            scanf("%s",&p->ISBN);
            printf("请输入新的书名：");
            scanf("%s",&p->name);
            printf("请输入新的作者姓名：");
            scanf("%s",&p->auther);
            printf("请输入新的出版社：");
            scanf("%s",&p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
}

void changebookISBN(){
    struct books *head=readbooks();
    struct books *p=head;
    int f=1;
    char ISBN[30];
    printf("请输入要修改书的ISBN：");
    scanf("%s",ISBN);
    while(p!=NULL)
    {
        if(strcmp(p->ISBN,ISBN)==0)
        {
            printf("请输入新的图书编号：");
            scanf("%d",&p->number);
            printf("请输入新的ISBN号：");
            scanf("%s",&p->ISBN);
            printf("请输入新的书名：");
            scanf("%s",&p->name);
            printf("请输入新的作者姓名：");
            scanf("%s",&p->auther);
            printf("请输入新的出版社：");
            scanf("%s",&p->publish);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书不在书库里\n");
        return;
    }
    FILE *fp=fopen("books","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
}

struct books* readbooks(){
    FILE *fp=fopen("books","r");
    struct books *head=NULL,*pre,*p;
    while(feof(fp)==0)
    {
        struct books *p=(struct books*)malloc(sizeof(struct books));
        if(head==NULL){
            head=p;
            fscanf(fp,"%d %s %s %s %s\n",&p->number,p->ISBN,p->name,p->auther,p->publish);
            p->next=NULL;
            pre=p;
        }else {
            fscanf(fp,"%d %s %s %s %s\n",&p->number,p->ISBN,p->name,p->auther,p->publish);
            p->next=NULL;
            pre->next=p;
            pre=p;
        }
    }
    return head;
}



void printbooks(struct books *head)
{
    struct books *p=head;
    while(p!=NULL)
    {
        printf("图书编号：%d ISBN号：%s 书名：%s 作者姓名：%s 出版社：%s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
}
void inputbook() {
    struct books newbook;
    printf("请输入图书编号：");
    scanf("%d",&newbook.number);
    printf("请输入ISBN号：");
    scanf("%s",&newbook.ISBN);
    printf("请输入书名：");
    scanf("%s",&newbook.name);
    printf("请输入作者姓名：");
    scanf("%s",&newbook.auther);
    printf("请输入出版社：");
    scanf("%s",&newbook.publish);
    FILE *fp=fopen("books","a");
    fprintf(fp,"%d %s %s %s %s\n",newbook.number,newbook.ISBN,newbook.name,newbook.auther,newbook.publish);
    fclose(fp);
}

#endif //BOOKS_H
