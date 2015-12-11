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
	return mass / (4. / 3. * CH_C_PI * radius * radius * radius);
}
// Cylinder
template <class T>
inline T MassToDens (T radius, T height, T mass){
	return mass / (CH_C_PI * radius * radius * height);
}
// Box
template <class T>
inline T MassToDens (T depth, T height, T width, T mass){
	return mass / (depth * height * width);
}

double GetGravitationalPotential (ChSharedPtr<ChBody> body, ChVector<> G_acc){
	return -1.* body->GetMass () * G_acc.Dot (body->GetPos ());
}

double GetKineticEnergy (ChSharedPtr<ChBody> body){
	const ChVector<> vel = body->GetPos_dt();
	const ChVector<> wvel = body->GetWvel_loc();
	return (body->GetMass() * vel.Dot (vel) + wvel.Dot (body->GetInertia() * wvel)) / 2.;
}

// It works, maybe...
ChSharedPtr<ChBody> ChBodyCopyEverything (ChSharedPtr<ChBody> source, ChSharedPtr<ChBody> target){
	target->Copy (source.get_ptr ());

	auto markers =  source->GetMarkerList ();
	for (auto&& elem : markers){
		target->AddMarker (ChSharedPtr<ChMarker>(elem));
	}
		
	auto forces = source->GetForceList ();
	for (auto elem&& : forces){
		target->AddForce (ChSharedPtr<ChForce> (elem));
	}

	target->GetCollisionModel ()->AddCopyOfAnotherModel (source->GetCollisionModel());
	return target;
}
	
ChSharedPtr<ChBodyEasyBox> CreateTypicalFloor (double side, double thickness, ChSharedPtr<ChAsset> appearance = ChSharedPtr<ChColorAsset>(new ChColorAsset(1.0, 1.0, 1.0))){
	auto body =  ChSharedPtr<ChBodyEasyBox> (new ChBodyEasyBox (side, thickness, side, 1000., true));
	body->SetPos (ChVector<> (0., -thickness / 2. , 0.));
	body->SetBodyFixed (true);
	body->AddAsset (appearance);
	return body;
}


}// namespace chrono


#endif