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
void borrowmune();
struct reader *readreader();
struct borrow *readborrow();


//读者信息管理系统目录
void borrowmune()
{
    printf("\t+-------------------欢迎进入------------------+\n");
    printf("\t|                图书管理系统                  |\n");
    printf("\t|                管理员管理系统                |\n");
    printf("\t|                                            |\n");
    printf("\t|                1.增加读者信息                |\n");
    printf("\t|                2.删除读者信息                |\n");
    printf("\t|                3.修改读者信息                |\n");
    printf("\t|                4.增加借阅信息                |\n");
    printf("\t|                5.删除借阅信息                |\n");
    printf("\t|                6.修改借阅信息                |\n");
    printf("\t|                7.查询借阅信息                |\n");
    printf("\t|                0.返回主菜单                  |\n");
    printf("\t+--------------------------------------------+\n");
    printf("\n");
    printf("                 请选择 (0-7):");
}

void readermain() {
    borrowmune();
    int choice;
    scanf("%d",&choice);
    while (choice!=0) {
        switch (choice) {        //选择功能，输入0退出系统
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
        borrowmune();
        scanf("%d",&choice);
    }
    printf("\t退出成功！\n");
}

//读取读者信息，返回对应的链表
struct reader *readreader() {
    FILE *fp;
    fp=fopen("reader.txt","rb");
    if (fp==NULL) {       //如果文件不存在，返回NULL
        printf("没有存储读者信息，请先存储读者信息");
        printf("\n");
        return NULL;
    }
    char line[MAX_LENGTH * 5]; // 假设 MAX_LENGTH 已定义
    struct reader *head = NULL, *tail = NULL, *p = NULL;
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

        // 读取读者编号
        token = strtok_s(line, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue; // 跳过当前行
        }
        //去掉bomb头
        // p->readernumber = atoi( );
        int j=0;
        char format_token[30];
        for (int i = 0; token[i] != '\0'; i++) {
            if (isdigit(token[i])) {
                format_token[j]=token[i];
                j++;
            }
        }
        format_token[j]='\0';

        p->readernumber = atoi(format_token);

        // 读取单位
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->unit, token);


        // 读取姓名
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->name, token);
        // 读取性别
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->gender, token);
        // 读取职称
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->jobtitle, token);

        // 读取地址
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->address, token);

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

//添加读者信息功能函数
void addreader() {
    struct reader newreader;
    printf("请输入读者编号：");
    scanf("%d",&newreader.readernumber);
    printf("请输入单位：");
    scanf("%s",newreader.unit);
    printf("请输入姓名：");
    scanf("%s",newreader.name);
    printf("请输入性别：");
    scanf("%s",newreader.gender);
    printf("请输入职称：");
    scanf("%s",newreader.jobtitle);
    printf("请输入地址：");
    scanf("%s",newreader.address);
    FILE *fp=fopen("reader.txt","ab+");
    //把信息用utf8编码写入文件
    fprintf(fp,"%d ",newreader.readernumber);
    writeUTF8(fp, newreader.unit);
    fprintf(fp, " ");
    writeUTF8(fp, newreader.name);
    fprintf(fp, " ");
    writeUTF8(fp, newreader.gender);
    fprintf(fp, " ");
    writeUTF8(fp, newreader.jobtitle);
    fprintf(fp, " ");
    writeUTF8(fp, newreader.address);
    fprintf(fp, "\n");

    fclose(fp);
}


//删除读者信息功能函数
void deletereader() {
    struct reader *head=readreader();
    if (head==NULL) {
        return;
    }
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

//修改读者信息功能函数
void changereader() {
    struct reader *head=readreader();
    if (head==NULL) {
        return;
    }
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

//读取借阅信息，返回对应的链表
struct borrow *readborrow() {
    FILE *fp;
    fp=fopen("borrow.txt","rb");
    char line[MAX_LENGTH * 5];  // 假设 MAX_LENGTH 已定义
    if (fp==NULL) {        //如果文件不存在，返回NULL
        printf("没有存储借阅信息，请先存储借阅信息");
        printf("\n");
        return NULL;
    }
    struct borrow *head = NULL, *tail = NULL, *p = NULL;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strcmp(line, "\0") == 0) {
            printf("没有存储书本内容，请先存储书本内容\n");
            return NULL;
        }
        p = (struct borrow*)malloc(sizeof(struct borrow));
        if (p == NULL) {
            printf("内存分配失败\n");
            break;
        }

        char *token;
        char *nextToken = NULL;

        // 读取读者编号
        token = strtok_s(line, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue; // 跳过当前行
        }
        //去掉bomb头
        // p->readernumber = atoi( );
        int j=0;
        char format_token[30];
        for (int i = 0; token[i] != '\0'; i++) {
            if (isdigit(token[i])) {
                format_token[j]=token[i];
                j++;
            }
        }
        format_token[j]='\0';

        p->readernumber = atoi(format_token);

        // 读取图书编号
        token = strtok_s(NULL, " ", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        p->booknumber = atoi(token);


        // 读取借阅时间
        token = strtok_s(NULL, "\n", &nextToken);
        if (token == NULL) {
            free(p);
            continue;
        }
        strcpy(p->time, token);

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

//添加借阅信息功能函数
void addborrow() {
    struct borrow newborrow;
    printf("请输入读者编号：");
    scanf("%d",&newborrow.readernumber);
    printf("请输入图书编号：");
    scanf("%d",&newborrow.booknumber);
    printf("请输入借阅时间：");
    scanf("%s",newborrow.time);
    FILE *fp=fopen("borrow.txt","ab+");
    //把信息用utf8编码写入文件
    fprintf(fp,"%d ",newborrow.readernumber);
    fprintf(fp, " ");
    fprintf(fp,"%d ",newborrow.booknumber);
    fprintf(fp, " ");
    writeUTF8(fp, newborrow.time);
    fprintf(fp, "\n");

    fclose(fp);
}

//删除借阅信息功能函数
void deleteborrow() {
    struct borrow *head=readborrow();
    if (head==NULL) {
        return;
    }
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

//修改借阅信息功能函数
void changeborrow() {
    struct borrow *head=readborrow();
    if (head==NULL) {
        return;
    }
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

//查询借阅信息功能函数
void searchborrow() {
    struct borrow *head=readborrow();
    if (head==NULL) {
        return;
    }
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
    if (head==NULL) {
        return;
    }
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
