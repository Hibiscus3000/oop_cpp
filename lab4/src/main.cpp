#include "Controller.h"
#include "BotCreator.h"
#include "MyException.h"

int main()
{
	try
	{
		Controller controller;
		controller.play();
	}
	catch (MyException& ex)
	{
		ex.errorReport();
		return 1;
	}
	return 0;
}