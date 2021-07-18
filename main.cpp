#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
struct
{
public:
std::string ConfigName = "Commands.txt";
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
std::cout << "press \"enter\" if you want to load an config.\nPress any other key if you don't want to load a config.\n";
char key = getch();
if (key == '\r')
{
tryagain:
    std::cout << "config name:"; std::cin >> status.ConfigName;
status.ConfigName = status.ConfigName;
std::fstream LoadConfig;
 if (status.ConfigName.find(".con"))
    {
        LoadConfig.open(status.ConfigName + ".con");
    }
    else
    {


LoadConfig.open(status.ConfigName);
    }
if (LoadConfig.is_open())
{
    LoadConfig.close();
}
else
{
    HighLighter(4);
    std::cout << "\n[!] Config not found!\n";
HighLighter(7);
    Sleep(500);
    system("cls");
    goto tryagain;
}
}
system("cls");

std::fstream GetCommandAmount;
if (status.ConfigName.find(".con"))
    {
        GetCommandAmount.open(status.ConfigName + ".con");
    }
    else
{


GetCommandAmount.open(status.ConfigName);
}
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
if (status.ConfigName.find(".con"))
    {
        GetCommands.open(status.ConfigName + ".con");
    }
    else
    {


GetCommands.open(status.ConfigName);
    }
while (!GetCommands.eof())
{//hhh

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
//poggers
if (!Command.find("echo"))
{
    std::cout << "[!]" << Command;
}
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
