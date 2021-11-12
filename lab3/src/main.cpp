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
	BlockMaker<ReadFile> readfile(ReadFile::getName());
	BlockMaker<WriteFile> writefile(WriteFile::getName());
	BlockMaker<Grep> grep(Grep::getName());
	BlockMaker<Sort> sort(Sort::getName());
	BlockMaker<Replace> replace(Replace::getName());
	BlockMaker<Dump> dump(Dump::getName());
	WorkFlowExecutor workFlow;
	workFlow.executeWorkFlow(workFlowFile);
	return 0;
}