#pragma once

#include "component.h"
#include "coreinclude.h"

namespace EE {
	class Body
		: public Component
	{
	public:

		Body();
		Body(const double& mass, const double& radius);

		void setRadius(const double& newRad);
		void setMass(const double& newMass);

		double getMass() const;
		double getRadius() const;
	private:
		double mass;
		double radius;

	};
}

