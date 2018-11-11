//Jesus Steven Medrano Carballo
//MC18055

//implemento con cola

#include <iostream> //se usa la libreria estandar para operaciones de entrada y salida
#include <stdio.h>// se usa para las declaraciones de funciones de la biblioteca
#include <stdlib.h>// se usa para ejecutar subprocesoslibreria standar
#include <conio.h> // consola de entrada y salida

using namespace std;

struct Nodo{	
	int dato;
	struct Nodo *siguiente;
};

//prototipos de funcion
void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *); //para retornar true o false
void suprimirCola(Nodo *&, Nodo *&, int &);

int main(){
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	int dato;
	int i;
	i = 1;
	int menu;
	int opc;
	
	while(menu != 5){
cout<<"\n\t\t BIENVENID@S\n\n"; //texto de bienvenida	
cout<<"\n\t IMPLEMENTACION DE COLAS\n\n";
cout<<" 1. GENERAR NUMERO                          "<<endl;
cout<<" 2. LLAMAR NUMERO                           "<<endl;
cout<<" 3. ATENDIENDO NUMERO                       "<<endl;
cout<<" 4. ELIMINANDO NUMERO                       "<<endl;
cout<<" 5. SALIR                                   "<<endl;

cout<<"\n INGRESE OPCION: "<<endl;
cin>>opc;

//usar un condicional multiple
	switch (menu)
	{
			case 1:
				cout<< "\n \n numero 1 \n\n";
				break;
			
			case 2:
				cout<< "\n\n llamando numero siguiente \n\n";
				break;
				
		    case 3:
				cout<< "\n\n procesando numero \n\n";
				break;
				
			case 4:
				cout<< "\n\n  numero eliminado \n\n";
				break;
				
			case 5:
				cout<< "Seguro que quieres salir??   SI o NO \n";
				cout<< "\n 1- SI";
				cout<< "\n 2- NO \n\n";
				cin >> opc;
				cout<< "\n \n";
				if (opc == 1)
				{
					return 0;
				}
				else
				{
					return main();
				}
				break;
			default:
				return main();
				break;
		}
}

	do{ //utilizamos do while para el rango en que queremos que se repita la introduccion de datos
	cout<<"digite un numero "<<i<<endl;
	i++; // aumenta el iterador de uno en uno
	cin>>dato;
	insertarCola(frente, fin, dato);//llamado de la funcion
}while(i<=5);
	
	//suprimir los elementos de la cola
	cout<<"\n eliminando cola: ";
	while(frente != NULL){
		suprimirCola(frente, fin, dato);
		if(frente != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<" . ";
		}
	}
	system("pause"); //hace una pausa antes de salir 
	getch();
	return 0;
}

//funcion para insertar numeros en cola
void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){ //para saber sila cola esta vacia
		frente = nuevo_nodo;	
	}
	else{
		
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	
	cout<<"\t elemento "<<n<<" insertado a cola correctamente\n";
}

//funcion para determinar si la cola esta vacia o no
bool cola_vacia(Nodo *frente){ //esta funcion va a devolver si es true o false
	return(frente == NULL)? true : false;	
}

//la funcion para suprimir elementos de la cola
void suprimirCola(Nodo *&frente, Nodo *&fin, int &n){
	
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}

