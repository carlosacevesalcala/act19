#include "civilizacion.h"
#include <fstream>
#include <algorithm>

Civilizacion::Civilizacion(){

}

void Civilizacion::setnombre(const string &v){
    
    nombre=v;
}

string Civilizacion::getnombre(){
    
    return nombre;
}

void Civilizacion::setx(int v){
    
    x=v;
}

int Civilizacion::getx(){
  
    return x;
}

void Civilizacion::sety(int v){
    
    y=v;
}

int Civilizacion::gety(){
    
    return y;
}

void Civilizacion::setpuntuacion(int v){
    puntuacion=v;
}

int Civilizacion::getpuntuacion(){
    return puntuacion;
}

void Civilizacion::agregaralfinal(const Aldeano &a){
    aldeanos.push_back(a);
}

void Civilizacion::agregaralinicio(const Aldeano &a){
    aldeanos.insert(aldeanos.begin(), a);
}

void Civilizacion::eliminar_nom(size_t pos)
{
    aldeanos.erase(aldeanos.begin());
}

void Civilizacion::eliminar_edad(size_t pos)
{
    aldeanos.erase(aldeanos.begin());
}

void Civilizacion::eliminar_salud(size_t pos)
{
    aldeanos.erase(aldeanos.begin());
}

void Civilizacion::ordenar_nom()
{
    sort(aldeanos.begin(), aldeanos.end(),[](Aldeano a1, Aldeano a2){return a1.getnom() < a2.getnom();});
}

void Civilizacion::ordenar_edad()
{
    sort(aldeanos.begin(), aldeanos.end(),[](Aldeano a1, Aldeano a2){return a1.getedad() > a2.getedad();});
}

void Civilizacion::ordenar_salud()
{
    sort(aldeanos.begin(), aldeanos.end(),[](Aldeano a1, Aldeano a2){return a1.getsalud() > a2.getsalud();});
}

void Civilizacion::modificar_nom(const Aldeano c, const Aldeano nuevo)
{
    replace(aldeanos.begin(), aldeanos.end(), c, nuevo);
}

void Civilizacion::modificar_genero(const Aldeano c, const Aldeano nuevo)
{
    replace(aldeanos.begin(), aldeanos.end(), c, nuevo);
}

void Civilizacion::modificar_salud(const Aldeano c, const Aldeano nuevo)
{
    replace(aldeanos.begin(), aldeanos.end(), c, nuevo);
}

void Civilizacion::modificar_edad(const Aldeano c, const Aldeano nuevo)
{
    replace(aldeanos.begin(), aldeanos.end(), c, nuevo);
}


Aldeano* Civilizacion::buscar(const Aldeano &c)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), c);
    if (it == aldeanos.end())
    {
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void Civilizacion::mostrar(){
    cout<<left;
    cout<<setw(10)<<"nombre";
    cout<<setw(15)<<"edad";
    cout<<setw(15)<<"genero";
    cout<<setw(10)<<"salud";
    cout<<endl;
    for(size_t i = 0; i<aldeanos.size(); i++){
        Aldeano &a = aldeanos[i];
        cout<<a;

    }
}
void Civilizacion::respaldar_al()
{
    ofstream archivo(getnombre()+".txt");
    if (archivo.is_open()){
        for(size_t i = 0; i<aldeanos.size(); i++){
            Aldeano &a = aldeanos[i];
            archivo<<a.getnom()<<endl;
            archivo<<a.getedad()<<endl;
            archivo<<a.getgenero()<<endl;
            archivo<<a.getsalud()<<endl;
        }
    }
    archivo.close();
}


void Civilizacion::recuperar_al()
{
    ifstream archivo(getnombre()+".txt");
    if (archivo.is_open()){

    
        string temp;
        int e;
        int s;
        Aldeano a;
        while (true) {
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            a.setnom(temp);
            getline(archivo, temp);

            e = stoi(temp);
            a.setedad(e);
            getline(archivo, temp);
            
            a.setgenero(temp);
            getline(archivo, temp);

            s = stoi(temp);
            a.setsalud(s);
            
            

            agregaralfinal(a);
        
        }
    }
    archivo.close();
}