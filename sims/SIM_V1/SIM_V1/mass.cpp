/*
  Stanford Student Space Initiative
  Satellites | Sims | February 2019
  Katie Mishra | katie@cs.stanford.edu

  File: component.cpp
  --------------------------
  Child class for mass implimentation.

  WARNING: Must update cRegistry in engine.h when new component added.
*/

// Must include component.h
#include "component.h"

// Must be under EE namespace
namespace EE {

    // Must extend base class Component
    class MassComponent : public Component
    {
    public:

        // Must overload default constructor
        MassComponent(double mass, string units);

        // Must define create function in the following way:
        // static Component* create() { return new #ClassName#(); }
        static Component* create() { return new MassComponent(); }
        double getKg();
        double getGrams();
        double getLbs();
        void setKg(double mass);
        void setGrams(double mass);
        void setLbs(double mass);

        // Must implement some sort of debug function
        virtual void debug();

    private:

        // Declare relevant properties as private
        double kg_mass;

        // Declare what systems can change component
        friend class TestSystem;
    };
}
