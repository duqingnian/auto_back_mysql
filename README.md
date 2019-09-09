自动备份数据库
主要依靠的是linux的crontab

先修改文件里面的：
1.备份目录
2.数据库密码
3.需要备份的数据库名称

1.先用gcc编译成可执行文件
gcc mysql_backup.c
mv a.o mysql_backup.o
2.crontab
比如。每天晚上23点30分执行
30 23 * * * /mysql_backs/mysql_backup.o