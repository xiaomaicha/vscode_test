//
// Created by wuqi on 19-6-4.
//

//#include <dirent.h>//遍历系统指定目录下文件要包含的头文件
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    DIR* dir = opendir("/home/wuqi/momenta/dms_model/cornercase_pic/all_data_clip/eyeocc/20190410");//打开指定目录
//    dirent* p = NULL;//定义遍历指针
//    while((p = readdir(dir)) != NULL)//开始逐个遍历
//    {
//        //这里需要注意，linux平台下一个目录中有"."和".."隐藏文件，需要过滤掉
//        if(p->d_name[0] != '.')//d_name是一个char数组，存放当前遍历到的文件名
//        {
//            string name = string(p->d_name);
//            cout<<name<<endl;
//        }
//    }
//    closedir(dir);//关闭指定目录
//}


//
//#include <iostream>
//#include <stdio.h>
//#include <unistd.h>
//#include <dirent.h>
//#include <stdlib.h>
//#include <sys/stat.h>
//#include <string.h>
//using namespace std;
//
///***** Global Variables *****/
//char dir[100] = "/home/wuqi";
//int const MAX_STR_LEN = 200;
//
///* Show all files under dir_name , do not show directories ! */
//void showAllFiles( const char * dir_name )
//{
//    // check the parameter !
//    if( NULL == dir_name )
//    {
//        cout<<" dir_name is null ! "<<endl;
//        return;
//    }
//
//    // check if dir_name is a valid dir
//    struct stat s;
//    lstat( dir_name , &s );
//    if( ! S_ISDIR( s.st_mode ) )
//    {
//        cout<<"dir_name is not a valid directory !"<<endl;
//        return;
//    }
//
//    struct dirent * filename;    // return value for readdir()
//    DIR * dir;                   // return value for opendir()
//    dir = opendir( dir_name );
//    if( NULL == dir )
//    {
//        cout<<"Can not open dir "<<dir_name<<endl;
//        return;
//    }
//    cout<<"Successfully opened the dir !"<<endl;
//
//    /* read all the files in the dir ~ */
//    while( ( filename = readdir(dir) ) != NULL )
//    {
//        // get rid of "." and ".."
//        if( strcmp( filename->d_name , "." ) == 0 ||
//            strcmp( filename->d_name , "..") == 0    )
//            continue;
//        cout<<filename ->d_name <<endl;
//    }
//}
//
//int main()
//{
//    // 测试
//    showAllFiles( dir );
//
//    return 0;
//}

//
//#include <io.h>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
////其实两个字符串连在一起比如string可惜写成：str1+str2+“xxx”。。。
////获取所有的文件名
//void GetAllFiles( string path, vector<string>& files)
//{
//
//    long   hFile   =   0;
//    //文件信息
//    struct _finddata_t fileinfo;//用来存储文件信息的结构体
//    string p;
//    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  //第一次查找
//    {
//        do
//        {
//            if((fileinfo.attrib &  _A_SUBDIR))  //如果查找到的是文件夹
//            {
//                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  //进入文件夹查找
//                {
//                    files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
//                    GetAllFiles( p.assign(path).append("\\").append(fileinfo.name), files );
//                }
//            }
//            else //如果查找到的不是是文件夹
//            {
//                files.push_back(p.assign(fileinfo.name) );  //将文件路径保存，也可以只保存文件名:    p.assign(path).append("\\").append(fileinfo.name)
//            }
//
//        }while(_findnext(hFile, &fileinfo)  == 0);
//
//        _findclose(hFile); //结束查找
//    }
//
//}
//
////获取特定格式的文件名
//void GetAllFormatFiles( string path, vector<string>& files,string format)
//{
//    //文件句柄
//    long   hFile   =   0;
//    //文件信息
//    struct _finddata_t fileinfo;
//    string p;
//    if((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(),&fileinfo)) !=  -1)
//    {
//        do
//        {
//            if((fileinfo.attrib &  _A_SUBDIR))
//            {
//                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
//                {
//                    //files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
//                    GetAllFormatFiles( p.assign(path).append("\\").append(fileinfo.name), files,format);
//                }
//            }
//            else
//            {
//                files.push_back( p.assign(fileinfo.name));  //将文件路径保存，也可以只保存文件名:    p.assign(path).append("\\").append(fileinfo.name)
//            }
//        }while(_findnext(hFile, &fileinfo)  == 0);
//
//        _findclose(hFile);
//    }
//}
//
//// 该函数有两个参数，第一个为路径字符串(string类型，最好为绝对路径)；
//// 第二个参数为文件夹与文件名称存储变量(vector类型,引用传递)。
//// 在主函数中调用格式(并将结果保存在文件"AllFiles.txt"中，第一行为总数)：
//
//int main()
//{
//    string filePath = "D:\\文档\\课程\\数据结构\\MOOC练习\\testPCL\\x64\\Debug";
//    vector<string> files;
//    char * distAll = "AllFiles.txt";
//
//    //读取所有的文件，包括子文件的文件
//    //GetAllFiles(filePath, files);
//
//    //读取所有格式为jpg的文件
//    string format = ".dll";
//    GetAllFormatFiles(filePath, files,format);
//    ofstream ofn(distAll);
//    int size = files.size();
//    ofn<<size<<endl;
//    for (int i = 0;i<size;i++)
//    {
//        ofn<<files[i]<<endl; // 写入文件
//        cout<< files[i] << endl;//输出到屏幕
//    }
//    ofn.close();
//    return 0;
//}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int readFileList(char *basePath) {
    DIR *dir;
    struct dirent *ptr;
    char base[1000];

    if ((dir = opendir(basePath)) == NULL) {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
            continue;
        else if (ptr->d_type == 8)    ///file
            printf("d_name:%s/%s\n", basePath, ptr->d_name);
        else if (ptr->d_type == 10)    ///link file
            printf("d_name:%s/%s\n", basePath, ptr->d_name);
        else if (ptr->d_type == 4)    ///dir
        {
            memset(base, '\0', sizeof(base));
            strcpy(base, basePath);
            strcat(base, "/");
            strcat(base, ptr->d_name);
            readFileList(base);
        }
    }
    closedir(dir);
    return 1;
}

int main(void) {
    char basePath[1000] = "/home/wuqi/momenta/dms_model/cornercase_pic/all_data_clip/eyeocc/20190410";

    ///get the current absoulte path
    memset(basePath, '\0', sizeof(basePath));
    getcwd(basePath, 999);
    printf("the current dir is : %s\n", basePath);

    readFileList(basePath);
    return 0;
}