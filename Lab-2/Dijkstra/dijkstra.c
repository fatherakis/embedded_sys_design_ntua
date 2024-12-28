#include <stdio.h>
#include <dijkstra.h>
#define NUM_NODES                          100
#define NONE                               9999


#if defined(SLL_PK)
	cdsl_sll *finList;
#elif defined(DLL_PK)
	cdsl_dll *finList;
#else
	cdsl_dyn_array *finList;
#endif


QITEM *qHead = NULL;
             
int AdjMatrix[NUM_NODES][NUM_NODES];

int g_qCount = 0;
NODE rgnNodes[NUM_NODES];
int ch;
int iPrev, iNode;
int i, iCost, iDist;


void print_path (NODE *rgnNodes, int chNode)
{
  if (rgnNodes[chNode].iPrev != NONE)
    {
      print_path(rgnNodes, rgnNodes[chNode].iPrev);
    }
  printf (" %d", chNode);
  fflush(stdout);
}


void enqueue (int iNode, int iDist, int iPrev)
{

  QITEM *qLast = qHead; //try the bbelow code
  
 /*  #if defined (SLL_CL)
	  iterator_cdsl_sll it, end;
	  finList = cdsl_sll_init();
  #elif defined (DLL_CL)
    iterator_cdsl_dll it, end;
    finList = cdsl_dll_init();
  #else 
    iterator_cdsl_dyn_array it, end;
    finList = cdsl_dyn_array_init();	
  #endif */



  QITEM *qNew = (QITEM *) malloc(sizeof(QITEM));
  
  if (!qNew) 
    {
      fprintf(stderr, "Out of memory.\n");
      exit(1);
    }
  qNew->iNode = iNode;
  qNew->iDist = iDist;
  qNew->iPrev = iPrev;

  #if defined (SLL_PK)
	  qNew->qList = cdsl_sll_init();
  #elif defined (DLL_PK)
    qNew->qList = cdsl_dll_init();
  #else 
    qNew->qList = cdsl_dyn_array_init();
  #endif
  
  if (!qLast) 
    {
      qHead = qNew;
    }
  else
    {
      while (qLast->qNext) qLast = qLast->qNext;  // USE ITERATOR

      qLast->qList->enqueue(0,qLast->qList,(void*)qNew)
    }
  g_qCount++;


}


void dequeue (int *piNode, int *piDist, int *piPrev)
{
  QITEM *qKill = qHead;

  if (qHead)
    {
	
      *piNode = qHead->iNode;
      *piDist = qHead->iDist;
      *piPrev = qHead->iPrev;
      qHead = qHead->qNext;
      free(qKill);
      g_qCount--;
    }
}


int qcount (void)
{
  return(g_qCount);
}

int dijkstra(int chStart, int chEnd) 
{
  

  
  for (ch = 0; ch < NUM_NODES; ch++)
    {
      rgnNodes[ch].iDist = NONE;
      rgnNodes[ch].iPrev = NONE;
    }

  if (chStart == chEnd) 
    {
      printf("Shortest path is 0 in cost. Just stay where you are.\n");
    }
  else
    {
      rgnNodes[chStart].iDist = 0;
      rgnNodes[chStart].iPrev = NONE;
      //HEEREEEEE FFFS

      enqueue (chStart, 0, NONE);
      
     while (qcount() > 0)
	{
	  dequeue (&iNode, &iDist, &iPrev);
	  for (i = 0; i < NUM_NODES; i++)
	    {
	      if ((iCost = AdjMatrix[iNode][i]) != NONE)
		{
		  if ((NONE == rgnNodes[i].iDist) || 
		      (rgnNodes[i].iDist > (iCost + iDist)))
		    {
		      rgnNodes[i].iDist = iDist + iCost;
		      rgnNodes[i].iPrev = iNode;
          //HEREEEE FFS

		      enqueue (i, iDist + iCost, iNode);
		    }
		}
	    }
	}
      
      printf("Shortest path is %d in cost. ", rgnNodes[chEnd].iDist);
      printf("Path is: ");
      print_path(rgnNodes, chEnd);
      printf("\n");
    }
}

int main(int argc, char *argv[]) {
  int i,j,k;
  FILE *fp;
  
  if (argc<2) {
    fprintf(stderr, "Usage: dijkstra <filename>\n");
    fprintf(stderr, "Only supports matrix size is #define'd.\n");
  }

  /* open the adjacency matrix file */
  fp = fopen (argv[1],"r");

  /* make a fully connected matrix */
  for (i=0;i<NUM_NODES;i++) {
    for (j=0;j<NUM_NODES;j++) {
      /* make it more sparce */
      fscanf(fp,"%d",&k);
	AdjMatrix[i][j]= k;
    }
  }

  /* finds 10 shortest paths between nodes */
  for (i=0,j=NUM_NODES/2;i<20;i++,j++) {
			j=j%NUM_NODES;
      dijkstra(i,j);
  }
  exit(0);
  

}


