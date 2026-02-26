#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string_utils.h"

int custom_len() {
    char first_element[100];
    int len;

    while(first_element[len] != '\0') {
        len++;
    }

    return len;
}

char *read_line_dynamic() {
    char string [100];
    int len = custom_len(string);

    fgets(string,custom_len(string),stdin);

    char *pstring = malloc(*pstring * sizeof(len));
    if (pstring == NULL) {
        printf("Space alocation failed\n");
        return NULL;
    }

    for(int i=0; i < len; i++) {
        pstring[i] == string [i];
    }

    printf("hello");
    
}