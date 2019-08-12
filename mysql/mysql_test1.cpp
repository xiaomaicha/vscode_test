//
// Created by wuqi on 19-8-12.
//
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<mysql/mysql.h>
//
//#define MAX_COLUMN_LEN    32
//int main(int argc, char *argv[]) {
//  MYSQL db;
//  MYSQL_RES *res;
//  MYSQL_ROW row;
//
//  //初始化数据库
//  mysql_init(&db);
//  //连接数据库
//  if (mysql_real_connect(&db, "127.0.0.1", "root", "root", "wuqi", 3306, NULL, 0)) {
//    printf("connect!!!\n");
//  }
//
//  //查询
//  if (mysql_real_query(&db, "select * from S_RESIDENCE", (unsigned long) strlen("select * from S_RESIDENCE"))) {
//    printf("mysql_real_query failed\n");
//    return 0;
//  }
//
//  // 存储结果集
//  res = mysql_store_result(&db);
//  if (nullptr == res) {
//    printf("mysql_store_result failed\n");
//    return 0;
//  }
//
//  // 重复读取行，并输出第一个字段的值，直到row为NULL
//  while (row = mysql_fetch_row(res)) {
//    printf("%s\n", row[0]);
//  }
//
//  // 释放结果集
//  mysql_free_result(res);
//  // 关闭Mysql连接
//  mysql_close(&db);
//
//  return 0;
//}

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char server[] = "localhost";
  char user[] = "root";
  char password[] = "wuqi";
  char database[] = "mysql";

  conn = mysql_init(NULL);

  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  if (mysql_query(conn, "show tables")) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_use_result(conn);

  printf("MySQL Tables in mysql database:\n");

  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("%s \n", row[0]);
  }

  mysql_free_result(res);
  mysql_close(conn);

  printf("finish! \n");
  return 0;
}

//insert into <表名> [( <字段名 1>[,..<字段名 n > ])] values ( 值 1 )[, ( 值 n )]