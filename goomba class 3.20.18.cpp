#include <allegro5/allegro.h>
#include<allegro5\allegro_image.h>
#include <iostream>
using namespace std;


//class definition
class goomba {
private:
	int xpos;
	int ypos;
	bool isdead;
	ALLEGRO_BITMAP*image;
	ALLEGRO_BITMAP*image2;
public:
	void initpotato(int x, int y, bool dead, ALLEGRO_BITMAP*image, ALLEGRO_BITMAP*image2);
	void drawpotato();

};
class koopa {
private:
	int xpos;
	int ypos;
	bool isdead1;
	ALLEGRO_BITMAP*image3;
	ALLEGRO_BITMAP*image4;
public:
	void initturtle(int x, int y, bool dead, ALLEGRO_BITMAP*image, ALLEGRO_BITMAP*image2);
	void drawturtle();

};

int main() {
	cout << "flag 3" << endl;
	al_init();
	al_init_image_addon();
	ALLEGRO_BITMAP *image = al_load_bitmap("g.png");
	ALLEGRO_BITMAP *image2 = al_load_bitmap("d.jpg");
	ALLEGRO_BITMAP *image3 = al_load_bitmap("r.png");
	ALLEGRO_BITMAP *image4 = al_load_bitmap("k.jpeg");
	cout << "flag 2.5" << endl;
	ALLEGRO_DISPLAY *display = al_create_display(800, 800);
	//al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//instantiate (create) the objects
	goomba i1;
	goomba i2;
	goomba i3;
	koopa j1;
	koopa j2;
	koopa j3;
	cout << "flag 2" << endl;
	//initialize (give data)
	i1.initpotato(25, 25, true, image, image2);
	i2.initpotato(500, 500, false, image, image2);
	i3.initpotato(250, 350, true, image, image2);
	j1.initturtle(25, 500, true, image3, image4);
	j2.initturtle(500, 50, false, image3, image4);
	j3.initturtle(250, 100, true, image3, image4);
	cout << "falg1" << endl;
	if (image3 == NULL)
		cout << "image3 wasn't loaded!" << endl;
	if (image4 == NULL)
		cout << "image4 wasn't loaded!" << endl;
	i1.drawpotato();
	i2.drawpotato();
	i3.drawpotato();
	j1.drawturtle();
	j2.drawturtle();
	j3.drawturtle();
	cout << "flag a";
	al_flip_display();



	system("pause");


}
//function definitions
void goomba::initpotato(int x, int y, bool dead, ALLEGRO_BITMAP*bitmap, ALLEGRO_BITMAP*bitmap2) {

	xpos = x;
	ypos = y;
	isdead = dead;
	 image = bitmap;
	 image2 = bitmap2;
	//image 1
	//image 2

}
void goomba::drawpotato() {
	cout << "beginning drawpotato";
	if (isdead == true)
		al_draw_bitmap(image, xpos, ypos, 0);
	else
		al_draw_bitmap(image2, xpos, ypos, 0);
}
void koopa::initturtle(int x, int y, bool dead, ALLEGRO_BITMAP*bitmap3, ALLEGRO_BITMAP*bitmap4) {
	
	xpos = x;
	ypos = y;
	isdead1 = dead;
	image3 = bitmap3;
	image4 = bitmap4;
	//image 1
	//image 2

}
void koopa::drawturtle() {
	cout << "121beginning drawpotato";
	if (isdead1 == true)
		al_draw_bitmap(image3, xpos, ypos, 0);
	else
		al_draw_bitmap(image4, xpos, ypos, 0);
}