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
    Set candidates;
};
Id CityGetId(City city){
    return city->id;
}
Name CityGetName(City city){
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
    new_city->name=StringCopy(*new_city->name);
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
    SetResult remove_result=setRemove(city->citizens,citizen);
   switch (remove_result){
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
bool CityIsLegal(City city){
    return (city->id>=0);
   // if(city==NULL)
     //   return CITY_NULL_ARGUMENT; you dont have to return null since u already checked that
}
CandidateResult CityInsertCandidate(City city,Candidate candidate){
    //we should check here in case of memory allocation error!!!the election funct doesnot expect that o.O
   // if(CityIsLegal(city)!=CITY_SUCCESS || CandidateIsLegal(candidate)!=CANDIDATE_SUCCESS)
    //    return CANDIDATE_NULL_ARGUMENT; /They dont return the same thing
    //if you want to use the "SomethingIsLegal" thing. you only use it in their function
    if(candidate==NULL)return CANDIDATE_NULL_ARGUMENT;
    if(CandidateGetId(candidate)<0)return CANDIDATE_ILLEGAL_ID;
    SetResult add_candidate_result=setAdd(city->candidates,candidate);
    switch (add_candidate_result){
        case SET_NULL_ARGUMENT:
            return CANDIDATE_NULL_ARGUMENT;
        case SET_OUT_OF_MEMORY:
            return CANDIDATE_MEMORY_ERROR;
        case SET_ITEM_ALREADY_EXISTS:
            return CANDIDATE_ALREADY_EXISTS;
        default:return CANDIDATE_SUCCESS;
    }


}