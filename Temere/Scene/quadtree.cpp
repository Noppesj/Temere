#include "quadtree.h"

using namespace Temere::Scene;


QuadTree::QuadTree()
{
	mMaxObjects = 10;
	mMaxLevels = 5;
}

QuadTree::QuadTree(unsigned int level, Rect *hitbox, unsigned maxLevels, unsigned int maxObjects)
{
	mCurrentLevel = level;
	mHitBox = hitbox;
	mMaxLevels = maxLevels;
	mMaxObjects = maxObjects;

	//mNodes = TEMERE_NEW QuadTree[4];
}

QuadTree::QuadTree(const QuadTree& ref)
{
	(void)ref;
}

QuadTree::~QuadTree()
{
	for(unsigned int i = 0; i < 4; i++)
	{
		TEMERE_SAFE_DELETE(mNodes[i])
	}

	TEMERE_SAFE_DELETE(mHitBox)
}

const QuadTree& QuadTree::operator=(const QuadTree& ref)
{
	if (this != &ref)
	{
		
	}
	return *this;
}

void QuadTree::clear()
{
	mObjects.clear();

	for(unsigned int i = 0; i < 4; i++)
	{
		if(mNodes != nullptr)
		{
			mNodes[i]->clear();
			TEMERE_SAFE_DELETE(mNodes[i])
		}
	}

	TEMERE_SAFE_DELETE(mHitBox)
}

void QuadTree::split()
{
	float subWidth = (mHitBox->getWidth() * 0.5f);
	float subHeight = (mHitBox->getHeight() * 0.5f);
	float x = mHitBox->getPosition().x;
	float y = mHitBox->getPosition().y;

	mNodes[0] = TEMERE_NEW QuadTree(mCurrentLevel+1, TEMERE_NEW Rect(x + subWidth, y, subWidth, subHeight), mMaxLevels, mMaxObjects);
	mNodes[1] = TEMERE_NEW QuadTree(mCurrentLevel+1, TEMERE_NEW Rect(x, y, subWidth, subHeight), mMaxLevels, mMaxObjects);
	mNodes[2] = TEMERE_NEW QuadTree(mCurrentLevel+1, TEMERE_NEW Rect(x, y + subHeight, subWidth, subHeight), mMaxLevels, mMaxObjects);
	mNodes[3] = TEMERE_NEW QuadTree(mCurrentLevel+1, TEMERE_NEW Rect(x + subWidth, y + subHeight, subWidth, subHeight), mMaxLevels, mMaxObjects);
}

int QuadTree::getIndex(Rect *hitbox)
{
	int index = -1;
	double verticalMidPoint = hitbox->getPosition().x + (hitbox->getWidth() * 0.5f);
	double horizontalMidPoint = hitbox->getPosition().y + (hitbox->getHeight() * 0.5f);

	// Object can completely fit within the top quadrants
	bool topQuadrant = (hitbox->getPosition().y < horizontalMidPoint && hitbox->getPosition().y + hitbox->getHeight() < horizontalMidPoint);
	// Object can completely fit within the bottom quadrants
	bool bottomQuadrant = (hitbox->getPosition().y > horizontalMidPoint);

	// Object can completely fit within the left quadrants
	if (hitbox->getPosition().x < verticalMidPoint && hitbox->getPosition().x + hitbox->getWidth() < horizontalMidPoint) 
	{
		if (topQuadrant)
		{
			index = 1;
		}
		else if (bottomQuadrant) 
		{
			index = 2;
		}
	}
	// Object can completely fit within the right quadrants
	else if (hitbox->getPosition().x > verticalMidPoint) 
	{
		if (topQuadrant) 
		{
			index = 0;
		}
		else if (bottomQuadrant) 
		{
			index = 3;
		}
	}
	return index;
}

void QuadTree::insert(Rect *hitbox)
{
	if (mNodes[0] != nullptr) 
	{
		int index = getIndex(hitbox);

		if (index != -1) 
		{
			mNodes[index]->insert(hitbox);
			return;
		}
	}

	mObjects.push_back(hitbox);

	if (mObjects.size() > mMaxObjects && mCurrentLevel < mMaxLevels) 
	{
		if (mNodes[0] == nullptr) 
		{
			split();
		}

		unsigned int i = 0;
		while (i < mObjects.size()) 
		{
			int index = getIndex(mObjects[i]);
			if (index != -1) 
			{
				mNodes[index]->insert(mObjects[i]);
				mObjects.erase(mObjects.begin() + i);
			}
			else 
			{
				i++;
			}
		}
	}
}

std::vector<Rect*> QuadTree::retrieve(std::vector<Rect*> &returnObjects, Rect *rect)
{
	int index = getIndex(rect);
	
	if(index != -1 && mNodes[0] != nullptr)
	{
		mNodes[index]->retrieve(returnObjects, rect);
	}
	for (auto& x: mObjects)
	{
		returnObjects.push_back(x);
	}
	return returnObjects;
}