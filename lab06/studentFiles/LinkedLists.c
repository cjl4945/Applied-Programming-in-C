/******************************************************************************
 An student framework implementation of doubly linked lists that holds 
 elements containing a 256 character string and a sequence number.
 12/24/2017 - R. Repka     Removed AddToFrontOfLinkedList()
 03/12/2018 - R. Repka     Added pseudo code 
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClassErrors.h"
#include "LinkedLists.h"


/******************************************************************************
  Pseudo code: 
  
  add 1st node
    LinkedList front = points to node 1,  LinkedList back = points to node 1
      Node 1 next     = NULL  (at the end)
      Node 1 previous = NULL (at the start)
          
  add 2nd node
    LinkedList front = points to node 1,  LinkedList back = points to node 2
      Node 1 next points to node 2             Node 2 next   = NULL  (at the end)
      Node 1 previous = NULL (at the start)    Node 2 previous points to node 1

  add 3rd node
  LinkedList front = points to node 1,  LinkedList back = points to node 3
      Node 1 next points to node 2           Node 2 next points to node 3      Node 3 next   = NULL  (at the end)
      Node 1 previous = NULL (at the start)  Node 2 previous points to node 1  Node 3 previous points to node 2
      
      
   Remove from front of 3 node list 
    save the pointer to the data and return it at the end
    LinkedList front = points to node 2,  LinkedList back = points to node 3
      Node 2 next points to node 3           Node 3 next   = NULL  (at the end)
      Node 2 previous = NULL (at the start)  Node 3 previous points to node 2
      free Node but NOT the data
******************************************************************************/

/******************************************************************************
 Initialize the linked list data structure.  Points to nothing, no entries.

 Where: LinkedLists *ListPtr - Pointer to the linked list to create
 Returns: nothing
 Errors: none
******************************************************************************/
void InitLinkedList(LinkedLists *ListPtr)
{
	//Initialize the members of the struct LinkedLists
	ListPtr -> NumElements = 0;
	ListPtr -> FrontPtr = NULL;
	ListPtr -> BackPtr = NULL;

} /* InitLinkedList() */


/******************************************************************************
 Adds a node to the back of the list.

 Where: LinkedLists *ListPtr    - Pointer to the linked list to add to
        char *DataPtr - Pointer to the data to add to the list
 Returns: nothing
 Errors: Prints to stderr and exits
******************************************************************************/
void AddToBackOfLinkedList(LinkedLists *ListPtr, char *DataPtr)
{
	LinkedListNodes *NewNode;
	NewNode = (LinkedListNodes*) malloc(sizeof(LinkedListNodes));
	NewNode -> Next = NULL;
	NewNode -> Previous = ListPtr -> BackPtr;
	//puts the data inputted into the LinkedListNodes 
	strncpy(NewNode -> String, DataPtr, MAX_BUFF_LEN);
	ListPtr -> BackPtr = NewNode;

	// if there are no elements set the new node to the front
	if(ListPtr -> NumElements == 0)
	{
		ListPtr -> FrontPtr = NewNode;
	} 
	// else if there is an elemetns set the new node's previous' next to 
	// the new node
	else{
    		(NewNode -> Previous) -> Next = NewNode;
	}
//increment the number of elements after everything is set
  ListPtr -> NumElements ++;

} /* AddToBackOfLinkedList */

/******************************************************************************
 Removes a node from the front of the list and returns a pointer to the node
 data removed. On empty lists should return a NULL pointer.
 Note: This will destroy the node but not the associated data element.
  
 Where: LinkedLists *ListPtr    - Pointer to the linked list to remove from
 Returns: Pointer to the node removed or NULL for none
 Errors: none
******************************************************************************/
char *RemoveFromFrontOfLinkedList(LinkedLists *ListPtr)
{
  char * NewStruct;
  LinkedListNodes *NewNode;

  if (ListPtr -> NumElements == 0)
  {
    return NULL;
  }

  NewNode = ListPtr -> FrontPtr; //pointer to removed node
  NewStruct = (ListPtr -> FrontPtr) -> String;

//if there isn't less than or equal to one element
  if (ListPtr -> FrontPtr != ListPtr -> BackPtr)
  {    
    ListPtr -> FrontPtr = (ListPtr -> FrontPtr) -> Next;
    (ListPtr -> FrontPtr) -> Previous = NULL;
   
  }
//if there's one element or nothing
  else
  {
    ListPtr -> FrontPtr = NULL;
    ListPtr -> BackPtr = NULL;
   // free(ListPtr -> FrontPtr);
  }
  free((ListPtr -> FrontPtr) -> Previous);
  ListPtr -> NumElements--; //decrement the number of elements

  if (NewNode == NULL)
  {
    return NULL;
  }
  free(NewNode);
  return NewStruct;
  
} /* RemoveFromFrontOfLinkedList() */

/******************************************************************************
 Removes a node from the back of the list and returns a pointer to the node
 data removed. On empty lists should return a NULL pointer.
 Note: This will destroy the node but not the associated data element.
  
 Where: LinkedLists *ListPtr    - Pointer to the linked list to remove from
 Returns: Pointer to the node removed or NULL for none
 Errors: none
******************************************************************************/
 /* RemoveFromBackOfLinkedList() */


/******************************************************************************
 De-allocates the linked list and resets the struct fields (in the header) 
 to indicate that the list is empty.

 Where: LinkedLists *ListPtr    - Pointer to the linked list to destroy
 Returns: nothing
 Errors: none
******************************************************************************/
void DestroyLinkedList(LinkedLists *ListPtr)
{
  int ii;

  LinkedListNodes *NodePtr;

//destroy the linked list in for loop
  for (ii = ListPtr ->NumElements; ii > 0; ii--)
  {
    NodePtr = ListPtr -> FrontPtr;

    ListPtr -> FrontPtr = NodePtr -> Next;

    ListPtr -> NumElements--;

      
    free(NodePtr);
    //if linked list is empty then break
    if(ListPtr ->FrontPtr == NULL)
    {
      break;
    }
    (ListPtr -> FrontPtr) ->Previous = NULL;
  }
  
} /* DestroyLinkedList() */


/******************************************************************************
 * Searches the linked list for a provided word. If found, returns the pointer
 to the element struct. If not found, returns a NULL pointer
 
 Where: LinkedLists *ListPtr - Pointer to the linked list to search
        char *String         - Pointer to the string to search
 Returns: Pointer to the element if found, NULL otherwise
 Errors: none
 * ***************************************************************************/
 char *SearchList(LinkedLists *ListPtr, char *String)
 {
	LinkedListNodes *strList;
	if(ListPtr == NULL)
	{
		return NULL;
	}
	
	else
	{
		strList = ListPtr->FrontPtr;
		while(strList != NULL)
		{

			if(strcmp(strList->String,String) == 0)
			{
				return strList->String;
			}
			strList = strList->Next;
		}
		return NULL;
	}
 /*-----  Don't implement this until instructed in Lab 6 ----*/
 
 } /* SearchList() */




