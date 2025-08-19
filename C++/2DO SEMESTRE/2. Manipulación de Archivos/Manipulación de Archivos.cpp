#include <iostream>
#include <stdio.h>
using namespace std;

struct Registros {
    int cod_producto;
    char nombre[100];
    char fecha_ingreso[20];
    char fecha_caducidad[20];
    char descripcion[200];
    int cantidad;
    float precio;
};

Registros producto;
Registros lectura;

void agregar() {
    FILE *archivo = fopen("productos.dat", "ab");
	
	if(archivo == NULL) cout<<"\nError al abrir el archivo"<<endl;
	
	cout<<"\nIngrese el codigo del producto que desea agregar: ";
	cin>>producto.cod_producto;
	cin.ignore();
	cout<<"Ingrese el nombre del producto: ";
	cin.getline(producto.nombre, 100);
	cout<<"Ingrese la fecha de ingreso (dd/mm/aaaa): ";
    cin.getline(producto.fecha_ingreso, 20);
	cout<<"Ingrese la fecha de caducidad (dd/mm/aaaa): ";
	cin.getline(producto.fecha_caducidad, 20);
	cout<<"Ingrese la descripcion: ";
	cin.getline(producto.descripcion, 200);
	cout<<"Ingrese la cantidad en inventario: ";
	cin>>producto.cantidad;
	cout<<"Ingrese el precio del producto: ";
	cin>>producto.precio;
	
	fwrite(&producto, sizeof(Registros), 1, archivo);
    fclose(archivo);
	
	cout<<"\nProducto agregado correctamente"<<endl;
}

void mostrar() {
    FILE *archivo = fopen("productos.dat", "rb");

    if(archivo == NULL) cout<<"\nError al abrir el archivo"<<endl;
    
    int numProducto = 1;
	
	cout<<"\nLista de Productos:"<<endl;
	
	while(fread(&lectura, sizeof(Registros), 1, archivo)) {
		if(lectura.cod_producto > 0) {
			cout<<"----- No. Producto: "<<numProducto<<" -----"<<endl;
			cout<<"Codigo: "<<lectura.cod_producto<<endl;
			cout<<"Nombre: "<<lectura.nombre<<endl;
			cout<<"Fecha de ingreso (dd/mm/aaaa): "<<lectura.fecha_ingreso<<endl;
	        cout<<"Fecha de caducidad (dd/mm/aaaa): "<<lectura.fecha_caducidad<<endl;
			cout<<"Descripcion: "<<lectura.descripcion<<endl;
			cout<<"Cantidad: "<<lectura.cantidad<<endl;
			cout<<"Precio: "<<lectura.precio<<endl;
			numProducto++;
		}
	}
	fclose(archivo);
	cout<<"\n";
}

void modificar() {
    int codigo = 0;
	bool encontrado = false;
	
	cout<<"\nIngrese el codigo del producto que desea modificar: ";
	cin>>codigo;
	cin.ignore();
	
	FILE *archivo = fopen("productos.dat", "rb+");  //Apertura en modo lectura/escritura
	
	if(archivo == NULL) cout<<"\nNo se pudo abrir el archivo"<<endl;
	
	while(fread(&lectura, sizeof(Registros), 1, archivo)) {
        if(lectura.cod_producto == codigo) {
            encontrado = true;
			cout<<"\nProducto encontrado. Datos actuales:"<<endl;
			cout<<"Nombre: "<<lectura.nombre<<endl;
			cout<<"Fecha de ingreso (dd/mm/aaaa): "<<lectura.fecha_ingreso<<endl;
            cout<<"Fecha de caducidad (dd/mm/aaaa): "<<lectura.fecha_caducidad<<endl;
			cout<<"Descripcion: "<<lectura.descripcion<<endl;
			cout<<"Cantidad: "<<lectura.cantidad<<endl;
			cout<<"Precio: "<<lectura.precio<<endl;
			
			char respuesta = '0';
			
			cout<<"\n¿Desea modificar este producto? (S/N): ";
			cin>>respuesta;
			cin.ignore();
			
			if((respuesta == 's') || (respuesta == 'S')) {
				char opcion = '0';
				
				cout<<"\n----- Opciones para modificar -----"<<endl;
				cout<<"1. Codigo del producto"<<endl;
				cout<<"2. Nombre"<<endl;
				cout<<"3. Fecha de ingreso"<<endl;
				cout<<"4. Fecha de caducidad"<<endl;
				cout<<"5. Descripcion"<<endl;
				cout<<"6. Cantidad"<<endl;
				cout<<"7. Precio"<<endl;
				cout<<"8. Cancelar y regresar al menu principal"<<endl;
				cout<<"Digite una opcion: ";
				cin>>opcion;
				
				switch(opcion) {
					case '1':
						cout<<"\nIngrese el nuevo codigo del producto: ";
						cin>>lectura.cod_producto;
						cin.ignore();
						break;
						
					case '2':
						cout<<"\nIngrese el nuevo nombre del producto: ";
						cin.getline(lectura.nombre, 100);
						break;
						
					case '3':
						cout<<"\nIngrese la nueva fecha de ingreso (dd/mm/aaaa): ";
						cin.getline(lectura.fecha_ingreso, 20);
						break;
						
					case '4':
						cout<<"\nIngrese la nueva fecha de caducidad (dd/mm/aaaa): ";
						cin.getline(lectura.fecha_caducidad, 20);
						break;
						
					case '5':
						cout<<"\nIngrese la nueva descripcion: ";
						cin.getline(lectura.descripcion, 200);
						break;
						
					case '6':
						cout<<"\nIngrese la nueva cantidad en inventario: ";
						cin>>lectura.cantidad;
						cin.ignore();
						break;
						
					case '7':
						cout<<"\nIngrese el nuevo precio del producto: ";
						cin>>lectura.precio;
						cin.ignore();
						break;
						
					case '8':
						break;
						
					default:
						cout<<"Opcion no valida"<<endl;
						fclose(archivo);
						break;
				}
				//Mover el puntero de archivo a la posición correcta antes de escribir
				fseek(archivo, (long)(-sizeof(Registros)), SEEK_CUR);
				fwrite(&lectura, sizeof(Registros), 1, archivo);
				
				cout<<"\nProducto modificado correctamente"<<endl;
			}
        }
    }
	if(!encontrado) {
        cout<<"\nNo se encontraron datos para el codigo ingresado"<<endl;
    }
	fclose(archivo);
}

int main() {
    char opcion = '0';
    
    while(opcion != '4') {
    	cout<<"----- Menu de Gestion de Inventario -----"<<endl;
		cout<<"1. Agregar Producto"<<endl;
		cout<<"2. Mostrar Productos"<<endl;
		cout<<"3. Modificar Producto"<<endl;
		cout<<"4. Salir del programa"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		cin.ignore();

        switch(opcion) {
            case '1':
                agregar();
                break;
				
			case '2':
                mostrar();
                break;
				
			case '3':
                modificar();
                break;
				
			case '4':
                cout<<"Saliendo del programa...";
                break;
				
			default:
                cout<<"Opcion no valida, vuelva a intentarlo"<<endl;
                break;
        }
        cout<<"\n";
    }
	return 0;
}
