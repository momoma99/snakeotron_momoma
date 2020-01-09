#include "clientAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include "snakeAPI.h"
#include "ret_type.h"
#include "deplace.h"


void main()
{

	char* serverName = "localhost";
	int port = 1234;
	char* name ="MohamedAKHOUZAM";

	char* gameType ="RANDOM_PLAYER difficulty=1 timeout=100 seed=123 start=0";
	char gameName[200];
	int sizeX;
	int sizeY;
	int nbWalls;

	t_move mymove;
  t_move itmove;


	connectToServer(serverName,port,name);

	waitForSnakeGame(gameType,gameName,&sizeX,&sizeY,&nbWalls);

	int* walls = (int*)malloc(sizeof(int));
  int player;
  int d;
  int pivot;
  t_return_code ret;
	player=getSnakeArena(walls);

  printArena();

  if(player==0)
  {
            mymove=deplace(d);
            ret=sendMove(mymove);
            printArena();
            pivot=!player;

  }
  else
	{
            ret=getMove(&itmove);
            printArena();
            pivot=!player;
  }

  while(ret==NORMAL_MOVE)
  {
    if(pivot==0)
    {

    mymove=deplace(d);
    ret=sendMove(mymove);
    printArena();
    pivot=1;
    if(ret==LOOSING_MOVE || ret==WINNING_MOVE)
    {
        closeConnection();
    }

    }
    else if(pivot==1)
    {

    ret=getMove(&itmove);
    printArena();
    pivot=0;
    if(ret==LOOSING_MOVE || ret==WINNING_MOVE)
    {
        closeConnection();
    }

  }
}

}
