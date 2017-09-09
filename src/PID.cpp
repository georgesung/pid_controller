#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;	// arg name is same as member variable name
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	prev_cte = 0.0;
	prev_cte_valid = false;
}

void PID::UpdateError(double cte) {
	// If this is the first time the function is called,
	// just record the cte value as prev_cte and return
	if (!prev_cte_valid) {
		prev_cte = cte;
		prev_cte_valid = true;
		return;
	}

	double diff_cte = cte - prev_cte;	// assume delta_t = 1
	prev_cte = cte;
	int_cte += cte;

	p_error = Kp * cte;
	i_error = Ki * int_cte;
	d_error = Kd * diff_cte;
}

double PID::TotalError() {
	return p_error + i_error + d_error;
}

