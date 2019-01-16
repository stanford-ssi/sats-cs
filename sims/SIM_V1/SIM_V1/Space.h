#pragma once

#include "coreinclude.h"

namespace EE {
	class Space
	{
	private:
		eId nextId;
		timeUnit time;
		timeUnit dt;

		eIdToName idToName;
		eNameToId nameToId;
		eIdToPointer idToPointer;

		sysNameVec sysUpdateOrder;
		sNameToPtr sNameToPointer;

		friend class Engine;
	};
}

