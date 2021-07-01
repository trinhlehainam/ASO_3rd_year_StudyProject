#pragma once
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

class Entity;

class EntityMng
{
public:
	EntityMng();
	~EntityMng();

	bool HasEntity(int entityID) const;

	std::shared_ptr<Entity> AddEntity(std::string tag);
	void AddEntity(const std::shared_ptr<Entity>& entity);
	const std::vector<std::shared_ptr<Entity>>& GetAllEntities() const;

	void Update(float deltaTime_s);
	void Render();
private:
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::unordered_map<int, std::shared_ptr<Entity>> m_entityMap;

	int m_currentID;
};

