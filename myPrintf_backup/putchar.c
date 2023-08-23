#include <unistd.h>

int putchar(int c) {
    char ch = (char)c;
    return write(1, &ch, 1);
}
