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

// KalPIDController.cpp

#include "KalPIDController.hpp"

namespace kalmia {
	KalPIDController::KalPIDController (double t0, bool isRotational) : t0(t0), isRotational (isRotational){
		limitEnabled = false;
		Kp = Ki = Kd = 0;
		err = err_dt = err_int = 0;
		mv = 0;
		sv = 0;
		prev_t = prev_pv = 0;
	}


	void KalPIDController::Update (double t, double pv){
		double dt;
		double pv_dt;

		if (t == t0){
			pv_dt = 0;
		} else{
			dt = (t - prev_t);
			pv_dt = (pv - prev_pv) / dt;
		}

		Update (t, pv, pv_dt);
	}

	void KalPIDController::Update (double t, double pv, double pv_dt){
		double dt = (t - prev_t);
		err = sv - pv;
		if (isRotational){
		}

		err_dt = -pv_dt;
		err_int += err*dt;

		mv = Kp*err + Ki*err_int + Kd*err_dt;
		prev_t = t;
		prev_t = pv;
	}

	double KalPIDController::Output (){
		if (limitEnabled){
			if (mv > upperLimit){
				return upperLimit;
			} else if (mv < lowerLimit){
				return lowerLimit;
			} else{
				return mv;
			}
		} else{
			return mv;
		}
	}

	void KalPIDController::EnableLimit (bool flag){
		limitEnabled = flag;
	}

	void KalPIDController::DisableLimit (){
		KalPIDController::EnableLimit (false);
	}

	void KalPIDController::SetLimit (double upperLimit, double lowerLimit){
		if (upperLimit < lowerLimit){
			std::cout << "Caution: upperLimit must not be less than lowerLimit. Command ignored." << std::endl;
			return;
		}
		this->upperLimit = upperLimit;
		this->lowerLimit = lowerLimit;
	}

	void KalPIDController::SetTargetValue (double sv){
		this->sv = sv;
	}

	void KalPIDController::SetKp (double Kp){
		this->Kp = CheckGain (Kp);
	}

	void KalPIDController::SetKi (double Ki){
		this->Ki = CheckGain (Ki);
	}

	void KalPIDController::SetKd (double Kd){
		this->Kd = CheckGain (Kd);
	}

	void KalPIDController::SetGains (double Kp, double Ki, double Kd){
		SetKp (Kp);
		SetKi (Ki);
		SetKd (Kd);
	}

	double KalPIDController::CheckGain (double gain){
		if (gain < 0){
			std::cout << "Notice: You must not set gain negative. Absolute value used." << std::endl;
			return -gain;
		} else{
			return gain;
		}
	}
}