/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: component.h
  --------------------------
  Abstract parent class for component implimentation.

  WARNING: Must update cRegistry in engine.h when new component added.
*/

#pragma once

#include "coreinclude.h"

namespace EE {
	class Component
	{
	public:

		// Returns cType of component name
		cType getType() const;

		// Debug function
		virtual void debug() = 0;

	protected:
		// String literal of component name
		cType type;

	};
}