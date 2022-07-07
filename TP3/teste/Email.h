#ifndef EMAIL_H
#define EMAIL_H

#include <string>
using namespace std;


class Email
{
public:
    int id;
    string mensagem;
    friend bool operator < (Email& e1, Email& e2);
    friend bool operator > (Email& e1, Email& e2);
    friend bool operator == (Email& e1, Email& e2);

};




#endif