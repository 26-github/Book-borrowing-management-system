//
// Created by 123456 on 24-12-23.
//

#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>

#include "book.h"
#include "reader.h"



struct reader {
    int readernumber;
    char unit[10];
    char name[20];
    char gender[5];
    char jobtitle[15];
    char address[15];
    struct reader *next;
};

struct borrow {
    int readernumber;
    int booknumber;
    char time[10];
    struct borrow *next;
};


void addreader();
void deletereader();
void changereader();
void addborrow();
void deleteborrow();
void changeborrow();
void searchborrow();
void searchreaderborrow();
void searchbookborrow();
void readermain();
struct reader *readreader();
struct borrow *readborrow();


void borrowmune()
{
    printf("\t+-------------------欢迎进入-------------------+\n");
    printf("\t|                图书管理系统                  |\n");
    printf("\t|                管理员管理系统                |\n");
    printf("\t|                                              |\n");
    printf("\t|                1.增加读者信息                |\n");
    printf("\t|                2.删除读者信息                |\n");
    printf("\t|                3.修改读者信息                |\n");
    printf("\t|                4.增加借阅信息                |\n");
    printf("\t|                5.删除借阅信息                |\n");
    printf("\t|                6.修改借阅信息                |\n");
    printf("\t|                7.查询借阅信息                |\n");
    printf("\t|                0.返回主菜单                  |\n");
    printf("\t+----------------------------------------------+\n");
    printf("\n");
    printf("                 请选择 (0-7):");
}

void readermain() {
    borrowmune();
    int choice;
    scanf("%d",&choice);
    while (choice!=0) {
        switch (choice) {
            case 1:
                addreader();
                break;
            case 2:
                deletereader();
                break;
            case 3:
                changereader();
                break;
            case 4:
                addborrow();
                break;
            case 5:
                deleteborrow();
                break;
            case 6:
                changeborrow();
                break;
            case 7:
                searchborrow();
                break;
            default:
                printf("您输入的数字有误，请重新输入！\n");
        }
        booksmune();
        scanf("%d",&choice);
    }
    printf("\t退出成功！\n");
}

struct reader *readreader() {
    FILE *fp;
    struct reader *head=NULL;
    struct reader *p=NULL;
    struct reader *q=NULL;
    fp=fopen("reader.txt","r");
    if (fp==NULL) {
        printf("文件打开失败！\n");
        return NULL;
    }
    while (!feof(fp)) {
        p=(struct reader *)malloc(sizeof(struct reader));
        if (head==NULL) {
            head=p;
        } else {
            q->next=p;
        }
        fscanf(fp,"%d %s %s %s %s %s",&p->readernumber,p->unit,p->name,p->gender,p->jobtitle,p->address);
        p->next=NULL;
        q=p;
    }
    fclose(fp);
    return head;
}

void addreader() {
    struct reader *head=readreader();
    struct reader *p=head;
    struct reader *newreader=(struct reader *)malloc(sizeof(struct reader));
    printf("请输入读者编号：");
    scanf("%d",&newreader->readernumber);
    printf("请输入单位：");
    scanf("%s",newreader->unit);
    printf("请输入姓名：");
    scanf("%s",newreader->name);
    printf("请输入性别：");
    scanf("%s",newreader->gender);
    printf("请输入职称：");
    scanf("%s",newreader->jobtitle);
    printf("请输入地址：");
    scanf("%s",newreader->address);
    newreader->next=NULL;
    if (head==NULL) {
        head=newreader;
    } else {
        while (p->next!=NULL) {
            p=p->next;
        }
        p->next=newreader;
    }
    FILE *fp=fopen("reader.txt","w");
    p=head;
    while (p!=NULL) {
        fprintf(fp,"%d %s %s %s %s %s\n",p->readernumber,p->unit,p->name,p->gender,p->jobtitle,p->address);
        p=p->next;
    }
    fclose(fp);
    printf("添加成功！\n");
}

