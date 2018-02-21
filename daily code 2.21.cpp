#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<iostream>
using namespace std;
int main() {
al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY *display = al_create_display(500, 500);
	ALLEGRO_COLOR electricblue = al_map_rgb(44, 117, 255);
	float points[8] = { 0, 0, 400, 100, 50, 200, 500, 500 };
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_spline(points, electricblue, 1.0);
	al_flip_display();
	al_rest(100);
	al_destroy_display(display);


}