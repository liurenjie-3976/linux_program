#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h> 

static struct termios initial_settings, new_settings;
static int peek_character = -1;

int kbhit();

int main() {
    while (1) {
        if (kbhit()) {
            int key = getch();  // 获取键盘按键的ASCII码
            printf("Key pressed: %c\n", key);
        }
        // 其他的程序逻辑
    }

    return 0;
}

int kbhit() {
    char ch;
    int nread;

    if (peek_character != -1) {
        return 1;
    }
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0, &ch, 1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);

    if (nread == 1) {
        peek_character = ch;
        return 1;
    }   
    return 0;
    
}   