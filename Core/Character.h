class Character
{
	public:
		std::string name;
		std::string type;
		int health;
		int level;
		int experience;
		int gold;
		int inventory[20];
		int antiCheatCode;
		
		void levelUp()
		{
			if(experience = level * level + 100 * level)
				level += 1;
		}
		
		void increaseGold(int amount)
		{
			gold += amount;
		}
		
		void setName(std::string newName)
		{
			name = newName;
		}
		
		void death()
		{
			health = 0;
		}
		
		bool dropInventoryItem(int itemId)
		{
			for(int index = 0; index < 20; index ++)
			{
				if(inventory[index] == itemId)
				{
					inventory[index] = 0;
					return true;
				}
			}
			return false;
		}
		
		bool insertInventoryItem(int itemId)
		{
			for(int index = 0; index < 20; index ++)
			{
				if(inventory[index] == 0)
				{
					inventory[index] = itemId;
					return true;
				}
			}
			return false;
		}
		
		
		int determineInventorySize()
		{
			int inventorySize = 0;
			for(int index = 0; index < sizeof(inventory)/sizeof(inventory[0]); index ++)
			{
				if(inventory[index] != 0)
				{
					inventorySize ++;
				}				
			}
			return inventorySize;
		}
		
		std::string decodeInventory()
		{
			std::string decodedItems;
			int itemCount = 0;
			for(int index = 0; index < sizeof(inventory)/sizeof(inventory[0]); index ++)
			{
				if(inventory[index] != 0)
				{
					itemCount += 1;
					decodedItems += intToStr(itemCount) + ": " + decodeItem(inventory[index]) + "\n";
				}
			}
			decodedItems += "\n\nRemaining inventory spaces left: " + intToStr(sizeof(inventory)/sizeof(inventory[0]) - determineInventorySize());
			return decodedItems;
		}
		
		int generateAntiCheatCode()
		{
			int generatedAntiCheatCode = (gold + health + experience + level) * name.length();
			if(type == "mage")
				generatedAntiCheatCode += 1;
			else if(type == "warrior")
				generatedAntiCheatCode += 2;
			else if(type == "warlock") 
				generatedAntiCheatCode += 3;
			return generatedAntiCheatCode;
		}
		
};
