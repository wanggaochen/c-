#include <iostream>
#include "head.h"
#include "arithmetic/arithmetic.h"
#include <functional>
#include <typeinfo>
#include <future>
#include <chrono>
#include <fstream>
#include "file/file.h"
#include <unistd.h>
#include "structClass/datatype.h"


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace  std;

void delLeftBlank(std::string str)
{
    int pos = str.find_first_not_of(' ');
    if(pos !=  std::string::npos)
    {
        //setValue()
    }

}


void Swap(int *heap, int len)
{
    int temp;

    temp = heap[0];
    heap[0] = heap[len-1];
    heap[len-1] = temp;
}

/* Function: 构建大顶堆 */
void BuildMaxHeap(int *heap, int len)
{
    int i;
    int temp;

    for (i = len/2-1; i >= 0; i--)
    {
        if ((2*i+1) < len && heap[i] < heap[2*i+1])    /* 根节点小于左子树 */
        {
            temp = heap[i];
            heap[i] = heap[2*i+1];
            heap[2*i+1] = temp;
            /* 检查交换后的左子树是否满足大顶堆性质 如果不满足 则重新调整子树结构 */
            if ((2*(2*i+1)+1 < len && heap[2*i+1] < heap[2*(2*i+1)+1]) || (2*(2*i+1)+2 < len && heap[2*i+1] < heap[2*(2*i+1)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
        if ((2*i+2) < len && heap[i] < heap[2*i+2])    /* 根节点小于右子树 */
        {
            temp = heap[i];
            heap[i] = heap[2*i+2];
            heap[2*i+2] = temp;
            /* 检查交换后的右子树是否满足大顶堆性质 如果不满足 则重新调整子树结构 */
            if ((2*(2*i+2)+1 < len && heap[2*i+2] < heap[2*(2*i+2)+1]) || (2*(2*i+2)+2 < len && heap[2*i+2] < heap[2*(2*i+2)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
    }
}

void replaceAllSubstr(std::string &str ,std::string new_value,std::string old_value)
{
    //当新字符是旧字符的子串是死循环
    if(new_value == old_value)
    {
        return;
    }
    while(str.find(old_value) != std::string::npos )
    {
        str.replace(str.find(old_value),old_value.length(),new_value);
    }
}

void replaceAllSubstr_(std::string &str,std::string new_value,std::string old_value)
{
    if(new_value == old_value)
    {
        return;
    }
    for(std::string::size_type   pos(0);   pos != std::string::npos;   pos += new_value.length())
    {
        if((pos=str.find(old_value,pos)) != std::string::npos)
        {
            str.replace(pos,old_value.length(),new_value);
        }
        else  { break; }
    }
}


void Thread_Fun1(std::promise<int> &p)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //std::thread

}


void f1(int n)
{
    std::cout <<n <<std::endl;
    return;
}
void f2(int n)
{
    for(auto i = 0;i < 5;i++)
    {
        std::cout <<n <<std::endl;
    }
    return;
}

//bind 函数适配器：  std::ref  std::cref
int add(int a , int b,int c)
{
    return  a+b+c;
}

int add1(int& a ,int& b,const int& c)
{
    std::cout << a  << b << c <<std::endl;
    a++;
    b++;
    return 0;
}

int  f(int& n1, int& n2, const int& n3)
{
    std::cout << "In function: n1[" << n1 << "]    n2[" << n2 << "]    n3[" << n3 << "]" << std::endl;
    ++n1; // 增加存储于函数对象的 n1 副本
    ++n2; // 增加 main() 的 n2
    //++n3; // 编译错误
    std::cout << "In function end: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
    return 0;
}
void close_file(std::fstream & fd)
{
    fd.close();
}

int main() {
    /*
	/随机生成 一系列的数字  进行测试
	int array[20] = {} ;
	srand( (unsigned)time(NULL) );
	for(int i = 0; i < 20;i++)
	{
	//srand((unsigned)time(NULL));   //根据不同时间生成不同的种子  时间单位为秒 所以不正确
	//array[i]  = rand()% 100 + 1; //这是傻逼bug  不能赋值给数组单元
	int tmp   = rand()% 100 + 1;
	array[i] = tmp;
	std::cout<<tmp<< "\n";
	}
	//sort


	for(int j = 0;j < 10; j++)
	{
	int test = rand_number(100,300);
	std::cout<<test<< "\n";
	}
	
	
    std::string str = "   wodiuniaomu  ";
    std::cout<< str.size() << std::endl;
    int n = str.find_first_not_of(' ');
    if(n != std::string::npos)
    {

        std::string strtmp(str.c_str() + n);
        std::cout<< strtmp.c_str() <<std::endl;
        std::cout<< str.size();
    }
    int n = str.find_last_not_of(' ');

    std::string tmp = str.substr(0,n+1);
    std::cout << tmp << "\n" << str <<std::endl;


    std::string str = "  ch na ma df dfn ka df na adf adf adf afch afdchn dfach  ";
    std::string sub = "ch";
    replace(str.begin(),str.end(),'c','?');
    std::cout <<str <<std::endl;


    std::string str = "  chhna ma df dfn ka df na adf adf adf afchh afdchhn dfach  ";
    std::string str1 = str;
    replaceAllSubstr(str,"c","ch");
    replaceAllSubstr_(str1,"c","ch");
    std::cout<<  str <<std::endl;
    std::cout<<  str1 <<std::endl;

    std::string str = "  chhna ma df dfn ka df na adf adf adf afchh afdchhn dfach  ";
    std::transform(str.begin(),str.end(),str.begin(),::toupper);
    std::cout<< str <<std::endl;

    std::string str1 = "  chhna ma df SDFSDSDFSDGS ka df na adf SDFSDG adf SDGS afdchhn dfach  ";
    std::transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    std::cout<< str <<std::endl;
    */
   /* std::string str = "ch";
    int num = 0;
    int pos = 0;
    std::string str_tmp = str;
    std::string substr = "ch";
    while(pos != std::string::npos && pos < str_tmp.length())
    {
        pos = str_tmp.find(substr,pos);
        if(pos != std::string::npos)
        {
            pos += substr.length();
            num++;
        }
    }
    std::cout<<num <<std::endl;

    replace(str.begin(),str.end(),'h','c');
    std::cout << str <<std::endl;*/
    /*std::string str = "   c   hfadn   sfsav   kanb  h  galch  aae  ach  aerq'ewor acch  h";
    while(str.find(" ") != std::string::npos)
    {
        str.replace(str.find(" "),1,"");
    }
    //std::cout <<str <<std::endl;
    std::string strtmp = "adfadafafdas";
    int pos = strtmp.find("das",50);
    std::cout <<pos <<std::endl;*/
   /* std::string strResult;
    sprintf((char*)strResult.data(),"%d",1561515);
    std::cout<< "afkadnfa" << strResult <<std::endl;*/
    /*function<int(int,int,int)> func1 = std::bind(add, placeholders::_1, placeholders::_2, placeholders::_3);
    //std::cout <<func1(1,2,3);
    int a ,b,c;
    a = 1; b = 2 ; c = 3;
    std::function<int()> func2 = std::bind(add1, a, std::ref(b), std::cref(c));
    a = b = c = 10;
    std::cout << a  << b << c <<std::endl;
    func2();
    std::cout << a  << b << c <<std::endl;

    int n1 = 1, n2 = 1, n3 = 1;
    std::function<int()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    bound_f();
    std::cout << "After function: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;*/

    //
/*    auto i = 5;
    cout << typeid(i).name()<<endl;
    auto arr = new auto(10);
    cout <<typeid(arr).name()<<endl;*/


    /*int array[10] = {15,38,-66,488,484,65,-100,0,14,16};

    HeapSort(array,10);

    for(int i = 0 ;i < 10;i++)
    {
        std::cout << array[i] << endl;
    }*/
/*
    int a[7] = {7, 3, 8, 5, 1, 2,-100};
    int len = 7;     //数组长度
    int i;

    for (i = len; i > 0; i--)
    {
        BuildMaxHeap(a, i);
        Swap(a, i);
    }
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }*/

    /* int a = -100;
     int b  = -100;

    a = a^b;
    b = b^a;
    a = a^b;
    EXCHANGE_INT(a,b);

    cout<< '\n' << a  <<'\n' << b << endl;
     */


/*
    std::string strpath = my_file_stream::get_Current_path();
    std::cout << strpath << std::endl;

    //文件流 ifstream

    std::ifstream  file_name("./test.txt");

    std::cout <<file_name.tellg() <<endl;

    file_name.seekg(0,file_name.end);

    std::cout <<file_name.tellg() <<endl;


    std::ifstream  file_name1("./test1.txt");
    if(!my_file_stream::is_exist("test.txt")) //文件是否存在
        return -1;

    if(!my_file_stream::is_read("test.txt"))
        return -1;



    std::streambuf * stream_buf = file_name.rdbuf();*/

    //std::cout << file_name.rdbuf() <<endl;


    /*char c = std::cin.get();
    std::cin.putback (c);
    std::cout << c <<endl;

    std::cin.get(c);
    std::cout << c <<endl;*/



    /*char buf[256];
    file_name.getline(buf,256);
    std::cout << buf <<endl;
    std::string str;
    while(getline(file_name,str))
    {
        //std::cout << str <<endl;
    }*/




    /*std::ofstream o_fd("o_test.txt");
    std::streambuf * buf = o_fd.rdbuf();
    buf->sputn("dsfadfadfadfadfadga",20);
    o_fd.close();*/
    //o_fd.write("sdasfadgdgdg",100);

    /*
     * std::ifstream i_fd("test.txt");
    std::streambuf * buf1 = i_fd.rdbuf();
    std::cout <<buf1 <<std::endl;


    std::ofstream o_fd("test1.txt");
    std::streambuf * buf = o_fd.rdbuf();
    std::cout <<buf <<std::endl;
     */


    //my_file_stream::remove_file_or_dir("./test");


    //int ffd = open("pathname", 1,  1);

    init_forward_list();

    return 0;

}
