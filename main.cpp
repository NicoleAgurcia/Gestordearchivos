#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Archivos{
    public:
       string nombre_archivo;

       Archivos(string nombre_archivo){
           this->nombre_archivo=nombre_archivo;
       }
};

list <Archivos*> ArchivosCreados;


void creararchivo(string nombre_archivo,Archivos *m){
    ofstream out(nombre_archivo.c_str(),ios::app|ios::binary);
    cout << "Archivo creado con exito..." << endl;
    out.write(m->nombre_archivo.c_str(),100);
    out.close();
}

void listararchivos(){
    while(!ArchivosCreados.empty()){
            for(int x=0; x < ArchivosCreados.size(); x++){
                cout << ArchivosCreados.front() << endl;
            }
            ArchivosCreados.pop_front();
    }
}

void modificararchivo(string nombre_archivo){
    string line;
    ofstream out(nombre_archivo.c_str(),ios::in|ios::binary);
    if(!out.is_open()){
        cout << "Error a la hora de abrir el archivo" << endl;
    }
    getline(cin,line);
    do{
        out << line << endl;
        cout << "> ";
        getline(cin,line);
    }while(line != "");
    out.close();
    cout << "Se termino de editar el archivo" << endl;
}


//void modificararchivobin(string nombre_archivo){
//   string line;
//   int tam;
//    ofstream out(nombre_archivo.c_str(),ios::binary);
//
//    if(!out.is_open()){
//            out.open(nombre_archivo.c_str());
//    }
//
//    getline(cin,line);
//    do{
//            tam = line.size();
//        out.write(line.c_str(),tam);
//        cout << "> ";
//        getline(cin,line);
//    }while(line != "");
//    out.close();
//    cout << "Se termino de editar el archivo" << endl;
//}



void verarchivo (string nombre_archivo){
   string line;
    ifstream in(nombre_archivo.c_str());
    cout << "Contenido del archivo" << endl;

   if(!in){
    cout << "Error al abrir el archivo" << endl;
   }else{
       while(getline(in,line)){
        cout << ">" << line<< endl;
       }
       cout <<"----Fin del archivo" << endl;
   }
}

//void verarchivobin (string nombre_archivo){
//    ifstream in(nombre_archivo.c_str());
//    cout << "Contenido del archivo" << endl;
//
////   if(!in){
////    cout << "Error al abrir el archivo" << endl;
////   }else{
//       string line;
//       //int tam = line.size();
//       in.read((char*)&line,sizeof(line));
//       cout << ">" << line << endl;
//    //}
//}

Archivos * getArchivo(){
    string nombre_archivo;
    cout << nombre_archivo << endl;
    cin >> nombre_archivo;

    return new Archivos(nombre_archivo);

}


int main()
{
    string op="";


string nombre_archivo;

    do{
            cout << ">" ;
    cin >> op;
        if(op== "creararchivo"){


            cin >> nombre_archivo;
            creararchivo(nombre_archivo,getArchivo());
        }
        if(op=="modificararchivo"){
            cin >> nombre_archivo;
            modificararchivo(nombre_archivo);
            //modificararchivobin(nombre_archivo);
        }
        if(op=="verarchivo"){
            cin >> nombre_archivo;
            verarchivo(nombre_archivo);
            //verarchivobin(nombre_archivo);
        }
        if(op=="listararchivos"){
            //listararchivos();
        }


    }while(op!="salir");


    return 0;
}

