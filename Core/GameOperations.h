void drawInterface(Character& myCharacter, std::string line)
{	
		std::cout << "\n\n______________________________________________________________________\n Name: " 
		<< myCharacter.name 
		<< "   Health: " 
		<< myCharacter.health 
		<< "     Class: "
		<< myCharacter.type
		<< "     level: "
		<< intToStr(myCharacter.level)
		<< "   \n experience: "
		<< intToStr(myCharacter.experience)
		<< "	 gold: "
		<< intToStr(myCharacter.gold)
		<< "\n______________________________________________________________________\n"
		<< line << "\n\n\n\n______________________________________________________________________\n"
		<< "e = exit s = save game i = display inventory q = quest r = random battle \nm = market\n______________________________________________________________________\n";
	return;
}

void messageBox(std::string line)
{
		std::cout << "\n\n----------------------------------------------------------------------\n"
		<< line
		<< "\n\n----------------------------------------------------------------------\n\n";
}

int generateRandom(int minValue, int maxValue)
{
	int random = rand() % maxValue + minValue;
	return random;
}

bool saveGame(Character& myCharacter)
{

	std::ofstream settings("Core/Settings.txt");
	if(settings.is_open())
	{
		settings << "Name\n"
		<< myCharacter.name << "\n\n"
		<< "Type\n"
		<< myCharacter.type << "\n\n"
		<< "Health\n"
		<< myCharacter.health << "\n\n"
		<< "Level\n"
		<< myCharacter.level << "\n\n"
		<< "Experience\n"
		<< myCharacter.experience << "\n\n"
		<< "Gold\n"
		<< myCharacter.gold << "\n\n"
		<< "Anti Cheat Code\n"
		<<  myCharacter.generateAntiCheatCode() << "\n\n"
		<< "Inventory\n";
		
		for(int index = 0; index < 20; index ++)
		{
			settings << myCharacter.inventory[index] << "\n";
		}
		settings.close();
		return true;
	}
	else
	{
		return false;
	}
}

Character loadGame()
{
	Character myCharacter;
	std::ifstream settings;
	settings.open("Core/Settings.txt");
	std::string settingsArray[100];
	std::string line;
	int index = 0;
	for(index = 0; settings.good(); index ++)
	{
		std::getline(settings,line);
		settingsArray[index] = line;
	}
	
	index = 0;
	
	while(index < 100)
	{
		if(settingsArray[index] == "Name")
			myCharacter.name = settingsArray[index + 1];
		else if(settingsArray[index] == "Type")
			myCharacter.type = settingsArray[index + 1];
		else if(settingsArray[index] == "Health")
			myCharacter.health = strToInt(settingsArray[index + 1]);
		else if(settingsArray[index] == "Level")
			myCharacter.level = strToInt(settingsArray[index + 1]);
		else if(settingsArray[index] == "Experience")
			myCharacter.experience = strToInt(settingsArray[index + 1]);
		else if(settingsArray[index] == "Gold")
			myCharacter.gold = strToInt(settingsArray[index + 1]);
		else if(settingsArray[index] == "Anti Cheat Code")
			myCharacter.antiCheatCode = strToInt(settingsArray[index + 1]);
		else if(settingsArray[index] == "Inventory")
			for(int accumulator = 0; accumulator < 20; accumulator ++)
				myCharacter.inventory[accumulator] = strToInt(settingsArray[index + accumulator]);
		index ++;
	}
	return myCharacter;
}

Character tutorial()
{
	Character myCharacter;
	std::string messageString;
	std::string choice;
	
	messageBox("This is a messagebox. These are used to display aspects of game content to you, the user. To input data into the game simply type your choice and press enter. Firstly we want to be setting you up a character so to start pick a name");
	while(myCharacter.name == "")
	{
		while(myCharacter.name == "")
		{
			std::cout << "Name: ";
			std::getline(std::cin,myCharacter.name);
			
			if(myCharacter.name == "")
				messageBox("Enter a name");
		}
		
		messageString = "You have chosen the name " + myCharacter.name + " is this okay? y/n";
		messageBox(messageString);
		
		while(choice == "" || choice != "y" && choice != "n")
		{
			std::cout << "choice: ";
			std::getline(std::cin,choice);
			
			if(choice == "" || choice != "y" && choice != "n")
					messageBox("Invalid Input please enter y/n");
			
			if(choice=="n")
				myCharacter.name="";
		}
		choice = "";
	}
	
	messageBox("Okay great! Now pick a class. You have three to choose from; 1. Warrior - These are strong characters with an ability to use a variety of weapons. They have good defence and hp but do less damage. 2. Mage - These characters are experts in magic and are capable of large amounts of damage but have a lower defence. 3. Warlock - These characters use demons and magic to deal damage, they strike a balance between defence and offence. Choose your class. ");
	while(myCharacter.type == "")
	{
		while(myCharacter.type != "mage" && myCharacter.type != "warrior" && myCharacter.type != "warlock")
		{
			std::cout << "Class: ";
			std::getline(std::cin,myCharacter.type);
			
			if(myCharacter.type != "mage" && myCharacter.type != "warrior" && myCharacter.type != "warlock")
				messageBox("Invalid Input please enter mage, warrior or warlock");
		}
		
		messageString = "You have chosen the class " + myCharacter.type + " is this okay? y/n";
		messageBox(messageString);
		
		while(choice == "" || choice != "y" && choice != "n")
		{
			std::cout << "choice: ";
			std::getline(std::cin,choice);
			
			if(choice == "" || choice != "y" && choice != "n")
				messageBox("Please enter y/n");
			
			if(choice == "n")
				myCharacter.type = "";
		}
		choice = "";
	}
	
	myCharacter.level = 1;
	myCharacter.experience = 0;
	myCharacter.gold = 1000;
	
	//To indicate empty places in the inventory fill the array with 0's
	
	for(int index = 0; index < 20; index ++)
		myCharacter.inventory[index] = 0;
	
	
	if(myCharacter.type == "mage")
	{
		myCharacter.health = 100;
		myCharacter.inventory[0] = 1;
	}
	else if(myCharacter.type == "warrior")
	{
		myCharacter.health = 200;
		myCharacter.inventory[0] = 2;
	}
	else if(myCharacter.type == "warlock")
	{
		myCharacter.health = 150;
		myCharacter.inventory[0] = 3;
	}
	
		messageString = "This is your created character profile. \nName: " 
		+ myCharacter.name + "\nHealth: "+ intToStr(myCharacter.health) + "\nType: " 
		+ myCharacter.type + "\nLevel: " + intToStr(myCharacter.level) 
		+ "\nExperience: " + intToStr(myCharacter.experience) 
		+ "\nGold: " + intToStr(myCharacter.gold) + "\n\nAre you happy with it? y/n";
		messageBox(messageString);
		
	while(choice == "" || choice!="y" && choice!= "n")
	{
		std::cout << "Choice: ";
		std::getline(std::cin, choice);
		if(choice != "y" && choice != "n")
			messageBox(" Invalid Input please enter y/n");
		if(choice == "n")
		{
			myCharacter.name = "";
			myCharacter.type = "";
			choice = "";
			tutorial();
		}
	}
	
	return myCharacter;
	std::cin.get();
	}
	
std::string intToStr(int n)
{
	std::ostringstream result;
	result << n;
	return result.str();
}

int strToInt(const std::string& s)
{
	int result;
	std::istringstream ss( s );
	ss >> result;
	return result;
}

std::string concatString(std::string& string1, std::string& string2)
{
	return string1 + string2;
}
