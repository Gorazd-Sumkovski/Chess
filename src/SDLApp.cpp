#include <iostream>

#include "SDLApp.hpp"

SDLApp::SDLApp(Uint32 subsystemFlags, const char* title, int x, int y, int w, int h)
{
    m_width = w;
    m_height = h;

    if (SDL_Init(subsystemFlags) < 0)
    {
        std::cout << "SDL initialisation failed: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL initialised" << std::endl;
    }

    m_window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDLApp::~SDLApp()
{
    SDL_DestroyWindow(m_window);

    SDL_Quit();
}

void SDLApp::SetEventCallback(std::function<void(void)> func)
{
    m_EventCallback = func;
}

void SDLApp::SetUpdateCallback(std::function<void(void)> func)
{
    m_UpdateCallback = func;
}


void SDLApp::SetRenderCallback(std::function<void(void)> func)
{
    m_RenderCallback = func;
    
}

void SDLApp::RunLoop()
{
    while (m_gameRunning)
    {
        Uint32 buttons = SDL_GetMouseState(&m_mouseX, &m_mouseY);

        m_EventCallback();
        m_UpdateCallback();

        // SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        // SDL_RenderClear(m_renderer);

        // SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

        m_RenderCallback();

        SDL_RenderPresent(m_renderer);
    }
}

SDL_Renderer* SDLApp::GetRenderer() const
{
    return m_renderer;
}

int SDLApp::GetMouseX()
{
    return m_mouseX;
}
int SDLApp::GetMouseY()
{
    return m_mouseY;
}

int SDLApp::GetWindowWidth()
{
    return m_width;
}

int SDLApp::GetWindowHeight()
{
    return m_height;
}

void SDLApp::StopAppLoop()
{
    m_gameRunning = false;
}
