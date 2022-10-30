#include <iostream>

#include "EntityManager.hpp"

EntityManager& EntityManager::GetInstance()
{
    static EntityManager* s_instance = new EntityManager;
    return *s_instance;
}

bool EntityManager::CreateEntity(std::string name, SDL_Renderer* renderer, LAYER layer)
{
    std::shared_ptr<GameEntity> newEntity = std::make_shared<GameEntity>(name, renderer);
    newEntity->SetLayer(layer);

    m_entities.insert(std::make_pair(name, newEntity));

    m_entityCount++;

    return (m_entities[name] != nullptr);
}

std::shared_ptr<GameEntity> EntityManager::GetEntityRef(std::string name)
{
    return m_entities[name];
}

void EntityManager::RemoveEntity(std::string name)
{
    auto entitySearch = m_entities.find(name);
    
    if (entitySearch != m_entities.end())
    {
        m_entities.erase(entitySearch);
        m_entityCount--;
    }
    else
    {
        std::cout << "Entity not found" << std::endl;
    }
}

void EntityManager::RenderLayer(LAYER layer)
{
    size_t index = 0;

    for (auto it = m_entities.begin(); it != m_entities.end(); it++)
    {
        if (m_entities[it->first] != nullptr && layer == m_entities[it->first]->GetLayer())
        {
            m_entities[it->first]->Render();
        }
        else if (m_entities[it->first] == nullptr && layer == m_entities[it->first]->GetLayer())
        {
            std::cout << "Unknown entity render at index: " << index << std::endl;
        }
        index++;
    }
}

void EntityManager::RenderAllLayers()
{
    RenderLayer(LAYER::BACKGROUND);
	RenderLayer(LAYER::FOREGROUND);
}

void EntityManager::DeleteAllEntities()
{
    m_entities.erase(m_entities.begin(), m_entities.end());
}
