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

// Chrono
#include "core/ChMathematics.h"
#include "core/ChSmartPointers.h"
#include "physics/ChBody.h"

namespace chrono {
	// Sphere
	template <class T>
	inline T MassToDens (T radius, T mass){
		return mass / (4. / 3. * ::chrono::CH_C_PI * radius * radius * radius);
	}
	// Cylinder
	template <class T>
	inline T MassToDens (T radius, T height, T mass){
		return mass / (::chrono::CH_C_PI * radius * radius * height);
	}
	// Box
	template <class T>
	inline T MassToDens (T depth, T height, T width, T mass){
		return mass / (depth * height * width);
	}

	double GetGravitationalPotential (::chrono::ChSharedPtr<::chrono::ChBody> body, ::chrono::ChVector<> G_acc){
		return -1.* body->GetMass () * G_acc.Dot (body->GetPos ());
	}

	double GetKineticEnergy (::chrono::ChSharedPtr<::chrono::ChBody> body){
		const ::chrono::ChVector<> vel = body->GetPos_dt();
		const ::chrono::ChVector<> wvel = body->GetWvel_loc();
		return (body->GetMass() * vel.Dot (vel) + wvel.Dot (body->GetInertia() * wvel)) / 2.;
	}

	// It works, maybe...
	::chrono::ChSharedPtr<::chrono::ChBody> ChBodyCopyEverything (::chrono::ChSharedPtr<::chrono::ChBody> source, ::chrono::ChSharedPtr<::chrono::ChBody> target){
		target->Copy (source.get_ptr ());

		auto markers =  source->GetMarkerList ();
		for (auto elem : markers){
			target->AddMarker (::chrono::ChSharedPtr<::chrono::ChMarker>(elem));
		}
		
		auto forces = source->GetForceList ();
		for (auto elem : forces){
			target->AddForce (::chrono::ChSharedPtr<::chrono::ChForce> (elem));
		}

		target->GetCollisionModel ()->AddCopyOfAnotherModel (source->GetCollisionModel());
		return target;
	}
}// namespace chrono


#endif