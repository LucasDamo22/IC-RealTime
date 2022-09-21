#ifndef _FACTORS_H_
#define _FACTORS_H_

class Factors
{
    double  m_execPeriod;
    double  m_worstExecPeriod;

public:
    Factors(double  execPeriod = 0, double worstExecPeriod = 0);
    ~Factors();
    void defineExec(double  execPeriod);
    void defineWorstExec(double  worstExecPeriod);
    double  getExec();
    double  getWorstExec();
};

#endif