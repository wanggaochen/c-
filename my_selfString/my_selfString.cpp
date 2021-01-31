//
// Created by Administrator on 2021/1/24.
//
#include "my_selfString.h"
// 错用函数  find_first_of 返回查找字符中任一字符作为返回值  不是查找全部字符

//构造函数
namespace string_my{
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

    //替换指定字符串 循环替换
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


    //偏移替换替换一次直到替换完所有字符
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


    //查找指定字符出现次数
    int myString::getShowNumber(std::string  substr)
    {
        int num = 0;
        int pos = 0;
        std::string str_tmp = str;
        while(pos != std::string::npos && pos < str_tmp.length())
        {
            pos = str_tmp.find(substr,pos);
            if(pos != std::string::npos)
            {
                pos += substr.length();
                num++;
            }
        }
        return num;
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


    //删除指定字符串
    // dnakgnalggdd;    删除gd    情况1 dnakgnalgd  情况2 dnakgnal
    void myString::delSubstr(std::string substr)
    {
        while(str.find(substr) != std::string::npos)
        {
            str.replace(str.find(substr),substr.length(),"");
        }
    }

    //指定位置插入
    void myString::stringInsert(int pos,std::string substring)
    {
        if(pos>str.length())
        {
            std::cout << "越界";
        }
        str.insert(pos,substring);
    }

    //指定字符后面  或者前面插入
    void myString::stringInsert(std::string preAim,std::string substr, bool pre)
    {
        if(substr.find(preAim) != std::string::npos || substr == preAim)
        {
            //一直循环插入;
            return;
        }
        while(str.find(preAim) != std::string::npos)
        {
            //前面
            if(pre)
            {
                str.insert(str.find(preAim),substr);
            }//后面
            else{
                str.insert(str.find(preAim) + preAim.length(),substr);
            }
        }

    }

    //指定字符后面  或者前面插入
    void myString::stringInsertLine(std::string preAim,std::string substr, bool pre)
    {
        int pos = 0;
        while(1)
        {
            //前面
            pos = str.find(preAim,pos);
            if(pos == std::string::npos)
                break;
            if(pre)
            {
                str.insert(str.find(preAim),substr);
            }//后面
            else{
                str.insert(str.find(preAim) + preAim.length(),substr);
            }
            pos += preAim.length() + substr.length();
        }

    }



    std::string myString::intToStr(int data)
    {
        char tmp[MAX_SIZE];
        sprintf(tmp,"%d",data);
        return  std::string(tmp);
    }

    std::string myString::doubleToStr(int data)
    {
        char tmp[MAX_SIZE];
        sprintf(tmp,"%lf",data);
        return  std::string(tmp);
    }
}

