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
//sysconf 获取运行时配置信息
namespace my_file_stream{
    class my_file {
    public:
        my_file();
        my_file(const char* filepath, const char* mode);
        my_file(std::string filepath, const char* mode);

        ~my_file();

        //打开文件
        /* mode:
            r+  开放阅读和写作。流被定位在文件的开头。
            w   将文件截断为零长度或创建用于写入的文本文件。流被定位在文件的开头。
            w+  开放阅读和写作。如果文件不存在，则创建该文件，否则将截断该文件。流被定位在文件的开头。
            a   一种用于追加(在文件末尾写入)的开口。如果文件不存在，则创建该文件。流被定位在文件的末尾。
            a+  打开用于读取和追加(在文件末尾写入)。如果文件不存在，则创建该文件。用于读取的初始文件位置是在开头文件，但是输出总是追加到文件的末尾。
            b   对二进制文件操作
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
        system_file();
        /*
         int flag
            O_RDONLY  只读    如果有读(O_RDONLY,O_RDWR)操作,文件必须存在
            O_WRONLY  只写    如果有写(O_WRONLY) 如果文件不存在先创建文件
            O_RDWR    读写

            O_APPEND:移动文件内部针到文件末尾写数据(追加)
            O_CLOEXEC:子进程关闭文件描述符(在执行execl家族函数)
            O_CREAT:创建文件,一般与O_EXCL一起使用,如果文件已经存在,返回错误.
            必须传递第三个参数,指定新文件创建默认模式.模式值
                a.宏变量
                #define S_IRWXU 00700
                #define S_IRUSR 00400
                #define S_IWUSR 00200
                #define S_IXUSR 00100

                #define S_IRWXG 00070
                #define S_IRGRP 00040
                #define S_IWGRP 00020
                #define S_IXGRP 00010

                #define S_IRWXO 00007
                #define S_IROTH 00004
                #define S_IWOTH 00002
                #define S_IXOTH 00001
                b.8进制数字表示:0777 0567

            O_NONBLOCK:设置文件非堵塞操作
            O_TRUNC:一般与O_RDWR|O_WRONLY,先清空文件,再写数据.
            O_RDWR|O_WRONLY只是覆盖
            返回值:成功返回>2值(从3开始)  -1:失败

        */
        system_file(const char* filepath, int flag,mode_t mode);
        system_file(const char* filepath, int flag);
        system_file(const std::string  filepath, int flag,mode_t mode);
        system_file(const std::string filepath, int flag);

        /*返回为0 操作成功 -1打开失败*/
        int sys_file_open(const char* filepath, int flag,mode_t mode);
        int sys_file_open(const char* filepath,int flag);
        int sys_file_open(const std::string  filepath, int flag,mode_t mode);
        int sys_file_open(const std::string filepath,int flag);

        int sys_file_create(const std::string filepath,mode_t mode = 0777);

        int sys_file_create(const char* filepath,mode_t mode = 0777);

        int  get_file_info(struct  stat* file_info);

        /*  文件描述度重定向
         dup/dup2
            int dup(int oldfd);
            复制 oldfd 文件描述符,返回当前最小未使用描述符值作为新文件描述符.两个文件描述符关联同一个文件
            这两个描述符共享同一个数据结构，共享所有的锁定，读写指针和各项全现或标志位  等效于 fcntl(oldfd, F_DUPFD, 0)
            int dup2(int oldfd, int newfd);
            int newfd:指定一个新的文件描述符复制oldfd文件描述符,关闭 oldfd
            如果oldfd 无效,newfd不关闭
            如果oldfd=newfd 不复制
         */

        int sys_file_dump();


        //改变文件内部指针
        long sys_file_seek(long pos,int whence);

        //获取文件大小
        long sys_file_len();

        //文件内存映射


        //修改文件权限
        int  modify_sys_file_limit(mode_t mode);

        //修改文件所有者 用户ID 组ID
        int modify_sys_file_user(uid_t __owner, gid_t __group);

        /*
            文件锁
                LOCK_SH :共享锁
                LOCK_EX :排斥锁
                LOCK_UN :解锁
                LOCK_NB :如果资源已经被锁住,进程立即返回不堵塞

            死锁: 死锁是指两个或两个以上的进程在执行过程中，由于竞争资源或者由于彼此通信而造成的一种阻塞的现象，若无外力作用，
            它们都将无法推进下去。此时称系统处于死锁状态或系统产生了死锁，这些永远在互相等待的进程称为死锁进程
            互相等待   系统资源竞争   进程运行推进顺序不合适
            互斥  保持 不可剥夺 循环等待
            线程A
                lock(fd);
                    .....
                    lock(fd1);//已经被锁住 堵塞

            线程B
                lock(fd1);
                    .....
                    lock(fd);// 已经被锁住 堵塞


         */
        int file_lock(int operation);

        //返回值:>0:从用户空间写到内核空间的字节数     返回值-1错误
        size_t sys_file_write(const void* buf,size_t count);

        //返回值:>0:从用内核空间写到用户空间的字节数  =0:文件读到末尾  -1错误
        size_t sys_file_read(void *buf, size_t count);

        int sys_file_close();

        int getfd();

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

    int delete_file(const char* path);


    void get_file_info(const char* file_path,struct  stat* file_info);

    /*
        如果是一个符号链接文件,获取自身链接文件状态信息,不是引用原文件状态信息
    */
    int  get_file_info(const std::string file_path,struct  stat* file_info,bool link =false);

    int modify_file_limit(const char* filepath, mode_t mode);
};





#endif //UNTITLED_FILE_H
