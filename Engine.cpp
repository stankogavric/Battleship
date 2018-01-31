#include "Grid.h"
#include "Ship.h"
#include "Tile.h"

using namespace std;

Engine::Engine()
{
    gameTitle = "";
}

Engine::Engine(const string &gameTitle) : gameTitle(gameTitle)
{
}

void Engine::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow(gameTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
    gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    TTF_Init();
    font = TTF_OpenFont("army.ttf", 24);
}

Grid gSpriteSheetTextureGrid;
SDL_Rect gSpriteClipsGrid[ 1 ];
Ship gSpriteSheetTextureShip5;
SDL_Rect gSpriteClipsShip5[ 1 ];
Ship gSpriteSheetTextureShip4;
SDL_Rect gSpriteClipsShip4[ 1 ];
Ship gSpriteSheetTextureShip3;
SDL_Rect gSpriteClipsShip3[ 1 ];
Ship gSpriteSheetTextureShip2;
SDL_Rect gSpriteClipsShip2[ 1 ];
Tile gSpriteSheetTextureTileHit;
SDL_Rect gSpriteClipsTileHit[ 1 ];
Tile gSpriteSheetTextureTileMiss;
SDL_Rect gSpriteClipsTileMiss[ 1 ];

void Engine::loadMedia()
{
    gSpriteSheetTextureGrid.loadFromFile("resources/tilesets/grid.jpg", gRenderer);
    gSpriteClipsGrid[0].x=0;
    gSpriteClipsGrid[0].y=0;
    gSpriteClipsGrid[0].w=400;
    gSpriteClipsGrid[0].h=400;
    gSpriteSheetTextureShip5.loadFromFile("resources/creatures/ship5.png", gRenderer);
    gSpriteClipsShip5[0].x=0;
    gSpriteClipsShip5[0].y=0;
    gSpriteClipsShip5[0].w=5*40;
    gSpriteClipsShip5[0].h=40;
    gSpriteSheetTextureShip4.loadFromFile("resources/creatures/ship4.png", gRenderer);
    gSpriteClipsShip4[0].x=0;
    gSpriteClipsShip4[0].y=0;
    gSpriteClipsShip4[0].w=4*40;
    gSpriteClipsShip4[0].h=40;
    gSpriteSheetTextureShip3.loadFromFile("resources/creatures/ship3.png", gRenderer);
    gSpriteClipsShip3[0].x=0;
    gSpriteClipsShip3[0].y=0;
    gSpriteClipsShip3[0].w=3*40;
    gSpriteClipsShip3[0].h=40;
    gSpriteSheetTextureShip2.loadFromFile("resources/creatures/ship2.png", gRenderer);
    gSpriteClipsShip2[0].x=0;
    gSpriteClipsShip2[0].y=0;
    gSpriteClipsShip2[0].w=2*40;
    gSpriteClipsShip2[0].h=40;
    gSpriteSheetTextureTileHit.loadFromFile("resources/tilesets/tile_hit.jpg", gRenderer);
    gSpriteClipsTileHit[0].x=0;
    gSpriteClipsTileHit[0].y=0;
    gSpriteClipsTileHit[0].w=40;
    gSpriteClipsTileHit[0].h=40;
    gSpriteSheetTextureTileMiss.loadFromFile("resources/tilesets/tile_miss.jpg", gRenderer);
    gSpriteClipsTileMiss[0].x=0;
    gSpriteClipsTileMiss[0].y=0;
    gSpriteClipsTileMiss[0].w=40;
    gSpriteClipsTileMiss[0].h=40;
}

