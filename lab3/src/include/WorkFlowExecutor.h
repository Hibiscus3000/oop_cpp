#ifndef _WORK_FLOW_EXECUTOR
#define _WORK_FLOW_EXECUTOR_

#include "WorkFlowParser.h"

class WorkFlowExecutor
{
	WorkFlowParser parser;

public:
	void executeWorkFlow(vector<int>);
};

#endif