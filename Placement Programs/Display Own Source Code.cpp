#include <stdio.h>
int main() {
    FILE *fp;
    char c;
    fp = fopen(__FILE__,"r"); //__FILE__ contains the location of this C programming file in a string.
    do {
         c = getc(fp);
         putchar(c);
    }
    while(c != EOF);
    fclose(fp);
    return 0;
}
