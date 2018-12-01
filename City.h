//
// Created by User on 28/11/2018.
// Created by Lina Bshouty القمر

#ifndef UNTITLED1_CITY_H
#define UNTITLED1_CITY_H


#include "citizen.h"
#include "libmtm/set.h"
typedef enum CityResult_t{
    CITY_MEMORY_ERROR,
    CITY_NULL_ARGUMENT,
    CITY_ALREADY_EXISTS,
    CITY_NOT_SAME_CITY,//maybe we wont use this
    CITY_DOES_NOT_EXIST,
    CITY_SUCCESS
}CityResult;

Id CityGetId(City);
Name CityGetName(City);
void CityDestroy(City);
City CityCreate();
City CityCopy(City);
bool CityCompare(City ,City );
CitizenResult CityInsertCitizen(City, Citizen);
CitizenResult CityRemoveCitizen(City, Citizen);
CitizenResult CityInsertCandidate(City,Citizen);

#endif //UNTITLED1_CITY_H