void Engine::drawText(string S, int x, int y, TTF_Font* font, SDL_Renderer* gRenderer)
{
    SDL_Color white = {255, 255, 255};
    stringstream ss;
    ss << S;
    SDL_Surface* sm = TTF_RenderText_Solid(font, ss.str().c_str(), white);
    SDL_Texture* poruka = SDL_CreateTextureFromSurface(gRenderer, sm);
    SDL_Rect poruka_box;
    poruka_box.x = x-(sm->w)/2; //centrirano
    poruka_box.y = y;
    poruka_box.w = sm->w;
    poruka_box.h = sm->h;
    SDL_RenderCopy(gRenderer, poruka, NULL, &poruka_box);

}
bool Engine::run()
{
    int x, y;
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10;
    int xP1, yP1, xP2, yP2;
    int player1 [10][10]= {};
    int player2 [10][10]= {};
    int ship=1;
    int player=1;
    int winner=0;
    bool start=false;
    bool quit=false;
    bool nacrtaj10, nacrtaj9, nacrtaj8, nacrtaj7, nacrtaj6, nacrtaj5, nacrtaj4, nacrtaj3, nacrtaj2, nacrtaj1;
    nacrtaj10=nacrtaj9=nacrtaj8=nacrtaj7=nacrtaj6=nacrtaj5=nacrtaj4=nacrtaj3=nacrtaj2=nacrtaj1=false;
    bool nacrtaj10m, nacrtaj9m, nacrtaj8m, nacrtaj7m, nacrtaj6m, nacrtaj5m, nacrtaj4m, nacrtaj3m, nacrtaj2m, nacrtaj1m;
    nacrtaj10m=nacrtaj9m=nacrtaj8m=nacrtaj7m=nacrtaj6m=nacrtaj5m=nacrtaj4m=nacrtaj3m=nacrtaj2m=nacrtaj1m=false;
    vector <int> misses, hitsP1, hitsP2;
    SDL_Event event;

    while (!quit)
    {
        SDL_Delay(10);
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch( event.key.keysym.sym )
            {
            case SDLK_ESCAPE:
                quit = true;
                break;
            default:
                break;
            }
            break;

        case SDL_MOUSEMOTION:
            if(start)
                break;
            SDL_GetMouseState(&x, &y);
            if (ship==1)
            {
                if(x > 20+200+20 && x<20+200+20+400-160 && y > 20 && y<20+400)
                {
                    x1=round((x-20-200-20)/40)*40+20+200+20;
                    y1=round((y-20)/40)*40+20;
                    nacrtaj1m=true;
                }
                break;
            }
            else if (ship==2)
            {
                if(x > 20+200+20 && x<20+200+20+400-120 && y > 20 && y<20+400 &&
                        (x<(x1-120) || x>(x1+200) || y<y1 || y>y1+40))
                {
                    x2=round((x-20-200-20)/40)*40+20+200+20;
                    y2=round((y-20)/40)*40+20;
                    nacrtaj2m=true;
                }
                break;
            }

            else if (ship==3)
            {
                if(x > 20+200+20 && x<20+200+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x1-80) || x>(x1+200) || y<y1 || y>y1+40) &&
                        (x<(x2-80) || x>(x2+160) || y<y2 || y>y2+40))
                {
                    x3=round((x-20-200-20)/40)*40+20+200+20;
                    y3=round((y-20)/40)*40+20;
                    nacrtaj3m=true;
                }
                break;
            }

            else if (ship==4)
            {
                if(x > 20+200+20 && x<20+200+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x1-80) || x>(x1+200) || y<y1 || y>y1+40) &&
                        (x<(x2-80) || x>(x2+160) || y<y2 || y>y2+40) &&
                        (x<(x3-80) || x>(x3+120) || y<y3 || y>y3+40))
                {
                    x4=round((x-20-200-20)/40)*40+20+200+20;
                    y4=round((y-20)/40)*40+20;
                    nacrtaj4m=true;
                }
                break;
            }

            else if (ship==5)
            {
                if(x > 20+200+20 && x<20+200+20+400-40 && y > 20 && y<20+400 &&
                        (x<(x1-40) || x>(x1+200) || y<y1 || y>y1+40) &&
                        (x<(x2-40) || x>(x2+160) || y<y2 || y>y2+40) &&
                        (x<(x3-40) || x>(x3+120) || y<y3 || y>y3+40) &&
                        (x<(x4-40) || x>(x4+120) || y<y4 || y>y4+40))
                {
                    x5=round((x-20-200-20)/40)*40+20+200+20;
                    y5=round((y-20)/40)*40+20;
                    nacrtaj5m=true;
                }
                break;
            }

            else if (ship==6)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-160 && y > 20 && y<20+400)
                {
                    x6=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y6=round((y-20)/40)*40+20;
                    nacrtaj6m=true;
                }
                break;
            }
            else if (ship==7)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-120 && y > 20 && y<20+400 &&
                        (x<(x6-120) || x>(x6+200) || y<y6 || y>y6+40))
                {
                    x7=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y7=round((y-20)/40)*40+20;
                    nacrtaj7m=true;
                }
                break;
            }

            else if (ship==8)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x6-80) || x>(x6+200) || y<y6 || y>y6+40) &&
                        (x<(x7-80) || x>(x7+160) || y<y7 || y>y7+40))
                {
                    x8=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y8=round((y-20)/40)*40+20;
                    nacrtaj8m=true;
                }
                break;
            }

            else if (ship==9)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x6-80) || x>(x6+200) || y<y6 || y>y6+40) &&
                        (x<(x7-80) || x>(x7+160) || y<y7 || y>y7+40) &&
                        (x<(x8-80) || x>(x8+120) || y<y8 || y>y8+40))
                {
                    x9=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y9=round((y-20)/40)*40+20;
                    nacrtaj9m=true;
                }
                break;
            }

            else if (ship==10)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-40 && y > 20 && y<20+400 &&
                        (x<(x6-40) || x>(x6+200) || y<y6 || y>y6+40) &&
                        (x<(x7-40) || x>(x7+160) || y<y7 || y>y7+40) &&
                        (x<(x8-40) || x>(x8+120) || y<y8 || y>y8+40) &&
                        (x<(x9-40) || x>(x9+120) || y<y9 || y>y9+40))
                {
                    x10=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y10=round((y-20)/40)*40+20;
                    nacrtaj10m=true;
                }
                break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&x, &y);
            if (ship==1)
            {
                if(x > 20+200+20 && x<20+200+20+400-160 && y > 20 && y<20+400)
                {
                    x1=round((x-20-200-20)/40)*40+20+200+20;
                    y1=round((y-20)/40)*40+20;
                    for (int i = 0; i<5; i++)
                        player1[(y1-20)/40][(x1-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj1=true;
                }
                break;
            }
            else if (ship==2)
            {
                if(x > 20+200+20 && x<20+200+20+400-120 && y > 20 && y<20+400 &&
                        (x<(x1-120) || x>(x1+200) || y<y1 || y>y1+40))
                {
                    x2=round((x-20-200-20)/40)*40+20+200+20;
                    y2=round((y-20)/40)*40+20;
                    for (int i = 0; i<4; i++)
                        player1[(y2-20)/40][(x2-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj2=true;
                }
                break;
            }

            else if (ship==3)
            {
                if(x > 20+200+20 && x<20+200+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x1-80) || x>(x1+200) || y<y1 || y>y1+40) &&
                        (x<(x2-80) || x>(x2+160) || y<y2 || y>y2+40))
                {
                    x3=round((x-20-200-20)/40)*40+20+200+20;
                    y3=round((y-20)/40)*40+20;
                    for (int i = 0; i<3; i++)
                        player1[(y3-20)/40][(x3-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj3=true;
                }
                break;
            }

            else if (ship==4)
            {
                if(x > 20+200+20 && x<20+200+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x1-80) || x>(x1+200) || y<y1 || y>y1+40) &&
                        (x<(x2-80) || x>(x2+160) || y<y2 || y>y2+40) &&
                        (x<(x3-80) || x>(x3+120) || y<y3 || y>y3+40))
                {
                    x4=round((x-20-200-20)/40)*40+20+200+20;
                    y4=round((y-20)/40)*40+20;
                    for (int i = 0; i<3; i++)
                        player1[(y4-20)/40][(x4-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj4=true;
                }
                break;
            }

            else if (ship==5)
            {
                if(x > 20+200+20 && x<20+200+20+400-40 && y > 20 && y<20+400 &&
                        (x<(x1-40) || x>(x1+200) || y<y1 || y>y1+40) &&
                        (x<(x2-40) || x>(x2+160) || y<y2 || y>y2+40) &&
                        (x<(x3-40) || x>(x3+120) || y<y3 || y>y3+40) &&
                        (x<(x4-40) || x>(x4+120) || y<y4 || y>y4+40))
                {
                    x5=round((x-20-200-20)/40)*40+20+200+20;
                    y5=round((y-20)/40)*40+20;
                    for (int i = 0; i<2; i++)
                        player1[(y5-20)/40][(x5-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj5=true;
                }
                break;
            }

            else if (ship==6)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-160 && y > 20 && y<20+400)
                {
                    x6=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y6=round((y-20)/40)*40+20;
                    for (int i = 0; i<5; i++)
                        player2[(y6-20)/40-1][(x6-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj6=true;
                }
                break;
            }
            else if (ship==7)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-120 && y > 20 && y<20+400 &&
                        (x<(x6-120) || x>(x6+200) || y<y6 || y>y6+40))
                {
                    x7=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y7=round((y-20)/40)*40+20;
                    for (int i = 0; i<4; i++)
                        player2[(y7-20)/40-1][(x7-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj7=true;
                }
                break;
            }

            else if (ship==8)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x6-80) || x>(x6+200) || y<y6 || y>y6+40) &&
                        (x<(x7-80) || x>(x7+160) || y<y7 || y>y7+40))
                {
                    x8=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y8=round((y-20)/40)*40+20;
                    for (int i = 0; i<3; i++)
                        player2[(y8-20)/40-1][(x8-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj8=true;
                }
                break;
            }

            else if (ship==9)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-80 && y > 20 && y<20+400 &&
                        (x<(x6-80) || x>(x6+200) || y<y6 || y>y6+40) &&
                        (x<(x7-80) || x>(x7+160) || y<y7 || y>y7+40) &&
                        (x<(x8-80) || x>(x8+120) || y<y8 || y>y8+40))
                {
                    x9=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y9=round((y-20)/40)*40+20;
                    for (int i = 0; i<3; i++)
                        player2[(y9-20)/40-1][(x9-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj9=true;
                }
                break;
            }

            else if (ship==10)
            {
                if(x > 20+200+20+400+20 && x<20+200+20+400+20+400-40 && y > 20 && y<20+400 &&
                        (x<(x6-40) || x>(x6+200) || y<y6 || y>y6+40) &&
                        (x<(x7-40) || x>(x7+160) || y<y7 || y>y7+40) &&
                        (x<(x8-40) || x>(x8+120) || y<y8 || y>y8+40) &&
                        (x<(x9-40) || x>(x9+120) || y<y9 || y>y9+40))
                {
                    x10=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                    y10=round((y-20)/40)*40+20;
                    for (int i = 0; i<2; i++)
                        player2[(y10-20)/40-1][(x10-20-200-20)/40+i]=1;
                    ship++;
                    nacrtaj10=true;
                }
                break;
            }

            else if(start)
            {
                if(player==1)
                {
                    if(x > 20+200+20+400+20 && x<20+200+20+400+20+400 && y > 20 && y<20+400)
                    {
                        xP1=round((x-20-400-20-200-20)/40)*40+20+400+20+200+20;
                        yP1=round((y-20)/40)*40+20;
                        if(player2[(yP1-20)/40-1][(xP1-20-200-20)/40]==1)
                        {
                            for(size_t i=0; i<hitsP1.size(); i+=2)
                            {
                                if(hitsP1[i]==xP1 && hitsP1[i+1]==yP1)
                                {
                                    goto duplikat;
                                }
                            }
                            hitsP1.push_back(xP1);
                            hitsP1.push_back(yP1);
duplikat:
                            ;
                        }
                        else
                        {
                            misses.push_back(xP1);
                            misses.push_back(yP1);
                            player++;
                        }
                    }
                    break;
                }
                else if(player==2)
                {
                    if(x > 20+200+20 && x<20+200+20+400 && y > 20 && y<20+400)
                    {
                        xP2=round((x-20-200-20)/40)*40+20+200+20;
                        yP2=round((y-20)/40)*40+20;
                        if(player1[(yP2-20)/40][(xP2-20-200-20)/40]==1)
                        {
                            for(size_t i=0; i<hitsP2.size(); i+=2)
                            {
                                if(hitsP2[i]==xP2 && hitsP2[i+1]==yP2)
                                {
                                    goto duplikat2;
                                }
                            }
                            hitsP2.push_back(xP2);
                            hitsP2.push_back(yP2);
duplikat2:
                            ;
                        }
                        else
                        {
                            misses.push_back(xP2);
                            misses.push_back(yP2);
                            player--;
                        }
                    }
                    break;
                }
            }

            break;
        }

        SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
        SDL_RenderClear(gRenderer);

        SDL_Rect* currentClipGrid = &gSpriteClipsGrid[ 0 ];
        gSpriteSheetTextureGrid.render(20+200+20, 20, gRenderer, currentClipGrid);
        gSpriteSheetTextureGrid.render(20+200+20+400+20, 20, gRenderer, currentClipGrid);

        if(nacrtaj1 || nacrtaj1m)
        {
            SDL_Rect* currentClipShip5 = &gSpriteClipsShip5 [0];
            gSpriteSheetTextureShip5.render(x1, y1, gRenderer, currentClipShip5);
        }

        if(nacrtaj2 || nacrtaj2m)
        {
            SDL_Rect* currentClipShip4 = &gSpriteClipsShip4 [0];
            gSpriteSheetTextureShip4.render(x2, y2, gRenderer, currentClipShip4);
        }


        SDL_Rect* currentClipShip3 = &gSpriteClipsShip3 [0];
        if(nacrtaj3 || nacrtaj3m)
            gSpriteSheetTextureShip3.render(x3, y3, gRenderer, currentClipShip3);

        if(nacrtaj4 || nacrtaj4m)
            gSpriteSheetTextureShip3.render(x4, y4, gRenderer, currentClipShip3);

        if(nacrtaj5 || nacrtaj5m)
        {
            SDL_Rect* currentClipShip2 = &gSpriteClipsShip2 [0];
            gSpriteSheetTextureShip2.render(x5, y5, gRenderer, currentClipShip2);
        }

        if(nacrtaj6 || nacrtaj6m)
        {
            SDL_Rect* currentClipShip5 = &gSpriteClipsShip5 [0];
            gSpriteSheetTextureShip5.render(x6, y6, gRenderer, currentClipShip5);
        }

        if(nacrtaj7 || nacrtaj7m)
        {
            SDL_Rect* currentClipShip4 = &gSpriteClipsShip4 [0];
            gSpriteSheetTextureShip4.render(x7, y7, gRenderer, currentClipShip4);
        }

        if(nacrtaj8 || nacrtaj8m)
            gSpriteSheetTextureShip3.render(x8, y8, gRenderer, currentClipShip3);

        if(nacrtaj9 || nacrtaj9m)
            gSpriteSheetTextureShip3.render(x9, y9, gRenderer, currentClipShip3);

        if(nacrtaj10 || nacrtaj10m)
        {
            SDL_Rect* currentClipShip2 = &gSpriteClipsShip2 [0];
            gSpriteSheetTextureShip2.render(x10, y10, gRenderer, currentClipShip2);
        }

        if(hitsP1.size()>0)
        {
            for(size_t i =0; i<hitsP1.size(); i+=2)
            {
                SDL_Rect* currentClipTileHit = &gSpriteClipsTileHit [0];
                gSpriteSheetTextureTileHit.render(hitsP1[i], hitsP1[i+1], gRenderer, currentClipTileHit);
            }
        }

        if(hitsP2.size()>0)
        {
            for(size_t i =0; i<hitsP2.size(); i+=2)
            {
                SDL_Rect* currentClipTileHit = &gSpriteClipsTileHit [0];
                gSpriteSheetTextureTileHit.render(hitsP2[i], hitsP2[i+1], gRenderer, currentClipTileHit);
            }
        }

        if(misses.size()>0)
        {
            for(size_t i =0; i<misses.size(); i+=2)
            {
                SDL_Rect* currentClipTileMiss = &gSpriteClipsTileMiss [0];
                gSpriteSheetTextureTileMiss.render(misses[i], misses[i+1], gRenderer, currentClipTileMiss);
            }
        }
        if (player == 1)
        {
            if(!start && winner==0)
            {
                drawText("Player 1", (20+200+20)/2, 20, font, gRenderer); //centrirano
                drawText("Ship deployment", (20+200+20)/2, 20+40, font, gRenderer);
            }
            else if(!start && winner==1)
            {
                drawText("Player 1", 20+200+20+400+20+400+(1280-(20+200+20+400+20+400))/2, 20, font, gRenderer); //centrirano
                drawText("Winner", 20+200+20+400+20+400+(1280-(20+200+20+400+20+400))/2, 20+40, font, gRenderer); //centrirano
            }
            else if(start && winner==0)
            {
                drawText("Player 1", 20+200+20+400+20+400+(1280-(20+200+20+400+20+400))/2, 20, font, gRenderer); //centrirano
                drawText("Play", 20+200+20+400+20+400+(1280-(20+200+20+400+20+400))/2, 20+40, font, gRenderer); //centrirano
            }
        }

        if (player == 2)
        {
            if(!start && winner==0)
            {
                drawText("Player 2", 20+200+20+400+20+400+(1280-(20+200+20+400+20+400))/2, 20, font, gRenderer); //centrirano
                drawText("Ship deployment", 20+200+20+400+20+400+(1280-(20+200+20+400+20+400))/2, 20+40, font, gRenderer);
            }
            else if(!start && winner==2)
            {
                drawText("Player 2", (20+200+20)/2, 20, font, gRenderer); //centrirano
                drawText("Winner", (20+200+20)/2, 20+40, font, gRenderer); //centrirano
            }
            else if(start && winner==0)
            {
                drawText("Player 2", (20+200+20)/2, 20, font, gRenderer); //centrirano
                drawText("Play", (20+200+20)/2, 20+40, font, gRenderer); //centrirano
            }
        }

        SDL_RenderPresent(gRenderer);

        if(nacrtaj5)
        {
            SDL_Delay(2000);
            nacrtaj1=nacrtaj2=nacrtaj3=nacrtaj4=nacrtaj5=nacrtaj1m=nacrtaj2m=nacrtaj3m=nacrtaj4m=nacrtaj5m=false;
            player=2;
        }

        if(nacrtaj10)
        {
            SDL_Delay(2000);
            nacrtaj6=nacrtaj7=nacrtaj8=nacrtaj9=nacrtaj10=nacrtaj6m=nacrtaj7m=nacrtaj8m=nacrtaj9m=nacrtaj10m=false;
            start=true;
            player=1;
        }
        if(hitsP1.size()==17*2)
        {
            start=false;
            winner=1;
        }

        if(hitsP2.size()==17*2)
        {
            start=false;
            winner=2;
        }

    }
    return true;
}

Engine::~Engine()
{
    gSpriteSheetTextureGrid.free();
    gSpriteSheetTextureShip5.free();
    gSpriteSheetTextureShip4.free();
    gSpriteSheetTextureShip3.free();
    gSpriteSheetTextureShip2.free();
    gSpriteSheetTextureTileHit.free();
    gSpriteSheetTextureTileMiss.free();
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
