//
// Created by wuqi on 19-6-13.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

#define dmax(a, b)  (((a) > (b)) ? (a) : (b))
#define dmin(a, b)  (((a) < (b)) ? (a) : (b))

//获取特定格式的文件名
int readFileList(std::vector<string> &filelist, const char *basePath, string format) {
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
        else if (ptr->d_type == 8)    //file
        {
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            string temp = ptr->d_name;
            //cout  << temp << endl;
            string sub = temp.substr(temp.length() - 4, temp.length() - 1);
            //cout  << sub << endl;
            if (sub == format) {
                string path = basePath;
                path += "/";
                path += ptr->d_name;
                filelist.push_back(path);
            }
        } else if (ptr->d_type == 10)    ///link file
        {
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
        } else if (ptr->d_type == 4)    ///dir
        {
            memset(base, '\0', sizeof(base));
            strcpy(base, basePath);
            strcat(base, "/");
            strcat(base, ptr->d_name);
            readFileList(filelist, base, format);
        }
    }
    closedir(dir);
    return 1;
}

//找出目录中所有子目录
int findAllSubDir(std::vector<string> &filelist, const char *basePath) {
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
        else if (ptr->d_type == 8)    //file
        {
            // //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            // string temp = ptr->d_name;
            // //cout  << temp << endl;
            // string sub = temp.substr(temp.length() - 4, temp.length()-1);
            // //cout  << sub << endl;
            // if(sub == format)
            // {
            //     string path = basePath;
            //     path += "/";
            //     path += ptr->d_name;
            //     filelist.push_back(path);
            // }
        } else if (ptr->d_type == 10)    ///link file
        {
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
        } else if (ptr->d_type == 4)    ///dir
        {
            memset(base, '\0', sizeof(base));
            strcpy(base, basePath);
            strcat(base, "/");
            strcat(base, ptr->d_name);
            filelist.push_back(ptr->d_name);
            findAllSubDir(filelist, base);
        }
    }
    closedir(dir);
    return 1;
}


void findDir(string src, string &facefolder, string &facenameindex, string filePath) {
    int begin = src.find(filePath) + filePath.size() + 1;
    int end = 0;
    for (int i = src.size() - 1; i >= 0; --i) {
        //cout << src[i] << endl;
        if (src[i] == '/') {
            end = i;
            break;
        }
    }
    //cout << begin << endl;
    //cout << end << endl;
    facefolder = src.substr(begin, end - 1 - begin + 1);
    facenameindex = src.substr(end + 1, src.size() - 1 - (end + 1) + 1);
}


void GetStringFileName(const string &filePath, string &filename, string &fileformat) {
    int fileformat_begin = 0;
    int fileformat_end = filePath.length() - 1;
    int filename_begin = 0;
    int filename_end = filePath.length() - 1;
    for (int i = filePath.length() - 1; i >= 0; --i) {
        //cout << filePath[i] << endl;
        if (filePath[i] == '.') {
            fileformat_begin = i + 1;
            filename_end = i - 1;
        }

        if (filePath[i] == '/') {
            filename_begin = i + 1;
            break;
        }
    }
    // cout << filename_begin << endl;
    // cout << filename_end << endl;
    filename = filePath.substr(filename_begin, filename_end - filename_begin + 1);
    fileformat = filePath.substr(fileformat_begin, fileformat_end - fileformat_begin + 1);
}

void StringSplit(const string &src, const char splitchar, vector<string> &dst) {
    int begin = 1;
    int end = 1;
    int i = 1;
    for (i = 1; i < src.length(); ++i) {
        if (src[i] == splitchar) {
            end = i - 1;
            dst.push_back(src.substr(begin, end - begin + 1));
            begin = i + 1;
            end = begin;
        }
    }

    //last
    if (i > end) {
        end = i - 1;
    }
    dst.push_back(src.substr(begin, end - begin + 1));
}

//遍历一个目录，找出其中某一后缀的所有文件
void sence0() {
    // Loop over all the images provided on the command line.
    std::vector<string> srcfiles;
    string srcpath = "./src/1";
    string srcformat = ".txt";
    string outputformat = ".png";
    printf("the current dir is : %s\n", srcpath.c_str());
    readFileList(srcfiles, srcpath.c_str(), srcformat);
    string dstpath = "./src/3";
    printf("the dst dir is : %s\n", dstpath.c_str());
    if (access(dstpath.c_str(), 0) == -1) {
        int flag = mkdir(dstpath.c_str(), 0777);
    }

    std::vector<string> dstfiles(srcfiles.size());
    for (int i = 0; i < srcfiles.size(); ++i) {
        /* code */
        cout << srcfiles[i] << endl;
        string filename;
        string fileformat;
        GetStringFileName(srcfiles[i], filename, fileformat);
        string dstfile = dstpath + "/" + filename + "." + fileformat;
        dstfiles[i] = dstfile;
        cout << dstfiles[i] << endl;
    }
}


