//
// Created by User on 30/11/2018.
//

#ifndef UNTITLED1_TYPEDEFS_H
#define UNTITLED1_TYPEDEFS_H
#include <stddef.h>

typedef enum mtmElectionsGeneralInput_t{
    GENERAL_ID,
    GENERAL_AGE,
    GENERAL_EDUCATION_YEARS,
    GENERAL_
}mtmElectionsGeneralInput;
typedef struct  City_t* City;
typedef struct Citizen_t * Citizen;
typedef struct Candidate_t * Candidate;
typedef struct  Preference_t  Preference;
typedef int* Id;
typedef int* Age;
typedef char* String;
typedef String* Name;
typedef void* Information;
typedef int* EducationYears;
typedef int Priorty;

String StringCopy(String);
size_t Stringlength( String );
#endif //UNTITLED1_TYPEDEFS_H