#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm> //find
#include <iterator> //begin, end
#include <cmath> //round

using namespace std;

class Engine
{
public:
    Engine();
    Engine(const string &gameTitle);
    void init();
    void loadMedia();
    void drawText(string S, int x, int y, TTF_Font* font, SDL_Renderer* gRenderer);
    bool run();
    virtual ~Engine();
private:
    string gameTitle;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    TTF_Font* font;
};

#endif // ENGINE_H_INCLUDED
