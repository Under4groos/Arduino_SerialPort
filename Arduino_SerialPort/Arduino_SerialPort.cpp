
#include <iostream>
 
#include "lib/httplib.h"

#include <io.h>     
#include <fcntl.h> 



#include "string"
#include <sstream>
using namespace std;
#if defined (_WIN32) || defined(_WIN64)
#define SERIAL_PORT "\\\\.\\COM4"
#endif
#include <vector>
#include "lib/serialib.h"
#define read cin;
#define write cout;
 
std::string str;
httplib::Server svr;
 
std::string trim(const std::string& source) {
	std::string s(source);
	s.erase(0, s.find_first_not_of(" \n\r\t"));
	s.erase(s.find_last_not_of(" \n\r\t") + 1);
	return s;
}
DWORD __stdcall THREAD__A(void* pObject) {
	

	svr.Get("/get", [](const httplib::Request&, httplib::Response& res) {
		if (str == "")
			str = "0:0";
		res.set_content(str, "text/plain");
		});

	svr.listen("0.0.0.0", 8080);
	 
	return 0;
}
 
int o;
char buffer[64];
std::string response;


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	 
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)THREAD__A, 0, 1, 0);
	while (true)
	{
		serialib serial;
		char errorOpening = serial.openDevice(SERIAL_PORT, 9600);

		if (errorOpening != 1) {
			cout << (int)errorOpening << endl;
			cout << "Reloaded" << endl;
			Sleep(1000);
			continue;
		}
		printf("Successful connection to %s\n", SERIAL_PORT);

		
		try
		{
			
			while (true)
			{
				 
				 
				 
				o = serial.readBytes(  buffer, '\n', sizeof buffer);
				response = std::string(buffer);

				if (o == -1) {
					cout << "Close Device" << endl;
					serial.closeDevice();
					break;
				}
				
			 
				cout << response << endl;
			 
					
				 

			}

		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
			serial.closeDevice();
		}

		
	}
	
}

 