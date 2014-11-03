#include <iostream>
#include <fstream>
#include <list>
#include <windows.h>




using namespace std;

class Archivos{
    public:
       string nombre_archivo;
       Archivos * sig;
       Archivos();
       Archivos(string);



};
typedef Archivos * ARC;

Archivos::Archivos(){
    sig= NULL;
}
Archivos::Archivos(string vnombre_archivo){
    nombre_archivo = vnombre_archivo;
    sig=NULL;

}


list <Archivos*> ArchivosCreados;


//kakaka
void insartararchivo(ARC &arc, string vnombre_archivo){
    Archivos *tem; Archivos *new_nodo;
    new_nodo = new Archivos();
    new_nodo->nombre_archivo = vnombre_archivo;
    if(arc == NULL){ arc = new_nodo;}
    else{
        tem= arc;
        while(tem->sig != NULL){
            tem = tem->sig;
        }
        tem->sig = new_nodo;
    }
}

void listararchivos(Archivos * arc){
    Archivos * temp;
    temp = arc;
    while(temp != NULL){
        cout << temp->nombre_archivo;
        if(temp->sig != NULL){
            cout << endl;
        }
        temp = temp->sig;
    }
}

//void listarDirectorio(int argc, TCHAR *argv[])
//{
//   WIN32_FIND_DATA FindFileData;
//   HANDLE hFind;
//
//   if( argc != 2 )
//   {
//      cout << (TEXT("Usage: %s [target_file]\n"), argv[0]);
//      return;
//   }
//
//   cout << (TEXT("Target file is %s\n"), argv[1]);
//   hFind = FindFirstFile(argv[1], &FindFileData);
//   if (hFind == INVALID_HANDLE_VALUE)
//   {
//       cout << ("FindFirstFile failed (%d)\n", GetLastError());
//      return;
//   }
//   else
//   {
//       cout <<  (TEXT("The first file found is %s\n"),
//                FindFileData.cFileName);
//      FindClose(hFind);
//   }
//}





void creararchivo(string nombre_archivo){
    Archivos * arc= NULL;
    ofstream out(nombre_archivo.c_str(),ios::app|ios::binary);
    if(out.is_open()){
    cout << "Archivo creado con exito..." << endl;
    }



//    for(list<Archivos*>::iterator i = ArchivosCreados.begin(); i!=ArchivosCreados.end(); i++){
//            out<<(*i)->nombre_archivo<<" ";
//    }
//    ArchivosCreados.push_front(new Archivos(nombre_archivo));

    out.close();
    // m->nombre_archivo = nombre_archivo;
    //ArchivosCreados.push_front(m);
}

//void listararchivos(){
//    //while(!ArchivosCreados.empty()){
//           for(list<Archivos*>::iterator i = ArchivosCreados.begin(); i!=ArchivosCreados.end(); i++){
//                cout<<(*i)->nombre_archivo<<endl;
//           }
//    //}
//
//}

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
     Archivos * arc= NULL;


string nombre_archivo;

    do{
            cout << ">" ;
    cin >> op;
        if(op== "creararchivo"){


            cin >> nombre_archivo;
            creararchivo(nombre_archivo);
            insartararchivo(arc,nombre_archivo);
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

                listararchivos(arc);



        }


    }while(op!="salir");


    return 0;
}

