#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include<iostream>
#include <vector>
#include "aldeano.h"

using namespace std;

class Civilizacion{
    private:
    vector<Aldeano>aldeanos;
    string nombre;
    int x;
    int y;
    int puntuacion;

    public:
    Civilizacion();

    void setnombre(const string &v);
    string getnombre();
    void setx(int v);
    int getx();
    void sety(int v);
    int gety();
    void setpuntuacion(int v);
    int getpuntuacion();

    void agregaralfinal(const Aldeano &a);
    void agregaralinicio(const Aldeano &a);
    void eliminar_nom(size_t pos);
    void eliminar_salud(size_t pos);
    void eliminar_edad(size_t pos);
    void ordenar_nom();
    void ordenar_edad();
    void ordenar_salud();
    Aldeano* buscar(const Aldeano &a);
    void modificar_nom(const Aldeano a, const Aldeano nuevo);
    void modificar_edad(const Aldeano a, const Aldeano nuevo);
    void modificar_genero(const Aldeano a, const Aldeano nuevo);
    void modificar_salud(const Aldeano a, const Aldeano nuevo);
    void mostrar();
    void respaldar_al();
    void recuperar_al();

    

    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out<<left;
        out<<setw(10)<<c.nombre;
        out<<setw(15)<<c.x;
        out<<setw(15)<<c.y;
        out<<setw(10)<<c.puntuacion;
        out<<endl;
        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        cout<<"nombre: ";
        getline(cin, c.nombre);
        cout<<"ubicacion en x: ";
        cin>>c.x;
        cout<<"ubicacion en y: ";
        cin>>c.y;
        cout<<"puntuacion: ";
        cin>>c.puntuacion;
        return in;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }
    
    bool operator<(const Civilizacion& c)
    {
        return nombre < c.nombre;
    }
     bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }

};

#endif