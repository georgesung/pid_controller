#ifndef PID_H
#define PID_H

class PID {
public:
	/*
	* Errors
	*/
	double p_error;
	double i_error;
	double d_error;

	/*
	* Coefficients
	*/ 
	double Kp;
	double Ki;
	double Kd;

	/*
	* cte's related variables
	*/
	double prev_cte;
	bool prev_cte_valid;
	double int_cte;	// integral of cte

	/*
	* Constructor
	*/
	PID();

	/*
	* Destructor.
	*/
	virtual ~PID();

	/*
	* Initialize PID.
	*/
	void Init(double Kp, double Ki, double Kd);

	/*
	* Update the PID error variables given cross track error.
	*/
	void UpdateError(double cte);

	/*
	* Calculate the total PID error.
	*/
	double TotalError();
};

#endif /* PID_H */
