//
// Created by George on 12/1/2018.
//

#ifndef INC_3011_PREFERENCE_H
#define INC_3011_PREFERENCE_H
#include "typedefs_and_general_functions.h"
#include "stdbool.h"

typedef struct Preference_t* Preference;
bool PreferenceComper(Preference,Preference);
bool PreferenceIsEquals(Preference,Preference);
Preference PreferenceCopy(Preference);
void PreferenceDestroy(Preference);
Preference PreferenceCreate();

#endif //INC_3011_PREFERENCE_H
