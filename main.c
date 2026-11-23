#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        perror("Error opening data.txt for writing");
        return 1;
    }

    fprintf(fp, "First Name: Zeyneb\n");
    fprintf(fp, "Last Name: Hesenova\n");
    fprintf(fp, "Group: 760 IITS\n");

    if (fclose(fp) != 0) {
        perror("Error closing data.txt after writing");
        return 1;
    }

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("Error opening data.txt for reading");
        return 1;
    }

    printf("Contents of data.txt:\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    if (fclose(fp) != 0) {
        perror("Error closing data.txt after reading");
        return 1;
    }

    return 0;
}
