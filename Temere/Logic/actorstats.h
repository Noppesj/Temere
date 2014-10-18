#ifndef TEMERE_LOGIC_ACTORSTATS_H
#define TEMERE_LOGIC_ACTORSTATS_H

namespace Temere
{
	namespace Logic
	{
		class ActorStats
		{
			public:

			private:
				unsigned int mHealth;
				unsigned int mMana;
				
				unsigned int mStr;
				unsigned int mDex;
				unsigned int mStam;
				unsigned int mInt;
				unsigned int mLuck;

				unsigned int mMovementSpeed;
				unsigned int mAttackSpeed;
				
				unsigned int mLifeReg;
				unsigned int mManaReg;

				unsigned int mMinDmg;
				unsigned int mMaxDmg;

				unsigned int mCritChance;
				unsigned int mCritDmg;

				unsigned int mArmor;
				unsigned int mDodgeChance;

				/* Resistance values */
				unsigned int mFireRes;
				unsigned int mPosRes;
				unsigned int mElecRes;
				unsigned int mLightRes;
				unsigned int mColdRes;
				unsigned int mDarkRes;
		};
	}
}
#endif