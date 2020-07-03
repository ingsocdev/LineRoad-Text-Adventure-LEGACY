
std::string decodeItem(int item)
{
	if(item == 1)
		return "Staff";
	if(item == 2)
		return "Sword";
	if(item == 3)
		return "Dagger";
	else return "";
}


class Staff
{
	public:
		Staff()
		{
			itemId = 1;
			minDamage = 1;
			maxDamage = 10;
			criticalChance = 1;
			dodgeChance = 10;
		}
	protected:
		//The item id as it will be read from a file
		int itemId;
		int minDamage;
		int maxDamage;
		int criticalChance;
		int dodgeChance;
};
