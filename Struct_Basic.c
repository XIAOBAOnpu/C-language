//
//  main.c
//  Structure_Basic
//
//  Created by HanBAO on 11/07/2024.
//

#include <stdio.h>

/*
struct People
{
    char name[20];
    char tele[12];
    char sex[5];
    int height;
}Bob, David;
 */
// Bob和David是使用struct People结构类型创建的2个变量
// 是两个全局的结构体变量 但是不推荐这样

// 一般来说：
struct People
{
    char name[20];
    char tele[12];
    char sex[5];
    int height;
};

// struct in another struct
struct Student
{
    struct People p;
    int score;
};

void dispUsing1(struct People sp)
{
    printf(" Name: %s;\n Tele: %s;\n Sex: %s;\n Height: %d;\n",sp.name, sp.tele, sp.sex, sp.height);
}

void dispUsing2(struct People* sp)
{
    printf(" Name: %s;\n Tele: %s;\n Sex: %s;\n Height: %d;\n",sp->name, sp->tele, sp->sex, sp->height);
}

int main(int argc, const char * argv[]) {
    // When you want to use this struct: create struct var:
    struct People p1 = {"Bob", "1234567012", "Male", 181};            // initialization
    struct Student s1 = {{"David", "1256789012", "Male", 198}, 10};   // initialization
    
    printf(" Name: %s;\n Tele: %s;\n Sex: %s;\n Height: %d;\n", p1.name, p1.tele, p1.sex, p1.height);
    printf(" Name: %s;\n Tele: %s;\n Sex: %s;\n Height: %d;\n Score: %d;\n", s1.p.name, s1.p.tele, s1.p.sex, s1.p.height, s1.score);
    // s1.p NOT s1.p1 !!!!!
    
    // Therefore, 2 methods:
    // 1. 结构体变量.成员变量
    dispUsing1(p1);     // 当结构体中的数据很多时，因为需要把所有这些数据传到函数中 --> 耗时长，浪费
    
    
    // if get the addr? use ->
    // 2. 结构体指针->成员变量
    dispUsing2(&p1);    // 取出4byte或者8byte大小的指针 --> 速度快，浪费小  推荐！！！
    
    return 0;
}
