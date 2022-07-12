#include "Email.h"

bool operator < (Email& e1, Email& e2){
        if (e1.id < e2.id) return true;
        else return false;
}
bool operator > (Email& e1, Email& e2){
    if (e1.id > e2.id) return true;
    else return false;
}
bool operator == (Email& e1, Email& e2){
    if (e1.id == e2.id) return true;
    else return false;
}

