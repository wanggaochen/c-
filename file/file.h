//
// Created by Administrator on 2021/2/2.
//

#ifndef UNTITLED_FILE_H
#define UNTITLED_FILE_H

#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../head.h"



/*
ios_base::in	        input File	        读的方式打开文件
ios_base::out	        output	            写的方式打开文件
ios_base::binary	    binary	            二进制方式打开
ios_base::ate	        at end	            打开的时候定位到文件末尾
ios_base::app	        append	            所有操作都定位到文件末尾
ios_base::trunc	        truncate	        丢弃打开前文件存在的内容
 */



//基于C语言  文件编程 系统函数文件编程  C语言文件编程
namespace my_file_stream{
    class my_file {
    public:
        my_file();
        my_file(const char* filepath, const char* mode);
        my_file(std::string filepath, const char* mode);

        ~my_file();

        //打开文件
        /* mode:
            r:只读
            w:只写,如果文件不存在则创建,如果文件存在且有内容,先清空文件
            r+:读写
            w+:读写
            a:追加,在文件末尾写入新数据
            a+:读 追加
            b:对二进制文件操作
         */
        int open_file(const char* path, const char* mode);
        int open_file(const std::string path, const char* mode);

        //关闭文件
        int close();

        //创建文件
        int create_file(const char* path,int mode);

        int create_file(const std::string path,int mode);


        /*读取文件
         void* buf:指向数据缓存
         size_t read_size:每个元素字节数
         size_t nmebm:读写元素个数
         返回值:实际读写字节数,fread 返回值是0 表示读到文件末尾
        */
        int  read_file(void * buf,size_t read_size,size_t number);

        //写文件
        size_t write_file(void * buf,size_t read_size,size_t number);

        int write_file(std::string &buf,long len);


        //获取文件长度
        long get_len();

        //读取一个字符
        char get_char_from_file();

        //读取一行
        void  get_line_from_file(char* stream_buf, int buf_size);


        //获取文件信息
        struct stat get_file_info();

        struct stat get_file_info(const char* path);

        struct stat get_file_info(const std::string path);

        struct stat get_file_info(int fd);

        //基于当前位置移动文件指针
        int move_fd(int pos);

        //创建空洞文件 什么是空洞文件  空洞文件作用


        int cope_file();

        int cope_file(int thread_number);

        /*  改变文件读写位置
            offset 设置偏移值;
            whence 相对位置
                SEEK_SET:文件开头
                SEEK_CUR:文件指针当前位置
                SEEK_END:文件末尾
         */
        int file_seek(long offset, int whence);

        /*改变文件位置到文件开头*/
        void rewind_start();

        /*获取文件当前位置到文件开头长度*/
        long get_current_len();

        bool is_efo();

    public:
        FILE* fd;
    };


    //linux 系统文件编程  c语言文件变成调用的是系统文件编程
    class system_file {
    public:

    public:
        int fd;
    };

    //目标
    class my_dir{

    };


//了解 c++ 输入输出流的基本使用 都是管理一个刘对象
    class ifstream{  //文件到内存
    public:
        ifstream(const std::string file_name);
        ifstream(const char* file_name);

        ifstream();

        ~ifstream();
        //打开文件
        /* 1 文件流对象与文件绑定
         * 2 文件不存在
         * 3 文件不可读
         * 0 打开成功
         * */
        int open_file(const std::string path,std::ios_base::openmode mode = std::ios_base::out);

        int open_file(const char* path,std::ios_base::openmode mode = std::ios_base::out);


        //读取一行
        std::string  get_line_data();

        bool is_already_open();

        void    close_file();

        std::streambuf* read_whole_file();

        void printf_whole_file();

        //返回文件指针的位置
        long location_ptr();

        long get_file_length();

        //设置文件读取位置
        std::istream & real_location(std::streampos pos);

        /*
         *off 偏移量
         * way 相对位置
         *      std::ios_base::beg
         *      std::ios_base::cur
         *      std::ios_base::end
         * */
        std::istream & real_location(long off, std::ios_base::seekdir way);

    public:
        std::ifstream file_fd;
    };

    class ofstream{  //内存到文件  文件不存在 默认创建
    public:
        ofstream(const std::string file_name);
        ofstream(const char* file_name);
        ofstream();

        ~ofstream();


        /*
         * 0  成功
         * -1 失败
         *
         * */
        int open(const char* filename, std::ios_base::openmode mode = std::ios_base::out);

        int open(const std::string filename, std::ios_base::openmode mode = std::ios_base::out);

        bool is_already_open();

        void  close();

        //返回文件指针的位置
        long location_ptr();

        long get_file_length();

        //设置文件下次写入位置
        std::ostream & real_location(std::streampos pos);

        /*
         *off 偏移量
         * way 相对位置
         *      std::ios_base::beg
         *      std::ios_base::cur
         *      std::ios_base::end
         * */
        std::ostream & real_location(long off, std::ios_base::seekdir way);


        std::ostream & write_file_char(const char* buf,long  len);

        std::ostream & write_file_string(const std::string strbuf,long  len);

        void streambuf_file_char(const char c);

        void streambuf_file(const char* strbuf ,long  len);



    public:
        std::ofstream file_fd;
    };

    class fstream{
    public:
        fstream(std::string file_name,int flag);
        //文件操作类函数
        //输出重定向
    public:
        std::fstream file_fd;
    };




    bool is_file(std::string str);
    bool is_dir(std::string str);
    std::string get_Current_path();
    //文件是否存在 可读 可写  可执行
    bool is_exist(const std::string path);
    bool is_write(const std::string path);
    bool is_read(const std::string path);

    bool is_exist(const char* path);
    bool is_write(const char* path);
    bool is_read(const char* path);

    void stream_cope(std::ifstream i_fd,std::ostream o_fd);

    //文件重定向
    //void file_redirect(std::ifstream i_fd,std::ostream o_fd);

    /*
     * 删除文件或者目录  目录删除没有成功
     * */
    int remove_file_or_dir(const std::string path);

    int remove_file_or_dir(const char* path);

};





#endif //UNTITLED_FILE_H
