cmake_minimum_required(VERSION 3.13)
project(SIM_V1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SIM_V1
        body.cpp
        body.h
        component.cpp
        component.h
        ComponentWriter.cpp
        ComponentWriter.h
        coreinclude.h
        Drag.cpp
        Drag.h
        engine.cpp
        engine.h
        entity.cpp
        entity.h
        Force.cpp
        Force.h
        main.cpp
        mass.cpp
        mass.h
        Space.h
        System.cpp
        System.h
        TestComponent.cpp
        TestComponent.h
        TestSystem.cpp
        TestSystem.h
        ForceSystem.cpp
        ForceSystem.h
        DragSystem.cpp
        DragSystem.h)
