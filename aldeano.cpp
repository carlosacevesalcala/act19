#include "aldeano.h"

Aldeano::Aldeano()
{

}

void Aldeano::setnom(const string &v)
{
    nom=v;
}

string Aldeano::getnom()
{
    return nom;
}

void Aldeano::setedad(int v)
{
    edad=v;
}

int Aldeano::getedad()
{
    return edad;
}

void Aldeano::setgenero(const string &v)
{
    genero=v;
}

string Aldeano::getgenero()
{
    return genero;
}

void Aldeano::setsalud(int v)
{
    salud=v;
}

int Aldeano::getsalud()
{
    return salud;
}