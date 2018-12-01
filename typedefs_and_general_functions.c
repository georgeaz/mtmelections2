//
// Created by George on 11/30/2018.
//

#include "typedefs_and_general_functions.h"

String StringCopy(String destination, const String Source)
{
    int i;
    for (i=0; Source[i] != '\0'; ++i)
        destination[i] = Source[i];
    destination[i]= '\0';
    return destination;
}
size_t Stringlength(const String string)
{
    const char *ptr;

    for (ptr = string; *ptr; ++ptr)
        ;
    return (ptr - string);
}

