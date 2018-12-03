//
// Created by George on 12/1/2018.
//

#include "preference.h"
struct Preference_t{
  Id candidate_id;
  int * preference_score;
};

Preference PreferenceCreate() {
    Preference preference = (Preference) malloc(sizeof(*preference));
    int * preference_score = (int*) malloc(sizeof(*preference_score));
    Id candidate_id = (Id) malloc(sizeof(*candidate_id));
    if(preference==NULL||preference_score==NULL||candidate_id==NULL){
        free(preference_score);
        free(candidate_id);
        free(preference);
        return NULL;
    }
    preference->candidate_id=candidate_id;
    preference->preference_score=preference_score;
    return preference;
}
void PreferenceDestroy(Preference preference){
    if(preference==NULL)return;
    free(preference->preference_score);
    free(preference->candidate_id);
    free(preference);
}
Preference PreferenceCopy(Preference source_prefernce){
    if(source_prefernce==NULL)return NULL;
    Preference new_prefernece=PreferenceCreate();
    if(new_prefernece==NULL){
        PreferenceDestroy(new_prefernece);
        return NULL;
    }
    new_prefernece->preference_score=source_prefernce->preference_score;
    new_prefernece->preference_score=source_prefernce->candidate_id;
    return new_prefernece;
}
bool PreferenceIsEquals(Preference source_preference,Preference new_preference){
    return source_preference->candidate_id==new_preference->candidate_id;
}
bool PreferenceCompare(Preference old_preference,Preference new_preference){
    return *(old_preference->preference_score)<=*(new_preference->preference_score);
}
