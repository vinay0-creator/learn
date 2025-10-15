#include <SDL2/SDL.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600
#define COLOR_WHITE 0xffff0000
#define COLOR_BACK 0x0f0f0f0f
#define A_GRAVITY 0.2


struct Circle{
	double x;
	double y;
	double radius;
	double v_x;
	double v_y;
};

void step(struct Circle* circle){
// new position of the ball
  circle->x += circle->v_x;
  circle->y += circle->v_y;
  circle->v_y += A_GRAVITY;
// did the ball exit the screen
  if ( circle->x + circle->radius > WIDTH ){
    circle->x = WIDTH - circle->radius;
    circle->v_x = -circle->v_x;
  }
  if ( circle->y + circle->radius > HEIGHT ){
    circle->y = HEIGHT - circle->radius;
    circle->v_y = -circle->v_y;
  }
  if ( circle->y - circle->radius < 0){
    circle->y = circle->radius;
    circle->v_y = -circle->v_y;
  }
  if ( circle->x - circle->radius < 0){
    circle->x = circle->radius;
    circle->v_x = -circle->v_x;
  }
}



void FillCircle(SDL_Surface* surface, struct Circle circle){
	double low_x = circle.x - circle.radius;
	double low_y = circle.y - circle.radius;
	double high_x = circle.x + circle.radius;
	double high_y = circle.y + circle.radius;
	
	double radius_squared = circle.radius * circle.radius;
	
	for(double x = low_x; x < high_x; x++){
		for(double y = low_y; y < high_y ; y++){
			// is the coordinete inside circle?
			double center_distance_squared = (x-circle.x)*(x-circle.x) + (y-circle.y)*(y-circle.y);
			if (center_distance_squared < radius_squared ){
			SDL_Rect pixel = (SDL_Rect) {x,y,1,1};
			SDL_FillRect(surface, &pixel, COLOR_WHITE);
			}
		}
	}
}



int main() {
    SDL_Window *window = SDL_CreateWindow("Ball",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_SHOWN);

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    struct Circle circle = (struct Circle) {200,200,100,10,5};
    SDL_Rect erase_rect = (SDL_Rect){0,0,WIDTH,HEIGHT};
   
   SDL_Event event;
    
    int running = 1;
    while(running){
      while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
          running = 0;
        }
        if(event.type == SDL_KEYDOWN){
          if(event.key.keysym.sym == SDLK_SPACE){
            running = 0;
          }
        }
      }
    SDL_FillRect(surface, &erase_rect, COLOR_BACK);
    FillCircle(surface, circle);
    step(&circle);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(20);
    }
    return 0;
}

