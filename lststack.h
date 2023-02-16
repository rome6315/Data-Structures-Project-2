#include "list.h"


class LstStackClass
   {
   public:
      // No constructor is mentioned here.  We instead use the default
      // constructor automatically supplied by the compiler.
      bool Empty(void) const;
      void Push(const ItemType & Item);
      void Pop(ItemType & Item);
   private:
      ListClass List;   // an embedded List object
   };