void deletereader() {
    struct reader *head=readreader();
    struct reader *p=head;
    struct reader *pre=head;
    int readernumber;
    int f=1;
    printf("请输入要删除的读者编号：");
    scanf("%d",&readernumber);
    while (p!=NULL) {
        if (p->readernumber==readernumber) {
            if (p==head) {
                head=p->next;
            } else {
                pre->next=p->next;
            }
            f=0;
            break;
        }
        pre=p;
        p=p->next;
    }
    if (f) {
        printf("您要找的读者不在读者库里\n");
        return;
    }
    FILE *fp=fopen("reader.txt","w");
    p=head;
    while (p!=NULL) {
        fprintf(fp,"%d %s %s %s %s %s\n",p->readernumber,p->unit,p->name,p->gender,p->jobtitle,p->address);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}

void changereader() {
    struct reader *head=readreader();
    struct reader *p=head;
    int readernumber;
    int f=1;
    printf("请输入要修改的读者编号：");
    scanf("%d",&readernumber);
    while (p!=NULL) {
        if (p->readernumber==readernumber) {
            printf("请输入新的读者编号：");
            scanf("%d",&p->readernumber);
            printf("请输入新的单位：");
            scanf("%s",p->unit);
            printf("请输入新的姓名：");
            scanf("%s",p->name);
            printf("请输入新的性别：");
            scanf("%s",p->gender);
            printf("请输入新的职称：");
            scanf("%s",p->jobtitle);
            printf("请输入新的地址：");
            scanf("%s",p->address);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的读者不在读者库里\n");
        return;
    }
    FILE *fp=fopen("reader.txt","w");
    p=head;
    while (p!=NULL) {
        fprintf(fp,"%d %s %s %s %s %s\n",p->readernumber,p->unit,p->name,p->gender,p->jobtitle,p->address);
        p=p->next;
    }
    fclose(fp);
    printf("修改成功！\n");
}

struct borrow *readborrow() {
    FILE *fp;
    struct borrow *head=NULL;
    struct borrow *p=NULL;
    struct borrow *q=NULL;
    fp=fopen("borrow.txt","r");
    if (fp==NULL) {
        printf("文件打开失败！\n");
        return NULL;
    }
    while (!feof(fp)) {
        p=(struct borrow *)malloc(sizeof(struct borrow));
        if (head==NULL) {
            head=p;
        } else {
            q->next=p;
        }
        fscanf(fp,"%d %d %s %s",&p->readernumber,&p->booknumber,p->time);
        p->next=NULL;
        q=p;
    }
    fclose(fp);
    return head;
}

void addborrow() {
    struct borrow *head=readborrow();
    struct borrow *p=head;
    struct borrow *newborrow=(struct borrow *)malloc(sizeof(struct borrow));
    printf("请输入读者编号：");
    scanf("%d",&newborrow->readernumber);
    printf("请输入图书编号：");
    scanf("%d",&newborrow->booknumber);
    printf("请输入借阅时间：");
    scanf("%s",newborrow->time);
    newborrow->next=NULL;
    if (head==NULL) {
        head=newborrow;
    } else {
        while (p->next!=NULL) {
            p=p->next;
        }
        p->next=newborrow;
    }
    FILE *fp=fopen("borrow.txt","w");
    p=head;
    while (p!=NULL) {
        fprintf(fp,"%d %d %s %s\n",p->readernumber,p->booknumber,p->time);
        p=p->next;
    }
    fclose(fp);
    printf("添加成功！\n");
}

void deleteborrow() {
    struct borrow *head=readborrow();
    struct borrow *p=head;
    struct borrow *pre=head;
    int booknumber;
    int f=1;
    printf("请输入要删除的书本编号：");
    scanf("%d",&booknumber);
    while (p!=NULL) {
        if (p->booknumber==booknumber) {
            struct books *pb=readbooks();
            while (pb->number==booknumber) {
                printf("%s 是这本吗？(y/n)",pb->name);
                char choice;
                scanf(" %c",&choice);
                if (choice=='n') {
                    pb=pb->next;
                    continue;
                }
                if (p==head) {
                    head=p->next;
                } else {
                    pre->next=p->next;
                }
                f=0;
                break;
            }
        if (f==0) {
            break;
        }
        }
        pre=p;
        p=p->next;
    }
    if (f) {
        printf("您要找的书本不在借阅信息里\n");
        return;
    }
    FILE *fp=fopen("borrow.txt","w");
    p=head;
    while (p!=NULL) {
        fprintf(fp,"%d %d %s %s\n",p->readernumber,p->booknumber,p->time);
        p=p->next;
    }
    fclose(fp);
    printf("删除成功！\n");
}

void changeborrow() {
    struct borrow *head=readborrow();
    struct borrow *p=head;
    int booknumber;
    int f=1;
    printf("请输入要修改的书本编号：");
    scanf("%d",&booknumber);
    while (p!=NULL) {
        if (p->booknumber==booknumber) {
            printf("请输入新的读者编号：");
            scanf("%d",&p->readernumber);
            printf("请输入新的图书编号：");
            scanf("%d",&p->booknumber);
            printf("请输入新的借阅时间：");
            scanf("%s",p->time);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书本不在借阅信息里\n");
        return;
    }
    FILE *fp=fopen("borrow.txt","w");
    p=head;
    while (p!=NULL) {
        fprintf(fp,"%d %d %s %s\n",p->readernumber,p->booknumber,p->time);
        p=p->next;
    }
    fclose(fp);
    printf("修改成功！\n");
}

void searchborrow() {
    struct borrow *head=readborrow();
    struct borrow *p=head;
    int choice;
    printf("1.指定读者编号\n");
    printf("2.指定图书编号\n");
    printf("请输入要查询的借阅信息：");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            searchreaderborrow();
            break;
        case 2:
            searchbookborrow();
            break;
        default:
            printf("您输入的数字有误，请重新输入！\n");
    }
}

void searchreaderborrow() {
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
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的读者不在借阅信息里\n");
        return;
    }
}

void searchbookborrow() {
    struct borrow *head=readborrow();
    struct borrow *p=head;
    int booknumber;
    int f=1;
    printf("请输入要查询的书本编号：");
    scanf("%d",&booknumber);
    while (p!=NULL) {
        if (p->booknumber==booknumber) {
            printf("读者编号是：%d\n",p->readernumber);
            printf("图书编号是：%d\n",p->booknumber);
            printf("借阅时间是：%s\n",p->time);
            f=0;
            break;
        }
        p=p->next;
    }
    if (f) {
        printf("您要找的书本不在借阅信息里\n");
        return;
    }
}
#endif //READER_H
