#pragma once


#include "coreinclude.h"
#include <iostream>
#include <typeinfo>
//#include "component.h"

namespace EE {
	class System
	{
	public:
		/*System(const sType& type);*/

		virtual void debug();

	protected:

		
		void addDependency(const cType& name, Component* depend);
		void removeDependency(const cType& depend);

		

		virtual void update(timeUnit dt) = 0;

		sType type;

		cDependencyMap compDependency;
		cDependencySet dependencies;

		friend class Engine;

	};
}

