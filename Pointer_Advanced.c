#include <stdio.h>

void disp2d(int (*arr_ptr_2d)[5], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", *(*(arr_ptr_2d + i)+j)); //第i行的第j个元素
            // printf("%d ", (*(arr_ptr_2d + i))[j]); // this works as well
        }
        printf("\n");
    }
}

void ptrAdvanced(void)
{
    printf("============================ CHAR POINTER ============================\n");
    // Compare the output below:
    const char* ptr_char_1 = "abcdef";
    const char* ptr_char_2 = "abcdef";
    
    char arr_char_1[] = "abcdef";
    char arr_char_2[] = "abcdef";
    
    // ptr_char_1 and ptr_char_2 points to the same const char --> equal
    // 首字符地址赋给了指针
    if(ptr_char_1 == ptr_char_2)
        printf("ptr_char_1 == ptr_char_2, addr is 1: %p, 2: %p\n", ptr_char_1, ptr_char_2);
    else
        printf("ptr_char_1 != ptr_char_2, addr is 1: %p, 2: %p\n", ptr_char_1, ptr_char_2);
    
    // Create two different arrays, have their own space --> not equal
    if(arr_char_1 == arr_char_2)
        printf("arr_char_1 == arr_char_2, addr is 1: %p, 2: %p\n", arr_char_1, arr_char_2);
    else
        printf("arr_char_1 != arr_char_2, addr is 1: %p, 2: %p\n", arr_char_1, arr_char_2);
    
    printf("============================ POINTER ARRAY ============================\n");
    // is an array to store pointer
    // AN ARRAY !!!!!
    int int_arr1[5] = {1, 2, 3, 4, 5};
    int int_arr2[5] = {2, 3, 4, 5, 6};
    int int_arr3[5] = {3, 4, 5, 6, 7};
    
    // saves the addr of the 1st element of each array
    int* ptr_int_arr[3] = {int_arr1, int_arr2, int_arr3};   // actually a 2D array
    // or more clear way:
    // int* (ptr_int_arr[3]) = {int_arr1, int_arr2, int_arr3};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            // for the i-th row, get value in j-th addr
            printf("%d ", *(ptr_int_arr[i] + j));
            // the same as:
            // printf("%d ", ptr_int_arr[i][j]);
        }
        printf("\n");
    }
    
    printf("============================ POINTER ARRAY AND ARRAY POINTER ============================\n");
    // 在开始之前，讨论一下数组名
    // use the array in previous section
    // here the name of arr is the addr of the 1st element
    printf("Addr of the int_arr1 (int_arr1): %p\n", int_arr1);
    printf("Addr of the int_arr1[0] (&int_arr1[0]): %p\n", &int_arr1[0]);
    // They have the same addr
    // ATTENTION: 数组名通常表示的都是数组首元素的地址
    
    // 但是有两个例外：
    // 1. sizeof(数组名)：
    // For sizeof function --> int_arr1 is no longer only the addr of the first element
    int sz_int_arr1 = sizeof(int_arr1);
    // 5 elements * 4 bytes/element (since int type) = 20
    printf("Size of int_arr1 (sizeof(int_arr1)) is: %d\n", sz_int_arr1);
    
    // 2. &数组名：
    // 这里的数组名表示的依然是整个数组，所以(&数组名)取出的是整个数组的地址
    printf("Addr of int_arr1 (int_arr1): %p\n", int_arr1);
    printf("Addr of int_arr1+1 (int_arr1 + 1): %p\n", int_arr1 + 1);    // +4 since int
    
    printf("Addr of int_arr1[0] (&int_arr1[0]): %p\n", &int_arr1[0]);
    printf("Addr of int_arr1[0]+1 (&int_arr1[0] + 1): %p\n", &int_arr1[0] + 1); // +4 since int
    
    printf("Addr of &int_arr1 (&int_arr1): %p\n", &int_arr1);
    printf("Addr of &int_arr1+1 (&int_arr1 + 1): %p\n", &int_arr1 + 1); // +20 since skip the array
    
    // Okay, now go back to array pointer
    // 也就是说：整形指针是用来存放整型的地址
    //         字符指针是用来存放字符的地址
    //         数组指针？==> 用来存放数组的地址 ==> &int_arr1
    int (*ptr2_int_arr1)[5] = &int_arr1;    // array ptr
    // a ptr
    // points to arries
    // each array has 5 elements
    // these elements are int type
    // 这个*不是解引用！！！是一个数组，数组由指针构成
    // let's use arr ptr to print the arr
    for(int i = 0; i < (sizeof(int_arr1) / sizeof(int_arr1[0])); i++)
    {
        // ptr2_int_arr1是指向数组的
        // *ptr2_int_arr1其实就相当于整个数组（更准确地说 数组名）
        // 数组名又是首元素的地址
        // 所以，*ptr2_int_arr1本质上是数组首元素的地址
        printf("%d ", *(*ptr2_int_arr1 + i));
    }   // 很不推荐，太绕了
    printf("\n");
    // 还是推荐用这个：
    int* ptr3_int_arr1 = int_arr1;
    for(int i = 0; i < (sizeof(int_arr1) / sizeof(int_arr1[0])); i++)
    {
        printf("%d ", *(ptr3_int_arr1 + i));
    }
    printf("\n");
    
    // arr ptr多用在2维数组
    int arr_ptr_2d[3][5] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7};
    // print this 2d arr
    disp2d(arr_ptr_2d, 3, 5);  // the first para is an addr
                               // 传的是一行的地址
                               // 第一行的地址，一个一维数组的地址
                               // 类似于&int_arr1，所以+1就直接到了第二行
}

int main(int argc, const char * argv[]) {
    ptrAdvanced();
    return 0;
}
