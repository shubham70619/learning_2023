#include <stdio.h>

int stringToInteger(char *str) {
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        int ival = str[i] - '0';
        res = res * 10 + ival;
        i++;
    }

    return res;
}

int main() {
    char str[] = "5278";
    printf("Input String: %s\n", str);

    int intValue = stringToInteger(str);

    printf("Integer Value: %d\n", intValue);

    return 0;
}
