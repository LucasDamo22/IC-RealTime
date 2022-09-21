#include "Factors.h"

Factors::Factors(double execPeriod, double worstExecPeriod)
{
    m_execPeriod = execPeriod;
    m_worstExecPeriod = worstExecPeriod;
}
Factors::~Factors(){}
void Factors::defineExec(double execPeriod)
{
    m_execPeriod = execPeriod;
}

void Factors::defineWorstExec(double worstExecPeriod)
{
    m_worstExecPeriod = worstExecPeriod;
}

double Factors::getExec()
{
    return m_execPeriod;
}
double Factors::getWorstExec()
{
    return m_worstExecPeriod;
}