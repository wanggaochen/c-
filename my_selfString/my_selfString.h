//
// Created by Administrator on 2021/1/24.
//

#ifndef UNTITLED_MY_SELFSTRING_H
#define UNTITLED_MY_SELFSTRING_H
#include "../head.h"
#define USING_STRING_MY using namespace string_my;
namespace string_my{
class  myString {
public:
    //构造函数
    myString();
    myString(char* str);
    myString(std::string str);

    //set  get
    void setValue(const char* value);
    void setValue(std::string value);

    const char* getCharValue();
    std::string getStringValue();
    int getStringSize();
    //连接
    void stringAppend(std::string value);

    //子串搜索 第一次出现
    int subSearchFirst(std::string subStr);
    //子串搜索 最后一次出现
    int subRSearchLast(std::string subStr);

    //字符串截取
    std::string getSubstring(int start,int end);

    //翻转
    std::string getReverse();
    void reverseSelf();

    char at(int pos);
    //删除左边空格
    void delLeftBlank();

    //删除右边空格
    void delRightBlank();
    //删除左右空格
    void delLRBlank();

    //替换指定字符
    void replaceAllSubstr(char new_char,char old_char);
    //字符串地柜替换
    void replaceAllSubstr(std::string new_value,std::string old_value);
    //原字符替换
    void replaceAllSubstr_(std::string new_value,std::string old_value);

    //大小写转换
    void toUp();

    void toLOw();

    //符号重写  +  输出  []  at()

    //指定字符出现次数
    int getShowNumber(std::string  substr);

    //是否是空格 字符  数字 空格  大写  小写
    bool isBlank(char c);

    bool isDigit(char c);

    bool isAlphabet(char c);

    bool isAlphabetUpper(char c);

    bool isAlphabetLower(char c);

    bool isAlphabetOrDigit(char c);

    //删除指定字符
    void delSubstr(std::string str);

    //string  to int
    int strToInt();

    //指定位置插入
    void stringInsert(int pos,std::string substring);

    //指定字符后面  或者前面插入
    void stringInsert(std::string preAim,std::string substr, bool pre);

    void stringInsertLine(std::string preAim,std::string substr, bool pre);

    // to string
    static std::string intToStr(int data);

    static std::string doubleToStr(int data);
private:
    std::string str;
};

class my_char{

};

}
#endif //UNTITLED_MY_SELFSTRING_H
