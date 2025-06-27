#include "Particle.h"
#include <iostream>

Particle::Particle(float x, float y, float mass) {
	this->position = Vec2(x, y);
	this->mass = mass;
	this->invMass = (mass != 0) ? 1.0f / mass : 0.0f; // avoid division by zero
	std::cout << "Particle constructor called!" << std::endl;
}

Particle::~Particle() {
	std::cout << "Particle destructor called!" << std::endl;
}

void Particle::AddForce(const Vec2& force) {
	this->sumForces += force;
}

void Particle::ClearForces() {
	this->sumForces = Vec2(0, 0);
}

void Particle::Integrate(float dt) {
	// find acceleration based on the forces that are being applied and the mass
	acceleration = sumForces * invMass;

	// Integrate the acceleration to find the new velocity
	this->velocity += this->acceleration * dt;

	// Integrate the velocity to find the position
	this->position += this->velocity * dt;

	ClearForces();
}