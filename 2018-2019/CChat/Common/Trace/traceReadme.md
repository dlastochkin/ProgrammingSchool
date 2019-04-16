# ProgrammingSchool
Public repository for Programming School projects

Пример испольхования:
<code>
#include "CChatTrace.h"

int main(int argc, char *argv[])
{
	CChatTrace* trace = new CChatTrace();
	trace->import("C:\\Users\\User\\Desktop\\trace.txt");
	FileTraceDestination* fdest = new FileTraceDestination("C:\\Users\\User\\Desktop\\trace.txt");
	trace->addDestination(fdest);
	trace->add("kek", DEBUG);
	return 0;
}
</code>