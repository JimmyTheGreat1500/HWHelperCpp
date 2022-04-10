#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

//create a checkfolder function
bool dirExists(const std::string& dirName_in)
{
    DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
    if (ftyp == INVALID_FILE_ATTRIBUTES)
        return false;  //something is wrong with your path!

    if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
        return true;   // this is a directory!

    return false;    // this is not a directory!
}

//check if the terms of service have been accepted
bool tosCheck() {
    ifstream ifile;
    ifile.open("./HWHelperFiles/TOS.hw");
    if (ifile) {
        return true;
    }
    ifile.open("./HWHelperFiles/TOS.hw");
    if (ifile) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
	//set the console color to 0d and the title to "homework"
    system("Color 0d");
    SetConsoleTitleA("homework\n");
	
	//make sure the additional files directory exists and if not, create it
    bool dirStatus = dirExists("./HWHelperFiles");
    if (dirStatus == false) {
		system("mkdir ./HWHelperFiles");
    }
    
    //call the tosCheck function, which tests if the terms of service have been accepted
    bool tos = tosCheck();
    if (tos == true) {
        cout << "TOS  Already Accepted\nPlease wait while the program is loading...\n";
    }
    else {
        //TOS has not been accepted, so we need to ask the user to accept it
        system("cls");
        cout << "\nTERMS OF SERVICE:\n---------------------------------------------------------------------\n- You will not reproduce this software.                             -\n- You will not claim ownership of this software.                    -\n- If you give us any feedback, we will not give credit to you.      -\n- You will not sell this software, for one can obtain it for free.  -\n---------------------------------------------------------------------/n";
        cout << "\nDo you agree to the Terms of Service?\n1. I agree to all the terms specified above\n2. No, I'm really annoying so i wont LOL";
        int tosChoice;
		cin >> tosChoice;
		if (tosChoice == 1) {
           // tosYes();
			}
		else {
            system("if exist TOS.hw del TOS.hw");
            system("cls");
			cout << "You have chosen not to accept the Terms of Service.\nPlease restart the program and accept the Terms of Service to continue.\n";
			system("pause");
            system("exit");
	    }
	}
	
    system("pause");

}