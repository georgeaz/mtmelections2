//
// Created by User on 28/11/2018.
//


#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "City.h"

struct City_t{
    Id id;
    Name name;
    Set citizens;
};
Id GetCityId(City city){
    return city->id;
}
Name GetCtyName(City city){
    return  city->name;
}
void CityDestroy(City city){
    free(city->name);
    free(city->id);
    setDestroy(city->citizens);
    free(city);
}
City CityCreate(){
    //Name was: Name*, Name is char**
    // if(name==NULL || city==NULL || id==NULL) What happens to the other two arguments?they are not freed
    //    return NULL;
    City city=(City)malloc(sizeof(*city));
    Set citizens=setCreate((copySetElements)CitizenCopy,CitizenDestroy,CitizenCompere);
    Id id=(Id)malloc(sizeof(*id));
    if(city==NULL||citizens==NULL||id==NULL){
        free(city);
        setDestroy(citizens);
        free(id);
        return NULL;
    }
    city->id=id;
    city->citizens=citizens;
    return city;
}
City CityCopy(City source_city){
    //if were added
    if(source_city==NULL)
        return NULL;
    City new_city= CityCreate();
    String name_copy=malloc(sizeof(Name)*Stringlength(*source_city->name));
    if(new_city==NULL||name_copy==NULL){
        CityDestroy(new_city);
        return NULL;
    }
    new_city->name=StringCopy(*new_city->name,name_copy);
    new_city->citizens=source_city->citizens;
    new_city->id=source_city->id;
        return new_city;
}
CitizenResult CityInsertCitizen(City city, Citizen citizen){
        //the whole function were replaced
    SetResult result=setAdd(city->citizens,citizen);
    switch(result){
        case SET_NULL_ARGUMENT:
            return CITIZEN_NULL_ARGUMENT;
        case SET_OUT_OF_MEMORY:
            return CITIZEN_MEMORY_ERROR;
        case SET_ITEM_ALREADY_EXISTS:
            return CITIZEN_ALREADY_EXISTS;
        case SET_SUCCESS:
            return CITIZEN_SUCCESS;
        default:return CITIZEN_SUCCESS;
    }
}
CitizenResult CityRemoveCitizen(City city, Citizen citizen){
    SetResult result=setRemove(city->citizens,citizen);
   switch (result){
     case SET_NULL_ARGUMENT:
         return CITIZEN_NULL_ARGUMENT;
     case SET_ITEM_DOES_NOT_EXIST:
         return CITIZEN_DOES_NOT_EXIST;
       case SET_SUCCESS:
           return CITIZEN_SUCCESS;
       default:return CITIZEN_SUCCESS;



   }
}
bool CityCompare(City old_city,City new_city){

    return old_city->id==new_city->id;
}