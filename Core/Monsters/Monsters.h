#include "Witch.h"

class Monsters
{
	public:
		Monsters(Character &myCharacter)
		{
			int randomNum = generateRandom(1,1);
			for(int index = 0; index < randomNum; index ++)
			{
				if(index = randomNum)
				{
					monsterID = index; 
					attackDialog(monsterID, myCharacter);
				}
			}
		}
	protected:
		int monsterID;
		int battlePanel()
		{
			
		}
		void attackDialog(int id, Character &myCharacter)
		{
			int levelRange = generateRandom(myCharacter.level, myCharacter.level + 5);
				switch (id)
				{
					case 1:
						Witch witch(levelRange);
						myCharacter.health -= witch.attackPlayer();
						std::cin.get();
						break;
					}
				}
};