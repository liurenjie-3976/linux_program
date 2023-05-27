#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dp;
    struct dirent *entry;

    dp = opendir("/home/jj/linux");
    if (dp == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);

    return 0;
}
