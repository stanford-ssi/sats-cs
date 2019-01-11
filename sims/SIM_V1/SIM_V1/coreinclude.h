#pragma once

#include <unordered_set>
#include <unordered_map>


namespace EE 
{
	class Entity;
	class Component;
	class System;
		typedef unsigned int eId;
		typedef std::string cType;
		typedef std::string eType;
		typedef std::string sType;
		typedef std::unordered_set<Component*> cPtrSet;
		typedef std::unordered_map<eId, cPtrSet> eComponentMap;
		typedef std::string entityName;
		typedef std::vector<eId> eVector;
		typedef std::unordered_map<eId, std::string> eIdToName;
		typedef std::unordered_map<std::string, eId> eNameToId;
		typedef std::unordered_map<eId, Entity*> eIdToPointer;
		typedef std::unordered_set<Component*> cPtrSet;
		typedef std::unordered_map<eId, cPtrSet> eComponentMap;
		typedef std::unordered_set<cType> cDependencySet;
		typedef std::vector<sType> sysNameVec;
		typedef std::unordered_set<eId> eSet;
		typedef std::unordered_map<cType, Component*> cNameToPtr;
		typedef std::unordered_map<sType, System*> sNameToPtr;
		typedef std::vector<Component*> cPtrVector;
		typedef std::pair<eId, Component*> idCompPtrPair;
		typedef std::unordered_map<cType, cPtrSet> cDependencyMap;
		typedef double timeUnit;

}