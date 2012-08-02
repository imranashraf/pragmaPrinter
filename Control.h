/*
 * Control.h
 *
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <string>

using namespace std;

class Control
{
	public:
		static bool debugging;
		static string QUIPU_HOME;
		static const char *APPNAME;

	Control();
	virtual ~Control();
	void start();
};

#endif /* MAIN_H_ */
