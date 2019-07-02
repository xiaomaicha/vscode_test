//
// Created by wuqi on 19-6-13.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <memory.h>
#include <stdlib.h>
#include <limits.h>

int CreateDirectoryEx(char *sPathName) {
    char DirName[256];
    strcpy(DirName, sPathName);
    int i, len = strlen(DirName);
    if (DirName[len - 1] != '/')
        strcat(DirName, "/");
    len = strlen(DirName);
    for (i = 1; i < len; i++) {
        if (DirName[i] == '/') {
            DirName[i] = 0;
            if (access(DirName, F_OK) != 0) {
                if (mkdir(DirName, 0777) == -1) {
                    perror("mkdir error");
                    return -1;
                }
            }
//            int a = access(DirName, F_OK);
//            if(a ==-1)
//            {
//                mkdir(DirName,0755);
//            }
            DirName[i] = '/';
        }
    }
    return 0;
}

int main() {
    char pathnamee[] = "/home/wuqi/momenta/dms_model/cornercase_pic/all_data_clip/result_no_bbox/faceshade/20190423/";
    CreateDirectoryEx(pathnamee);

    const char *file_name = "/home/wuqi/momenta/dms_model/cornercase_pic/all_data_clip/result_no_bbox/faceshade_data_20190424.xlsx";
    char abs_path_buff[PATH_MAX];

    //获取文件路径, 填充到abs_path_buff
    //realpath函数返回: null表示获取失败; 否则返回指向abs_path_buff的指针
    if(realpath(file_name, abs_path_buff)){
        printf("%s %s\n", file_name, abs_path_buff);
    }
    else{
        printf("the file '%s' is not exist\n", file_name);
    }


    return 0;
}