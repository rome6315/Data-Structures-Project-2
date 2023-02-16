#include "itemtype.h"


class ListNodeClass
   {
   private:
      ItemType Info;
      ListNodeClass * Next;
   public:
      // First, the constructor:
      ListNodeClass(const ItemType & Item, ListNodeClass * NextPtr = NULL):
         Info(Item), Next(NextPtr)
            {
            };
      void GetInfo(ItemType & TheInfo) const;
   friend class ListClass;   // very convenient to allow this
   };

typedef ListNodeClass * ListNodePtr;
