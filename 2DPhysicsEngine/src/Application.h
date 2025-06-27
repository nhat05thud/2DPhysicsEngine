#ifndef APPLICATION_H
#define APPLICATION_H

#include "./Graphics.h"
#include "./Physics/Particle.h"
#include <SDL.h>
#include <vector>

class Application {
    private:
        bool running = false;

        std::vector<Particle*> particles;
        Vec2 pushForce = Vec2(0.0, 0.0);

        // Create a liquid
        SDL_Rect liquid;

    public:
        Application() = default;
        ~Application() = default;
        bool IsRunning();
        void Setup();
        void Input();
        void Update();
        void Render();
        void Destroy();
};

#endif