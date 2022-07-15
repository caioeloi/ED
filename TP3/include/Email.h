#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <iostream>
using namespace std;

class Email
{
public:
    int id = -1;
    string mensagem;
    friend bool operator < (Email& e1, Email& e2);
    friend bool operator > (Email& e1, Email& e2);
    friend bool operator == (Email& e1, Email& e2);
};
#endif