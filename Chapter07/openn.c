#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

    int fd=open("t1.txt", O_RDWR | O_CREAT | O_TRUNC |  O_APPEND, 0644);
    if(fd==-1){
        perror("open");
        exit(1);
    }

    const char* buf="Hello world\n";
    size_t count=strlen(buf);
    // strlen会把字符串的长度,包括最后的'\0'也算进去。
    ssize_t write_size=write(fd, buf, count);
    // 返回值表示实际写入的字节数
    

    close(fd);


    return 0;
}