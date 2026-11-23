/* Assignment 9: Copy contents of one file to another using file handling */
#include <stdio.h>

int main() {
    FILE *source, *dest;
    char sourceName[100], destName[100];
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourceName);

    printf("Enter destination file name: ");
    scanf("%s", destName);

    /* open source file in read mode */
    source = fopen(sourceName, "r");
    if (source == NULL) {
        printf("Error: Cannot open source file '%s'\n", sourceName);
        return 1;
    }

    /* open destination file in write mode */
    dest = fopen(destName, "w");
    if (dest == NULL) {
        printf("Error: Cannot create destination file '%s'\n", destName);
        fclose(source);
        return 1;
    }

    /* read one character at a time and write it to destination */
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully!\n");

    fclose(source);
    fclose(dest);
    return 0;
}