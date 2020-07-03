#define HEALTH level * level * 100;
#define DAMAGE health / 100 * level + generateRandom(level, health/health + level * 3);
class Witch
{
	public:
		Witch(int wlevel)
		{
			level = wlevel;
			health = HEALTH;
			std::string construct = "A witch appears cackling wildly health: " + intToStr(health) + " level: " + intToStr(level);
			messageBox(construct);
		}
		int attackPlayer()
		{
			int damageDone = DAMAGE;
			std::string damageString = "The witch savagely claws you for " + intToStr(damageDone) + " health!";
			messageBox(damageString);
			return damageDone;
		}
		int getHealth()
		{
			return health;
		}
		
		int setHealth(int newHealth)
		{
			health = newHealth;
			return health;
		}
	protected:
		int health;
		int level;
};