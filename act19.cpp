#include <iostream>
#include "videogame.h"

using namespace std;

int main(){
    Videogame v;
    string op;
    Civilizacion c;

    while (true)
    {
        cout<<"1)  Nombre del usuario"<<endl;
        cout<<"2)  Agregar civilizacion"<<endl;
        cout<<"3)  Insertar civilizacion"<<endl;
        cout<<"4)  Crear civilizaciones"<<endl;
        cout<<"5)  Primera civilizacion"<<endl;
        cout<<"6)  Ultima civilizacion"<<endl;
        cout<<"7)  Ordenar"<<endl;
        cout<<"8)  Eliminar civilizacion"<<endl;
        cout<<"9)  Buscar"<<endl;
        cout<<"10) Modificar"<<endl;
        cout<<"11) Resumen"<<endl;
        cout<<"12) Buscar civilizaciones"<<endl;
        cout<<"13) respaldar"<<endl;
        cout<<"14) recuperar"<<endl;
        cout<<"15) Salir"<<endl;
        getline(cin, op);

        if(op == "1"){
            Videogame v;
            string nom;
            cin>>nom;
            v.setusuario(nom);
            cout<<v.getusuario()<<endl;
            cin.ignore();
        }
        else if (op == "2")
        {
            Civilizacion c;
            cin>>c;
            v.agregaralfinal(c);
            cin.ignore();
        }
        else if (op == "3")
        {
            Civilizacion c;
            cin>>c;

            size_t pos;
            cout<<"posicion: ";
            cin>>pos; cin.ignore();

            if (pos>=v.size())
            {
                cout<<"posicion no valida"<<endl;
            }
            else{
                v.insertar(c, pos);
            }
        }
        else if (op == "4")
        {
            Civilizacion c;
            cin>>c;
            size_t n;
            cout<<"n: ";
            cin>>n; cin.ignore();

            v.crear(c, n);
        }
        else if (op == "5")
        {
            v.primera();
        }
        else if (op == "6")
        {
            v.ultima();
        }
        else if (op == "7")
        {
            string o;
            while (true){
                    cout<<"1) Ordenar nombre"<<endl;
                    cout<<"2) Ordenar ubicacion en x"<<endl;
                    cout<<"3) Ordenar ubicacion en y"<<endl;
                    cout<<"4) Ordenar puntuacion"<<endl;
                    cout<<"0) salir"<<endl;
                    getline(cin, o);
                if (o == "1")
                {
                    v.ordenar_n();
                }
                
                else if (o == "2")
                {
                    v.ordenar_x();
                }

                else if (o == "3")
                {
                    v.ordenar_y();
                }

                else if (o == "4")
                {
                    v.ordenar_p();
                }
                
                else if (o == "0")
                {
                    break;
                }
            }
        }
        else if (op == "8")
        {
            size_t pos;
            cout<<"posicion: ";
            cin>>pos; cin.ignore();

            if (pos>=v.size())
            {
                cout<<"posicion no valida"<<endl;
            }
            else{
                v.eliminar(pos);
            }
        }
        else if (op == "9")
        {
            Civilizacion c;
            string n;
            cout<<"nombre:"<<endl;
            cin>>n;
            c.setnombre(n); cin.ignore();

            Civilizacion *ptr = v.buscar(c);

            if (ptr == nullptr)
            {
                cout<<"no encontrado"<<endl;
            }
            else
            {
                cout<<*ptr<<endl;
            }
        }
        else if (op == "10")
        {
            size_t pos;
            Civilizacion c;
            Civilizacion nuevo;
            string n;
            cout<<"nombre:"<<endl;
            cin>>n;
            c.setnombre(n); cin.ignore();

            Civilizacion *ptr = v.buscar(c);
            if (ptr == nullptr)
            {
                cout<<"no encontrado"<<endl;
            }
            else
            {
                
                string opc;

                while (true){
                    cout<<*ptr<<endl;
                    cout<<"1) Cambiar nombre"<<endl;
                    cout<<"2) Cambiar ubicacion en x"<<endl;
                    cout<<"3) Cambiar ubicacion en y"<<endl;
                    cout<<"4) Cambiar puntuacion"<<endl;
                    cout<<"0) salir"<<endl;
                    getline(cin, opc);
                    
                    
                    if (opc == "1")
                    {
                        cin>>n;
                        nuevo.setnombre(n);
                        v.modificar_n(c,nuevo);
                        cin.ignore();
                    }

                    else if (opc == "2")
                    {
                        int x;
                        cin>>x;
                        nuevo.setnombre(n);
                        nuevo.setx(x);
                        v.modificar_x(c,nuevo);
                        cin.ignore();
                    }

                    else if (opc == "3")
                    {
                        int y;
                        cin>>y;
                        nuevo.setnombre(n);
                        nuevo.sety(y);
                        v.modificar_y(c,nuevo);
                        cin.ignore();
                    }

                    else if (opc == "4")
                    {
                        int p;
                        cin>>p;
                        nuevo.setnombre(n);
                        nuevo.setpuntuacion(p);
                        v.modificar_p(c,nuevo);
                        cin.ignore();
                    }
                    
                    else if (opc == "0")
                    {
                        break;
                    }
                }
            }
        }
        else if (op == "11")
        {
            v.total();
        }
        else if(op == "12")
        {
            Civilizacion c;
            string n;
            cout<<"nombre:"<<endl;
            cin>>n;
            c.setnombre(n); cin.ignore();

            Civilizacion *ptr = v.buscar(c);
            if (ptr == nullptr)
            {
                cout<<"no encontrado"<<endl;
            }
            else{
            string opci;
            Civilizacion &c = *ptr;
            cout<<*ptr<<endl;

                while (true){
                    cout<<"1) Agregar aldeano"<<endl;
                    cout<<"2) Eliminar aldeano"<<endl;
                    cout<<"3) clasificar aldeanos"<<endl;
                    cout<<"4) Buscar aldeano"<<endl;
                    cout<<"5) Modificar aldeano"<<endl;
                    cout<<"6) Mostrar aldeanos"<<endl;
                    cout<<"7) recuperar"<<endl;
                    cout<<"0) salir"<<endl;
                    getline(cin, opci);
                    
                    
                    if (opci == "1")
                    {
                        string opcio;
                        while (true){
                            cout<<"1) Agregar al final"<<endl;
                            cout<<"2) Agregar al inicio"<<endl;
                            cout<<"3) Salir"<<endl;
                            getline(cin, opcio);
                            if (opcio == "1")
                            {
                                Aldeano a;
                                cin>>a;
                                c.agregaralfinal(a);
                                c.getpuntuacion()+100;
                                cin.ignore();
                            }

                            else if (opcio == "2")
                            {
                                Aldeano a;
                                cin>>a;
                                c.agregaralinicio(a);
                                c.getpuntuacion()+100;
                                cin.ignore();
                            }
                            
                            else if (opcio == "3")
                            {
                                break;
                            }
                        }
                    }

                    else if (opci == "2")
                    {
                        string opcion;
                        while (true){
                            cout<<"1) Eliminar por nombre"<<endl;
                            cout<<"2) Eliminar aldeanos donde su salud sea menor a"<<endl;
                            cout<<"3) Eliminar aldeanos donde su edad sea mayor igual a 60"<<endl;
                            cout<<"4) Salir"<<endl;
                            getline(cin, opcion);
                            if (opcion == "1")
                            {
                                Aldeano a;
                                string n;
                                size_t pos = 1;
                                cout<<"nombre:"<<endl;
                                cin>>n;
                                a.setnom(n);

                                Aldeano *ptr = c.buscar(a);

                                if (ptr == nullptr)
                                {
                                    cout<<"no encontrado"<<endl;
                                }
                                else
                                {
                                    c.eliminar_nom(pos);
                                    cin.ignore();
                                }
                            }

                            else if (opcion == "2")
                            {
                                Aldeano a;
                                int n;
                                size_t pos = 1;
                                cout<<"salud:"<<endl;
                                cin>>n;
                                a.setsalud(n); 

                                for (size_t i = 0; i < n ; n--)
                                {
                                    a.setsalud(n); 
                                    Aldeano *ptr = c.buscar(a);

                                    if (ptr == nullptr)
                                    {
                                    
                                    }
                                    else
                                    {
                                        c.eliminar_salud(pos);
                                        cin.ignore();
                                    }
                                }
                            
                            }
                            
                            else if (opcion == "3")
                            {
                                Aldeano a;
                                size_t pos = 1;

                                for (size_t n = 60; n <= 120 ; n++)
                                {
                                    a.setedad(n);
                                    Aldeano *ptr = c.buscar(a);

                                    if (ptr == nullptr)
                                    {
                                    
                                    }
                                    else
                                    {
                                        c.eliminar_salud(pos);
                                    }
                                }
                            }

                            else if (opcion == "4")
                            {
                                break;
                            }
                        }
                    }

                    else if (opci == "3")
                    {
                        string opcione;
                        while (true){
                        cout<<"1) Clasificar nombre"<<endl;
                        cout<<"2) Clasificar edad"<<endl;
                        cout<<"3) Clasificar salud"<<endl;
                        cout<<"0) salir"<<endl;
                        getline(cin, opcione);
                        if (opcione == "1")
                        {
                            c.ordenar_nom();
                        }
                
                        else if (opcione == "2")
                        {
                            c.ordenar_edad();
                        }

                        else if (opcione == "3")
                        {
                            c.ordenar_salud();
                        }
                
                        else if (opcione == "0")
                        {
                            break;
                        }
                    }
                    }
                    else if (opci == "4")
                    {
                        Aldeano a;
                        string n;
                        cout<<"nombre:"<<endl;
                        cin>>n;
                        a.setnom(n); cin.ignore();

                        Aldeano *ptr = c.buscar(a);

                        if (ptr == nullptr)
                        {
                        cout<<"no encontrado"<<endl;
                        }
                        else
                        {
                        cout<<*ptr<<endl;
                        }
                    }

                    else if (opci == "5")
                    {
                        Aldeano a;
                        Aldeano nuev;
                        string n;
                        cout<<"nombre:"<<endl;
                        cin>>n;
                        a.setnom(n); cin.ignore();

                        Aldeano *ptr = c.buscar(a);

                        if (ptr == nullptr)
                        {
                        cout<<"no encontrado"<<endl;
                        }
                        else
                        {
                            string opciones;
                            cout<<*ptr<<endl;
                            while (true){
                            
                            cout<<"1) Cambiar nombre"<<endl;
                            cout<<"2) Cambiar edad"<<endl;
                            cout<<"3) Cambiar genero"<<endl;
                            cout<<"4) Cambiar salud"<<endl;
                            cout<<"0) salir"<<endl;
                            getline(cin, opciones);
                    
                    
                            if (opciones == "1")
                            {
                            cin>>n;
                            nuev.setnom(n);
                            c.modificar_nom(a,nuev);
                            cin.ignore();
                            }

                            else if (opciones == "2")
                            {
                                int edad;
                                cin>>edad;
                                nuev.setnom(n);
                                nuev.setedad(edad);
                                c.modificar_edad(a,nuev);
                                cin.ignore();
                            }

                            else if (opciones == "3")
                            {
                                string genero;
                                cin>>genero;
                                nuev.setnom(n);
                                nuev.setgenero(genero);
                                c.modificar_genero(a,nuev);
                                cin.ignore();
                            }

                            else if (opciones == "4")
                            {
                                int salud;
                                cin>>salud;
                                nuev.setnom(n);
                                nuev.setsalud(salud);
                                c.modificar_salud(a,nuev);
                                cin.ignore();
                            }
                    
                            else if (opciones == "0")
                            {
                                break;
                            }
                            }
                        }
                    }

                    else if (opci == "6")
                    {
                        c.mostrar();
                    }

                    else if (opci == "7")
                    {
                        c.recuperar_al();
                    }
                    
                    else if (opci == "0")
                    {
                        break;
                    }
                }
            }
        }

        else if (op == "13")
        {
            v.respaldar();
        }

        else if (op == "14")
        {
            v.recuperar();
        }

        else if (op == "15")
        {
            break;
        }
        
    }

    return 0;
}