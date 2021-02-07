#include <iostream>
#include "head.h"
#include <functional>

#include <future>
#include <chrono>
using namespace  std;

void delLeftBlank(std::string str)
{
    int pos = str.find_first_not_of(' ');
    if(pos !=  std::string::npos)
    {
        //setValue()
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
    return 0;

}
