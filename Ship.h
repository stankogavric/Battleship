#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "Engine.h"

using namespace std;

class Ship:public Engine
{
public:
    Ship();
    ~Ship();

    bool loadFromFile(string path, SDL_Renderer* gRenderer);
    void free();
    void render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL);

private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
};

#endif // SHIP_H_INCLUDED
