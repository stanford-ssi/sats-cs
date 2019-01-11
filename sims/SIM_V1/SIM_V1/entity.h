#pragma once

#include "coreinclude.h"
//#include "EntityEventFire.h"


namespace EE {
	class Entity
		//: public EntityEventFire
	{
	public:

		Entity(const eType& inputName, const eId& idInput);
		Entity(const Entity& rhs) = delete;
		~Entity();

		eType getName() const;
		eId getId() const;

		cNameToPtr getComponentList();
		const cNameToPtr getComponentList() const;

		bool contains(const cType& comp) const;

		Component* getComponent(const cType& type);
		Component const * const getComponent(const cType& type) const;
		cPtrSet getComponentSet() const;

		void addComponent(Component* comp);
		void removeComponent(const cType& comp);

		idCompPtrPair getComponentPair(const cType& comp);

		void debug();

		void operator=(const Entity& rhs) = delete;

	private:
		eId id;
		eType name;

		cNameToPtr componentMap;
		cPtrSet componentSet;

	};
}
