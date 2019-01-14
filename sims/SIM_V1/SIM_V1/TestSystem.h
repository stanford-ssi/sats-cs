/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: TestSystem.h
  --------------------------
  Example implimentation of a system.
  
  WARNING: Must update sRegistry in engine.h when new system added.
*/

// Required precompile condition for Microsoft C++ Compiler
#pragma once

// Must include System.h
#include "System.h"

// Must use EE namespace
namespace EE {

	// Must extend System parent class
	class TestSystem
		: public System
	{
	public:

		// Must overload default constructor
		TestSystem();

		// Must define create function in the following way:
		// static System* create() { return new #ClassName#(); }
		static System* create() { return new TestSystem(); }

		// Must impliment some sort of debug function
		virtual void debug();

	private:

		// Must impliment private update function
		virtual void update(timeUnit dt);

	};
}

