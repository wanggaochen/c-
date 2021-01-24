////
//// Created by Administrator on 2021/1/24.
////
//
//#include <stdio.h>
//#include <stdlib.h>
///*冒泡排序*/
///*
//时间复杂度:
//最好为O(n);(本身为一个有序的)
//最坏为O(n^2)(本身为一个倒序)
//时间复杂度为O(n)到O(n^2);
//稳定排序
//优点:代码简单
//可以给链表这种连续的空间排序;
//*/
//
//
//void bubble_sort(int *a,int n)
//{
//    int i,j;
//    int flag;
//    for (i=0;i<n-1; i++)
//    {
//        flag=0;
//        for(j=0;j<n-i-1;j++)
//        {
//            if(a[j]>a[j+1])
//            {
//                /*交换*/
//                int temp=a[j+1];
//                a[j+1]=a[j];
//                a[j]=temp;
//                flag=1;
//            }
//
//        }
//        if(flag==0)
//            break;
//    }
//
//}
//
///*插入排序*/
///*
//基本有序 插入简单高效
//平均逆序对(元素个数 n)为(n(n-1)/4)
//交换相邻两个元素的排序算法平均时间复杂度为 @(n^2)
//最好为O(n);(本身为一个有序的)
//时间复杂度为O(n)到O(n^2); 时间复杂度为O(n)到O(n^2);
//优点:只要错位不要多次交换
//稳定:
//*/
//void insert_sort(int* a,int n)
//{
//    int i,j;
//    int temp;
//    for(i=1;i<n;i++)
//    {
//        temp=a[i];
//        j=i;
//        while(j>0 && a[j-1]>temp)
//        {
//            a[j]=a[j-1];
//            j--;
//        }
//        a[j]=temp;
//    }
//}
///*希尔排序*/
///*
//希尔排序:将序列分成若干的子序列,对每个子序列进行值插入排序;
//然后逐渐缩小间隔，重复以上过程，直到间隔为1。不需要大量的辅助空间
//，和归并排序一样容易实现。希尔排序是基于插入排序的一种算法，
//在此算法基础之上增加了一个新的特性
//，提高了效率。希尔排序的时间复杂度为 O(N*(logN)2)
//不稳定 快选堆希
//shell_sort:
//建立在插入排序的基础上的一种时间复杂度更小的排序
//不稳定排序:
//*/
//void shell_sort(int* a,int len)
//{
//    int n,j,k;
//    int temp;
//    for(n=len/2;n>0;n/=2)
//    {
//        for(i=n;i<len;i++)
//        {
//            temp=a[i];
//            k=i;
//            while(j>=0 && a[j-n]>temp)
//            {
//                a[j]=a[j-i];
//                j=j-n;
//            }
//            a[j]=temp;
//        }
//    }
//}
///*选择排序*/
///*
//无所谓最号最坏时间复杂度;
//选择排序:每次从数据中选择最小的值放到前面
//类似冒泡时间复杂度O(n*n)
//*/
//void select_sort(int* a,int n)
//{
//    int i,j;
//    int min_value;
//    int min_index;
//    for(i=0;i<n-1;i++)
//    {
//        min_value=a[i];
//        for(j=i+1;j<n;j++)
//        {
//            if(min_value>a[j])
//            {
//                min_value=a[j];
//                min_index=j;
//            }
//        }
//        if(i!=min_index)
//        {
//            int temp;
//            temp=a[min_index];
//            a[min_index]=a[i];
//            a[i]=temp;
//        }
//
//
//    }
//}
///*堆排序*/
//
///*
//最选择排序的一种优化
//时间复杂度NlogN
//*/
//void   swap(int *p,int i,int j)
//{
//    int temp=p[i];
//    p[i]=p[j];
//    p[j]=temp;
//}
//void  init_heap(int *a ,int index,int num)
//{
//    int j;
//    int temp=a[index];
//    for(j=2*index;j<=num;j=j*2)
//    {
//        if(j<num&&a[j]<a[j+1])
//        {
//            j++;
//        }
//        if(a[j]>temp)
//        {
//            a[index]=a[j];
//            index=j;
//        }
//    }
//    a[index]=temp;
//}
//void  heap_sort(int *a,int num)
//{
//    int i;
//    for(i=num/2;i>0;i--)
//    {
//        init_heap(a,i,num);
//    }
//    for(i=num;i>1;i--)
//    {
//        swap(a,1,i);
//        init_heap(a,1,i-1);
//    }
//}
//
//
//void Swap( int *a, int *b )
//{
//    int t = *a; *a = *b; *b = t;
//}
//
//void PercDown( int*  A, int p, int N )
//{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
//    /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
//    int Parent, Child;
//    int X;
//    X = A[p]; /* 取出根结点存放的值 */
//    for( Parent=p; (Parent*2+1)<N; Parent=Child )
//    {
//        Child = Parent * 2 + 1;
//        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
//            Child++;  /* Child指向左右子结点的较大者 */
//        if( X >= A[Child] ) break; /* 找到了合适位置 */
//        else  /* 下滤X */
//            A[Parent] = A[Child];
//    }
//    A[Parent] = X;
//}
//
//void HeapSort( int* A, int N )
//{ /* 堆排序 */
//    int i;
//
//    for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
//        PercDown( A, i, N );
//
//    for ( i=N-1; i>0; i-- ) {
//        /* 删除最大堆顶 */
//        Swap( &A[0], &A[i] ); /* 见代码7.1 */
//        PercDown( A, 0, i );
//    }
//}
///*归并排序*/
///*
//最强O(NlogN);
//1.把排序序列拆开成多个子序列(每个子序列只有一个元素)
//2.合并相邻的子序列并有序
//*/
//void merge(int* list1,int len1,int* list2,int len2)
//{
//    int temp[15];//分配一个存放结果的数组
//    int i,j,k;
//    i=j=k=0;
//    while(i<len1 && j<len2 )
//    {
//        if(list1[i]<list2[j])
//        {
//            temp[k++]=list1[i++];
//        }
//        else
//        {
//            temp[k++]=list2[j++];
//        }
//    }
//    while(i<len1)
//    {
//        temp[k++]=list1[i++];
//    }
//    while(j<len2)
//    {
//        temp[k++]=list2[j++];
//    }
//    /*将排好序的数组放回原数组*/
//    for(i=0;i<len1+len2;i++)
//    {
//        list1[i]=temp[i];
//    }
//}
//void merge_sort(int* a,int n)
//{
//    if(n>1)
//    {
//        int* list1=a;
//        int len1=n/2;
//        int* list2=a+len1;
//        int len2=n-len1;
//        merge_sort(list1,len1);
//        merge_sort(list2,len2);
//        merge(list1,len1,list2,len2);
//    }
//}
///*非递归实现归并排序*/
//// void merge_pass(int* a,int* temp,int n,int length)
//// {
//// 	/*两两归并相邻有序子列*/
//// 	int i,j;
//// 	for(i=0;i<10;i++)
//// 	{
//// 		printf("%d\t",a[i]);
//// 	}
//// 	for(i=0;i<n-length;i+=2*length)
//// 	{
//// 		int len1;
//// 		// int* temp1=malloc(n*sizeof(int));
//// 		// temp=a+i;
//// 		temp=a+i+length;
//// 		// printf("FUck\n");
//// 		// printf("%d\n",*temp);
//// 		if(i+2*length<=n)
//// 		{
//// 			int len1=length;
//// 			merge(a+i,length,temp,len1);
//
//// 		}
//// 		if(i+length>n  && i+2*length>n)
//// 		{
//// 			len1=n-i-length;
//// 			merge(a+i,length,temp,len1);
//
//// 		}
//// 		if(i+length<=n)
//// 		{
//// 			for(j=i;j<n;j++)
//// 			{
//// 				a[j]=temp[j];
//// 			}
//// 		}
//// 	}
//// }
//// void merge1_sort(int* a,int n)
//// {
//// 	int length=1;/*初始化子序列长度*/
//// 	int* temp=malloc(n*sizeof(int));
//// 	if(temp!=NULL)
//// 	{
//// 		// while(length<n)
//// 		// {
//// 		 	merge_pass( a,temp, n, length );
////             length *= 2;
//// 		// }
//// 	}
//// }
//
//
//
///* 归并排序 - 递归实现 */
//
///* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
//// void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
//// { /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
////      int LeftEnd, NumElements, Tmp;
////      int i;
//
////      LeftEnd = R - 1; /* 左边终点位置 */
////      Tmp = L;         /* 有序序列的起始位置 */
////      NumElements = RightEnd - L + 1;
//
////      while( L <= LeftEnd && R <= RightEnd ) {
////          if ( A[L] <= A[R] )
////              TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
////          else
////              TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
////      }
//
////      while( L <= LeftEnd )
////          TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
////      while( R <= RightEnd )
////          TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */
//
////      for( i = 0; i < NumElements; i++, RightEnd -- )
////          A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
//// }
//
//// void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
//// { /* 核心递归排序函数 */
////      int Center;
//
////      if ( L < RightEnd ) {
////           Center = (L+RightEnd) / 2;
////           Msort( A, TmpA, L, Center );              /* 递归解决左边 */
////           Msort( A, TmpA, Center+1, RightEnd );     /* 递归解决右边 */
////           Merge( A, TmpA, L, Center+1, RightEnd );  /* 合并两段有序序列 */
////      }
//// }
//
//// void MergeSort( ElementType A[], int N )
//// { /* 归并排序 */
////      ElementType *TmpA;
////      TmpA = (ElementType *)malloc(N*sizeof(ElementType));
//
////      if ( TmpA != NULL ) {
////           Msort( A, TmpA, 0, N-1 );
////           free( TmpA );
////      }
////      else printf( "空间不足" );
//// }
//
//
//
///* 归并排序 - 循环实现 */
///* 这里Merge函数在递归版本中给出 */
//
///* length = 当前有序子列的长度*/
//// void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
//// { /* 两两归并相邻有序子列 */
////      int i, j;
//
////      for ( i=0; i <= N-2*length; i += 2*length )
////          Merge( A, TmpA, i, i+length, i+2*length-1 );
////      if ( i+length < N ) /* 归并最后2个子列*/
////          Merge( A, TmpA, i, i+length, N-1);
////      else /* 最后只剩1个子列*/
////          for ( j = i; j < N; j++ ) TmpA[j] = A[j];
//// }
//
//// void Merge_Sort( ElementType A[], int N )
//// {
////      int length;
////      ElementType *TmpA;
//
////      length = 1; /* 初始化子序列长度*/
////      TmpA = malloc( N * sizeof( ElementType ) );
////      if ( TmpA != NULL ) {
////           while( length < N ) {
////               Merge_pass( A, TmpA, N, length );
////               length *= 2;
////               Merge_pass( TmpA, A, N, length );
////               length *= 2;
////           }
////           free( TmpA );
////      }
////      else printf( "空间不足" );
//// }
//
//
///*快排*/
///*
//最好(NlogN)
//大多情况下快排效率高
///*
//快排:讲一个序列分成左右两边与指定目标数比较.如果比目标小放在目标数左边,如果
//比目标数大,放在目标数右边.继续以目标数为分解点.分成两个子序列.递归使用前面比较
//选主元
//*/
//int quick(int* a,int left,int right)
//{
//    int mid=left;
//    int temp=a[left++];
//    int data;
//    while(left<right)
//    {
//        while(left<right && a[left]<temp)
//        {
//            left++;
//        }
//        while(left<right && a[right]>temp)
//        {
//            right--;
//        }
//        if(left<right)
//        {
//            data=a[right];
//            a[right]=a[left];
//            a[left]=data;
//        }
//    }
//
//    if(right==left && a[left]<temp)
//    {
//        a[mid]=a[left];
//        a[left]=temp;
//    }
//    else
//    {
//        a[mid]=a[--left];
//        a[left]=temp;
//    }
//
//
//    return left;
//}
//void   quick_sort(int * array,int left,int right)
//{
//    if(left<right)
//    {
//        int mid=quick(array,left,right);
//        quick_sort(array,left,mid-1);
//        quick_sort(array,mid+1,right);
//    }
//}
///* 基数排序 - 次位优先 */
//
///* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
//#define MaxDigit 4
//#define Radix 10
//
///* 桶元素结点 */
//typedef struct Node *PtrToNode;
//struct Node {
//    int key;
//    PtrToNode next;
//};
//
///* 桶头结点 */
//struct HeadNode {
//    PtrToNode head, tail;
//};
//typedef struct HeadNode Bucket[Radix];
//
//int GetDigit ( int X, int D )
//{ /* 默认次位D=1, 主位D<=MaxDigit */
//    int d, i;
//
//    for (i=1; i<=D; i++) {
//        d = X % Radix;
//        X /= Radix;
//    }
//    return d;
//}
//
//void LSDRadixSort( ElementType A[], int N )
//{ /* 基数排序 - 次位优先 */
//    int D, Di, i;
//    Bucket B;
//    PtrToNode tmp, p, List = NULL;
//
//    for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
//        B[i].head = B[i].tail = NULL;
//    for (i=0; i<N; i++) { /* 将原始序列逆序存入初始链表List */
//        tmp = (PtrToNode)malloc(sizeof(struct Node));
//        tmp->key = A[i];
//        tmp->next = List;
//        List = tmp;
//    }
//    /* 下面开始排序 */
//    for (D=1; D<=MaxDigit; D++) { /* 对数据的每一位循环处理 */
//        /* 下面是分配的过程 */
//        p = List;
//        while (p) {
//            Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
//            /* 从List中摘除 */
//            tmp = p; p = p->next;
//            /* 插入B[Di]号桶尾 */
//            tmp->next = NULL;
//            if (B[Di].head == NULL)
//                B[Di].head = B[Di].tail = tmp;
//            else {
//                B[Di].tail->next = tmp;
//                B[Di].tail = tmp;
//            }
//        }
//        /* 下面是收集的过程 */
//        List = NULL;
//        for (Di=Radix-1; Di>=0; Di--) { /* 将每个桶的元素顺序收集入List */
//            if (B[Di].head) { /* 如果桶不为空 */
//                /* 整桶插入List表头 */
//                B[Di].tail->next = List;
//                List = B[Di].head;
//                B[Di].head = B[Di].tail = NULL; /* 清空桶 */
//            }
//        }
//    }
//    /* 将List倒入A[]并释放空间 */
//    for (i=0; i<N; i++) {
//        tmp = List;
//        List = List->next;
//        A[i] = tmp->key;
//        free(tmp);
//    }
//}
//
///* 基数排序 - 主位优先 */
//
///* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
//
//#define MaxDigit 4
//#define Radix 10
//
///* 桶元素结点 */
//typedef struct Node *PtrToNode;
//struct Node{
//    int key;
//    PtrToNode next;
//};
//
///* 桶头结点 */
//struct HeadNode {
//    PtrToNode head, tail;
//};
//typedef struct HeadNode Bucket[Radix];
//
//int GetDigit ( int X, int D )
//{ /* 默认次位D=1, 主位D<=MaxDigit */
//    int d, i;
//
//    for (i=1; i<=D; i++) {
//        d = X%Radix;
//        X /= Radix;
//    }
//    return d;
//}
//
//void MSD( ElementType A[], int L, int R, int D )
//{ /* 核心递归函数: 对A[L]...A[R]的第D位数进行排序 */
//    int Di, i, j;
//    Bucket B;
//    PtrToNode tmp, p, List = NULL;
//    if (D==0) return; /* 递归终止条件 */
//
//    for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
//        B[i].head = B[i].tail = NULL;
//    for (i=L; i<=R; i++) { /* 将原始序列逆序存入初始链表List */
//        tmp = (PtrToNode)malloc(sizeof(struct Node));
//        tmp->key = A[i];
//        tmp->next = List;
//        List = tmp;
//    }
//    /* 下面是分配的过程 */
//    p = List;
//    while (p) {
//        Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
//        /* 从List中摘除 */
//        tmp = p; p = p->next;
//        /* 插入B[Di]号桶 */
//        if (B[Di].head == NULL) B[Di].tail = tmp;
//        tmp->next = B[Di].head;
//        B[Di].head = tmp;
//    }
//    /* 下面是收集的过程 */
//    i = j = L; /* i, j记录当前要处理的A[]的左右端下标 */
//    for (Di=0; Di<Radix; Di++) { /* 对于每个桶 */
//        if (B[Di].head) { /* 将非空的桶整桶倒入A[], 递归排序 */
//            p = B[Di].head;
//            while (p) {
//                tmp = p;
//                p = p->next;
//                A[j++] = tmp->key;
//                free(tmp);
//            }
//            /* 递归对该桶数据排序, 位数减1 */
//            MSD(A, i, j-1, D-1);
//            i = j; /* 为下一个桶对应的A[]左端 */
//        }
//    }
//}
//
//void MSDRadixSort( ElementType A[], int N )
//{ /* 统一接口 */
//    MSD(A, 0, N-1, MaxDigit);
//}
//int main(int argc, char const *argv[])
//{
//    int a[]={8,10,15,9,2,7,5,3,22,16,95,12};
//    // hash_sort( array,10);
//    // inset_sort(array,10);
//    quick_sort(a,0,11);
//    int i;
//    for(i=0;i<12;i++)
//    {
//        printf("%d\t",a[i]);
//    }
//    printf("\n");
//    return 0;
//}
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
///*交换函数*/
//void swap(int* array,int i,int j)
//{
//    int temp=array[i];
//    array[i]=array[j];
//    array[j]=temp;
//}
///*冒泡排序 O(n*n)*/
///*每次将最大的最大的数放在后面*/
//void maopao_sort(int* array,int len)
//{
//    int i,j;
//    for(i=0;i<len;i++)
//    {
//        for(j=0;j<len-i-1;j++)
//        {
//            if(array[j]>array[j+1])
//            {
//                swap(array,j,j+1);
//            }
//        }
//    }
//}
///*选择排序 每次最小放在前面*/
//void select_sort(int *array,int len)
//{
//    int i,j;
//    int min_value;
//    int min_index;
//    int temp;
//    for(i=0;i<len-1;i++)
//    {
//        temp=array[i];
//        min_value=array[i];
//        for(j=i+1;j<len;j++)
//        {
//            if(min_value>array[j])
//            {
//                min_value=array[j];
//                min_index=j;
//            }
//        }
//        if(temp!=min_value)
//        {
//            swap(array,i,min_index);
//        }
//    }
//}
//// 交换:每次拿一个数与后面其他数比较比较完一轮就把最小的放到前面O(n*n)
//void  swap_sort(int *array,int len)
//{
//    int i,j;
//    for(i=0;i<len;i++)
//    {
//        for(j=i+1;j<len;j++)
//        {
//            if(array[i]>array[j])
//            {
//                swap(array,i,j);
//            }
//        }
//    }
//}
//
///*insert_sort 把后面的数在前面有序的序列中插入一个合适的位置*/
//void insert_sort(int *array,int len)
//{
//    int i,j,temp;
//    for(i=0;i<len;i++)
//    {
//        temp=array[i];
//        j=i-1;
//        while(j>=0 && temp<array[j])
//        {
//            array[j+1]=array[j];
//            j--;
//        }
//        array[j+1]=temp;
//    }
//}
///*归并排序*/
///*
//1.把排序序列拆开成多个子序列(每个子序列只有一个元素)
//2.合并相邻的子序列并有序
//*/
//void mergeing(int *list1,int list1_len,int * list2,int list2_len)
//{
//    int temp[15];
//    int i,j,k;
//    i=j=k=0;
//    while(i<list1_len && j<list2_len)
//    {
//        if(list1[i]<list2[j])
//        {
//            temp[k++]=list1[i++];
//        }
//        else
//        {
//            temp[k++]=list2[j++];
//        }
//    }
//    while(i<list1_len)
//    {
//        temp[k++]=list1[i++];
//    }
//    while(j<list2_len)
//    {
//        temp[k++]=list2[j++];
//    }
//    for(i=0;i<list1_len+list2_len;i++)
//    {
//        list1[i]=temp[i];
//    }
//
//}
//void merge_sort(int *array,int len)
//{
//    if (len>1)
//    {
//        int *list1=array;
//        int list1_len=len/2;
//        int *list2=array+list1_len;
//        int list2_len=len-list1_len;
//        merge_sort(list1,list1_len);
//        merge_sort(list2,list2_len);
//        mergeing(list1,list1_len,list2,list2_len);
//    }
//}
///*希尔排序 时间复杂度为 O(N*(logN)2)*/
///*
//将序列分成若干的子序列,对每个子序列进行值插入排序;然后逐渐缩小间隔，重复
//以上过程直到间隔为1不需要大量的辅助空间，和归并排序一样容易实现。希尔排序
//是基于插入排序的一种算法，在此算法基础之上增加了一个新的特性提高了效率。
//*/
//void shell_sort(int *array,int len)
//{
//    int i,j,n,temp;
//    for(n=len/2;n>0;n=n/2)
//    {
//        for(i=n;i<len;i++)
//        {
//            temp=array[i];
//            for(j=i-n ;j>=0&&array[j]>temp;j=j-n)
//            {
//                array[j+n]=array[j];
//            }
//            array[j+n]=temp;
//        }
//    }
//}
//
///*
//快排:O(nlogN)
//快排:讲一个序列分成左右两边与指定目标数比较.如果比目标小放在目标数左边,如果
//比目标数大,放在目标数右边.继续以目标数为分解点.分成两个子序列.递归使用前面比较
//*/
///*print data*/
//int quicking(int* array,int left,int right)
//{
//    int mid=left;/*选取比较元 保存选取位置*/
//    int temp=array[left++];/*从选取下一位置开始比较*/
//    int data;
//    while(left<right)
//    {
//        while(left<right && array[left]<temp)
//        {
//            left++;
//        }
//        while(left<right && array[right]>temp)
//        {
//            right--;
//        }
//        swap(array,left,right);
//    }
//    if(right==left && array[left]<temp)
//    {
//        array[mid]=array[left];
//        array[left]=temp;
//    }
//    else
//    {
//        array[mid]=array[--left];
//        array[left]=temp;
//    }
//    return left;
//}
//void   quick_sort_sort(int * array,int left,int right)
//{
//    if(left<right)
//    {
//        int mid=quicking(array,left,right);
//        quick_sort_sort(array,left,mid-1);
//        quick_sort_sort(array,mid+1,right);
//    }
//}
///*统一接口*/
//void quick_sort(int *array,int len)
//{
//    quick_sort_sort(array,0,len-1);
//}
//
///*堆排序*/
//
///*
//最选择排序的一种优化
//时间复杂度NlogN
//*/
//void  init_heap(int *a ,int index,int num)
//{
//    int j;
//    int temp=a[index];
//    for(j=2*index;j<=num;j=j*2)
//    {
//        if(j<num&&a[j]<a[j+1])
//        {
//            j++;
//        }
//        if(a[j]>temp)
//        {
//            a[index]=a[j];
//            index=j;
//        }
//    }
//    a[index]=temp;
//}
//void  heap_sort(int *a,int num)
//{
//    int i;
//    for(i=num/2;i>0;i--)
//    {
//        init_heap(a,i,num);
//    }
//    for(i=num;i>1;i--)
//    {
//        swap(a,1,i);
//        init_heap(a,1,i-1);
//    }
//}
///*
//位排序:以位当做存储单位,任何类型都可以看做微元素的集合(数组)
//.数组必定存在一个从0开始有序唯一下标序列值.
//把目标值与位图数组下标比较
//必须利用位操作实现位图元素判断.
//一整数为例位图空间为:1/32
//*/
///*初始化位图*/
//int* init_bit_map(int size)
//{
//    int *ptr=(int*)malloc(size*sizeof(int));
//    bzero(ptr,size);
//    return ptr;
//}
//
///*set bit_map value*/
//void set_bit_map(int* ptr,int value)
//{
//    int main_index=value/32;//页数
//    int remain_index=value%32;//位置
//    int temp=0x1;
//    *(ptr+main_index)=*(ptr+main_index)|(tmp<<remain_index);
//}
///*get max value*/
//int get_max_value(int* array,int len)
//{
//    int max_value=array[0];
//    int i;
//    for(i=0;i<len;i++)
//    {
//        if(max_value<array[i])
//        {
//            max_value=array[i];
//        }
//    }
//    return max_value;
//}
//
//void  get_bit_value(int *ptr,int max_value)
//{
//
//    int i;
//    int j;
//    int tmp=0x1;
//    for(i=0;i<size;i++)
//    {
//        tmp=0x1;
//        for(j=0;j<32;j++)
//        {
//            tmp=tmp<<j;
//            if((*(ptr+i))&tmp)
//            {
//                printf("%d\t",i*32+j);
//            }
//        }
//    }
///*bit_sort*/
//    void bit_sort(int* array,int len)
//    {
//        int max_value=get_max_value(array,len);
//        int size=max_value%32?max_value/32+1:max_value/32;//judge number of int
//        int* ptr=init_bit_map(size);
//        if(ptr!=NULL)
//        {
//            int i;
//            for(i=0;i<len;i++)
//            {
//                set_bit_map(ptr,array[i]);
//            }
//            get_bit_value(ptr,max_value);
//        }
//    }
//
//
//
//
//
//
//
//    void print_sort(int *array,int len)
//    {
//        int i;
//        for(i=0;i<len;i++)
//        {
//            printf("%d\n",array[i]);
//        }
//    }
//
//    int main(int argc, char const *argv[])
//    {
//        int array[10]={5,8,3,99,82,17,49,140,61,58};
//        quick_sort(array,10);
//        print_sort(array,10);
//        return 0;
//    }
