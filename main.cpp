#include "Engine.h"

using namespace std;

int main(int argc, char ** argv)
{
    Engine *engine = new Engine("Battleship");
    engine->init();
    engine->loadMedia();
    engine->run();
    delete engine;
    return 0;
}
