#include "Enemigos.h"

#include <iostream>
using namespace std;

Enemigos::Enemigos(int pEneHp, int pEneDamage, string pEneName, int pEneYpos, int pEneXpos)
    : EneHp(pEneHp), EneDamage(pEneDamage), EneName(pEneName), EneYpos(pEneYpos), EneXpos(pEneXpos)
{
}

Enemigos::Enemigos()
    : EneHp(0), EneDamage(0), EneName(""), EneYpos(0), EneXpos(0)
{
}

string Enemigos::getEneName()
{
    return EneName;
}

int Enemigos::getEneHp()
{
    return EneHp;
}

int Enemigos::getEneDamage()
{
    return EneDamage;
}

int Enemigos::getEneYpos()
{
    return EneYpos;
}

int Enemigos::getEneXpos()
{
    return EneXpos;
}

void Enemigos::setEneName(string pEneName)
{
    EneName = pEneName;
}

void Enemigos::setEneHp(int pEneHp)
{
    EneHp = pEneHp;
}

void Enemigos::setEneDamage(int pEneDamage)
{
    EneDamage = pEneDamage;
}

void Enemigos::setEneYpos(int pEneYpos)
{
    EneYpos = pEneYpos;
}

void Enemigos::setEneXpos(int pEneXpos)
{
    EneXpos = pEneXpos;
}
