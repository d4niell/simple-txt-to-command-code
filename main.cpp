#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

struct
{
public:

    int ReturnValue = 0;
int CommandAmount = 0;
std::string ErrorReason = " is not an registered external or internal command.";
}status;
void HighLighter(int H)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), H);
}

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
HighLighter(14);

std::cout << "[!] " << status.CommandAmount << " Commands Found!";
HighLighter(7);
Sleep(1000);
std::fstream GetCommands;
GetCommands.open("commands.txt");
while (!GetCommands.eof())
{

status.CommandAmount++;

getline(GetCommands, Command);
if (!Command.find("clearlog"))
{
  int deletelog = remove("output.txt");
if (deletelog != 0)
    {
        status.ReturnValue == 0;
    std::cout << "Returned:" << status.ReturnValue;

}
}
std::cout << "\n\n[*] Start Of " << Command << "\n{\n\n";

if (system(Command.c_str()))
{
std::ofstream AutoReport;

AutoReport.open("output.txt", std::ios::app);
if (!Command.find("ping"))
{
    status.ErrorReason = " Request timed out several times... Maybe down?";
}
if (!Command.find("taskkill"))
{
    status.ErrorReason = " this program isn't running in the background";

}
AutoReport << "\n[ERROR] " << Command << status.ErrorReason;
AutoReport.close();
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
HighLighter(4);
        std::cout << "\n [!] Some of the commands were not executed as they were supposed to. See the output for more details.\n";
        }
        else
        {
HighLighter(10);
            std::cout << "\n [!] Success\n";
        }
HighLighter(7);
system("pause");
return 0;
}

