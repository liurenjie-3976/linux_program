#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    struct stat buf;
    if (argc != 2) {
        printf("usage: stat file_name\n");
        exit(1);
    }
    if (stat(argv[1], &buf) < 0) {
        perror("stat");
        exit(1);
    }
    printf("file: %s\n", argv[1]);
    printf("inode: %ld\n", buf.st_ino);
    printf("device: %ld\n", buf.st_dev);
    printf("mode: %o\n", buf.st_mode);
    printf("number of hard links: %ld\n", buf.st_nlink);
    printf("user ID of owner: %d\n", buf.st_uid);
    printf("group ID of owner: %d\n", buf.st_gid);
    printf("device type (if inode device): %ld\n", buf.st_rdev);
    printf("total size, in bytes: %ld\n", buf.st_size);
    printf("blocksize for filesystem I/O: %ld\n", buf.st_blksize);
    printf("number of blocks allocated: %ld\n", buf.st_blocks);
    printf("time of last access: %ld\n", buf.st_atime);
    printf("time of last modification: %ld\n", buf.st_mtime);
    printf("time of last change: %ld\n", buf.st_ctime);
    return 0;
}

// 用户ID和组ID有什么区别吗？