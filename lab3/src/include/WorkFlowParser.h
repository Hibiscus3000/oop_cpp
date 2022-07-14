#ifndef _WORK_FLOW_PARSER_
#define _WORK_FLOW_PARSER_

#include "MyException.h"
#include <utility>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <map>

using namespace std;

typedef map<string, vector<string>> blockMap;

class WorkFlowParser
{
	const string beginLine = "desc", endLine = "csed";
	void parseBlock(string block, blockMap& blocks);
	void getBlockNumber(int& i, string block, string& blockNumber);
	void getBlockName(int& i, int& j, string& block, string& blockName);
	void getBlockArgs(int& i, int& j, string& block, vector<string>& nameAndParams);
public:
	blockMap getBlocks(ifstream& in);
};

#endif 

