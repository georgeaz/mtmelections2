//
// Created by George on 12/1/2018.
//
#include "Candidate.h"
#include "stdlib.h"

typedef struct Candidate_t{
  Id id;
};
Candidate CandidateCreate(){
    Candidate candidate=(Candidate)malloc(sizeof(*candidate));
    if(candidate==NULL)
        return NULL;
    Id id=(Id)malloc(sizeof(*id));
    if(id==NULL){
        CandidateDestroy(candidate);
        return NULL;
    }
    candidate->id=id;
    return candidate;
}
void CandidateDestroy(Candidate candidate){
    free(candidate->id);
    free(candidate);
}

Candidate CandidateCopy(Candidate source_candidate){
    if(source_candidate==NULL){
        return NULL;
    }
    Candidate new_candidate=CandidateCreate();
    if(new_candidate==NULL){
        return NULL;
    }
    new_candidate->id=source_candidate->id;
    return new_candidate;
}
bool CandidateCompere(Candidate candidate_new,Candidate );