//建立多级目录,包括子目录, 并依次处理文件，适用于小文件
void sence1() {
    // Loop over all the images provided on the command line.
    std::vector<string> files;
    string filePath = "./lfw_small_raw";
    string format = ".jpg";
    string outputformat = ".png";
    printf("the current dir is : %s\n", filePath.c_str());
    readFileList(files, filePath.c_str(), format);
    string dstpath = "./lfw_small_convert";
    printf("the dst dir is : %s\n", dstpath.c_str());
    if (access(dstpath.c_str(), 0) == -1) {
        int flag = mkdir(dstpath.c_str(), 0777);
    }

    std::vector<string> alignimg(files.size());
    for (int i = 0; i < files.size(); ++i) {
        /* code */
        cout << files[i] << endl;
        string facefolder;
        string facenameindex;
        findDir(files[i], facefolder, facenameindex, filePath);
        facenameindex = facenameindex.substr(0, facenameindex.size() - 4);
        facenameindex += outputformat;
        //cout  << facefolder << endl;
        //cout  << facenameindex << endl;
        string newfacefolder = dstpath + "/" + facefolder;
        if (access(newfacefolder.c_str(), 0) == -1) {
            int flag = mkdir(newfacefolder.c_str(), 0777);
        }
        alignimg[i] = newfacefolder + "/" + facenameindex;
        cout << alignimg[i] << endl;
    }
}

//依次遍历文件夹中的每一个目录，遇到一个目录新建一个目录，然后遍历该目录的文件
void sence2() {
    // Loop over all the images provided on the command line.
    std::vector<string> sudDirfiles;
    string srcpath = "./lfw_small_raw";
    string dstpath = "./lfw_small_convert";

    //如果目录存在就删除目录
    if (access(dstpath.c_str(), 0) == 0) {
        cout << "remove " << dstpath << endl;
        int flag = rmdir(dstpath.c_str());
    }

    //如果目录不存在就新建
    if (access(dstpath.c_str(), 0) == -1) {

        cout << "mkdir " << dstpath << endl;
        int flag = mkdir(dstpath.c_str(), 0777);
    }

    findAllSubDir(sudDirfiles, srcpath.c_str());
    for (int i = 0; i < sudDirfiles.size(); ++i) {
        //cout  << sudDirfiles[i] << endl;
        //遍历当前子目录中所有文件
        std::vector<string> srcfiles;
        string srcSudDir = srcpath + "/" + sudDirfiles[i];
        string srcformat = ".jpg";
        printf("the current subdir is : %s\n", srcSudDir.c_str());

        string dstSudDir = dstpath + "/" + sudDirfiles[i];
        //建立目标子目录
        if (access(dstSudDir.c_str(), 0) == -1) {
            cout << "mkdir " << dstSudDir << endl;
            int flag = mkdir(dstSudDir.c_str(), 0777);
        }
        printf("the current subdir is : %s\n", dstSudDir.c_str());

        readFileList(srcfiles, srcSudDir.c_str(), srcformat);
        for (int j = 0; j < srcfiles.size(); ++j) {
            cout << srcfiles[j] << endl;
            string filename;
            string fileformat;
            GetStringFileName(srcfiles[j], filename, fileformat);
            string dstfile = dstSudDir + "/" + filename + "." + fileformat;
            cout << dstfile << endl;
        }
    }
}


int main() {
    sence2();
    // string filePath = "./lfw_small_raw/Aaron_Eckhart";
    // std::vector<string> split;
    // StringSplit(filePath, '/', split);
    // string curSubDir = split[split.size() - 1];
    // cout << curSubDir << endl;
    // for (int i = 0; i < split.size(); ++i)
    // {
    //     cout << split[i] << endl;
    // }

    // string filename;
    // string fileformat;
    // GetStringFileName(filePath, filename, fileformat);
    // //cout << filePath.substr(2, 3) << endl;
    // cout << filePath << endl;
    // cout << filename << endl;
    // cout << fileformat << endl;
    return 0;
}