#ifndef _WORK_FLOW_EXECUTOR
#define _WORK_FLOW_EXECUTOR_

#include "WorkFlowParser.h"
#include "BlockFactory.h"

class WorkFlowExecutor
{
	void blockCheck(list<Block*>& blockObjects);
	void executeBlocks(list<Block*>& blockObjects);
	void createBlockObjects(blockMap& blocks, list<Block*> blockObjects, ifstream& in);
public:
	void executeWorkFlow(ifstream& in);
};

#endif