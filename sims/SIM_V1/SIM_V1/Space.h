#pragma once

#include "coreinclude.h"

namespace EE {

	class Space
	{
	public:

		Space();
		~Space();


	private:
		eIdToName idToName;
		eNameToId nameToId;
		eIdToPointer idToPointer;

		sysNameVec sysUpdateOrder;
		sNameToPtr sNameToPointer;

		friend class Engine;

	};
}

