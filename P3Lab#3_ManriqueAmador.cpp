#include <iostream>
#include <string>
#include <vector>

using namespace std;

int menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
int* generarArreglo(int);
void liberarMemoria(int**&);
void imprimirMatriz(int**);
int parsearNumero(char);
bool validarFecha(string);

int main(){
	cout<<"**LAB_3 Manrique Amador**"<<endl;
	char respuesta = 's';
	do{
		switch(menu()){
			case 1:{
		       	}
		       	break;
			case 2:{
				ejercicio2();
			}
		        break;
			case 3:{
				ejercicio3();
		       	}
  		        break;
			default:
			break;
		}
		cout<<"Desea continuar[S/N]: ";
		cin>>respuesta;
	}while(respuesta=='s' || respuesta=='s');
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

int* generarArreglo(int size){
	int* matriz = new int[size];
	return matriz;
}

/*
void ejercicio1(){
	cout<<"\n*Ejercicio 1"<<endl;
	cout<<"Ingrese el tamaño del arreglo: ";
	int size = 0,medianaPP = 0;
	cin>>size;
	int* arregloPrincipal = generarArreglo(size);
	int* arregloTemporal;
	for(int i=0 ; i<size; i++){
                int random = rand()%100+1;
                arregloPrincipal[i] = random;
        }
	if(size<5)
		//medianaPP = arregloMenor();
	else{
		for(int i=0 ; i<size/5 ; i++){
			arregloTemporal = generarArreglo(5);
			for(int j=0 ; j<5 ; j++){
			
			}
		}
	}
}
*/
int parsearNumero(char letra){
	switch(letra){
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
                        return 3;
		case '4':
                        return 4;
		case '5':
                        return 5;
		case '6':
                        return 6;
		case '7':
		        return 7;
		case '8':
                        return 8;
		case '9':
			return 9;
		default:
			return 0;
	}
}

void ejercicio2(){
	cout<<"\n*Ejercicio 2"<<endl;
	cout<<"Ingrese la cadena de numero: ";
	string cadena;
	cin>>cadena;

	int** matriz = new int*[12];
	matriz[0] = new int[4];
	matriz[0][0] = parsearNumero(cadena[0]);
	matriz[0][1] = parsearNumero(cadena[1]);
	matriz[0][2] = parsearNumero(cadena[2]);
	matriz[0][3] = parsearNumero(cadena[3]);

	for(int i=1 ; i<=12 ; i+=3){
		matriz[i] = new int[4];
		matriz[i][0] = matriz[i-1][1];
		matriz[i][1] = matriz[i-1][0];
		matriz[i][2] = matriz[i-1][2];
		matriz[i][3] = matriz[i-1][3];
		
		matriz[i+1] = new int[4];
		matriz[i+1][0] = matriz[i][0];
		matriz[i+1][1] = matriz[i][2];
		matriz[i+1][2] = matriz[i][1];
		matriz[i+1][3] = matriz[i][3];
		
		matriz[i+2] = new int[4];
		matriz[i+2][0] = matriz[i][0];
                matriz[i+2][1] = matriz[i][1];
                matriz[i+2][2] = matriz[i][3];
                matriz[i+2][3] = matriz[i][2];
	}
	imprimirMatriz(matriz);
	liberarMemoria(matriz);
}

void imprimirMatriz(int**matrix){
	for (int i = 0; i<12 ; i++){
		for(int j = 0; j<4 ; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void liberarMemoria(int**& matrix){
	for(int i = 0; i<12 ; i++){
		delete [] matrix[i];
		matrix[i] = NULL;
	}
	delete [] matrix;
}

void ejercicio3(){
	vector <string> fechas;
	cout<<"**Ejercicio 3"<<endl;
	cout<<"->Ingrese su fecha: ";
	string fecha;
	cin>>fecha;
	if(validarFecha(fecha)){
		cout<<"drogas";
	}else{
		cout<<"Fecha incorrecta"<<endl;
	}
}

bool validarFecha(string fecha){
	int imes,idia,iano;
	string mes,dia,ano;
	if(fecha.size() != 8)
		return false;
	ano = fecha.substr(0,4);
	mes = fecha.substr(4,6);
	dia = fecha.substr(6,7);

	iano = parsearNumero(ano[0])*1000 + parsearNumero(ano[1])*100 + parsearNumero(ano[2])*10 + parsearNumero(ano[3]);

	imes = parsearNumero(mes[0])*10 + parsearNumero(mes[1]);

	idia = parsearNumero(dia[0])*10 + parsearNumero(dia[1]);
	
	if(iano>2018 && imes>2 && idia>9)
		return false;

	if(imes>12 || idia>31)
		return false;

	if(iano%4 != 0 && idia==29)
		return false;
	return 0;		
}




