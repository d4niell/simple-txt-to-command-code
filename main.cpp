#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

struct
{
public:
    int ReturnValue = 0;
int CommandAmount = -1;
}status;


int main()
{



std::fstream GetCommandAmount;
GetCommandAmount.open("commands.txt");
std::string Command = " ";
while (!GetCommandAmount.eof())
{
getline(GetCommandAmount, Command);
status.CommandAmount++;
}
system("title txt to command converter!");
GetCommandAmount.close();
std::cout << "[!] " << status.CommandAmount << " Commands Found!";
Sleep(1000);
std::fstream GetCommands;
GetCommands.open("commands.txt");
while (!GetCommands.eof())
{
status.CommandAmount++;

getline(GetCommands, Command);

std::cout << "\n\n[*] Start Of " << Command << "\n{\n\n";

if (system(Command.c_str()))
{

    status.ReturnValue = 1;



}
else
    {
      std::cout << "\n\n}\n[*] End Of " << Command << "\n\n";
    }

}




        std::cout << "\n\n [*] Program ended with return of: " << status.ReturnValue;
        if (status.ReturnValue != 0)
        {
        std::cout << "\n [!] false\n";
        }
        else
        {
            std::cout << "\n [!] true\n";
        }
system("pause");
return 0;
}
