class Quest
{
	public:
		void startQuest(Character& myCharacter)
		{
			std::string choice = "";
			messageBox("Welcome to LineRoad - a desolate kingdom in control of the ruthless monarch King Brengor. You are tasked with liberating the kingdom and its besieged inhabitants by any means necessary.\n\n Would you like to accept this quest?\ny/n");
			std::cout << "Choice: ";
			while(choice == "" || choice != "y" && choice != "n")
			{ 
				if(choice != "")
				{
					messageBox("Invalid Input please choose y/n");
					std::cout << "Choice: ";
				}
				std::getline(std::cin, choice);
			}
			if(choice == "n")
			{
				return;
			}
			choice = "";
			messageBox("Humbled by the importance of your mission you decide it's best to get a move on. After walking for several hours you reach a crossroads. Do you want to go north, east or west?");
			std::cout << "Direction: ";
			while(choice == "" || choice != "north" && choice != "east" && choice != "west")
			{
				if(choice != "")
				{
					messageBox("Invalid Input please choose north, east or west");
					std::cout << "Choice: ";
				}
				std::getline(std::cin, choice);
			}
			Monsters monsters(myCharacter);
		}
		
};