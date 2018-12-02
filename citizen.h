//
// Created by George on 11/28/2018.
//
#include <stdbool.h>
#ifndef HOMEWORK2ELECTIONS_CITIZEN_H
#define HOMEWORK2ELECTIONS_CITIZEN_H
#include "libmtm/set.h"
#include "typedefs_and_general_functions.h"
/**
 * A citizen implementation
 *
 *
 *     * The following functions are available:
 *     CitizenCreate            - Creates a new empty list
 *     CitizenDestroy
 *     GetCitizenInformation    -
 *
 *     */

typedef enum CitizenResult_t{
    CITIZEN_MEMORY_ERROR,
    CITIZEN_NULL_ARGUMENT,
    CITIZEN_ALREADY_EXISTS,
    CITIZEN_DOES_NOT_EXIST,
    CITIZEN_SUCCESS
}CitizenResult;

typedef enum CitizenInformation_t{
  CITIZEN_ID,
  CITIZEN_NAME,
  CITIZEN_EDUCATION_YEARS,
  CITIZEN_AGE
}CitizenInformation;

Citizen CitizenCreate();
void CitizenDestroy(Citizen );
Citizen CitizenCopy(Citizen );
bool CitizenCompere(Citizen ,Citizen );
void CitizenRemovePreferences(Citizen);
void CitizenGetInformation(Citizen ,Information ,CitizenInformation );
void CitizenRemovePrefrence(Citizen , Id const );
void CitizenCandidateToBeRemovePrefrences(Citizen );

#endif //HOMEWORK2ELECTIONS_CITIZEN_H