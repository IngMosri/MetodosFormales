# include <iostream>
# include <sstream>
# include <stdio.h>
# include <ctype.h>

using namespace std;

bool alfabetoEntrada(string cadena);
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

bool alfabetoEntrada(string cadena){
    //validacion del alfabeto que este separado correctame por comas
    bool correcto = false;
    bool separacionComas = false; 
    bool alfaNumerico = false;
    bool cardinalidad = true; 
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
            i++;

        }

        cout << alfabetoEnter[0] << endl;


        // validacion de alfabeto que sea Alfanumerico

        for(int i = 0; i <cadena.length(); i++) {
            for( int j = 0; j < alfabetoEnter[i].length(); j++ ){
                 if(isalpha(alfabetoEnter[i][j] || isdigit(alfabetoEnter[i][j]))) {
                     alfaNumerico = true; 

                 }

            }
           
        }

        if(alfaNumerico == true){
            // validacion del alfabeto que sea de cardinalidad 1 
        for(int i = 0; i < cadena.length(); i ++) {
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
        if(separacionComas && alfabetoSalida && cardinalidad){
            correcto = true;
            cout<< "Alfabeto de entrada es valido: \n";
        }
        return correcto;
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
