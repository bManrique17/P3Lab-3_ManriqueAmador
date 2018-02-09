#include <iostream>
#include <string>

using namespace std;

int menu();

int main(){
	cout<<"**LAB_3 Manrique Amador**"<<endl;
	char respuesta = 's';
	do{
		switch(menu()){
			case 1:{
		       	}
		       	break;
			case 2:{
			}
		        break;
			case 3:{
		       	}
  		        break;
			default:
			break;
		}
		cout<<"Desea continuar[S/N]: ";
		cin>>respuesta;
	}while(respuesta!='r' || respuesta!='R');
}

int menu(){
	cout<<"(1)Ejercicio 1"<<endl<<
		"(2)Ejercicio 2"<<endl<<
		"(3)Ejercicio 3"<<endl<<
		"->Ingrese su opcion: ";
	int respuesta = 0;
	cin>>respuesta;
	return respuesta;
}
