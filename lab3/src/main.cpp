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
	cin >> workFlowFileName;
	ifstream workFlowFile(workFlowFileName);
	try
	{
		if (!workFlowFile)
			throw MyException("couldn't open workflow file", workFlowFileName);
		BlockMaker<ReadFile> readfile("readfile");
		BlockMaker<WriteFile> writefile("writefile");
		BlockMaker<Grep> grep("grep");
		BlockMaker<Sort> sort("sort");
		BlockMaker<Replace> replace("replace");
		BlockMaker<Dump> dump("dump");
		WorkFlowExecutor workFlow;
		workFlow.executeWorkFlow(workFlowFile);
	}
	catch (MyException& ex)
	{
		cerr << ex.what() << endl;
		ex.showLine();
		return 1;
	}
	return 0;
}