//
// Created by Administrator on 2021/1/24.
// chen  基本算法 库
//总结一些常用算法 从最基本的算法开始 --->使用过 ----->扩展
//



#ifndef UNTITLED_ARITHMETIC_H
#define UNTITLED_ARITHMETIC_H
#include "../head.h"

#include <openssl/md5.h>
#define   MAX(a, b) ((a) > (b) ? (a):(b))
//位操作交换两个数  三次异或交换
#define  EXCHANGE_INT(a, b)  {a = a^b; b = b^a; a = a^b;}

enum class sort_type{
    SORT_BUBBLE,
    SORT_SELECT,
    SORT_EXCHANGE,
    SORT_INSERT,
    SORT_QUICK,
    SORT_SHELL,
};

void specific_type_sort(int array[],int n,sort_type type);



// 冒泡  第一个数与后面的数比较如果符合大小关系,继续拿大的数后面的数比较.每次将最大的数放到最后
void bubble_sort(int array[], int n);

//选择  每次从数据中选择最小的值放到前面 类似冒泡时间复杂度O(n*n)
void select_sort(int array[], int n);

//交换  每次拿一个数与后面其他数比较比较完一轮就把最小的放到前面O(n*n)
void exchange_sort(int array[], int n);

//插入  把后面的数在前面有序序列中插入一个合适的O(n*n)
void inset_sort(int array[], int n);

// 归并
/*
1.把排序序列拆开成多个子序列(每个子序列只有一个元素)
2.合并相邻的子序列并有序
*/
void merge_sort(int *array,int n_size);


//快排:O(nlogN)
/*
快排:讲一个序列分成左右两边与指定目标数比较.如果比目标小放在目标数左边,如果
        比目标数大,放在目标数右边.继续以目标数为分解点.分成两个子序列.递归使用前面比较
*/
void   quick_sort(int * array,int left,int right);


//希尔排序 时间复杂度为 O(N*(logN)2)*/
/*
将序列分成若干的子序列,对每个子序列进行值插入排序;然后逐渐缩小间隔，重复
以上过程直到间隔为1不需要大量的辅助空间，和归并排序一样容易实现。希尔排序
是基于插入排序的一种算法，在此算法基础之上增加了一个新的特性提高了效率。
*/
void shell_sort(int *array,int n_size);

//桶排序

//堆排序

//大小堆

//hash




//二分查找
int  binary_search(int key,int a[],int n,int &mid);

int binary_recursion_search(int left, int right, int a[],int k);

//随机数产生  指定类型   指定范围  模板函数不能在cpp 文件中定义 不然使用的时候需要手动包含cpp 文件(只包含头文件会找不到定义)  最好解决办法在 .h头文件中定义模板函数
/*
 * start 随机数的指定开始位置
 * end 随机数指定结束为位置
 * */
template<typename T>  T rand_number(T start, T end)
{
    return  (T)(rand()%(int )(end - start + 1) + start);
}
#endif //UNTITLED_ARITHMETIC_H
