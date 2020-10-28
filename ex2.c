//
//  main.c
//  ex2
//
//  Created by НУРИЯ on 10/28/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(){
    setvbuf(stdout, NULL,_IOFBF, 0);
    char word[]="Hello";
    for(int i=0; i<strlen(word); i++){
        printf("%c\n", word[i]);
        sleep(1);
    }
    exit(0);
}
