# include <iostream>
# include <sstream>
# include <stdio.h>
# include <ctype.h>
# include <iomanip>

using namespace std;

bool alfabetoEntrada(string cadena);
bool alfabetoSalida(string cadena);
bool conjuntoEstados(string cadena);
bool estadoInicio(string cadena);
bool estadoAceptable(string cadena);
bool validacion(string cadena);
void CreateMatrixV();
void CreateMatrixT();

string* alfabetoEnter= NULL;
string* alfabetoExit = NULL;
string* estados = NULL;
string* estadosAceptacion= NULL;
string estadoInicial;
string** matrixv = NULL; 
string** matrixt = NULL;
int numerosEstados;
int numeroalfabeto;
int estadoNumericoAceptable;

int main() {

    cout<< setw(-40) << "Morgoth Systems" << setw(20) << "||Autor: Cristian Alatorre " << setw(10) << "||Autómata  finito determinista: AFD " << endl; 

    cout<< "----------------------\n\n\n";
    cout<< "Automata Finito Determinista   \n";
    cout<< "Por favor indique el tipo de funcion\n";
    cout<< "1. AFD Validacion\n";
    cout<< "2. AFD Traduccion\n";
    cout<< "3.Terminar Programa\n"; 
    cout<< "Funcion:";
    
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

       

        cout<< "conjunto de Estados: ";
        cin>> cadena;
        while(!conjuntoEstados(cadena)){
            cout<< "conjunto de Estados: ";
            cin>> cadena;

        }
        cout<< endl;

        cout<< "Estado de inicio : ";
        cin>> cadena;
        while(!estadoInicio(cadena)){
            cout<< "Estado de inicio : ";
            cin>> cadena;

        }
        cout<< endl;

        cout<< "Estado de aceptacion  : ";
        cin>> cadena;
        while(!estadoAceptable(cadena)){
            cout<< "Estado de aceptacion  : ";
            cin>> cadena;
        }
        cout<< endl;

        CreateMatrixV();

        
            int finishValidation;
            do{
                cout<< "Palabra a validar   : ";
                cin>> cadena;
                while(!validacion(cadena)){
                cout<< "Palabra a validar   : ";
                cin>> cadena;
 
            }
                cout << "Deseas validar otra palabra? si [1]-- no [2]:";
                cin >> finishValidation; 
        }while (finishValidation != 2);
                cout<< endl;


        delete [] alfabetoEnter;
        alfabetoEnter = 0;
        delete [] alfabetoExit;
        alfabetoExit = 0;
        delete [] estados;
        estados = 0; 
        delete [] estadosAceptacion;
        estadosAceptacion = 0;
    }
    // funciones de traduccion 
    if(funcion == 2){
        string cadena;

         cout<< "Alfabeto de salida : ";
        cin>>cadena;
        while(!alfabetoSalida(cadena)){
            cout<< "Alfabeto de salida : ";
            cin>> cadena;

        }
        cout<< endl;
        

    }
    // funcion para salir 
    if(funcion != 1 && funcion != 2) {


    }

return 0;
}

void CreateMatrixV(){
    bool correcto = false;
    matrixv = new string *[numerosEstados];
    for(int i = 0; i < numerosEstados; i++){
        matrixv[i] = new string [numeroalfabeto];
    }

    cout<<"ingresar tabla de valadacion:";
    cout<< "Estado" << setw(29) << "Alfabeto" << setw(22) << "Transicion" << endl; 
    cout<< "____________________________________________________________";
    for(int i = 0; i < numerosEstados; i++){
        for(int j = 0; j <numeroalfabeto; j++){
            
            do{
                cout<< estados[i] << setw(30) << alfabetoEnter[j] << setw(30) << "Transicion: ";
                cin >> matrixv[i][j];
                for(int k = 0; k < numerosEstados; k++){
                    if(matrixv[i][j] == estados[k]){
                        correcto = true;
                        break;

                    }else {
                        
                        correcto = false;
                    }
                }
                if(!correcto) cout << "\n Estados no valido. \n";  

            }while(!correcto);


        }
    }
     
}


