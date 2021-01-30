//
// Created by Administrator on 2021/1/24.
//


#include "arithmetic.h"
#define   MAX(a, b) ((a) > (b) ? (a):(b))
//位操作交换两个数  三次异或交换
#define  EXCHANGE_INT(a, b)  {a = a^b; b = b^a; a = a^b;}

void specific_type_sort(int array[],int n,sort_type type)
{
    switch(type) {
        case sort_type::SORT_BUBBLE: {
            bubble_sort(array, n);
            break;
        }

        case sort_type::SORT_EXCHANGE: {
            break;
        }

        case sort_type::SORT_SELECT: {
            break;
        }

        case sort_type::SORT_SHELL:{
            break;
        }

        case sort_type::SORT_QUICK:{
            break;
        }
        default:
            break;

    }
}


/*
 * array 数组
 * i  j 为数组下表 默认输入下表小于数组长度
 * */
void swap(int *array, int i, int j)
{
    int tmp  = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

//不利用新的空间实现数据交换 可能出现溢出情况
void swap(int a,  int  b)
{
    a = a + b;
    b = a - b;
    a =  a- b;
}

// 冒泡  第一个数与后面的数比较如果符合大小关系,继续拿大的数后面的数比较.每次将最大的数放到最后
void bubble_sort(int array[], int n_size)
{
    for(int i = 0; i < n_size; i++)
    {
        for(int j = 0; j < n_size - i; j++)
        {
            if(array[i] > array[j])
            {
                EXCHANGE_INT(array[i],array[j]);
            }
        }
    }
}

//选择  每次从数据中选择最小的值放到前面 类似冒泡时间复杂度O(n*n)
void select_sort(int array[], int n_size)
{
    for(int i = 0; i < n_size; i++)
    {
        int n_index = i;
        int n_minValue = array[i];
        for(int j = i+1; j < n_size ; j++)
        {
            if( n_minValue > array[j])
            {
                n_minValue = array[j];
                n_index = j;
            }
        }
        if(i != n_index)
        {
            EXCHANGE_INT(array[i],array[n_index]);
        }
    }
}

//交换  每次拿一个数与后面其他数比较比较完一轮就把最小的放到前面O(n*n)
void exchange_sort(int array[], int n_size)
{
    for(int i = 0; i < n_size; i++)
    {
        for(int j = i+1; j < n_size ; j++)
        {
            if( array[i] > array[j])
            {
                EXCHANGE_INT(array[i],array[j]);
            }
        }


    }
}
//插入  把后面的数在前面有序序列中插入一个合适的O(n*n)
void inset_sort(int array[], int n_size)
{
    int j;
    for(int i = 0; i < n_size;i++)
    {
        int temp = array[i];
        j =i-1;
        while(j>=0 && temp<array[j])
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
}

/*归并排序*/
/*
1.把排序序列拆开成多个子序列(每个子序列只有一个元素)
2.合并相邻的子序列并有序
*/
void mergeing(int *list1,int list1_len,int * list2,int list2_len)
{
    int *temp = new int[list1_len + list2_len];
    int i, j, k;
    i = j = k = 0;
    while(i < list1_len && j < list2_len)
    {
        if(list1[i]<list2[j])
        {
            temp[k++] = list1[i++];
        }
        else
        {
            temp[k++] = list2[j++];
        }
    }
    while(i < list1_len)
    {
        temp[k++] = list1[i++];
    }
    while(j < list2_len)
    {
        temp[k++] = list2[j++];
    }
    //写回原数组
    for(i = 0;i < list1_len + list2_len; i++)
    {
        list1[i] = temp[i];
    }
    delete[] temp;

}
void merge_sort(int *array,int n_size)
{
    if ( n_size > 1)
    {
        int *list1 = array;
        int list1_len = n_size/2;
        int *list2 = array + list1_len;
        int list2_len = n_size - list1_len;
        //分为多个子序列  知道子序列长度为1
        merge_sort(list1, list1_len);
        merge_sort(list2, list2_len);
        mergeing(list1, list1_len, list2, list2_len);
    }
}

/*希尔排序 时间复杂度为 O(N*(logN)2)*/
/*
将序列分成若干的子序列,对每个子序列进行值插入排序;然后逐渐缩小间隔，重复
以上过程直到间隔为1不需要大量的辅助空间，和归并排序一样容易实现。希尔排序
是基于插入排序的一种算法，在此算法基础之上增加了一个新的特性提高了效率。
*/
void shell_sort(int *array,int n_size)
{
    int i,j,temp;
    for(int n = n_size/2;n>0;n=n/2)
    {
        for(i = n;i < n_size;i++)
        {
            temp=array[i];
            for( j = i - n ;j >= 0 && array[j] > temp;j = j - n)
            {
                array[j+n] = array[j]; //移动插入到合适的位置
            }
            array[j+n] = temp;
        }
    }
}

/*
快排:O(nlogN)
快排:讲一个序列分成左右两边与指定目标数比较.如果比目标小放在目标数左边,如果
比目标数大,放在目标数右边.继续以目标数为分解点.分成两个子序列.递归使用前面比较
*/
int   quicking(int * array,int left,int right)
{
    int tmp=array[left];
    while(left<right)
    {
        while(left<right&& array[right]>tmp)
        {
            right--;
        }
        if(left<right)
        {
            array[left]=array[right];
            left++;
        }
        while(left<right && array[left]<tmp)
        {
            left++;
        }
        if(left<right)
        {
            array[right]=array[left];
            right--;
        }
    }
    array[left]=tmp;
    return left;
}

void   quick_sort(int * array,int left,int right)
{
    if(left<right)
    {
        int mid=quicking(array,left,right);
        quick_sort(array,left,mid-1);
        quick_sort(array,mid+1,right);
    }
}














