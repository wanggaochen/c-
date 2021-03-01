//
// Created by Administrator on 2021/2/2.
//

#include "file.h"
#include <unistd.h>
#include <sys/stat.h>
namespace my_file_stream{

    my_file::my_file()
    {

    }

    my_file::~my_file()
    {
        if(!fd)
        {
            fclose(fd);
        }
    }

    my_file::my_file(const char* filepath,const char* mode)
    {
        fd = fopen(filepath,mode);
        if(fd == NULL)
        {
            std::cout << " 文件打开失败";
        }
    }

    my_file::my_file(std::string filepath,const char* mode)
    {
        open_file(filepath,mode);
    }


    //打开文件
    int my_file::open_file(const char* filepath, const char* mode)
    {
        open_file(filepath,mode);
    }

    int my_file::open_file(const std::string filepath, const char* mode)
    {
        fd = fopen(filepath.c_str(),mode);
        if(fd == NULL)
        {
            std::cout << " 文件打开失败";
        }
    }

    //关闭文件
    int my_file::close()
    {
        if(!fd)
            return fclose(fd);
        return 0;
    }


    //创建文件
    int my_file::create_file(const char* path,int mode)
    {

    }

    int my_file::create_file(const std::string path,int mode)
    {

    }



    int  my_file::read_file(void * buf,size_t read_size,size_t number)
    {
        return fread(buf ,read_size,number,fd);
    }

    //写文件
    size_t my_file::write_file(void * buf,size_t read_size,size_t number)
    {
        return fwrite(buf,read_size,number,fd);
    }

    //获取文件长度
    long my_file::get_len()
    {
        if(fd == nullptr)
            return 0;
        fseek(fd,0,SEEK_END);
        return ftell(fd);
    }

    //获取文件信息
    struct stat my_file::get_file_info()
    {
        //c语言文件变成获取文件信息
    }

    struct stat my_file::get_file_info(const char* path)
    {

    }

    struct stat my_file::get_file_info(const std::string path)
    {

    }

    struct stat my_file::get_file_info(int fd)
    {

    }

    //在当前位置上移动文件指针
    int my_file::move_fd(int pos)
    {
        return fseek(fd,pos,SEEK_CUR);
    }

    //创建空洞文件 什么是空洞文件  空洞文件作用


    int my_file::cope_file()
    {

    }

    int my_file::cope_file(int thread_number)
    {

    }

    //返回值是代表什么
    int my_file::file_seek(long offset, int whence = SEEK_CUR)
    {
        return fseek(fd,offset,whence);
    }

    /*改变文件位置到文件开头*/
    void my_file::rewind_start()
    {
        rewind(fd);
    }

    /*获取文件当前位置到文件开头长度*/
    long my_file::get_current_len()
    {
        if(fd == nullptr)
            return 0;
        return ftell(fd);
    }

    bool my_file::is_efo()
    {
        return feof(fd);
    }


    //读取一个字符
    char my_file::get_char_from_file()
    {
        return fgetc(fd);
    }

    //读取一行
    void my_file::get_line_from_file(char* stream_buf, int buf_size)
    {
        fgets(stream_buf,buf_size,fd);
    }


    ifstream::ifstream()
    {

    }



    ifstream::~ifstream()
    {
        if(!file_fd)
        {
            file_fd.close();
        }
    }

    //如果 file_fd  为空则文件不存在
    ifstream::ifstream(const std::string file_name)
    {
        if(!is_file(file_name))
            std::cout << " 不是文件或者文件不存在";
        if(!is_read(file_name))
            std::cout << " 文件不可读";
        file_fd.open(file_name);
    }

    ifstream::ifstream(const char* file_name)
    {
        if(!is_file(file_name))
            std::cout << " 不是文件或者文件不存在";
        if(!is_read(file_name))
            std::cout << " 文件不可读";
        file_fd.open(file_name);
    }


    int ifstream::open_file(const std::string path,std::ios_base::openmode mode )
    {
        if(file_fd.is_open())
            return 1;
        if(!my_file_stream::is_exist(path))
            return 2;
        if(!my_file_stream::is_read(path))
            return 3;
        file_fd.open(path,mode);
        return 0;
    }

    int ifstream::open_file(const char* path,std::ios_base::openmode mode )
    {
        if(file_fd.is_open())
            return 1;
        if(!my_file_stream::is_exist(path))
            return 2;
        if(!my_file_stream::is_read(path))
            return 3;
        file_fd.open(path,mode);
        return 0;
    }

    std::string  ifstream::get_line_data()
    {
        std::string str;
        getline(file_fd,str);
        return str;
    }

    bool ifstream::is_already_open()
    {
        return file_fd.is_open();
    }

    void ifstream::close_file()
    {
        file_fd.close();
    }

    std::streambuf* ifstream::read_whole_file()
    {
        return file_fd.rdbuf();
    }

    void ifstream::printf_whole_file()
    {
        std::cout << file_fd.rdbuf() << std::endl;
    }

    long ifstream::location_ptr()
    {
        return file_fd.tellg();
    }

    long ifstream::get_file_length()
    {
        file_fd.seekg(0,file_fd.end);
        return  file_fd.tellg();
    }

    std::istream & ifstream::real_location(std::streampos pos)
    {
        return file_fd.seekg(pos);
    }


