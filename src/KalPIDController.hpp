/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*            Kaji-Lab Magnifier Integrated Assets            */
/*                                                            */
/*     ============== " Be Ambitious For " ==============     */
/*                                                            */
/*              Muroran Institute of Technology               */
/*      Electronic System Control Engineering Laboratory      */
/*                                                            */
/**************************************************************/

// KalPIDController.hpps

// TODO:
//    Verify derivative estimation of single arg Update method.

// OPTIONAL:
//    Variable reformation in rotational mode. (really needed?)
//    Implement Trapezoidal, or Sympthon's Integration.
//    Implement integration range limitation (use KalQueue).



#ifndef KALPIDCONTROLLER_HPP
#define KALPIDCONTROLLER_HPP

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

namespace kalmia {
	class KalPIDController {
	public:
		KalPIDController (double t0 = 0., bool isRotational = false);
		virtual ~KalPIDController() = default;
		
		void SetTargetValue (double sv);

		void SetKp (double Kp);
		void SetKi (double Ki);
		void SetKd (double Kd);
		void SetGains (double Kp, double Ki, double Kd);

		void SetLimit (double upperLimit, double lowerLimit);
		void EnableLimit (bool flag = true);
		void DisableLimit ();
		


		void Update (double t, double pv);
		void Update (double t, double pv, double pv_dt);


		double Output ();

	//private:
		KalPIDController(KalPIDController&&) = delete;
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
#endif