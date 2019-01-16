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
/************************************  FUNCTIONS *************************************/
		
		cType getType() const;
		virtual void debug() = 0;

	protected:
/************************************  PROPERTIES *************************************/

		/* String literal of component name */
		cType type;
	};
}