    std::istream & ifstream::real_location(long off, std::ios_base::seekdir way)
    {
        return file_fd.seekg(off,way);
    }




    ofstream::ofstream(const std::string file_name)
    {
        file_fd.open(file_name);
    }

    ofstream::ofstream(const char* file_name)
    {
        file_fd.open(file_name);
    }
    ofstream::ofstream()
    {

    }

    ofstream::~ofstream()
    {
        if(!file_fd)
        {
            file_fd.close();
        }
    }

    int ofstream::open(const char* filename, std::ios_base::openmode mode )
    {
        //文件存在  文件是否可写
        if(is_exist(filename) && !is_write(filename))
            return -1;
        file_fd.open(filename,mode);
        if(!filename)
        {
            return -1;
        }
        return 0;
    }

    int ofstream::open(const std::string filename, std::ios_base::openmode mode )
    {
        //文件存在  文件是否可写
        if(is_exist(filename) && !is_write(filename))
            return -1;
        file_fd.open(filename,mode);
        if(!file_fd)
        {
            return -1;
        }
        return 0;
    }

    bool ofstream::is_already_open()
    {
        return file_fd.is_open();
    }

    void  ofstream::close()
    {
        file_fd.close();
    }

    //返回文件指针的位置
    long ofstream::location_ptr()
    {
        return file_fd.tellp();
    }

    long ofstream::get_file_length()
    {
        file_fd.seekp(0,file_fd.end);
        return file_fd.tellp();
    }

    //设置文件下次写入位置
    std::ostream & ofstream::real_location(std::streampos pos)
    {
         return file_fd.seekp(pos);
    }

    /*
     *off 偏移量
     * way 相对位置
     *      std::ios_base::beg
     *      std::ios_base::cur
     *      std::ios_base::end
     * */
    std::ostream & ofstream::real_location(long off, std::ios_base::seekdir way)
    {
       return  file_fd.seekp(off,way);
    }



    std::ostream & ofstream::write_file_char(const char* buf, long  len)
    {
        return file_fd.write(buf,len);
    }


    std::ostream & ofstream::write_file_string(const std::string strbuf,long  len)
    {
        return file_fd.write(strbuf.c_str(),len);
    }


    void  ofstream::streambuf_file_char(const char c)
    {
        std::streambuf  * out_buf = file_fd.rdbuf();
        out_buf->sputc(c);
    }

    void ofstream::streambuf_file(const char* strbuf,long  len)
    {
        std::streambuf  * out_buf = file_fd.rdbuf();
        out_buf->sputn(strbuf, len);
    }

    bool is_dir(std::string str)
    {
        struct  stat s_buf;
        stat(str.c_str(),&s_buf);
        if(S_ISDIR(s_buf.st_mode))
            return true;
        return false;

    }

    bool is_file(std::string str)
    {

        struct  stat s_buf;
        stat(str.c_str(),&s_buf);
        if(S_ISREG(s_buf.st_mode))
            return true;
        return false;
    }


    std::string get_Current_path()
    {
        char pwd [1000];
        std::string dir("");
        if (getcwd(pwd, sizeof(pwd))) {
            dir = std::string(pwd);
        }
        dir = dir +'/';
        return dir;
    }

    bool is_exist(const std::string path)
    {
        if(access(path.c_str(),F_OK) == 0)
        {
            return true;
        }
        return false;
    }

    bool is_write(const std::string path)
    {
        if(access(path.c_str(),F_OK|W_OK) == 0)
        {
            return true;
        }
        return false;
    }

    bool is_read(const std::string path)
    {
        if(access(path.c_str(),F_OK|R_OK) == 0)
        {
            return true;
        }
        return false;
    }

    bool is_exist(const char* path)
    {
        if(access(path,F_OK|W_OK) == 0)
        {
            return true;
        }
        return false;
    }

    bool is_write(const char* path)
    {
        if(access(path,F_OK|W_OK) == 0)
        {
            return true;
        }
        return false;
    }

    bool is_read(const char* path)
    {
        if(access(path,F_OK|R_OK) == 0)
        {
            return true;
        }
        return false;
    }

    void stream_cope(std::ifstream i_fd,std::ostream o_fd)
    {
        o_fd << i_fd.rdbuf();
    }


    int remove_file_or_dir(const std::string path)
    {
            if(is_dir(path) )
            {
                if(remove(path.c_str()) == 0)
                {
                    std::cout << "目录删除成功" << std::endl;
                    return 0;
                }
                return  -1;
            }
            if( is_file(path))
            {
                if(remove(path.c_str()) == 0)
                {
                    std::cout << "文件删除成功" << std::endl;
                    return 0;
                }
                return  -1;
            }
            std::cout << "path 不是文件或者目录名" <<std::endl;
            return -1;
    }

    int remove_file_or_dir(const char* path)
    {
        if(is_dir(path) )
        {

            if(remove(path) == 0)
            {
                std::cout << "目录删除成功" << std::endl;
                return 0;
            }
            return  -1;
        }
        if( is_file(path))
        {
            if(remove(path) == 0)
            {
                std::cout << "文件删除成功" << std::endl;
                return 0;
            }
            return  -1;
        }
        std::cout << "path 不是文件或者目录名" <<std::endl;
        return -1;
    }

}