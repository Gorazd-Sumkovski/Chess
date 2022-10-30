#include <iostream>
#include <string>
#include <vector>

#include "SDLApp.hpp"
#include "EntityManager.hpp"
#include "GameEntity.hpp"
#include "ResourceManager.hpp"
#include "TexturedRectangle.hpp"
#include "Layer.hpp"

const char* title = "Chess";
const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 1080;
const int TILE_WIDTH = WINDOW_WIDTH / 8;
const int TILE_HEIGHT = WINDOW_HEIGHT / 8;

SDLApp* app;

void HandleEvents()
{
    SDL_Event event;

    SDL_WaitEvent(&event);
    
    if (event.type == SDL_QUIT)
    {
        app->StopAppLoop();
    }
    
}

void CreateChessBoardTiles()
{
    std::shared_ptr<GameEntity> white_tile = EntityManager::GetInstance().GetEntityRef("white_tile");
    std::shared_ptr<GameEntity> brown_tile = EntityManager::GetInstance().GetEntityRef("brown_tile");

    bool white = true;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (white)
            {
                TexturedRectangle* temp = new TexturedRectangle(white_tile->GetTexturedRectangle().GetSDLTexture());
                temp->SetPostion(i * TILE_WIDTH, j * TILE_HEIGHT);
                temp->SetDimensions(TILE_WIDTH, TILE_HEIGHT);
                white_tile->AddTexturedRectangle(temp);
            }
            else
            {
                TexturedRectangle* temp = new TexturedRectangle(brown_tile->GetTexturedRectangle().GetSDLTexture());
                temp->SetPostion(i * TILE_WIDTH, j * TILE_HEIGHT);
                temp->SetDimensions(TILE_WIDTH, TILE_HEIGHT);
                brown_tile->AddTexturedRectangle(temp);
            }

            white = !white;
        }

        white = !white;
    }
}

bool initialisingBoard = true;

void HandleUpdates()
{
    if (initialisingBoard)
    {
        CreateChessBoardTiles();
        initialisingBoard = false;
    }
}

void HandleRendering()
{
    EntityManager::GetInstance().RenderAllLayers();
}

int main(int argc, char** argv)
{
    app = new SDLApp(SDL_INIT_VIDEO, title, 200, 200, WINDOW_WIDTH, WINDOW_HEIGHT);

    EntityManager::GetInstance().CreateEntity("white_tile", app->GetRenderer(), LAYER::BACKGROUND);
    EntityManager::GetInstance().CreateEntity("brown_tile", app->GetRenderer(), LAYER::BACKGROUND);

    std::shared_ptr<GameEntity> white_tile = EntityManager::GetInstance().GetEntityRef("white_tile");
    std::shared_ptr<GameEntity> brown_tile = EntityManager::GetInstance().GetEntityRef("brown_tile");
    
    white_tile->AddTexturedRectangle("./assets/images/" + white_tile->GetName() + ".bmp");
    brown_tile->AddTexturedRectangle("./assets/images/" + brown_tile->GetName() + ".bmp");

    app->SetEventCallback(HandleEvents);
    app->SetUpdateCallback(HandleUpdates);
    app->SetRenderCallback(HandleRendering);

    app->RunLoop();
    
    delete app;
    EntityManager::GetInstance().DeleteAllEntities();

    return 0;
}
