#pragma once

#include "component.h"

namespace EE {
	class TestComponent
		: public Component
	{
	public:
		TestComponent();

		static Component* create() { return new TestComponent(); }

		virtual void debug();

	private:
		int state = 0;

		// Declare what systems can change component
		friend class TestSystem;
	};
}

