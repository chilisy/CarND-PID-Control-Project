#include "PID.h"

/*
 * TODO: Complete the PID class.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double pt1_T, bool use_pt1) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    
    this->p_error = 0.0;
    this->i_error = 0.0;
    this->d_error = 0.0;
    
    this->pre_cte = 0.0;
    
    this->use_pt1_filter = true;
    this->T = pt1_T;
    this->pre_total_err = 0.0;
    this->K = 0.2;
    
}

void PID::UpdateError(double cte) {
    
    pre_cte = p_error;
    
    p_error = cte;
    i_error += cte;
    d_error = cte - pre_cte;
    
}

double PID::TotalError() {
    
    if (use_pt1_filter)
    {
        double totalErr = Kp * p_error + Kd * d_error + Ki * i_error;
        
        double out = T*(K*totalErr-pre_total_err) + pre_total_err;
        
        return out;
    }
    else
        return Kp * p_error + Kd * d_error + Ki * i_error;
}

