/*
  Name:Thomas Pham
  CruzID: tpham26
  Pa5
*/

//-----------------------------------------------------------------------------
// List.h
// Header file for List ADT
//-----------------------------------------------------------------------------

#ifndef _LIST_H_INCLUDE_
#define _List_H_INCLUDE_


// Exported type --------------------------------------------------------------
typedef struct ListObj* List;


// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object.
List newList(void);

// freeList()
// Frees all heap memory associated with Queue *pQ, and sets *pQ to NULL.
void freeList(List* pL);


// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L);

//Returns value at the back of L
int back(List L);
// getLength()
// Returns the length of L.
int length(List L);

// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0)
int isEmpty(List L);

//returns index of cursor element
int index(List L);

//returns weather or not A==B
int equals(List A, List B);

//returns cursor data
int get(List L);

// Manipulation procedures ----------------------------------------------------

//Returns List to its orginal State
void clear(List L);

//Moves the cursor to the first element in the list
//Sets index to 0
void moveFront(List L);

//Move the cursor to the back element.
//sets index to list.length - 1
void moveBack(List L);

// If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev(List L);

// If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext(List L);

// Insert new element into this List. If List is non-empty,
// insertion takes place before front element.
void prepend(List L, int data);

// Insert new element into this List. If List is non-empty,
// insertion takes place after back element.
void append(List L, int data);

// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int data);

// Inserts new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int data);

// Deletes the front element. Pre: length()>0
void deleteFront(List L);

// Deletes the back element. Pre: length()>0
void deleteBack(List L);

// Deletes cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L);



// Other Functions ------------------------------------------------------------

// printList()
//Writes entire list in order to file.
void printList(FILE* out, List L);

//Returns an identical copy of the list.
List copyList(List L);

#endif
