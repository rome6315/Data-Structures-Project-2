#include "list.h"
#include <string>

/* Given:  Nothing.
   Task:   This is the constructor to initialize a list to be empty
           (with a dummy node).
   Return: Nothing directly, but the implicit object is created.
*/
ListClass::ListClass(void)
   {
   ItemType Item;

   // We don't care what's in the Info field of the dummy node.
   // Leave whatever garbage is there.
   Front = GetNode(Item, NULL);
   Rear = Front;
   Count = 0;
   }


/* Given:  Nothing.
   Task:   This is the destructor for ListClass.  It's job is to recover
           the space for all nodes remaining on the list.
   Return: Nothing directly, but the implicit object is destroyed.
*/
ListClass::~ListClass(void)
   {
   ClearList();
   FreeNode(Front);  // get rid of the dummy node, too
   }


/* Given:  Nothing.
   Task:   Clear out all nodes on the list except the dummy.
           The list is thus set to an empty list.
   Return: Nothing directly, but the implicit ListClass object is modified.
*/
void ListClass::ClearList(void)
   {
   ListNodePtr Current, Temp;

   Current = Front->Next;
   while (Current != NULL)
      {
      Temp = Current;
      Current = Current->Next;
      FreeNode(Temp);
      }

   Front->Next = NULL;
   Rear = Front;
   Count = 0;
   }


/* Given:  Item     A data item to place in the Info field of a new node.
           NextPtr  The pointer to place in the Next field of the new node.
   Task:   To allocate a new node and place Item and NextPtr in it.
   Return: A pointer to the new node is returned in the function name.
*/
ListNodePtr ListClass::GetNode(const ItemType &Item, ListNodePtr NextPtr)
   {
   ListNodePtr NodePtr;
   string junk;

   try
      {
      NodePtr = new ListNodeClass(Item, NextPtr);
      }
   catch (bad_alloc)
      {
      // Some people might prefer to take a less drastic action in this case.
      // Here we give up on the list and on the entire program.
      cerr << "Memory allocation error!  Calling the destructor and exiting the program." << endl;
      this->~ListClass();
      cerr << "Press Enter" << endl;
      getline(cin, junk, '\n');
      exit(1);
      }

   return NodePtr;
   }


/* Given:  NodePtr   A pointer to a ListNodeClass node.
   Task:   To reclaim the space used by this node.
   Return: Nothing.
*/
void ListClass::FreeNode(ListNodePtr NodePtr)
   {
   delete NodePtr;
   }


/* Given:  Nothing (other than the implicit list object).
   Task:   To look up the number of items in this object.
   Return: This number in the function name.
*/
int ListClass::NumItems(void) const
   {
   return Count;
   }


/* Given:  Nothing (other than the implicit ListClass object).
   Task:   To check whether this object is empty.
   Return: true if this object is empty, false otherwise.
*/
bool ListClass::Empty(void) const
   {
   if (Count > 0)
      return false;
   else
      return true;
   }


/* Given:  Item   A data item.
   Task:   To insert a new node containing Item at the front of the implicit
           ListClass object.
   Return: Nothing directly, but the implicit object is modified.
*/
void ListClass::InsertFront(const ItemType & Item)
   {
   ListNodePtr NodePtr;

   NodePtr = GetNode(Item, Front->Next);
   Front->Next = NodePtr;

   if (Count == 0)
      Rear = NodePtr;
   Count++;
   }


/* Given:  Item   A data item.
   Task:   To insert Item into a new node added to the rear of the implicit
           ListClass object.
   Return: Nothing directly, but the implicit object is modified.
*/
void ListClass::InsertRear(const ItemType & Item)
   {
   ListNodePtr NodePtr;

   NodePtr = GetNode(Item);
   Rear->Next = NodePtr;
   Rear = NodePtr;
   Count++;
   }


/* Given:  Item   A data item.
   Task:   Insert Item into a new node added to the implicit ListClass object
           (assumed to already be in ascending order based on the Info
           field) so as to maintain the ascending order.
   Return: Nothing directly, but the implicit object is modified.
*/
void ListClass::InsertInOrder(const ItemType & Item)
   {
   ListNodePtr Current, Last, Temp;
   bool Proceed;

   Temp = GetNode(Item);
   Current = Front->Next;
   Last = Front;
   Proceed = true;

   while (Proceed && (Current != NULL))
      if (Item > Current->Info)
         {
         Last = Current;
         Current = Current->Next;
         }
      else
         Proceed = false;

   Last->Next = Temp;
   Temp->Next = Current;

   if (Current == NULL)  // item was inserted at rear of list
      Rear = Temp;
   Count++;
   }


/* Given:  Nothing (other than the implicit ListClass object).
   Task:   To remove the data item at the front of this list.
   Return: This data item gets returned in the function name.  The implicit
           object is modified.
*/
ItemType ListClass::RemoveFront(void)
   {
   ListNodePtr NodePtr;
   ItemType Item;

   if (Count == 0)
      {
      cerr << "ERROR: there is no item to remove in the list!" << endl;
      exit(1);
      }

   NodePtr = Front->Next;
   Item = NodePtr->Info;
   Front->Next = NodePtr->Next;
   Count--;
   if (Count == 0)
      Rear = Front;
   FreeNode(NodePtr);
   return Item;
   }


/* Given:   Item   A data item to look up.
   Task:    Look for Item in the implicit ListClass object.
   Return:  In the function name return a pointer to the node where Item
            was found (or the NULL pointer if Item was not found).
*/
ListNodePtr ListClass::Find(const ItemType & Item) const
   {
   ListNodePtr NodePtr;
   bool Found;

   NodePtr = Front->Next;
   Found = false;

   while ((! Found) && (NodePtr != NULL))
      if (NodePtr->Info == Item)
         Found = true;
      else
         NodePtr = NodePtr->Next;

   return NodePtr;
   }
