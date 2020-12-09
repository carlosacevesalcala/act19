#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <vector>
#include "civilizacion.h"

class Videogame{
private:
    string usuario;
    vector<Civilizacion>civilizaciones;

public:
    Videogame();

    void setusuario(const string &v);
    string getusuario();
    size_t size();
    void agregaralfinal(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    void crear(const Civilizacion &c, size_t n);
    void primera();
    void ultima();
    void ordenar_n();
    void ordenar_x();
    void ordenar_y();
    void ordenar_p();
    void modificar_n(const Civilizacion c, const Civilizacion nuevo);
    void modificar_x(const Civilizacion c, const Civilizacion nuevo);
    void modificar_y(const Civilizacion c, const Civilizacion nuevo);
    void modificar_p(const Civilizacion c, const Civilizacion nuevo);
    void eliminar(size_t pos);
    Civilizacion* buscar(const Civilizacion &c);
    void total();
    void respaldar();
    void recuperar();

    friend Videogame& operator<<(Videogame &v, const Civilizacion &c)
    {
        v.agregaralfinal(c);

        return v;
    }

};

#endif