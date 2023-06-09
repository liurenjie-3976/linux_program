#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// 这个有bug，不知道为什么

void printdir(char *dir,int depth){

    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if((dp = opendir(dir)) == NULL){
        fprintf(stderr,"cannot open directory: %s\n",dir);
        return;
    }

    chdir(dir); //切换目录，如果存在那就返回一个0，不存在就返回-1。

    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name,&statbuf);
        // lstat()函数接受一个字符串参数path，表示要获取信息的文件或目录路径，
        // 同时接受一个指向struct stat结构体的指针statbuf，用于存储获取到的文件信息。
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0){
                continue;
            }
            printf("%*s%s/\n",depth,"",entry->d_name);
            printdir(entry->d_name,depth+4);
        }else{
            printf("%*s%s\n",depth,"",entry->d_name);
        }
    }
   
    chdir("..");
    closedir(dp);

}

int main(){

    printf("Directory scan of /home:\n");
    printdir("/proc",0);
    printf("done.\n");
    exit(0);

}