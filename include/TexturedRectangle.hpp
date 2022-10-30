#ifndef TEXTURED_RECTANGLE_HPP
#define TEXTURED_RECTANGLE_HPP

#include <string>

#include <SDL2/SDL.h>

class TexturedRectangle
{
    private:
        SDL_Rect m_rectangle;
        SDL_Texture* m_texture;

        inline SDL_Rect GetRectangle() const { return m_rectangle; }

    public:
        TexturedRectangle(SDL_Renderer* renderer, std::string filepath);
        TexturedRectangle(SDL_Texture* texture);

        void InitDefaults();
        
        ~TexturedRectangle();
        
        SDL_Rect& GetSDLRect();
        SDL_Rect* GetSDLRectPtr();
        SDL_Texture* GetSDLTexture();

        void SetPostion(int x, int y);
        int GetPositionX();
        int GetPositionY();
        void SetDimensions(int w, int h);
        int GetWidth();
        int GetHeight();

        void Render(SDL_Renderer* renderer);
};

#endif
