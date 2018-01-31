#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include "Engine.h"

using namespace std;

class Grid:public Engine
{
public:
    Grid();
    ~Grid();

    bool loadFromFile(string path, SDL_Renderer* gRenderer);
    void free();
    void render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL);

private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
};

#endif // GRID_H_INCLUDED
