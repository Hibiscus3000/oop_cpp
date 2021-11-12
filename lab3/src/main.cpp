#include "ReadFile.h"
#include "WriteFile.h"
#include "Grep.h"
#include "Sort.h"
#include "Replace.h"
#include "Dump.h"
#include "WorkFlowExecutor.h"
#include "BlockMaker.h"

int main()
{
	string workFlowFileName;
	ifstream workFlowFile(workFlowFileName);
	BlockMaker<ReadFile> readfile("readfile");
	BlockMaker<WriteFile> writefile("writefile");
	BlockMaker<Grep> grep("grep");
	BlockMaker<Sort> sort("sort");
	BlockMaker<Replace> replace("replace");
	BlockMaker<Dump> dump("dump");
	WorkFlowExecutor workFlow;
	workFlow.executeWorkFlow(workFlowFile);
	return 0;
}