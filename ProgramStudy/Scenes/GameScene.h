#pragma once
#include "IScene.h"

#include <memory>

class GeometryManager;

class GameScene :
    public IScene
{
public:
    GameScene();
    ~GameScene();

private:
    bool Init() override;
    void Update(float deltaTime_ms) override;
    void Render() override;

private:
    std::unique_ptr<GeometryManager> m_geoMng;
};

