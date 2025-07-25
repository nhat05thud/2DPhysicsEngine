#define SDL_MAIN_HANDLED
#include "src/Application.h"

int main(int argc, char* argv[])
{
    Application app;

    app.Setup();

    while (app.IsRunning()) {
        app.Input();
        app.Update();
        app.Render();
    }

    app.Destroy();

    return 0;
}