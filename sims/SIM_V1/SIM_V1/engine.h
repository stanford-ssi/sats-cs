#pragma once


#include <algorithm>
#include "component.h"
#include "entity.h"
#include "coreinclude.h"
#include "Space.h"
#include "System.h"

// Include All Components for registry:
#include "TestComponent.h"

// Include all Systems for registry:
#include "TestSystem.h"



namespace EE {
	class Engine
	{
	public:
		static Engine* Instance();

		void loadSpace(Space* space);

		void addEntity(const eType& name);
		void removeEntity(const eType& name);

		void addSystem(const sType& system);
		void removeSystem(const sType& system);
		
		Entity* getEntity(const eType& name);
		System* getSystem(const sType& system);

		
		void addComponent(const eType& eName, const cType& comp);
		void removeComponent(const eType& eName, const cType& comp);

		void addSysDependency(const sType& sys, const cType& depend);
		void removeSysDependency(const sType& sys, const cType& depend);

		void update(timeUnit dt);

		void debugEntity(const eType& name);
		void debugSpace();
		void debugSystem(const cType& system);

	private:
		// Singleton Engine:
		Engine();
		Engine(Engine const&) {};
		Engine& operator=(Engine const&) {};
		static Engine* m_pInstance;


		Space* currentSpace;
		eId nextId;
		timeUnit time;

		
		// TODO: Better Register abstraction
		std::unordered_map<sType, System* (*)()> sRegistry = { {"TestSystem", &TestSystem::create},
			/* More Systems */
		};
		
		std::unordered_map<cType, Component* (*)()> cRegistry = { {"TestComponent", &TestComponent::create},
			/* More Components */
		};

	};
}

