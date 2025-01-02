//
// Created by 123456 on 24-12-19.
//

#ifndef BOOKS_H
#define BOOKS_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winnls.h>

#define MAX_LENGTH 100

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
int getValidChoice();
void clearInputBuffer();
void writeUTF8(FILE *fp, const char *str) {
    wchar_t wstr[MAX_LENGTH];
    char utf8[MAX_LENGTH * 4];  // UTF-8 可能需要更多空间

    // 将ANSI字符串转换为宽字符
    MultiByteToWideChar(CP_ACP, 0, str, -1, wstr, MAX_LENGTH);

    // 将宽字符转换为UTF-8
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8, sizeof(utf8), NULL, NULL);

    // 写入UTF-8字符串
    fprintf(fp, "%s", utf8);
}
void readUTF8(char *utf8, char *str, int maxLen) {
    wchar_t wstr[MAX_LENGTH];

    // 将UTF-8转换为宽字符
    MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, MAX_LENGTH);

    // 将宽字符转换为ANSI
    WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, maxLen, NULL, NULL);
}

//图书信息管理系统目录
void booksmune()
{
    printf("\t+-------------------欢迎进入-------------------+\n");
    printf("\t|                图书管理系统                   |\n");
    printf("\t|                管理员管理系统                 |\n");
    printf("\t|                                             |\n");
    printf("\t|                1.修改图书信息                 |\n");
    printf("\t|                2.删除图书信息                 |\n");
    printf("\t|                3.添加图书信息                 |\n");
    printf("\t|                4.显示图书信息                 |\n");
    printf("\t|                5.查询指定图书信息              |\n");
    printf("\t|                0.返回主菜单                   |\n");
    printf("\t+---------------------------------------------+\n");
    printf("\n");
    printf("                 请选择 (0-5):");
}

void bookmain() {
    booksmune();
    int choice = getValidChoice();
    while (choice!=0) {
        switch (choice) {               //选择功能，输入0退出系统
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
        clearInputBuffer();
        choice = getValidChoice();
    }
    printf("\t退出成功！\n");
}


//删除图书信息功能函数
void deletebook() {
    struct books *head=readbooks();
    if (head==NULL) {
        return;
    }
    struct books *p=head;
    int choice ;
    printf("1.指定图书编号\n");
    printf("2.指定ISBM号\n");
    printf("3.指定书名\n");
    printf("4.指定作者姓名\n");
    printf("5.指定出版社\n");
    printf("请输入要删除的图书信息：");
    choice = getValidChoice();
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
    FILE *fp=fopen("books.txt","w");
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
    FILE *fp=fopen("books.txt","w");
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
    printf("请输入要删除书的名字：");
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
    FILE *fp=fopen("books.txt","w");
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
    printf("请输入要删除书的编号：");
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
    FILE *fp=fopen("books.txt","w");
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
    printf("请输入要删除书的ISBN：");
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
    FILE *fp=fopen("books.txt","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}


//查询图书信息功能函数
void searchbook()
{
    struct books *head=readbooks();
    if (head==NULL) {
        return;
    }
    struct books *p=head;
    int choice ;
    printf("1.指定图书编号\n");
    printf("2.指定ISBN号\n");
    printf("3.指定书名\n");
    printf("4.指定作者姓名\n");
    printf("5.指定出版社\n");
    printf("请输入要修改的图书信息：");
    choice = getValidChoice();
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


//修改图书信息功能函数
void changebook()
{
    struct books *head=readbooks();
    if (head==NULL) {
        return;
    }
    struct books *p=head;
    int choice ;
    printf("1.指定图书编号\n");
    printf("2.指定ISBN号\n");
    printf("3.指定书名\n");
    printf("4.指定作者姓名\n");
    printf("5.指定出版社\n");
    printf("请输入要修改的图书信息：");
    choice = getValidChoice();
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
    FILE *fp=fopen("books.txt","w");
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
    FILE *fp=fopen("books.txt","w");
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
    FILE *fp=fopen("books.txt","w");
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
    FILE *fp=fopen("books.txt","w");
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
    FILE *fp=fopen("books.txt","w");
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %s %s %s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
    fclose(fp);
}

//读取图书信息,得到链表
struct books* readbooks() {
    FILE *fp = fopen("books.txt", "rb");
    if (fp == NULL) {
        printf("没有存储书本内容，请先存储书本内容\n");
        return NULL;
    }

    struct books *head = NULL, *tail = NULL, *p = NULL;
    char line[MAX_LENGTH * 5];  // 假设 MAX_LENGTH 已定义

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strcmp(line, "\0") == 0) {
            printf("没有存储书本内容，请先存储书本内容\n");
            return NULL;
        }
        p = (struct books*)malloc(sizeof(struct books));
        if (p == NULL) {
            printf("内存分配失败\n");
            break;
        }

        char *token;
        char *nextToken = NULL;

        // 读取图书编号
        token = strtok_s(line, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue; // 跳过当前行
        }
        p->number = atoi(token);

        // 读取ISBN
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->ISBN, token);


        // 读取书名
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->name, token);
        // 读取作者
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->auther, token);
        // 读取出版社
        token = strtok_s(NULL, "\n", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->publish, token);

        p->next = NULL;

        if (head == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }

        p = NULL;  // 重置 p，防止在下一次循环时重复释放
    }

    fclose(fp);
    return head;

}


//输出所有图书信息
void printbooks(struct books *head)
{
    struct books *p=head;
    if (head==NULL) {
        return;
    }
    while(p!=NULL)
    {
        printf("图书编号：%d ISBN号：%s 书名：%s 作者姓名：%s 出版社：%s\n",p->number,p->ISBN,p->name,p->auther,p->publish);
        p=p->next;
    }
}


//添加图书信息功能函数
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
    FILE *fp=fopen("books.txt","ab+");
    //把信息用utf8编码写入文件
    fprintf(fp,"%d ",newbook.number);
    writeUTF8(fp, newbook.ISBN);
    fprintf(fp, " ");
    writeUTF8(fp, newbook.name);
    fprintf(fp, " ");
    writeUTF8(fp, newbook.auther);
    fprintf(fp, " ");
    writeUTF8(fp, newbook.publish);
    fprintf(fp, "\n");


    fclose(fp);
}

int getValidChoice() {
    char line[256];
    char *endptr;
    long choice;
    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return -1;  // 读取失败
        }

        // 移除行尾的换行符
        line[strcspn(line, "\n")] = 0;

        // 跳过前导空白字符
        char *start = line;
        while (isspace(*start)) start++;

        // 如果输入为空，继续循环
        if (*start == '\0') {
            printf("\n输入为空，请重新输入：\n");
            continue;
        }

        // 尝试将输入转换为长整型
        choice = strtol(start, &endptr, 10);

        // 检查转换是否成功，以及是否有多余字符
        if (endptr == start || *endptr != '\0') {
            printf("\n无效输入，请输入一个整数：\n");
            continue;
        }

        // 检查是否在int范围内
        if (choice > INT_MAX || choice < INT_MIN) {
            printf("\n数字超出范围，请重新输入：\n");
            continue;
        }

        return (int)choice;
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


#endif //BOOKS_H
