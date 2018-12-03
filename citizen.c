//
// Created by George on 11/29/2018.
//
#include "citizen.h"
#include "uniqueOrderedList/uniqueOrderedList.h"
#include "preference.h"
#include <stdlib.h>
//we should include this in general functions
struct Citizen_t{
  Name name;
  Age age;
  Id id;
  EducationYears education_years;
  UniqueOrderedList citizen_prefrences;
};
Citizen CitizenCreate(){
    //Name name=(Name)malloc(sizeof(*name));
    //malloc for name will be added in copy, since we dont know the size of name
    Citizen citizen=(Citizen)malloc(sizeof(*citizen));
    Age age=(Age)malloc(sizeof(*age));
    Id id=(Id)malloc(sizeof(*id));
    EducationYears education_years=(EducationYears)malloc(sizeof(*education_years));
    UniqueOrderedList citizen_prefrences=uniqueOrderedListCreate(PreferenceCopy,PreferenceDestroy,PreferenceIsEquals,PreferenceCompare);
    if(citizen==NULL||age==NULL||id==NULL||education_years==NULL||citizen_prefrences==NULL){
        free(citizen);
        free(age);
        free(id);
        free(education_years);
        uniqueOrderedListDestroy(citizen_prefrences);
        return NULL;
    }
    citizen->age=age;
    citizen->id=id;
    citizen->education_years=education_years;
    citizen->citizen_prefrences=citizen_prefrences;
    return citizen;
}
void CitizenDestroy(Citizen citizen)
{
    //always check if  object==NULL before accessing struct fields!
    if(citizen==NULL)return NULL;
    free(citizen->age);
    free(citizen->education_years);
    free(citizen->id);
    uniqueOrderedListDestroy(citizen->citizen_prefrences);
    free(citizen);

}
Citizen CitizenCopy(Citizen source_citizen){
    if(source_citizen==NULL)return NULL;
    Citizen new_citizen=CitizenCreate();
    if(new_citizen==NULL){
        CitizenDestroy(new_citizen);
        return NULL;
    }
    //we should check this!
    new_citizen->name=StringCopy(*new_citizen->name);
    new_citizen->id=source_citizen->id;
    new_citizen->education_years=source_citizen->education_years;
    new_citizen->age=source_citizen->age;
    //u should make a unique ordered list that return a copy
    //new_citizen->citizen_prefrences=source_citizen->citizen_prefrences;
    return new_citizen;
}
CitizenResult CitizenInsertPrefrence(City city, Citizen citizen,Id candidate,Priority priorty ) {
    UniqueOrderedList result=uniqueOrderedListInsert(citizen->citizen_prefrences,);
    //switch(result

}
bool CitizenCompere(Citizen old_citizen,Citizen new_citizen){
    return old_citizen->id==new_citizen->id;
}

void CitizenGetInformation(Citizen citizen,Information information,CitizenInformation desirable_information) {
    //للأمانة انا غير متأكد من الدالّة يا لينا الع!
    switch (desirable_information) {
        case CITIZEN_ID:information = citizen->id;
        case CITIZEN_NAME:information = citizen->name;
        case CITIZEN_EDUCATION_YEARS:information = citizen->education_years;
        case CITIZEN_AGE:information = citizen->age;
    }
}
void CitizenCandidateToBeRemovePrefrences(Citizen citizen){
    uniqueOrderedListClear(citizen->citizen_prefrences);
}
void CitizenRemovePrefrence(Citizen citizen, int candidate_id) {
    Preference preference = uniqueOrderedListGetLowest(citizen->citizen_prefrences);
    while (preference) {
        if (PreferenceGetId(preference) == candidate_id) {
            uniqueOrderedListRemove(citizen->citizen_prefrences, preference);
            return;;
        }
        preference = uniqueOrderedListGetNext(citizen->citizen_prefrences);
    }
}
/*Preference CitizenGetPrefrence(Citizen citizen,int candidate_id)
{lina 3m tjrb lmkledet bs wleshy kter w wow !!!!
 wow
 jd wow
gogo wq7...
    Preference preference=uniqueOrderedListGetLowest(citizen->citizen_prefrences);
    while(preference) {
        if(PreferenceGetId(preference)==candidate_id){
        }
    }
}*/
int CitizenGetid(Citizen citizen){
    return *(citizen->id);
}
//maybe no:

void CitizenChangeInformation(Citizen citizen,int id,const String name,int education_years,int age){
    *(citizen->id)=id;
    *(citizen->name)=StringCopy(name);
    *(citizen->age)=age;
    *(citizen->education_years)=education_years;
}
