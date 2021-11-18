#ifndef _WORK_FLOW_EXECUTOR
#define _WORK_FLOW_EXECUTOR_

#include <memory> 
#include "WorkFlowParser.h"
#include "BlockFactory.h"

class WorkFlowExecutor
{
	void blockCheck(const list<shared_ptr<Block>>& blockObjects) const;
	void executeBlocks(list<shared_ptr<Block>>& blockObjects);
	void createBlockObjects(blockMap& blocks, list<shared_ptr<Block>>& blockObjects, ifstream& in);
public:
	void executeWorkFlow(ifstream& in);
};

#endif