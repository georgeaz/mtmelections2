//
// Created by User on 28/11/2018.
// Created by Lina Bshouty القمر

#ifndef UNTITLED1_CITY_H
#define UNTITLED1_CITY_H


#include "citizen.h"
#include "libmtm/set.h"
#include "Candidate.h"

typedef enum CityResult_t{
    CITY_MEMORY_ERROR,
    CITY_NULL_ARGUMENT,
    CITY_ALREADY_EXISTS,
    CITY_NOT_SAME_CITY,//maybe we wont use this
    CITY_DOES_NOT_EXIST,
    CITY_SUCCESS,
    CITY_ILLEGAL_ID
}CityResult;

Id CityGetId(City);
Name CityGetName(City);
void CityDestroy(City);
City CityCreate();
City CityCopy(City);
bool CityCompare(City ,City );
bool CityIsLegal(City );
Citizen CityGetCitizen(City ,int );
CitizenResult CityInsertCitizen(City, Citizen);
CitizenResult CityRemoveCitizen(City, Citizen);
CandidateResult CityInsertCandidate(City, int);
CandidateResult CityRemoveCandidate(City,Candidate);
void CityChangeInformation(City,const String,int);

#endif //UNTITLED1_CITY_H
