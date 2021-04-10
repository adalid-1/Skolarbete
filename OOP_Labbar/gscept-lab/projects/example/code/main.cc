//------------------------------------------------------------------------------
// main.cc
// (C) 2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include <iostream>
using namespace std;

int
main(int argc, const char** argv)
{
	Example::AssignmentApp & app = Example::AssignmentApp::GetInstance();
	if (app.Open())
	{
		app.Run();
		
		app.Close();
	}
	app.Exit();
	
}

/*
int main()
{
Matrix2D rot;
Matrix2D matris(1.0, 2.0, 3.0, 4.0);


rot = rot.rotation(3.14/2);
matris = rot * matris;
cout << matris.get(0,0) << "........." << matris.get(0,1) << endl;
cout << matris.get(1,0) << "........." << matris.get(1,1) << endl; 

system("PAUSE");
*/
