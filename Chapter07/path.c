#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// 实现的目标是find命令。

void find_files(const char *path, const char *pattern) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char file_path[1024];

    dir = opendir(path);
    // 返回值是一个指向DIR结构体的指针，该结构体包含了目录流的有关信息。
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        if (lstat(file_path, &info) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            // 如果是目录，则递归遍历子目录
            find_files(file_path, pattern);
        } else if (S_ISREG(info.st_mode)) {
            // 如果是普通文件，并匹配模式，则输出文件路径
            if (strstr(entry->d_name, pattern) != NULL) {
                printf("%s\n", file_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <path> <pattern>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];
    const char *pattern = argv[2];
    find_files(path, pattern);

    return 0;
}
