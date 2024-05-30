
#include <iostream>
#include "lib/serialib.h"
#include "string"
#include <sstream>
using namespace std;
#if defined (_WIN32) || defined(_WIN64)
#define SERIAL_PORT "\\\\.\\COM3"
#endif
#include <vector>

#define read cin;
#define write cout;
std::vector<std::string> tokens;
size_t pos = 0;


std::vector<std::string> Splet(std::string str , std::string delimiter) {
	tokens.clear();
	pos = 0;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		tokens.push_back(str.substr(0, pos));
		str.erase(0, pos + delimiter.size());
	}
	return tokens;
}

int main()
{
	
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

		unsigned char received[8];
		char buffer[15] = "";
		std::string str(buffer);
		 
		int o;
		try
		{
			
			while (true)
			{

				o = serial.readString(buffer, '\n', 128, 2000);
				if (o == -1) {
					cout << "Close Device" << endl;
					serial.closeDevice();
					break;
				}
				
				if (buffer) {
					str = { buffer };

					for (const auto& str : Splet(str,":")) {
						std::cout << str << std::endl;
					}
					Sleep(1000);
				}
					
				 

			}

		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
			serial.closeDevice();
		}

		
	}
	
}

 