#include <stdio.h>
#include "list.h"


#include <stdlib.h>
#include <assert.h>
void freeInt(void* e){
    free(e);
}

int main() {
    int x=6;
    int arr[] = {3,2,1,-4,1,2};
    List list=listCreate(copyInt,freeInt);
   // void* xx=listGetFirst(list);

    for(int i = 0; i < 6 ; i++){
        listInsertFirst(list,arr+i);
    }

      printf("%d",(*(int*)listGetFirst(list)));
    printf("Hello, World!\n");
    return 0;
}
