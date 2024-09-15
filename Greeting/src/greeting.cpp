#include <greeting.h>
#include <sstream>

#include <string.h>

using namespace std;

string greet(const char *name)
{
    string returnValue = "Hello World!";

    if (name != nullptr && strlen(name))
    {
        stringstream ss;
        ss << "Hello " << name << "!";

        returnValue = ss.str();
    }

    return returnValue;
}