#include <string>

#include <SDL2/SDL.h>

#include "TexturedRectangle.hpp"
#include "ResourceManager.hpp"

TexturedRectangle::TexturedRectangle(SDL_Renderer* renderer, std::string filepath)
{
    SDL_Surface* surface = ResourceManager::GetInstance().GetSurface(filepath);

    m_texture = SDL_CreateTextureFromSurface(renderer, surface);

    InitDefaults();
}

TexturedRectangle::TexturedRectangle(SDL_Texture* texture)
{
    m_texture = texture;

    InitDefaults();
}

void TexturedRectangle::InitDefaults()
{
    m_rectangle.x = 0;
    m_rectangle.y = 0;
    m_rectangle.w = 32;
    m_rectangle.h = 32;
}

TexturedRectangle::~TexturedRectangle()
{
    SDL_DestroyTexture(m_texture);
}

SDL_Rect& TexturedRectangle::GetSDLRect()
{
    return m_rectangle;
}

SDL_Rect* TexturedRectangle::GetSDLRectPtr()
{
    return &m_rectangle;
}

SDL_Texture* TexturedRectangle::GetSDLTexture()
{
    return m_texture;
}

void TexturedRectangle::SetPostion(int x, int y)
{
    m_rectangle.x = x;
    m_rectangle.y = y;
}

int TexturedRectangle::GetPositionX()
{
    return m_rectangle.x;
}
int TexturedRectangle::GetPositionY()
{
    return m_rectangle.y;
}

void TexturedRectangle::SetDimensions(int w, int h)
{
    m_rectangle.w = w;
    m_rectangle.h = h;
}
int TexturedRectangle::GetWidth()
{
    return m_rectangle.w;
}
int TexturedRectangle::GetHeight()
{
    return m_rectangle.h;
}

void TexturedRectangle::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, m_texture, NULL, &m_rectangle);
}
