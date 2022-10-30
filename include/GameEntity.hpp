#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "TexturedRectangle.hpp"
#include "Layer.hpp"

class GameEntity
{
    private:
        std::string m_name;
        std::vector<TexturedRectangle*> m_sprites;
        SDL_Renderer* m_renderer;
        LAYER m_layer;

    public:
        GameEntity();
        GameEntity(std::string name, SDL_Renderer* renderer);
        ~GameEntity();

        void Render();

        void AddTexturedRectangle(std::string spritePath);
        void AddTexturedRectangle(TexturedRectangle* p_rect);
        void AddCollider();

        TexturedRectangle& GetTexturedRectangle(size_t index = 0);
        LAYER GetLayer();
        std::string GetName();

        void SetPosition(int x, int y, size_t index = 0);
        void SetDimensions(int w, int h, size_t index = 0);
        void SetLayer(LAYER layer);
};

#endif
