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

    double T;
    double K;
    bool use_pt1_filter;
    
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
    void Init(double Kp, double Ki, double Kd, double pt1_T, bool use_pt1);
    
    /*
     * Update the PID error variables given cross track error.
     */
    void UpdateError(double cte);
    
    /*
     * Calculate the total PID error.
     */
    double TotalError();
    
private:
    
    double pre_total_err;
    double pre_cte;
};

#endif /* PID_H */
