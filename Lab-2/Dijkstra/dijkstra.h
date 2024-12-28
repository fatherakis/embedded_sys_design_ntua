#define SLL
//#define DLL
//#define DYN_ARR


#if defined(SLL)
#include "../synch_implementations/cdsl_queue.h"
#endif
#if defined(DLL)
#include "../synch_implementations/cdsl_deque.h"
#endif
#if defined(DYN_ARR)
#include "../synch_implementations/cdsl_dyn_array.h"
#endif

struct _NODE{
  int iDist;
  int iPrev;
};
typedef struct _NODE NODE;

struct _QITEM {
  int iNode;
  int iDist;
  int iPrev;
  //struct _QITEM *qNext;
#if defined(SLL_PK)
	cdsl_sll *qList;
#elif defined(DLL_PK)
	cdsl_dll *qList;
#else
	cdsl_dyn_array *qList;
#endif
};
typedef struct _QITEM QITEM;

