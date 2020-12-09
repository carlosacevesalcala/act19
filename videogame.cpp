#include "videogame.h"
#include <fstream>
#include <algorithm>

Videogame::Videogame(){

}

void Videogame::setusuario(const string &v){
    usuario=v;
}

string Videogame::getusuario(){
    return usuario;
}

size_t Videogame::size(){
    return civilizaciones.size();
}

void Videogame::agregaralfinal(const Civilizacion &c){
    civilizaciones.push_back(c);
}

void Videogame::insertar(const Civilizacion &c, size_t pos){
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void Videogame::crear(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void Videogame::primera(){
    if (civilizaciones.empty()){
                cout<<"vector esta vacio"<<endl;
            }
            else{
                cout<<civilizaciones.front()<<endl;
            }
}

void Videogame::ultima(){
    if (civilizaciones.empty()){
                cout<<"vector esta vacio"<<endl;
            }
            else{
                cout<<civilizaciones.back()<<endl;
            }
}

void Videogame::ordenar_n()
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getnombre() < c2.getnombre();});
}

void Videogame::ordenar_x()
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getx() < c2.getx();});
}

void Videogame::ordenar_y()
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.gety() < c2.gety();});
}

void Videogame::ordenar_p()
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getpuntuacion() < c2.getpuntuacion();});
}

void Videogame::modificar_n(const Civilizacion c, const Civilizacion nuevo)
{
    replace(civilizaciones.begin(), civilizaciones.end(), c, nuevo);
}

void Videogame::modificar_x(const Civilizacion c, const Civilizacion nuevo)
{
    replace(civilizaciones.begin(), civilizaciones.end(), c, nuevo);
}

void Videogame::modificar_y(const Civilizacion c, const Civilizacion nuevo)
{
    replace(civilizaciones.begin(), civilizaciones.end(), c, nuevo);
}

void Videogame::modificar_p(const Civilizacion c, const Civilizacion nuevo)
{
    replace(civilizaciones.begin(), civilizaciones.end(), c, nuevo);
}

void Videogame::eliminar(size_t pos)
{
    civilizaciones.erase(civilizaciones.begin()+pos);
}

Civilizacion* Videogame::buscar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void Videogame::total(){
    cout<<left;
    cout<<setw(10)<<"nombre";
    cout<<setw(15)<<"ubicacion x";
    cout<<setw(15)<<"ubicacion y";
    cout<<setw(10)<<"puntuacion";
    cout<<endl;
    for(size_t i = 0; i<civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout<<c;

    }
}


void Videogame::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civilizaciones.size(); ++i) {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getnombre() << endl;
        archivo << c.getx() << endl;
        archivo << c.gety() << endl;
        archivo << c.getpuntuacion() << endl;
        c.respaldar_al();
    }
    archivo.close();
}
void Videogame::recuperar()
{
    ifstream archivo("civilizaciones.txt", ios::out);
    if (archivo.is_open()){
        
        string temp;
        int x;
        int y;
        int p;
        Civilizacion c;
        while(true){
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            c.setnombre(temp);
            getline(archivo, temp);

            x = stoi(temp);
            c.setx(x);
            getline(archivo, temp);
            
            y = stoi(temp);
            c.sety(y);
            getline(archivo, temp);
            
            p = stoi(temp);
            c.setpuntuacion(p);
            

            agregaralfinal(c);
            //c.recuperar_al();
        }
    }
    archivo.close();
}
