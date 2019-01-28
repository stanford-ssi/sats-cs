/*
  Stanford Student Space Initiative
  Satellites | Sims | December 2018
  Garand Tyson  | gttyson@stanford.edu

  File: Space.h
  --------------------------
  Space is a data structure to hold all information for a given simulations,
  including simulation time interval, component lists, entity information, etc.
*/

#pragma once

#include "coreinclude.h"

namespace EE {
	class Space
	{
	private:
/************************************  PROPERTIES *************************************/

		/* Simulation time information */
		timeUnit time;
		timeUnit dt;

		/* Entity information */
		eId nextId;
		eIdToName idToName;
		eNameToId nameToId;
		eIdToPointer idToPointer;

		/* System Information */
		sysNameVec sysUpdateOrder;
		sNameToPtr sNameToPointer;

		friend class Engine;
	};
}

