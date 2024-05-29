#pragma once
#include <iostream>
using namespace std;

class Enemigos
{
public:

    Enemigos(int pEneHp, int pEneDamage, string EneName, int pEneYpos, int pEneXpos);
    Enemigos();
    string getEneName();
    int getEneHp();
    int getEneDamage();
    int getEneYpos();
    int getEneXpos();
    void setEneName(string pEneName);

    void setEneHp(int pEneHp);
    void setEneDamage(int pEneDamage);
    void setEneYpos(int pEneYpos);
    void setEneXpos(int pEneXpos);

private:
    int EneHp;
    int EneDamage;
    string EneName;
    int EneYpos;
    int EneXpos;
};

