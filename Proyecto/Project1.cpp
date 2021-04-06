# include <iostream>
# include <sstream>
# include <stdio.h>
# include <ctype.h>

using namespace std;

bool alfabetoEntrada(string cadena);
bool alfabetoSalida(string cadena);
bool conjuntoEstados(string cadena);
bool estadoInicio(string cadena);
bool estadoAceptable(string cadena);
bool validacion(string cadena);

string* alfabetoEnter= NULL;
string* alfabetoExit = NULL;
string* estados = NULL;
string* estadosAceptacion= NULL;
string* estadoInicial;

int main() {
    cout<< "----------------------\n";
    cout<< "Automata Finito Determinista   \n";
    cout<< "Por favor indique el tipo de funcion\n";
    cout<< "1.  AFD Validacion\n";
    cout<< "2. AFD Traduccion\n";
    cout<< "funcion: *";
    int funcion = 0;
    cin>> funcion;
    // funciones de validaciones 
    if( funcion== 1){
        string cadena;
        cout<< "Alfabeto de entrada : ";
        cin>> cadena;
        while(!alfabetoEntrada(cadena)){
            cout<< "Alfabeto de entrada : ";
            cin>> cadena;
        }
        cout<< endl;

        cout<< "Alfabeto de salida : ";
        cin>> cadena;
        while(!alfabetoSalida(cadena)){
            cout<< "Alfabeto de salida : ";
            cin>> cadena;

        }
        cout<< endl;
        

        cout<< "conjunto de Estados: ";
        cin>> cadena;
        conjuntoEstados(cadena);
        cout<< endl;

        cout<< "Estado de inicio : ";
        cin>> cadena;
        estadoInicio(cadena);
        cout<< endl;

        cout<< "Estado de aceptacion  : ";
        cin>> cadena;
        estadoAceptable(cadena);
        cout<< endl;

        cout<< "Palabra a validar   : ";
        cin>> cadena;
        validacion(cadena);
        cout<< endl;











    }
    // funciones de traduccion 
    if(funcion== 2){

    }
    // funcion para salir 
    if(funcion != 1 && funcion != 2) {


    }





return 0;
}

bool alfabetoEntrada(string cadena){
    //validacion del alfabeto que este separado correctame por comas
    bool correcto = false;
    bool separacionComas = false; 
    bool alfaNumerico = true;
    bool cardinalidad = true; 
    string caracter;
    for(int i = 0; i < cadena.length(); i++){
        if(cadena[i] == ',') {
            separacionComas = true; 
        }

    }
    if(separacionComas == true ){
        // ingresar alfabeto del arreglo
        alfabetoEnter = new string [cadena.length()/2+1];
        istringstream streamAlfabeto(cadena);
        int i = 0;
        while(getline(streamAlfabeto, caracter, ',')) {
            alfabetoEnter[i] = caracter;
            i++;

        }
            // validacion de alfabeto que sea Alfanumerico
        for(int i = 0; i < cadena.length()/2+1; i++){
            for(int j = 0; j < alfabetoEnter[i].length(); j++){
                if(isalpha(alfabetoEnter[i][j]) || isdigit(alfabetoEnter[i][j])) {
                    alfaNumerico = true;
              } else {
                    alfaNumerico = false;
                    break;
                }

            }
        }
           
       if(alfaNumerico == true){
            // validacion del alfabeto que sea de cardinalidad 1 
        for(int i = 0; i < cadena.length()/2+1; i ++) {
            if(alfabetoEnter[i].length() > 1) {
                cardinalidad = false;
                break;
            }

        }
             if(cardinalidad == false) cout << "El alfabeto debe ser cardinalidad de 1. : \n";
    
        }else{
            cout << " El alfabeto debe ser alfanumerico: \n";

        }

       
    } else{
        cout << "El alfabeto tiene que estar separado por comas: \n";
        
    }
        if(separacionComas && alfaNumerico && cardinalidad){
            correcto = true;
            cout<< "Alfabeto de entrada es valido: \n";
        }
        return correcto;
}

bool alfabetoSalida(string cadena){
     //validacion del alfabeto que este separado correctame por comas
    bool correcto = false;
    bool separacionComas = false; 
    bool alfaNumerico = false;
    bool cardinalidad = true; 
    string caracter;
    for(int i = 0; i < cadena.length(); i++){
        if(cadena[i] == ',') {
            separacionComas = true; 
        }

    }
    if(separacionComas == true ){
        // ingresar alfabeto del arreglo
        alfabetoExit = new string [cadena.length()/2+1];
        istringstream streamAlfabeto(cadena);
        int i = 0;
        while(getline(streamAlfabeto, caracter, ',')) {
            alfabetoExit[i] = caracter;
            i++;

        }
            // validacion de alfabeto que sea Alfanumerico
        for(int i = 0; i < cadena.length()/2+1; i++){
            for(int j = 0; j < alfabetoExit[i].length(); j++){
                if(isalpha(alfabetoExit[i][j]) || isdigit(alfabetoExit[i][j])) {
                    alfaNumerico = true;
              } else {
                    alfaNumerico = false;
                    break;
                }

            }
        }
           
       if(alfaNumerico == true){
            // validacion del alfabeto que sea de cardinalidad 1 
        for(int i = 0; i < cadena.length()/2+1; i ++) {
            if(alfabetoExit[i].length() > 1) {
                cardinalidad = false;
                break;
            }

        }
             if(cardinalidad == false) cout << "El alfabeto debe ser cardinalidad de 1. : \n";
    
        }else{
            cout << " El alfabeto debe ser alfanumerico: \n";

        }

       
    } else{
        cout << "El alfabeto tiene que estar separado por comas: \n";
        
    }
        if(separacionComas && alfaNumerico && cardinalidad){
            correcto = true;
            cout<< "Alfabeto de salida es valido: \n";
        }
        return correcto;

}

bool conjuntoEstados(string cadena){
    string estado;
    bool correcto = false;
    bool separacionComas = false;
    bool alfaNumerico = false;
    bool cardinalidad = false; 

    for(int i = 0; i < cadena.length(); i++){
        if(cadena[i] == ',') {
            separacionComas = true; 
        }

    }
    if(separacionComas){
        //Asignacion de memoria al arreglo
        estados = new string[cadena.length()/2+1];
        istringstream streamAlfabeto(cadena);
        int i = 0;
        while(getline(streamAlfabeto, estado, ',')){
            estados[i] = estado;
            i++;

        }
        //Verufucacion alfanumerica
        
        for(int i = 0; i < cadena.length()/2+1; i++){
            for(int j = 0; j < estados[i].length(); j++){
                if(isalpha(estados[i][j]) || isdigit(estados[i][j])) {
                    alfaNumerico = true;
              } else {
                    alfaNumerico = false;
                    break;
                }


            }
        }
        if(!alfaNumerico){

            //Verificacion de carninalidad de 10 
            for(int i = 0; i < cadena.length()/2+1; i++){
                if(estados[i].length() <= 10){

                }

            }

            if(!cardinalidad) cout << "LOs estados deben de ser menor o igual a 10 caracteres. \n\n";
        } cout <<"Los estados deben ser alfanumericos. \n\n";
        
        }else{
            cout<< "Ls estados deberan estar separados por comas.\n\n";
        }
        if(separacionComas && alfaNumerico && cardinalidad){
            correcto = true;
            cout<< "Conjunto de estados es validos. \n\n";
        }
    return correcto;

}

 bool estadoInicio(string cadena){
     return false;

}

bool estadoAceptable(string cadena){
    return false;

}
bool validacion(string cadena){
    return false;

}
