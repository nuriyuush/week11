//  main.c
//  ex3
//  Created by НУРИЯ on 10/28/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int main(){
    int file_1=open("ex1.txt", O_RDWR);
    int file_2=open("ex1.memcpu.txt", O_RDWR);
    struct stat buffer;
    fstat(file_1, &buffer);
    ftruncate(file_2, buffer.st_size);
    char *string;
    char *str;
    string=mmap(NULL, buffer.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file_1, 0);
    str=mmap(NULL, buffer.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file_2, 0);
    memcpy(str, string, buffer.st_size);
    exit(0);
}

