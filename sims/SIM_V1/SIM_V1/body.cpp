#include "body.h"

EE::Body::Body()
{
	mass = 0;
	radius = 0;
	type = "Body";
}

EE::Body::Body(const double& mass, const double& radius) 
{
	this->mass = mass;
	this->radius = radius;
	type = "Body";
}

void EE::Body::setRadius(const double& newRad)
{
	radius = newRad;
}

void EE::Body::setMass(const double& newMass)
{
	mass = newMass;
}

double EE::Body::getMass() const 
{
	return mass;
}

double EE::Body::getRadius() const
{
	return radius;
}