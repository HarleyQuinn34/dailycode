#include<allegro5\allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;

//GLOBALS and constants
const int WIDTH = 700;
const int HEIGHT = 700;
bool keys[] = { false, false, false, false };
enum KEYS { UP, DOWN, LEFT, RIGHT };

//the map! 10 ROWS, 100 COLUMNS!
//legend: 1 = triangle, 2= upside down triangle, 3= platform, 4= star

int map[15][15] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,
	0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

//function declaration
int collide(int x, int y, int map[15][15]);

int main()
{
	//game variables
	bool done = false;
	bool render = false;

	//allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *square = NULL;

	//player vaiables
	float square_x = 70;
	float square_y = 70;
	float dx = 0;
	float dy = 0;


	// is true if the player is on the ground
	bool isOnSolidGround = false;
	bool mayjumpagain = false; 

	//program setup
	al_init();
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//set up player
	square = al_create_bitmap(50, 50);
	al_set_target_bitmap(square);
	al_clear_to_color(al_map_rgb(255, 255, 255));


	//set up game stuff: display, event queue, timer, etc.
	display = al_create_display(WIDTH, HEIGHT);

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_set_target_bitmap(al_get_backbuffer(display));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	//GAME LOOP
	while (!done)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		//Keyboard Section////////////////////////////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)

		{
			//cout << "key pressed";
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;


			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;

				break;

			}
		}
		//TIMER SECTION/////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			//cout << "may jump is " << mayJumpAgain << ", solid ground is " << isOnSolidGround << endl;
			//player movement

			//stop falling when you hit the bottom.
			if (square_y + 32 >= HEIGHT) {
				square_y = HEIGHT - 32;
				dy = 0;
				isOnSolidGround = true;
			}
			else {
				isOnSolidGround = false;
			}

			//stop falling if you're on a platform
			if (collide(square_x, square_y, map) == 1) {
				isOnSolidGround = true;
				dy = 0;
			}

			//here's my check to stop my square from walking off the window (left, right, and top sides)
			if (square_x > WIDTH - 30)
				square_x = WIDTH - 30;
			if (square_x < 0)
				square_x = 0;
			if (square_y < 0)
				square_y = 0;


			//JUMPING
			//if the up button is pressed, increase y velocity until "jumping" runs out
			if (keys[UP] && isOnSolidGround == true && mayjumpagain == true   ) {
				dy = -10.0;
				mayjumpagain = false;
 
			}
			else
				mayjumpagain = true;

			//should we turn off left and right movement?
			//left
			if (keys[LEFT]) {
				square_x -= 4.0;

			}
			////right
			if (keys[RIGHT]) {
				square_x += 4.0;

			}

			//gravity
			//if we're not on solid ground, we should be falling (remember, positive y is "down")
			//I changed this to gravity only happens if we let go of the up key...
			if (isOnSolidGround == false) {
				dy += .5;

			}

			//put a cap on how fast you can fall
			if (dy > 8)
				dy = 8;

			render = true;
		}

		//here's where your box's coordinates are acutally updated
		square_x += dx; //adding the component velocities to the actual positions
		square_y += dy;
		//cout << "dy is " << dy << " , square_y is " << square_y << endl;


		//RENDER SECTION//////////////////////////////////////////////////////////////////////
		if (render && al_is_event_queue_empty(event_queue))
		{
			render = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			//draw map
			//remember, i is rows, j is columns
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {

					if (map[i][j] == 1)//platforms
						al_draw_filled_rectangle(j * 50, i * 50, j * 50 + 50, i * 50 + 50, al_map_rgb(80, 220, 120));

				}
			}

			//draw player
			al_draw_bitmap(square, square_x, square_y, 0);


			al_flip_display();

		}
		//cout << "game loop" << endl;
	}//end game loop

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	return 0;
}

int collide(int x, int y, int map[15][15]) {
	//cout << "checkign map slot " << (x + 30 + 5 + offset) / 30 << " , " << (y + 30) / 30 << endl;



	//check for platform collision
	if (
		//check bottom right corner
		(map[(y + 30 + 2) / 50][(x + 30) / 50] == 1)

		//check bottom left corner
		|| (map[(y + 30 + 5) / 50][(x) / 50] == 1)) {
		cout << "platform collision.";
		return 1;
	}
	else
		return 0;


}