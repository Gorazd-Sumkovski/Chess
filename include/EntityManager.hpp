#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>

#include <SDL2/SDL.h>

#include "GameEntity.hpp"
#include "Layer.hpp"

class EntityManager
{
    private:
        int m_entityCount = 0;
        std::unordered_map<std::string, std::shared_ptr<GameEntity>> m_entities;

    public:
        static EntityManager& GetInstance();

        bool CreateEntity(std::string name, SDL_Renderer* renderer, LAYER layer);

        std::shared_ptr<GameEntity> GetEntityRef(std::string name);

        void RemoveEntity(std::string name);
        void RenderAllLayers();
        void RenderLayer(LAYER layer);
        void DeleteAllEntities();
};

#endif
