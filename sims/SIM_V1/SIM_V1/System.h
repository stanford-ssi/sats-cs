/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: System.h
  --------------------------
  Abstract parent class for system implimentation.

  WARNING: Must update sRegistry in engine.h when new system added.
*/

#pragma once

#include "coreinclude.h"
#include <iostream>
#include <typeinfo>

namespace EE {
	class System
	{
	public:

		// TODO: Add const correctness
		virtual void debug();

	protected:

		// Used by the engine to add and remove dependencies
		void addDependency(const cType& name, Component* depend);
		void removeDependency(const cType& depend);

		// System updates dependent components given a time interval dt
		// Pure virtual funtion must be implimented in child system
		virtual void update(timeUnit dt) = 0;

		// String literal of system name
		sType type;

		// Map of <component type: component* set>
		cDependencyMap compDependency;
		// Set of types of required components
		cDependencySet dependencies;

		// TODO?: Add <eId : component*> or something

		friend class Engine;

	};
}

