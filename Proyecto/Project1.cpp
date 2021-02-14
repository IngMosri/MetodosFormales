# include <iostream>
# include <sstream>
# include <stdio.h>
# include <ctype.h>

using namespace std;

void alfabetoEntrada(string cadena);
void alfabetoSalida(string cadena);
void conjuntoEstados(string cadena);
void estadoInicio(string cadena);
void estadoAceptable(string cadena);
void validacion(string cadena);

string* alfabetoEnter = NULL;
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
        alfabetoEntrada(cadena);
        cout<< endl;

        cout<< "Alfabeto de salida : ";
        cin>> cadena;
        alfabetoSalida(cadena);
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

void alfabetoEntrada(string cadena){
    //validacion del alfabeto que este separado correctame por comas
    bool separacionComas = false; 
    bool alfaNumerico = false;
    string caracter;
    for(int i = 0; i < cadena.length(); i++){
        if(cadena[i] == ','){
            separacionComas = true;
        }


    }
    if(separacionComas == true ){
        // ingresar alfabeto del arreglo
        alfabetoEnter = new string [cadena.length()];
        istringstream streamAlfabeto(cadena);
        int i = 0;
        while(getline(streamAlfabeto, caracter, ',')){
            alfabetoEnter[i] = caracter;

        }


        // validacion de alfabeto que sea Alfanumerico
        for(int i = 0; i <cadena.length(); i++) {
            for( int j = 0; j < alfabetoEnter[i].length(); j++ ){
                 if(isalpha(alfabetoEnter[i][j] || isdigit(alfabetoEnter[i][j]))) {
                     alfaNumerico = true;

                 }

            }
           
        }
    } else{
        cout << "El alfabeto tiene que estar separado por comas: \n";
    }

}

void alfabetoSalida(string cadena){

}

void conjuntoEstados(string cadena){

}

void estadoInicio(string cadena){

}

void estadoAceptable(string cadena){

}
void validacion(string cadena){

}