bool alfabetoEntrada(string cadena){
    cout<< setw(-40) << "Morgoth Systems" << setw(20) << "||Autor: Cristian Alatorre " << setw(10) << "||Autómata  finito determinista: AFD " << endl; 

    cout<< "----------------------\n\n\n";
    //validacion del alfabeto que este separado correctame por comas
    numeroalfabeto = cadena.length()/2+1;
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
        alfabetoEnter = new string [numeroalfabeto];
        istringstream streamAlfabeto(cadena);
        int i = 0;
        while(getline(streamAlfabeto, caracter, ',')) {
            alfabetoEnter[i] = caracter;
            i++;

        }
            // validacion de alfabeto que sea Alfanumerico
        for(int i = 0; i < numeroalfabeto; i++){
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
        for(int i = 0; i < numeroalfabeto; i ++) {
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
    cout<< setw(-40) << "Morgoth Systems" << setw(20) << "||Autor: Cristian Alatorre " << setw(10) << "||Autómata  finito determinista: AFD " << endl; 

    cout<< "----------------------\n\n\n";
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
    cout<< setw(-40) << "Morgoth Systems" << setw(20) << "||Autor: Cristian Alatorre " << setw(10) << "||Autómata  finito determinista: AFD " << endl; 

    cout<< "----------------------\n\n\n";
    string estado;
    numerosEstados = (int)cadena.length()/2+1;
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
        estados = new string[numerosEstados];
        istringstream streamAlfabeto(cadena);
        int i = 0;
        while(getline(streamAlfabeto, estado, ',')){
            estados[i] = estado;
            i++;

        }
        //Verufucacion alfanumerica
        
        for(int i = 0; i < numerosEstados; i++){
            for(int j = 0; j < estados[i].length(); j++){
                if(isalpha(estados[i][j]) || isdigit(estados[i][j])) {
                    alfaNumerico = true;
              } else {
                    alfaNumerico = false;
                    break;
                }


            }
        }
        if(alfaNumerico){

            //Verificacion de carninalidad de 10 
            for(int i = 0; i < numerosEstados; i++){
                if(estados[i].length() <= 10){
                    cardinalidad = true;

                } else{
                    cardinalidad = false;
                    break;
                }

            }

            if(!cardinalidad) cout << "LOs estados deben de ser menor o igual a 10 caracteres. \n\n";

        
        } else{
            cout <<"Los estados deben ser alfanumericos. \n\n";

        } 
        
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
     cout<< setw(-40) << "Morgoth Systems" << setw(20) << "||Autor: Cristian Alatorre " << setw(10) << "||Autómata  finito determinista: AFD " << endl; 

    cout<< "----------------------\n\n\n";
     bool correcto = false;
     bool equals = false;
     bool multiples = true;

     for(int i = 0; i< cadena.length(); i++){
         if(cadena[i]== ','){
             cout<< " SOlo puede existir un estado de inicio \n\n";
             return false;
         }
     }
     for (int i = 0; i < numerosEstados; i++){
         if(cadena == estados[i]){
             equals = true;
             break;
     }else {
         equals = false;
     }

         }
    if(!equals){
        cout<<"EL estado inicial debe ser igual a uno de los estados de AFD \n\n";
        correcto = false;
    }else {
        cout<< "el estado de inicial es valido. \n\n";
        estadoInicial = cadena;
        correcto = true;
    }






     return correcto;

}

bool estadoAceptable(string cadena){
    cout<< setw(-40) << "Morgoth Systems" << setw(20) << "||Autor: Cristian Alatorre " << setw(10) << "||Autómata  finito determinista: AFD " << endl; 

    cout<< "----------------------\n\n\n";
    bool correcto =false;
    bool equals = false;
    bool multipleStatesTrue = true;
    string estado;

    //Verificacion de cuantos estados de aceptacion son 
    for(int i = 0; i < cadena.length(); i++){
        if(cadena[i] == ','){
            multipleStatesTrue =true;
    }
        
        }
        if(multipleStatesTrue){
            estadoNumericoAceptable = (int)cadena.length() / 2+1;
            //rompemos la cadena en varios estados de aceptacion 
            istringstream streamAlfabeto(cadena);
            estadosAceptacion = new string[cadena.length()/2+1];
            int i = 0;
            while(getline(streamAlfabeto,estado,',')) {
                estadosAceptacion[i] = estado;
                i++;

            }


            //verificamos los estados de aceptacion sean de los mismos estados ingresados anteorimente para el AFD
            for(int i = 0; i < numerosEstados; i++){
                for(int j = 0; j < cadena.length() /2+1; j++){
                    if(estadosAceptacion[j] == estados[i]){
                        equals = true;
                        break;

                    }else{
                        equals = false;
                    }

                }
            }
            if(!equals) cout<< "Los estados de aceptacion deben pertenercer a los estados del AFD. \n\n"; 

        }else {
            estadoNumericoAceptable = 1;
            for (int i =0; i < numerosEstados; i++ ){
        if(cadena == estados[i]){
            estadosAceptacion = new string[1];
            estadosAceptacion[0] = cadena;
            equals = true; 
            break;

        }
    
        }
    }
    if(!equals){
        cout<< "Los estados de aceptacion debe ser igual a los estados ingreesados ppara el AFD. \n\n";
    }else {
        cout<< " Estados de aceptacion son validos. \n\n";
        correcto = true;
    }
    return correcto;

}
bool validacion(string cadena){
    cout<< setw(-40) << "Morgoth Systems" << setw(20) << "||Autor: Cristian Alatorre " << setw(10) << "||Autómata  finito determinista: AFD " << endl; 

    cout<< "----------------------\n\n\n";
    bool validacionPalabra = false;
    string position = estadoInicial;
    bool correcto = false;
    int x = 0;
    int y =0;

    for(int i = 0; i < cadena.length(); i++){
        correcto = false;
        for(int j = 0; j < numerosEstados; j++){

            if(position == estados[j]){
                x = j;
                correcto = true;
                break;
            }
        }
        for (int k=0; k< numeroalfabeto; k++ ){
            if(cadena[i] == alfabetoEnter[k][0]){
                y = k;
                correcto = true;
                break;
            }
            
        }
        if(!correcto) {
            cout<< "Palabra contiene simboloes que no estan en el alfabeto de entrada.\n\n";
        }else{
                position = matrixv[x][y];
        }
    }   
                
        for(int i = 0; i < estadoNumericoAceptable; i++){
            if(position == estadosAceptacion[i]){
                validacionPalabra = true;
                break;
            }else {
                validacionPalabra = false;
            }

        }


        cout << "La palabra" << cadena << "es ";
        if(validacionPalabra){
            cout << "Palabra valida\n";
        } else {
            cout << "Palabra invalida\n";
        }

    
    return correcto;

}
