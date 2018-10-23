#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <shlobj.h>
#include <exdisp.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <mmsystem.h>
#include <MMSystem.h>


using namespace std;


#define MIN_ALL        419
#define MIN_ALL_UNDO   416

bool setBackground();

const string strLocalDirectory = "C:\\Users\\Jeffrey\\Desktop\\Programing\\Projects\\Monika\\Monika\\Images\\"; // TWEAKED PATH

string filePath;

void changeIt() // so no warnings about unref params
{
  if(setBackground()) {
    cout << "Applied Background: " << filePath << "\n";
  } else {
     DWORD DWLastError = GetLastError();
     cout << "\nError: " << std::hex << DWLastError;
  }
  //cin.get();
  //return EXIT_SUCCESS;
}

bool setBackground()
{
  int dirSize = 5;  //Will be automated later.
  int bgChoice = 0; //Index of chosen wallpaper.

  srand ( (unsigned int)time(NULL) );
  bgChoice = rand() % dirSize + 1;
  //Convert the index choice into a usable filename string.
  stringstream ssFilePath;
  ssFilePath << strLocalDirectory << bgChoice << ".jpg";
  //Returns true on success, false otherwise.
  if( SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (PVOID)ssFilePath.str().c_str(),
                            SPIF_UPDATEINIFILE | SPIF_SENDCHANGE) != 0)
  {
    filePath = ssFilePath.str();
    return true;
  }

  return false;
}
/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    PlaySound("Hej.wav", NULL, SND_ASYNC);
    return 0;
}
*/


int main(int argc, char* argv[])
{
    PlaySound(TEXT("C:\\Users\\Jeffrey\\Desktop\\Programing\\Projects\\Monika\\Monika\\Hej.wav") , NULL , SND_SYNC);
    changeIt();
    // I am unsure what this does
	HWND lHwnd = FindWindow("Shell_TrayWnd",NULL);
	// minimize
	SendMessage(lHwnd,WM_COMMAND,MIN_ALL,0);
    PlaySound(TEXT("C:\\Users\\Jeffrey\\Desktop\\Programing\\Projects\\Monika\\Monika\\MONIKA.wav") , NULL , SND_SYNC);
	// this causes a delay
	Sleep(2000);
	// unminimize
	SendMessage(lHwnd,WM_COMMAND,MIN_ALL_UNDO,0);
	return 0;
}
