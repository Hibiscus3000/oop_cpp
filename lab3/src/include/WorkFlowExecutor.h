#ifndef _WORK_FLOW_EXECUTOR
#define _WORK_FLOW_EXECUTOR_

#include "WorkFlowParser.h"
#include "BlockFactory.h"

class WorkFlowExecutor
{
public:
	void executeWorkFlow(ifstream& in);
	void blockCheck(list<Block*> blockObjects);
	void executeBlocks(list<Block*> blockObjects);
	void deleteBlocks(list<Block*> blockObjects);
};

#endif