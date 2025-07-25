#include "./Force.h"
#include "./Vec2.h"
#include "./Particle.h"

Vec2 Force::GenerateDragForce(const Particle& particle, float k) {
	Vec2 dragForce = Vec2(0, 0);
	if (particle.velocity.MagnitudeSquared() > 0) {
		// Calculate the drag direction (invert of velocity unit vector)
		Vec2 dragDirection = particle.velocity.UnitVector() * -1.0;

		// Calculate the drag magnitude, k * |v|^2
		float dragMagnitude = k * particle.velocity.MagnitudeSquared();

		// Generate the final drag force with direction and magnitude
		dragForce = dragDirection * dragMagnitude;
	}
	return dragForce;
}

// TODO: Generate Friction Force


// TODO: Generate Spring Force