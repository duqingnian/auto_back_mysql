#include <time.h> 
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

//备份目录
char back_dir[50] = "/存储路径/";

//检测目录是不是存在
int is_dir_exist(const char*dir_path){
    if(dir_path==NULL){
        return -1;
    }
    if(opendir(dir_path)==NULL){
        return -1;
    }
    return 0;
}

//备份数据库
int back_db(char* db_name)
{
    char cmd_db1[200]={0};
    char db1[15] = {0};
    strcat(db1,db_name);
    char file1[100] = {0};
    sprintf(file1,"%s/%s.sql.gz",back_dir,db1);
    sprintf(cmd_db1,"/phpstudy/mysql/bin/mysqldump -u root -p密码 %s | gzip > %s",db1,file1);
    system(cmd_db1);
    return 0;
}

int main( void )
{ 
    time_t t = time(0); 
    char t_date[15]; 
    strftime( t_date, sizeof(t_date), "%Y_%m_%d",localtime(&t) );
    
    strcat(back_dir,t_date);//将备份目录拼接日期

    int dir_exists = is_dir_exist(back_dir);
    if(dir_exists < 0)
    {
        printf("dir[%s] is not exists.\n",back_dir);
        //back dir not exists, create
        char cmd1[50] = {0};
        sprintf(cmd1,"mkdir %s",back_dir);
        system(cmd1);
        printf("dir[%s] created success.\n",back_dir);
    }
    
    //开始执行备份命令
    back_db("数据库1");
    back_db("数据库2");
    back_db("数据库3");
    
    return 0; 
}














