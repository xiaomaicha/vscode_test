//
// Created by wuqi on 19-6-25.
//

#include "json.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <iomanip>
using namespace std;

std::string basepath = "/home/wuqi/Videos/b1_datong/gray_test/failsafe_20190625";
std::ofstream outfile(basepath + ".json");
std::vector<string> filepath;

int readfilelist(std::string basepath) {
  DIR *dir;
  struct dirent *ptr;
  char base[1000];

  if ((dir = opendir(basepath.c_str())) == nullptr) {
    perror("Open dir error...");
    exit(1);
  }

  while ((ptr = readdir(dir)) != nullptr) {
    if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
      continue;
    else if (ptr->d_type == 8)    ///file
    {
      printf("d_name:%s/%s\n", basepath.c_str(), ptr->d_name);
      filepath.emplace_back(basepath + '/' + ptr->d_name);

    } else if (ptr->d_type == 10)    ///link file
      printf("d_name:%s/%s\n", basepath.c_str(), ptr->d_name);
    else if (ptr->d_type == 4)    ///dir
    {
      memset(base, '\0', sizeof(base));
      strcpy(base, basepath.c_str());
      strcat(base, "/");
      strcat(base, ptr->d_name);
      readfilelist(base);
    }
  }
  closedir(dir);
  return 1;
}

int main(void) {
  readfilelist(basepath);
  nlohmann::json json_video;
  for (auto &file:filepath) {
    nlohmann::json info;
    info["groubd_true"] = false;
    info["file_path"] = file;
    json_video.push_back(info);
  }
  outfile << std::setw(2) << json_video;
  return 0;
}