#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int read_file(char* filename, char** buffer) {
    FILE* file1;
    file1 = fopen(filename, "r");

    //gets the size of the file
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    *buffer = malloc(size);
    fread(*buffer, size, 1, file1);
    fclose(file1);

    return size;
}

void write_file(char* filename, char* buffer, int size) {
    FILE* file2 = fopen(filename, "w"); int k;

    for (k = size - 1; k >= 0; k--) {
        fwrite(buffer + k, 1, 1, file2);
    }

    fclose(file2);
}

int main(int argc, char* argv[]) {
    char* buffer;
    char* filename1;
    char* filename2;
    int filesize;

    filename1 = "A.txt";
    filename2 = "B.txt";

    filesize = read_file(filename1, &buffer);
    write_file(filename2, buffer, filesize);

    free(buffer);

    return 0;
}


