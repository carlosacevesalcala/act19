#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano{
private:
    string nom; 
    int edad; 
    string genero;
    int salud;
public:
    Aldeano();

    void setnom(const string &v);
    string getnom();
    void setedad(int v);
    int getedad();
    void setgenero(const string &v);
    string getgenero();
    void setsalud(int v);
    int getsalud();

    friend istream& operator>>(istream &in, Aldeano &a)
    {
        cout<<"nombre: ";
        getline(cin, a.nom);
        cout<<"edad: ";
        cin>>a.edad;
        cout<<"genero: ";
        cin>>a.genero;
        cout<<"salud: ";
        cin>>a.salud;
        return in;
    }

    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
        out<<left;
        out<<setw(10)<<a.nom;
        out<<setw(15)<<a.edad;
        out<<setw(15)<<a.genero;
        out<<setw(10)<<a.salud;
        out<<endl;
        return out;
    }

    bool operator==(const Aldeano& a)
    {
        return nom == a.nom;
    }
    bool operator==(const Aldeano& a) const
    {
        return nom == a.nom;
    }
    
    bool operator<(const Aldeano& a)
    {
        return nom < a.nom;
    }
     bool operator<(const Aldeano& a) const
    {
        return nom < a.nom;
    }

    bool operator>(const Aldeano& a)
    {
        return nom > a.nom;
    }
     bool operator>(const Aldeano& a) const
    {
        return nom > a.nom;
    }

};

#endif