#include "List.h
#include "List.h"
#include <stdlib.h>
#include <memory.h>
LISTINFO* RemoveFront ( **pList );
LISTINFO* Remove ( **pAfter );
LISTINFO* Front ( pList );
int       IsEmpty ( pList );
int       InsertFront ( pList , /*wsk do inf - pInfo */ );

int       IsEmpty ( pList ) 
{
  return !(pList);
}
LISTINFO* RemoveFront ( **pList )
{
  if ( isEmpty ( *pList ) )
  {
    cout << "ERROR: Stack underflow! xd\n";
    return;
  }

  ListItem* p = *pList;   //jesl info ma dynamiczna pamiec to trza usunac ja
  *pList = p->List;
  free ( p );         //zwolnienie pamieci

}
LISTINFO* Remove ( **pAfter )
{
  if ( isEmpty ( *pAfter) )
  {
    cout << "ERROR: Stack underflow! xd\n";
    return;
  }
  free ( *pAfter );
}
LISTINFO* Front ( *pList )
{
  if ( !isEmpty ( *pList ) )
    return pList->pInfo;
  return 0;
}

int      InsertFront ( **pList , /*wsk do inf - pInfo */ )
{

StackItem* p = ( ListItem* ) malloc ( sizeof ( ListItem ) );
if ( !p )
{
  cout << "ERROR: Stack overflow!\n";
  return;
}
memset ( p , 0 , sizeof ( ListItem ) );
p->pInfo = c;  //c wsk do info
p->pNext = *pList;
*pList = p;

}