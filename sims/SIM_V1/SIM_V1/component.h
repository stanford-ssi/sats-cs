#pragma once


#include "coreinclude.h"

namespace EE {
	class Component
	{
	public:


		cType getType() const;

		virtual void debug() = 0;

	protected:
		cType type;

	};
}