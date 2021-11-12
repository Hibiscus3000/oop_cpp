#ifndef _WORK_FLOW_PARSER_
#define _WORK_FLOW_PARSER_

#include "MyException.h"
#include <utility>
#include <vector>
#include <string>
#include <list>
#include <fstream>

using namespace std;

typedef list<pair<string,vector<string>>> blockList;

class WorkFlowParser
{
	const string beginLine = "desc\n", endLine = "csed\n";
	void parseBlock(string block, blockList& blocks);
	void getBlockNumber(int& i, string block, string& blockNumber);
	void getBlockName(int& i, int& j, string block, string& blockName);
	void getBlockArgs(int& i, int& j, string block, string& param, vector<string>& nameAndParams);
public:
	blockList getBlocks(ifstream &in);
	list<string> getStructure(ifstream& in);
};

#endif 

