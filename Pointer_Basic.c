#include <stdio.h>

void ptrBasic(void)
{
    printf("============================ POINTER BASIC ============================\n");
    int a = 10; // a is an int, needs 4 bytes of mem space
    int* pa = &a; // & to get the addr of a （引用）
                  // * to get the value in that addr （解引用）
                  // pa is a pointer var (i.e. pointer, still a var), used to store addr
                  // pointer is addr
    printf("Value of a (a) is: %d\n", a);
    printf("Addr of a (&a) is: %p\n", &a);
    printf("Value of pointer var (pa) is: %p\n", pa);
    printf("Value in pointed addr (*pa) is: %d\n", *pa);
    
    printf("============================ SIZE OF POINTERS ============================\n");
    printf("Size of char is: %zu bytes\n", sizeof(char));
    printf("Size of int is: %zu bytes\n", sizeof(int));
    printf("Size of long is: %zu bytes\n", sizeof(long));
    printf("Size of float is: %zu bytes\n", sizeof(float));
    // in x64 size of all pointers are 8 bytes
    printf("Size of char pointer is: %zu bytes\n", sizeof(char*));
    printf("Size of int pointer is: %zu bytes\n", sizeof(int*));
    printf("Size of long pointer is: %zu bytes\n", sizeof(long*));
    printf("Size of float pointer is: %zu bytes\n", sizeof(float*));
    
    // Though the size of the pointers are the same
    // different types of pointer can have different results sometimes:
    int int_b = 0x11223344;
    int char_b = 0x11223344;
    int* pointer_int_b = &int_b;
    char* pointer_char_b = (char*) &char_b;     // 强制类型转换
    *pointer_int_b = 0; // change the value
    *pointer_char_b = 0; // change the value
    printf("Value of int after changing: %x\n", int_b); // Everything changes to 0
                                                        // since int type is 4 bytes
    printf("Value of char after changing: %x\n", char_b); // Only last byte changes to 0
                                                          // since char type is 1 byte only
    // Therefore: 指针类型决定了指针在被解引用的时候访问几个字节
    //            如果是int*的指针，解引用访问4个bytes
    //            如果是char*的指针，解引用访问1个byte
    // One more example:
    printf("pointer_int_b is: %p\n", pointer_int_b);
    printf("pointer_int_b + 1 is: %p\n", pointer_int_b + 1);    // 4 bytes addr forward
                                                                // since int type is 4 bytes
    printf("pointer_char_b is: %p\n", pointer_char_b);
    printf("pointer_char_b + 1 is: %p\n", pointer_char_b + 1);  // 1 byte addr forward
                                                                // since char type is 1 byte only
    // Therefore: 指针的类型决定了指针+1和-1操作的时候跳过几个byte
    //            也就是决定了指针的步长
    //            便于访问，例如你想一次性访问4个bytes -> 用int*
    //                         想一次只访问1个byte -> 可以强制转换(char*)然后用char*
    //            同理，+n和-n对于int*就是跳过4 * n个bytes
    //                       对于char*就是跳过1 * n个bytes
    
    printf("============================ USE POINTER TO CHANGE THE VALUE ============================\n");
    // We can use pointer to change the value of a
    *pa = 20;
    printf("Value of a (a) after changing is: %d\n", a);    // no longer 10, but 20
    
    printf("============================ WILD POINTER ============================\n");
    //int* wild_pointer;  // no initialization
                        // 没有初始化就意味着没有明确的指向，存放随机值
    //*wild_pointer = 10; // 非法访问内存了 will have warning
                          // INITIALIZE IT TO NULL (本质上是0)
    
    // int* wild_pointer = NULL; // this is good!!!!
    // when want to use this NULL
    // error:
    // *wild_pointer = 100;
    // good:
    /*
     if (wild_pointer != NULL)
     {
        *wild_pointer = 100;
     }
     */
    
    // 指针越界访问 pointer out-of-bounds access:
    int arr_out_of_bounds[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int* pointer_arr_out_of_bounds = arr_out_of_bounds;
    // pointer points to the 1st element of array
    printf("Addr of 1st element in array (&arr_out_of_bounds[0]) is: %p\n", &arr_out_of_bounds[0]);
    printf("Addr of 2st element in array (&arr_out_of_bounds[1]) is: %p\n", &arr_out_of_bounds[1]);
    printf("Value of 2st element in array (arr_out_of_bounds[1]) is: %d\n", arr_out_of_bounds[1]);
    printf("Addr of pointer (pointer_arr_out_of_bounds) is: %p\n", pointer_arr_out_of_bounds);
    printf("Addr of pointer + 1(pointer_arr_out_of_bounds + 1) is: %p\n", pointer_arr_out_of_bounds + 1);
    
    // some other reminders: be careful when using +1 or -1 (+n, -n)
    printf("Value of *pointer_arr_out_of_bounds + 1 is: %d\n", *pointer_arr_out_of_bounds + 1); // point to 0, then + 1 = 1
    printf("Value of *(pointer_arr_out_of_bounds + 1) is: %d\n", *(pointer_arr_out_of_bounds + 1)); // point to 10
    
    /*
    for(int count_arr_out_of_bounds = 0; count_arr_out_of_bounds <= 10; count_arr_out_of_bounds++)  // loop for 11 times
    {
        *pointer_arr_out_of_bounds = count_arr_out_of_bounds;   // array from 0~10
                                                                // out of bounds when count_arr_out_of_bounds = 10
                                                                // result in wild pointer
        pointer_arr_out_of_bounds++;
    }
    */
    
    printf("============================ USE POINTER TO INITIAL ARRAY ============================\n");
    // Two ways to initializa the array
    int arr_pointer_initial[10] = {0};
    int count_pointer_initial = 0;
    
    // 1. Normal way
    int sz_pointer_initial = sizeof(arr_pointer_initial) / sizeof(arr_pointer_initial[0]); //to get #elements
    for(count_pointer_initial = 0; count_pointer_initial < sz_pointer_initial; count_pointer_initial++)
    {
        arr_pointer_initial[count_pointer_initial] = 1;
    }
    for(int i = 0; i < sz_pointer_initial; i++)
    {
        printf("%d ", arr_pointer_initial[i]);
    }
    printf("\n");
    
    //2. Use pointer
    int* pointer_arr_pointer_initial = arr_pointer_initial;
    printf("Value of ptr (pointer_arr_pointer_initial): %p\n", pointer_arr_pointer_initial);
    printf("Addr of arr (arr_pointer_initial): %p\n", arr_pointer_initial);
    
    for(count_pointer_initial = 0; count_pointer_initial < sz_pointer_initial; count_pointer_initial++)
    {
        *pointer_arr_pointer_initial = 8;
        pointer_arr_pointer_initial++;
        // equivalent to
        // *pointer_arr_pointer_initial++ = 3;
    }
    
    for(int i = 0; i < sz_pointer_initial; i++)
    {
        printf("%d ", arr_pointer_initial[i]);
    }
    printf("\n");
    
    printf("============================ POINTER - POINTER ============================\n");
    int pointer_pointer[10] = {0};
    printf("Result of pointer - pointer is: %d\n", &pointer_pointer[9] - &pointer_pointer[0]);
    printf("Result of pointer - pointer is: %p\n", &pointer_pointer[9] - &pointer_pointer[0]);
    // 指针减指针得到的是两个指针之间的元素的个数
    // 注意：不是所有的指针都能相减，指向同一块空间的两个指针才能相减！！！！
    
    printf("============================ POINTER AND ARRAY ============================\n");
    int arr_pointer[7] = {0, 1, 2, 3, 4, 5, 6};
    // arr_pointer is the addr of the first element, &arr_pointer[0]
    // i.e. 数组名是数组首元素的地址
    printf("arr_pointer is: %p\n", arr_pointer);
    // establish the connection between array and pointer
    int* p_arr_pointer = arr_pointer;
    int sz_arr_pointer = sizeof(arr_pointer) / sizeof(arr_pointer[0]);
    for(int i = 0; i < sz_arr_pointer; i++)
    {
        printf("&arr_pointer[%d] = %p <===> p_arr_pointer + %d = %p\n", i, &arr_pointer[i], i, p_arr_pointer + i);
    }
    // Therefore, actually arr_pointer[i] ==> *(arr_pointer + i)
}

int main(int argc, const char * argv[]) {
    ptrBasic();
    return 0;
}
