#include "Controller.h"
#include "PlayerCreator.h"
#include "MyException.h"

int main()
{
	try
	{
		PlayerCreator<Human> human("human");
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