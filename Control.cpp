/*
 * Main.cpp
 *
 */

#include "Control.h"
#include "Channel.h"
#include "Exception.h"
#include "Q2XMLFile.h"

#include <iostream>


using namespace std;

bool Control::debugging = true;
string Control::QUIPU_HOME = "";
const char *Control::APPNAME = "CR";

Control::Control()
{
	char *homedir = getenv("HOME");
	if(!homedir)
	{
		throw Exception("$HOME environment variable is not set, is Quipu properly installed?",__FILE__,__LINE__);
	}
	Control::QUIPU_HOME = homedir;
}

Control::~Control()
{
	// TODO Auto-generated destructor stub
}

void Control::start()
{
	string ns("q2:");
	string fileName("q2profiling.xml");
	cout<<"Application Name is "<<Control::APPNAME<<endl;
	cout<<"Opening XML file <"<<fileName<<"> ..."<<endl;
	Q2XMLFile *q2xml = new Q2XMLFile(fileName,ns);

	q2xml->printPragmas();

	delete q2xml;
}

int main(int argc, char *argv[])
{
    try 
    {
        Control control;
        control.start();
    } 
    catch(Exception &e) 
    {
        cout << "Exception occurred at " << e.File() << ":" << e.Line() << endl <<"\twith reason:\"" << e.Reason() << endl;
    }
}
