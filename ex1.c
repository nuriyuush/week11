//
//  main.c
//  exe1
//
//  Created by НУРИЯ on 10/28/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char* words="This is a nice day";
    FILE *my_file=fopen("ex1.txt", "w");
    ftruncate(fileno(my_file), strlen(words) );
    fclose(my_file);
    
    int file=open("ex1.txt", O_RDWR);
    char* map=mmap(NULL, strlen(words), PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
    memcpy(map, words, strlen(words));
    msync(map, strlen(words)-1, MS_ASYNC);
    munmap(map, strlen(words)-1);
    exit(0);
}
