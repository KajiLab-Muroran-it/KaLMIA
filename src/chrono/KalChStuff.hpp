/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*           Kaji-Lab Moderate Instrumental Assets            */
/*                                                            */
/*     ============== " Be Ambitious For " ==============     */
/*                                                            */
/*              Muroran Institute of Technology               */
/*      Electronic System Control Engineering Laboratory      */
/*                                                            */
/**************************************************************/

// KalChStuff.hpp
// Stuffs for Chrono::Engine.

#ifndef KALCHSTUFF_HPP
#define KALCHSTUFF_HPP

#include "core/ChMathematics.h"
#include "core/ChSmartPointers.h"
#include "physics/ChBody.h"

namespace kalmia {
namespace chrono {
	// Sphere
	template <class T>
	T MassToDens (T mass, T radius){
		return mass / (4. / 3. * ::chrono::CH_C_PI * radius * radius * radius);
	}
	//
	template <class T>
	T MassToDens (T mass, T radius, T height){
		return mass / (::chrono::CH_C_PI * radius * radius * height);
	}
	template <class T>
	T MassToDens (T mass, T depth, T height, T width){
		return mass / (depth * height * width);
	}

	double GetGravitionalPotential (::chrono::ChSharedPtr<::chrono::ChBody> body, ::chrono::ChVector<> G_acc){
		return body->GetMass () * G_acc.Dot (body->GetPos ());
	}

	double GetKineticEnergy (::chrono::ChSharedPtr<::chrono::ChBody> body){
		::chrono::ChVector<> vel = body->GetPos_dt();
		::chrono::ChVector<> wvel = body->GetWvel_loc();
		return (body->GetMass() * vel.Dot (vel) + wvel.Dot (body->GetInertia() * wvel)) / 2.;
	}
}
}

#ifdef KALMIA_HEADER_ONLY
#include "KalChStuff.cpp"
#endif
#endif