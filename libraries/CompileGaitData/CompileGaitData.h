#ifndef compileGaitData_h
#define compileGaitData_h

#include "Energia.h"

class CompileGaitData
{
	public:
		CompileGaitData();
		double getGaitData(int index);
	private:
		int index;
		double gaitData[1001];
};
#endif