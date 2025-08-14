#include <graphics.h>

int main() {
	#define tiempo 150
	//Iniciar ventana para mostrar imagenes
	initwindow(850, 450, "Descansa Pantallas", 500, 250);
	Sleep(tiempo);
	
	//Mostrar imagen almacenada en una carpeta
	readimagefile("assets\\images\\Spider-Man chikito.jpg", 0, 0, 80, 80);
	
	//Crear variable para almacenar imagen
	void *imagen1;
	imagen1 = malloc(imagesize(0, 0, 80, 80));
	
	//Capturar la imagen en una variable
	getimage(0, 0, 80, 80, imagen1);
	
	//Mostrar imagen en cordenadas x,y
	for(int y=0;y<=450;y+=80) {
		for(int x=0;x<=850;x+=80) {
			putimage(x, y, imagen1, 0);
			Sleep(tiempo);
		}
	}
	//Mostrar una imagen color negro
	Sleep(tiempo);
	void *imagen2;
	imagen2 = malloc(imagesize(770, 370, 850, 450));
	
	readimagefile("assets\\images\\Color_negro.jpg", 770, 370, 850, 450);
	getimage(770, 370, 850, 450, imagen2);
	
	for(int y=370;y>=-80;y-=80) {
		for(int x=770;x>=-80;x-=80) {
			putimage(x, y, imagen2, 0);
			Sleep(tiempo);
		}
	}
	return 0;
}
