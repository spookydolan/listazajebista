#ifndef _global_h
#define _global_h
#include "global.h"
typedef int(*ptc)(const void* , const void*);
typedef struct tagListItem
{
  LISTINFO * pInfo;
  tagListItem* pNext;
  tagListItem* First = NULL;
} ListItem;


// module: list.h (module interface)  list.cpp (module implementation) g

// ZABEZPIECZYC PREPROCESOREM PRZED WIELOKROTNYM INKLUDOWANIEM !!!!! g

// include global.h which should be defined by the user !!!g
  // w pliku global.h  g
  //  zdefinowac typ uzytkonika -  g


// the list with the empty elem on top (GUARD)
// the user define own list variable and
// has to use CreateList() first
// and FreeList() at the end

//zdefiniowac typ strukturalny o nazwie ListItem
 // Pola:  m_pInfo  typu zdefiniowanego przez uzytkownika - stala preprocesora LISTINFO g
 //        m_pNext  wsk do nastepnego elementu na liscie  (tagListItem) g

ListItem* CreateList ( ); //empty elem on top (GUARD)

int       InsertFront ( pList , /*wsk do inf - pInfo */ ); // insert na poczatku (jak na stosie)
int       Insert ( pAfter , /*wsk do inf - pInfo */ ); // insert po elemencie wskazywanym przez pAfter

LISTINFO* RemoveFront ( pList );  // usun pierwszy elem listy (jak del() w stosie)
LISTINFO* Remove ( pAfter );      // usun element po elemencie wsk przez pAfter

LISTINFO* Front ( pList );        // zwraca wsk do pierwszego (jak top() w stosie)

int       IsEmpty ( pList );     // 1 pusta,  0 -nie pusta  - nie uzywac if!

void      ClearList ( pList , /* pointer to the function of void type with one parameter const void*  */ );
void      RemoveList ( pList , /* pointer to the function of void type with one parameter const void*  */ );
// after removing, set list as NULL

void      SortList ( pList ,
  /* pointer to the function with two parameters const void* and returned int value */ );

ListItem* Find ( pList , pItem/*pointer to the wanted - const void* */ , pPrev/*wsk na poprzednigo do znalezionego*/ ,
  /* pointer to the function with two parameters const void* and returned int value */ );
ListItem* CreateList ( );
int isEmpty ( ListItem* p );
ListItem* Front ( ListItem* p );
void RemoveFront ( ListItem* p ); // funkcja usuwa pierwszy element
void Remove ( ListItem* pAfter );
void Insert ( ListItem* pAfter , LISTINFO* pInfo );
void FreeList ( ListItem* p );
void DelList ( ListItem** p );
void InsertFront ( ListItem* p , LISTINFO* pInfo );
ListItem* Find ( ListItem* p , const void* value , ListItem** previous , ptc compare );
int compare ( const void* p , const void* v );
void SortList ( ListItem* p , ptc compare );



#endif
