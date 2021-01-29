//
// Created by Administrator on 2021/1/24.
//
#include "my_selfString.h"

//构造函数
myString::myString()
{
    this->str="";
}
myString::myString(char* str)
{
    this->str = std::string(str);
}
myString::myString(std::string str)
{
    this->str = str;
}
//set  get
void myString::setValue(const char* value)
{
    this->str = std::string(str);
}

void myString::setValue(std::string value)
{
    this->str = value;
}

const char* myString::getCharValue()
{
    return this->str.c_str();
}

std::string myString::getStringValue()
{
    return this->str;
}

int myString::getStringSize()
{
    return this->str.size();
}

//连接
void myString::stringAppend(std::string value)
{
    this->str = this->str + value;
}

//子串搜索 第一次出现
int myString::subSearchFirst(std::string subStr) {
    return this->str.find_first_of(subStr.c_str());
}

//子串搜索 最后一次出现
int myString::subRSearchLast(std::string subStr)
{
    return this->str.find_last_of(subStr.c_str());
}

//字符串截取
std::string myString::getSubstring(int start,int size)
{
    return this->str.substr(start,size);
}

//翻转
std::string myString::getReverse()
{
    std::string result = this->str;
    reverse(result.begin(),result.end());
    return  result;
}

void myString::reverseSelf()
{
    return reverse(this->str.begin(),this->str.end());
}

char myString::at(int pos)
{
    return  this->str.at(pos);
}


//删除左边空格
void myString::delLeftBlank()
{
    int pos = this->str.find_first_not_of(' ');
    if(pos !=  std::string::npos)
    {
        setValue(str.c_str() + pos);
    }

}

//删除右边空格
void myString::delRightBlank()
{
    int pos = this->str.find_last_of(' ');
    if(pos !=  std::string::npos)
    {
        setValue(str.substr(0,pos + 1));
    }
}


//删除左右空格
void myString::delLRBlank()
{
    delLeftBlank();
    delRightBlank();
}

//替换指定字符
void myString::replaceAllSubstr(char new_char,char old_char)
{
    replace(str.begin(),str.end(),old_char,new_char);
}

//替换指定字符串
void myString::replaceAllSubstr(std::string new_value,std::string old_value)
{
    //当新字符是旧字符的子串是死循环
    if(old_value.find(new_value) != std::string::npos || new_value == old_value)
    {
        return;
    }
    while(str.find(old_value) != std::string::npos )
    {
        str.replace(str.find(old_value),old_value.length(),new_value);
    }
}

void myString::replaceAllSubstr_(std::string new_value,std::string old_value)
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


//大小写转换
void myString::toUp()
{
    //std::transform 对str中的每个元素都做一次结尾的函数操作 结果存到第三个参数中  具体库文件
    std::transform(str.begin(),str.end(),str.begin(),::toupper);
}

void myString::toLOw()
{
    std::transform(str.begin(),str.end(),str.begin(),::tolower);
}

//大小写互换
void myString::upLow()
{

}


//符号重写  +  输出  []  at()

//指定字符出现次数
int myString::getShowNumber(std::string  substr)
{

}

//是否是空格
bool myString::isBlank(char c)
{
    return isblank(c);
}


bool myString::isDigit(char c)
{
    return isdigit(c);
}

bool myString::isAlphabet(char c)
{
    return isalpha(c);
}

bool myString::isAlphabetUpper(char c)
{
    return isupper(c);
}

bool myString::isAlphabetLower(char c)
{
    return islower(c);
}

bool myString::isAlphabetOrDigit(char c)
{
    return isalnum(c);
}


//删除指定字符
void myString::delSubstr(std::string str)
{

}


