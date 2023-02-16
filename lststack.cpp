#include "lststack.h"


/* Given:  Nothing (other than the implicit LstStackClass object).
   Task:   To check whether this object is empty.
   Return: true if it is empty, false otherwise.
*/
bool LstStackClass::Empty(void) const
   {
   return List.Empty();   // Note the use of 2 different Empty functions!
   }


/* Given:  Item   A data item.
   Task:   To push item onto the stack (the implicit object).
   Return: Nothing directly, but the implicit object is modified.
*/
void LstStackClass::Push(const ItemType & Item)
   {
   List.InsertFront(Item);
   }


/* Given:  Nothing.
   Task:   To pop the top item from the stack (the implicit object).
   Return: Item   The item popped from the stack.
*/
void LstStackClass::Pop(ItemType & Item)
   {
   Item = List.RemoveFront();   // assumes that = works on this type
   }
