/*
  Stanford Student Space Initiative
  Satellites | Sims | February 2019
  Katie Mishra  | krmishra@stanford.edu

  File: ComponentWriter.h
  --------------------------
  ComponentWriter supplies a GUI for users to write JSON code for new components to a given file. 
  These files can then be supplied to the engine for testing, instead of having to handwrite
  component code each time. 
*/

#pragma once

#include "coreinclude.h"

namespace EE {
    class ComponentWriter
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

