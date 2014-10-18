#ifndef SV11_GRAPHIC_MODELOBJECT_H
#define SV11_GRAPHIC_MODELOBJECT_H


#include "graphicobject.h"

namespace Temere
{
	namespace Graphic
	{
		class ModelObject : public GraphicObject
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX ModelObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX ModelObject(const ModelObject& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~ModelObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const ModelObject& operator=(const ModelObject& ref);
				
				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadObj(const std::string& path);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void test();
			private:
			
		};
	}
}
#endif