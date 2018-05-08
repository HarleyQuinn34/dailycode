#include <stdio.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<iostream>
using namespace std;
const int PACSIZE = 20;
const float FPS = 60;
const int SCREEN_W = 500;
const int SCREEN_H = 500;
const int BOUNCER_SIZE = 60;



int main(int argc, char **argv) {
	srand(time(NULL));
	al_init();
	al_init_primitives_addon();
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP*wall = NULL;
	//ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_BITMAP*dots = NULL;
	ALLEGRO_BITMAP *image = al_load_bitmap("c.png");
	ALLEGRO_BITMAP *image2 = al_load_bitmap("d.jpg");
	ALLEGRO_BITMAP *image3 = al_load_bitmap("r.png");
	ALLEGRO_BITMAP *image4 = al_load_bitmap("s.jpeg");
	ALLEGRO_BITMAP *image5 = al_load_bitmap("t.png");
	ALLEGRO_BITMAP *image6 = al_load_bitmap("l.jpg");
	

	cout << "FLEGIN" << endl;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;

	float bouncer2_x = SCREEN_W / 4.0 - BOUNCER_SIZE / 2.0;
	float bouncer2_y = SCREEN_H / 4.0 - BOUNCER_SIZE / 2.0;
	float bouncer2_dx = -2.0, bouncer2_dy = 4.0;
	cout << "FLEGIN2" << endl;

	bool redraw = true;
	bool doexit = false;
	al_init();
	al_init_primitives_addon();

	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);
	//sample = al_load_sample("oof.wav");
	cout << "FLEGIN3" << endl;



	dots = al_create_bitmap(5, 5);
	al_set_target_bitmap(dots);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	//////////////////////
	wall = al_create_bitmap(30, 30);////////////////////wall size
	al_set_target_bitmap(wall);
	al_clear_to_color(al_map_rgb(128, 0, 0));
	/////////////////////////////////
	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	bouncer2 = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	cout << "FLEGIN4" << endl;

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 255, 0));
	al_set_target_bitmap(bouncer2);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	cout << "FLEGIN5" << endl;

	/*al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);*/
	cout << "FLEGIN6" << endl;

	int level[10][10];
	for (int i = 0; i < 10; i++) {//rows
		for (int j = 0; j < 10; j++) {//collumns

			level[i][j] = rand() % 4 + 1;//print out each grid slit
		}
	}

		//prints to console
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << level[i][j] <<" ";
			}
			cout << endl;
		}
		//draw to game wwindow
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (level[i][j] == 1)
				al_draw_filled_rectangle(i*50, j*50, i*50+50, j*50+50, al_map_rgb(128, 0, 0));
				else if (level[i][j] == 2)
					al_draw_filled_circle(i * 50+25, j * 50+25, 25 , al_map_rgb(0, 155, 255));
				else if (level[i][j] == 3)
					al_draw_filled_triangle(i * 50 , j * 50 , i * 50 , j * 50+50 , i * 50+50 , j * 50 , al_map_rgb(0, 255, 0));
				else if (level[i][j] == 4)
					al_draw_rectangle(i * 50, j * 50, i * 50 + 50, j * 50 + 50, al_map_rgb(240, 246, 155),10);
			}
			
		}
		al_flip_display();
		system("pause");
		//while (!doexit)
		//{
		//	




		//	//render section//////////////////////////////////////////////////////////////////////////////
		//	if (redraw && al_is_event_queue_empty(event_queue)) {
		//		redraw = false;

		//		al_clear_to_color(al_map_rgb(0, 0, 0));

		//		//al_draw_filled_circle(bouncer_x, bouncer_y, 15, al_map_rgb(255, 255, 0));
		//		cout << "f1";


		//		//for (int i = 0; i < 21; i++)
		//		//	for (int j = 0; j < 21; j++) {
		//		//		if (level[i][j] == 1)
		//		//			al_draw_bitmap(wall, i * 30, j * 30, 0);
		//		//		if (level[i][j] == 0)
		//		//			al_draw_bitmap(dots, i * 30 + 10, j * 30 + 10, 0);

		//		//	}
		//		al_flip_display();
		//	}
		//}


		al_destroy_bitmap(bouncer);
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
	
		
	//return 0;
}