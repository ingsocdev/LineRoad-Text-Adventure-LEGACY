#include "Core/library.h"

void loadSettings();
void executionLoop(Character& myCharacter, std::string startText);

int main()
{
	std::cout << "Welcome to LineRoad - Copyright Tom Brown 2011\n\n##       #### ##    ## ########    ########   #######     ###    ########\n##        ##  ###   ## ##          ##     ## ##     ##   ## ##   ##     ##\n##        ##  ####  ## ##          ##     ## ##     ##  ##   ##  ##     ##\n##        ##  ## ## ## ######      ########  ##     ## ##     ## ##     ##\n##        ##  ##  #### ##          ##   ##   ##     ## ######### ##     ##\n##        ##  ##   ### ##          ##    ##  ##     ## ##     ## ##     ## \n######## #### ##    ## ########    ##     ##  #######  ##     ## ########";
	loadSettings();
	
}

//Fully loaded program starts its execution loop

void executionLoop(Character& myCharacter, std::string startText, char signal)
{
	char choice = signal;
	for(;;)
	{
		drawInterface(myCharacter, startText);
		std::cout << "\n\nChoice: ";
		while(choice == NULL || choice != 'e' && choice != 's' && choice != 'i' && choice != 'q' && choice != 'r')
		{
		std::cin >> choice;
		switch(choice)
		{
			case 'e':
			{
				return;
			}
			case 's':
			{
				if(saveGame(myCharacter)==true)
					executionLoop(myCharacter, "Your character has been saved.",NULL);
				break;
			}	
			case 'i':
			{
				std::string decodedItems = myCharacter.decodeInventory();
				startText = decodedItems;
				break;
			}
			case 'q':
			{	
				Quest myQuest;
				myQuest.startQuest(myCharacter);
				break;
			}
			case 'r':
			{
				break;
			}
		}
		}
	choice = NULL;
	}
}

//Routine to load settings into memory. Performs conditional processing to check that the data in the settings file is in order.
//The anti cheat code is also evaluated to ensure that the file hasn't been tampered with.

void loadSettings()
{
	Character myCharacter;
	myCharacter = loadGame();
	if(myCharacter.name == "" || myCharacter.type == "" && myCharacter.type != "mage" && myCharacter.type != "warrior" 
	&& myCharacter.type != "warlock" || intToStr(myCharacter.health) == "" || intToStr(myCharacter.level) == "" 
	|| intToStr(myCharacter.experience) == "" || intToStr(myCharacter.gold) == "" || intToStr(myCharacter.inventory[0])==""
	|| intToStr(myCharacter.antiCheatCode) == "" || myCharacter.antiCheatCode != myCharacter.generateAntiCheatCode())
	{
		myCharacter = tutorial();
		if(saveGame(myCharacter)==true) 
			executionLoop(myCharacter, "Your character has been saved. This is the general game interface and will serve as your control panel. To use a specific function just type the coresponding character.",NULL);
		else
		{
			messageBox("An unhandled exception occured. Please restart the tutorial");
			std::cin.get();
			myCharacter = tutorial();
		}
	}
	else executionLoop(myCharacter, "Game Profile Loaded!",NULL);
	return;
}
