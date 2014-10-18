#ifndef TEMERE_SCENE_QUADTREE_H
#define TEMERE_SCENE_QUADTREE_H

#include "..\\Utility\macro.h"
#include "..\\Utility\object.h"
#include "rect.h"
#include <vector>

namespace Temere
{
	namespace Scene
	{
		class QuadTree
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX QuadTree(unsigned int level, Rect *hitbox, unsigned maxLevels, unsigned int maxObjects);		
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~QuadTree();

				TEMERE_DYNAMIC_LIBRARY_PREFIX void clear();
				TEMERE_DYNAMIC_LIBRARY_PREFIX int getIndex(Rect *hitbox);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void insert(Rect *hitbox);
				TEMERE_DYNAMIC_LIBRARY_PREFIX std::vector<Rect*> retrieve(std::vector<Rect*> &returnObjects, Rect *rect);
			private:
				unsigned int mMaxObjects;
				unsigned int mMaxLevels;
				unsigned int mCurrentLevel;

				std::vector<Rect*> mObjects;
				Rect *mHitBox;

				QuadTree *mNodes[4];

				TEMERE_DYNAMIC_LIBRARY_PREFIX QuadTree();
				TEMERE_DYNAMIC_LIBRARY_PREFIX QuadTree(const QuadTree& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX const QuadTree& operator=(const QuadTree& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void split();
		};
	}
}
#endif