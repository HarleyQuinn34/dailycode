#include <allegro5/allegro.h>
#include<allegro5\allegro_image.h>
#include <iostream>
#include<Windows.h>
#include <ctime>
using namespace std;


//class definition
class Invader {
private:
	int health;
	int x;
	int y;
public:
	void initInvader(int h, int xpos, int ypos);
	void drawInvader(ALLEGRO_BITMAP *image);
	void printInfo();
};


int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY *display = al_create_display(800, 800);
	//instantiate (create) the objects
	Invader i1;
	Invader i2;
	Invader i3;
	//initialize (give data)
	i1.initInvader(50, 100, 200);
	i2.initInvader(80, 300, 100);
	i3.initInvader(100, 100, 400);

	ALLEGRO_BITMAP *image = al_load_bitmap("palpatine.jpg");

	i1.drawInvader(image);
	i2.drawInvader(image);
	i3.drawInvader(image);
	al_flip_display();
	
	i1.printInfo();
	i2.printInfo();
	i3.printInfo();

	system("pause");
}
//function definitions
void Invader::initInvader(int h, int xpos, int ypos){
	 health=h;
	 x=xpos;
	 y = ypos;
}
void Invader:: drawInvader(ALLEGRO_BITMAP *image){
	al_draw_bitmap(image, x, y, 0);
}

void Invader::printInfo() {

	cout << "invader is at " << x << " , " << y << " and has a health of " << health << endl;

}