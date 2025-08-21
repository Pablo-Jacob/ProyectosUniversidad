#include <iostream>
using namespace std;

float num1 = 0, num2 = 0;

float suma(float num1, float num2) {
	return (num1 + num2);
}

float resta(float num1, float num2) {
	return (num1 - num2);
}

float multiplicacion(float num1, float num2) {
	return (num1 * num2);
}

float division(float num1, float num2) {
	return (num1 / num2);
}

float porcentaje(float num1, float num2) {
	return ((num1 * num2) / 100);
}

void pedirNumeros() {
	cout<<"\nIngrese un numero: ";
	cin>>num1;
	cout<<"Ingrese otro numero: ";
	cin>>num2;
}

void menu() {
	char opcion = '0';
	float sumaR = 0, restaR = 0, multiplicacionR = 0, divisionR = 0, porcentajeR = 0;
	
	while(opcion != '6') {
		cout<<"1. SUMA"<<endl;
		cout<<"2. RESTA"<<endl;
		cout<<"3. MULTIPLICACION"<<endl;
		cout<<"4. DIVISION"<<endl;
		cout<<"5. PORCENTAJE"<<endl;
		cout<<"6. SALIR DEL PROGRAMA"<<endl;
		cout<<"Digite una opcion: ";
		cin>>opcion;
		
		switch(opcion) {
			case '1':
				pedirNumeros();
				sumaR = suma(num1, num2);
				printf("\nEl resultado de la suma es: %.2f\n", sumaR);
				break;
				
			case '2':
				pedirNumeros();
				restaR = resta(num1, num2);
				printf("\nEl resultado de la resta es %.2f\n", restaR);
				break;
				
			case '3':
				pedirNumeros();
				multiplicacionR = multiplicacion(num1, num2);
				printf("\nEl resultado de la multiplicacion es: %.2f\n", sumaR);
				break;
				
			case '4':
				pedirNumeros();
				divisionR = division(num1, num2);
				printf("\nEl resultado de la division es: %.2f\n", divisionR);
				break;
				
			case '5':
				cout<<"\nIngrese un numero: ";
				cin>>num1;
				cout<<"Ingrese el porcentaje que desea calcular: ";
				cin>>num2;
				porcentajeR = porcentaje(num1, num2);
				printf("\nEl %.2f por ciento de %.2f es: %.2f\n", num2, num1, porcentajeR);
				break;
				
			case '6':
				cout<<"\nSaliendo del programa...";
				break;
				
			default:
				cout<<"\nOpcion no valida, vuelva a intentarlo"<<endl;
				break;
		}
		cout<<"\n";
	}
}

int main() {
	menu();
	
	return 0;
}
