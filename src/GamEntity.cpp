#include "GameEntity.hpp"

GameEntity::GameEntity()
{
    m_name = "Unnamed";
}

GameEntity::GameEntity(std::string name, SDL_Renderer* renderer)
{
    m_name = name;
    m_renderer = renderer;
}

GameEntity::~GameEntity()
{
    for (auto sprite : m_sprites) delete sprite;
}

void GameEntity::Render()
{   
    for (auto sprite : m_sprites)
    {
        if (sprite != nullptr) sprite->Render(m_renderer);
    }
}

void GameEntity::AddTexturedRectangle(std::string spritePath)
{
    m_sprites.push_back(new TexturedRectangle(m_renderer, spritePath));
}

void GameEntity::AddTexturedRectangle(TexturedRectangle* p_rect)
{
    // TexturedRectangle& temp = rect;
    m_sprites.push_back(p_rect);
}

TexturedRectangle& GameEntity::GetTexturedRectangle(size_t index /* = 0 */)
{
    return *m_sprites[index];
}

LAYER GameEntity::GetLayer()
{
    return m_layer;
}

std::string GameEntity::GetName()
{
    return m_name;
}

void GameEntity::SetPosition(int x, int y, size_t index /* = 0 */)
{
    if (m_sprites[index] != nullptr) m_sprites[index]->SetPostion(x, y);
}

void GameEntity::SetDimensions(int w, int h, size_t index /* = 0 */)
{
    if (m_sprites[index] != nullptr) m_sprites[index]->SetDimensions(w, h);
}

void GameEntity::SetLayer(LAYER layer)
{
    m_layer = layer;
}
