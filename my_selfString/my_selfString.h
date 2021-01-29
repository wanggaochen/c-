//
// Created by Administrator on 2021/1/24.
//

#ifndef UNTITLED_MY_SELFSTRING_H
#define UNTITLED_MY_SELFSTRING_H
#include "../head.h"
class  myString {
public:
    //构造函数
    myString();
    myString(char* str);
    myString(std::string str);
    void upLow();

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

    //string  to double/float
    double  strToDouble();

    static std::string intToStr();

    static std::string doubleToStr();
private:
    std::string str;
};
#endif //UNTITLED_MY_SELFSTRING_H
