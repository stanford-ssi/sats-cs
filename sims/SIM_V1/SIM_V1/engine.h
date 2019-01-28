/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: engine.h
  --------------------------
  Engine to manage systems, system dependencies, entities, and 
  components. Runs the simulation for the current space.

  WARNING: Must update sRegistry when new system added.
  WARNING: Must update cRegistry when new component added.
*/

#pragma once

#include <algorithm>
#include "component.h"
#include "entity.h"
#include "coreinclude.h"
#include "Space.h"
#include "System.h"

/******************************  COMPONENT INCLUDES ********************************/
#include "TestComponent.h"

/********************************  SYSTEM INCLUDES *********************************/
#include "TestSystem.h"


namespace EE {
	class Engine
	{
	public:
/********************************  FUNCTIONS *********************************/

		/* MANAGE SPACE */
		void loadSpace(Space* space);

		/* MANAGE ENTITY */
		void addEntity(const eType& name);
		void removeEntity(const eType& name);
		Entity* getEntity(const eType& name);

		/* MANAGE SYSTEM */
		void addSystem(const sType& system);
		void removeSystem(const sType& system);
		System* getSystem(const sType& system);
		void addSysDependency(const sType& sys, const cType& depend);
		void removeSysDependency(const sType& sys, const cType& depend);
		
		/* MANAGE COMPONENT */
		void addComponent(const eType& eName, const cType& comp);
		void removeComponent(const eType& eName, const cType& comp);

		/* RUN SIMULATION */
		void update();

		/* DEBUG */
		void debugEntity(const eType& name);
		void debugSystem(const sType& system);
		void debugSpace();

		/*******************************  SINGLETON SUPPORT ********************************/
		static Engine* Instance();

	private:
		Engine() {};
		Engine(Engine const&) {};
		Engine& operator=(Engine const&) {};
		static Engine* m_pInstance;

		/************************************  OBJECTS *************************************/

		Space* currentSpace;
		
		// TODO: Better Register abstraction:

		/********************************  SYSTEM REGISTRY *********************************/
		std::unordered_map<sType, System* (*)()> sRegistry = { {"TestSystem", &TestSystem::create},
			
			/* Format: {"#SystemName#", &#SystemName#::create} */
		};
		
		/*******************************  COMPONENT REGISTRY ********************************/
		std::unordered_map<cType, Component* (*)()> cRegistry = { {"TestComponent", &TestComponent::create},

			/* Format: {"#ComponentName#", &#ComponentName#::create} */
		};

	};
}

