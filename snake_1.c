#include<stdio.h>
#include<SDL2/SDL.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#define WIDTH 1200
#define HEIGHT 900
#define COLOR_GRID 0xffffffff
#define COLOR_BACK 0xf
#define COLOR_SNAKE 0x00ff00
#define BLOCK 50
#define COLOR_FOOD 0xff0000

int snake_x[1000];
int snake_y[1000];
int food_x;
int food_y;
int n = 1; //number of block
int dir_x = 1;
int dir_y = 0;
void snake(SDL_Surface* surface,int x, int y){
	SDL_Rect block = (SDL_Rect){x,y,BLOCK,BLOCK};
	SDL_FillRect(surface, &block, COLOR_SNAKE);
}

void  food(SDL_Surface* surface){
	SDL_Rect fd = (SDL_Rect){food_x * 50 ,food_y * 50,BLOCK,BLOCK};
	SDL_FillRect(surface, &fd, COLOR_FOOD);
}

void grid(SDL_Surface* surface){
    //side of block 50,50.
    for(int i = 0; i < HEIGHT+1; i+=50){
	SDL_Rect grid_hor = (SDL_Rect){0,i,WIDTH,1};
	SDL_FillRect(surface, &grid_hor, COLOR_GRID);
    }
    for(int i = 0; i < WIDTH+1; i+=50){
	SDL_Rect grid_ver = (SDL_Rect){i,0,1,HEIGHT};
	SDL_FillRect(surface, &grid_ver, COLOR_GRID);
    }
}

int  main(){

   	SDL_Window *window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_Rect back = (SDL_Rect){0,0,WIDTH,HEIGHT};
	srand(time(NULL));

	snake_x[0] = WIDTH / 2;
	snake_y[0] = HEIGHT / 2;
	//random position of food.
	food_x = rand() % 25;
	food_y = rand() % 18;
	SDL_Event event;
	int running = 1;
    while(running){
        while(SDL_PollEvent(&event)){
		if(event.type == SDL_KEYDOWN){
			//controle;
		    switch(event.key.keysym.sym){
			case SDLK_ESCAPE: running = 0; break;
			case SDLK_UP: if(dir_y == 0){dir_x = 0; dir_y = -1;}; break;
			case SDLK_DOWN: if(dir_y == 0){dir_x = 0; dir_y = 1;}; break;
			case SDLK_LEFT: if(dir_x == 0){dir_y = 0; dir_x = -1;}; break;
			case SDLK_RIGHT: if(dir_x == 0){dir_y = 0; dir_x = 1;}; break;
			}
		}
	}

	snake_x[0] += dir_x * BLOCK;
	snake_y[0] += dir_y * BLOCK;

	//boundry case;
	if(snake_x[0] < 0) snake_x[0] = WIDTH - 50;
	if(snake_x[0] >= WIDTH) snake_x[0] = 0;
	if(snake_y[0] < 0) snake_y[0] = HEIGHT - 50;
	if(snake_y[0] >= HEIGHT) snake_y[0] = 0;

	//snake length;
	if (food_x == snake_x[0] / BLOCK && food_y == snake_y[0] / BLOCK) {
            food_x = rand() % (WIDTH / BLOCK);
            food_y = rand() % (HEIGHT / BLOCK);
            n++;
        }
	//ending condition.
	for(int i = 1; i < n+1; i++){
	if(snake_x[i] == snake_x[0] && snake_y[i] == snake_y[0]) goto end;
	}
	//snake movement, body.
	for(int i = n - 1; i > 0; i--){
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}
	//display..
	SDL_FillRect(surface, &back, COLOR_BACK);
	for(int i = 0; i < n; i++){
	snake(surface,snake_x[i],snake_y[i]);
	}
    food(surface);
    grid(surface);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(100);
    }
end:
    printf("your points :%d\n", n);
    return 0;
}
