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

// KalPIDController.hpp

// PIDÇ∆Ç¢Ç¢Ç¬Ç¬Ç‡é¿ëïÇÕPI-DÅiÅj



#ifndef KALPIDCONTROLLER_HPP
#define KALPIDCONTROLLER_HPP

#include <iostream>
#include <controller/KalController.hpp>

namespace kalmia {
	namespace controller {
		class KalPIDController : public KalController{
		public:
			KalPIDController (double t0 = 0., bool isRotational = false);
			virtual ~KalPIDController () = default;

			void SetTargetValue (double sv);

			void SetKp (double Kp);
			void SetKi (double Ki);
			void SetKd (double Kd);
			void SetGains (double Kp, double Ki, double Kd);

			void SetLimit (double upperLimit, double lowerLimit);
			void EnableLimit (bool flag = true);
			void DisableLimit ();



			void Update (double t, double pv) override;
			void Update (double t, double pv, double pv_dt);

			double Output () override;

			//private:
			KalPIDController (KalPIDController&&) = delete;
			KalPIDController& operator =(KalPIDController const&) = delete;
			KalPIDController& operator =(KalPIDController&&) = delete;

			const bool isRotational;

			bool limitEnabled;
			double t0;
			double sv, mv;
			double Kp, Ki, Kd;
			double err, err_dt, err_int;
			double prev_t, prev_pv;
			double upperLimit, lowerLimit;

			double CheckGain (double gain);
		};
	}
}
#ifdef KALMIA_HEADER_ONLY
#include <controller/KalPIDController.cpp>
#endif
#endif