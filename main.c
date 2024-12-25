#include <stdio.h>
#include "book.h"
#include "reader.h"
#include "search.h"
void Menu() {
    printf("\t  +-----------------------欢迎进入-----------------------+\n");
    printf("\t|                     图书借阅管理系统                   |\n");
    printf("\t|                                                     |\n");
    printf("\t|                  1. 图书信息管理系统                    |\n");
    printf("\t|                  2. 读者信息管理系统                    |\n");
    printf("\t|                  3. 批量查询系统                       |\n");
    printf("\t|                  4. xxxx系统                       |\n");
    printf("\t|                  0. 退出系统                          |\n");
    printf("\t+------------------------------------------------------+\n");
    printf("\n");
    printf("                    请选择 (0-3): ");
}

int login() {
    char username[20];
    char password[20];
    printf("请输入用户名：");
    scanf("%s",username);
    printf("请输入密码：");
    scanf("%s",password);
    for (int i=0;i<3;i++) {
        if (strcmp(username,"pass")==0 && strcmp(password,"word")==0) {
            printf("登录成功！\n");
            return 1;
        }
        if (i<2) {
            printf("用户名或密码错误，请重新输入！\n");
            printf("请输入用户名：");
            scanf("%s",username);
            printf("请输入密码：");
            scanf("%s",password);
        }
    }
    return 0;
}
int main(void) {
    if (!login()) {
        printf("登录失败！\n");
        return 0;
    }
    Menu();
    int choice;
    scanf("%d",&choice);
    while (choice!=0) {
        switch (choice) {
            case 1:
                bookmain();
                break;
            case 2:
                readermain();
                break;
            case 3:
                searchall();
                break;
            default:
                printf("您输入的数字有误，请重新输入！\n");

        }
        Menu();
        scanf("%d",&choice);
    }
    printf("\t欢迎下次使用！");


    return 0;
}