#ifndef ECS_H
#define ECS_H

#include <bitset>
#include <vector>

const unsigned int MAX_COMPONENTS = 32;

ñ/// <summary>
/// Signature
/// </summary>
/// <remarks>
/// we use a bitset (1s and 0s) to keep track of which coponents an antity has,
/// and also helps keep track of which enteties a system is interested in
/// </remarks>

typedef std::bitset<MAX_COMPONENTS> Signature;

class Component {
	//TODO
};

class Entity {
	private:
		int id;
	public:
		Entity(int id) : id(id) {};
		int Getid() const;
};
/// <summary>
/// System
/// </summary>
/// <remarks>
/// The system processes enteties that contain a specific signature
/// </remarks>
class System {
	private:
		Signature componentSignature;
		std::vector<Entity> entities;
	public:
		System() = default;
		~System() = default;

		void AddEntityToSystem(Entity entity);
		void RemoveEntityFromSystem(Entity entity);
		std::vector<Entity> GetSystemntities() const;
		Signature& GetComponentSignature()const;
};

class Registry {
	//TODO
};
#endif