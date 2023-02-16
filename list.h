#include "listnode.h"


class ListClass
   {
   private:
      ListNodePtr GetNode(const ItemType & Item,
         ListNodePtr NextPtr = NULL);
      void FreeNode(ListNodePtr NodePtr);
      void ClearList(void);
      // Next 3 are sometimes made into protected fields:
      ListNodePtr Front, Rear;
      int Count;
   public:
      //  constructor:
      ListClass(void);
      //  destructor:
      ~ListClass(void);
      int NumItems(void) const;
      bool Empty(void) const;
      void InsertFront(const ItemType & Item);
      void InsertRear(const ItemType & Item);
      void InsertInOrder(const ItemType & Item);
      ItemType RemoveFront(void);
      ListNodePtr Find(const ItemType & Item) const;
   };
