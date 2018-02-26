#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>

int main() {
	ALLEGRO_DISPLAY *gamewindow = NULL;

	al_init();
	al_init_primitives_addon();
	gamewindow = al_create_display(1080,1080);
	al_set_window_position(gamewindow, 200, 200);
	while (1) {
		//al_clear_to_color(al_map_rgb(rand(), rand(), rand()));
		al_draw_filled_rectangle(rand()%800, rand() % 800, rand() % 800, rand() % 800, al_map_rgb(rand() % 800, rand() % 800, rand() % 800));
		al_draw_triangle(rand() % 800, rand() % 800, rand() % 800, rand() % 800, rand() % 800, rand() % 800, al_map_rgb(rand() % 800, rand() % 800, rand() % 800), rand()%400);
		al_draw_filled_circle(rand() % 800, rand() % 800, rand() % 800, al_map_rgb(rand() % 800, rand() % 800, rand() % 800));
		al_rest(.1);
		
		al_flip_display();
		//system("pause");
	}
	al_destroy_display(gamewindow);
}