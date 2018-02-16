#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include<iostream>
using namespace std;

//declaration
bool PixelCollision(int x1, int y1, int x2, int y2);
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 1;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum MYKEYS2 {
	KEY_W, KEY_A, KEY_S, KEY_D
};
int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	//starting positions of players
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer2_x = 100;
	float bouncer2_y = 100;
	bool key[4] = { false, false, false, false };
	bool key2[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	cout << "flag2" << endl;
	al_init();
	al_install_audio();
	al_init_acodec_addon;
	al_install_keyboard();
	al_reserve_samples(1);

	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	bouncer2 = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer2);

	al_clear_to_color(al_map_rgb(150, 150, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	cout << "flag1" << endl;
	while (!doexit)//game loop
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) { //physics engine!
			if (key[KEY_UP] && bouncer_y >= 4.0) {
				bouncer_y -= 1.0;
			}

			if (key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
				bouncer_y += 1.0;
			}

			if (key[KEY_LEFT] && bouncer_x >= 4.0) {
				bouncer_x -= 1.0;
			}

			if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
				bouncer_x += 1.0;
			}

			if (key2[KEY_W && bouncer2_y >= 4.0]) {
				bouncer2_y -= 3.0;
			}

			if (key2[KEY_A] && bouncer2_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
				bouncer2_x -= 3.0;
			}

			if (key2[KEY_S] && bouncer2_x >= 4.0) {
				bouncer2_y += 3.0;
			}

			if (key2[KEY_D] && bouncer2_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
				bouncer2_x += 3.0;
			}

			if (PixelCollision(bouncer_x, bouncer_y, bouncer2_x, bouncer2_y) == true) {
				cout << "boi" << endl;
				//do funny stuff here
				sample = al_load_sample("oof.wav");
				al_play_sample(sample, 2, 0.0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

			}





			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;


			case ALLEGRO_KEY_W:
				key2[KEY_W] = true;
				break;

			case ALLEGRO_KEY_A:
				key2[KEY_A] = true;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = true;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = true;
				break;

			}
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;

				//add cases for WASD
			case ALLEGRO_KEY_W:
				key2[KEY_W] = false;

			case ALLEGRO_KEY_A:
				key2[KEY_A] = false;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = false;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = false;
				break;


			case ALLEGRO_KEY_4:
				doexit = true;
				break;






			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_bitmap(bouncer2, bouncer2_x, bouncer2_y, 0);
			al_flip_display();
		}
	}
	cout << "end game loop" << endl;
	al_destroy_bitmap(bouncer);
	al_destroy_bitmap(bouncer2);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_sample(sample);
	al_destroy_event_queue(event_queue);
	return 0;
}


bool PixelCollision(int x1, int y1, int x2, int y2) {


	if (x1 == x2 && y1 == y2)
		return true;
	else
		return false;
}

