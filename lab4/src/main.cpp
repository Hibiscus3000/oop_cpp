#include "Controller.h"
#include "BotCreator.h"
#include "MyException.h"
#include <ctime>
#include "EasyBot.h"
#include "MediumBot.h"
#include "HardBot.h"

int main()
{
	srand((unsigned)time(0));
	try
	{
		BotCreator<EasyBot> easyBot("easy");
		BotCreator<EasyBot> mediumBot("medium");
		BotCreator<EasyBot> hardBot("hard");
		Controller controller;
		controller.start();
	}
	catch (MyException& ex)
	{
		ex.errorReport();
		return 1;
	}
	return 0;
}