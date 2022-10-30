#ifndef SDL_APP_HPP
#define SDL_APP_HPP

#include <functional>

#include <SDL2/SDL.h>

class SDLApp
{
    private:
        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        bool m_gameRunning = true;

        int m_mouseX, m_mouseY;

        int m_width, m_height;

        std::function<void(void)> m_EventCallback;
        std::function<void(void)> m_UpdateCallback;
        std::function<void(void)> m_RenderCallback;

    public:
        SDLApp(Uint32 subSystemFlags, const char* title, int x, int y, int w, int h);
        ~SDLApp();

        void SetEventCallback(std::function<void(void)> func);
        void SetUpdateCallback(std::function<void(void)> func);
        void SetRenderCallback(std::function<void(void)> func);
        
        void RunLoop();

        SDL_Renderer* GetRenderer() const;
        
        int GetMouseX();
        int GetMouseY();

        int GetWindowWidth();
        int GetWindowHeight();

        void StopAppLoop();
};

#endif
