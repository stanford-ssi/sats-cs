/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: TestComponent.h
  --------------------------
  Example implimentation of a component.

  WARNING: Must update cRegistry in engine.h when new component added.
*/

// Required precompile condition for Microsoft C++ Compiler
#pragma once

// Must include component.h
#include "component.h"

// Must be under EE namespace
namespace EE {

	// Must extend base class Component
	class TestComponent
		: public Component
	{
	public:

		// Must overload default constructor
		TestComponent();

		// Must define create function in the following way:
		// static Component* create() { return new #ClassName#(); }
		static Component* create() { return new TestComponent(); }

		// Must impliment some sort of debug funciton
		virtual void debug();

	private:

		// Declare relevant properties as private
		int state = 0;

		// Declare what systems can change component
		friend class TestSystem;
	};
}

