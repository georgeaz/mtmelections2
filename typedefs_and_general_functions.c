//
// Created by George on 11/30/2018.
//
#include <stdlib.h>
#include "typedefs_and_general_functions.h"

Name StringCopy(const String source_string){
    String new_copy=(String)malloc(sizeof(String*)*Stringlength(source_string));
    if(new_copy==NULL){
        return NULL;
    }
    int i=0;
    for(;source_string[i] !='\0';i++){
        new_copy[i]=source_string[i];
    }
    new_copy[i]="\0";
    return &new_copy;

}
size_t Stringlength(const String  string)
{
     String ptr;

    for (ptr = string; *ptr; ++ptr)
        ;
    return (ptr - string);
}