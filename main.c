#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_DIE 6

int rolldie(void)
{
    return rand() % MAX_DIE + 1;
}


int main(int argc, char *argv[]) {
	 int cnt;
	 int pos;
	srand((unsigned)(time(NULL)));
	
	printf("======================================================\n");
	printf("******************************************************\n");
	printf("*******************   BINGO GAME   *******************\n");
	printf("******************************************************\n");
	printf("======================================================\n");


	// 1. 초기화(플레이어 이름 설정, 변수)
	board_initBoard();
	
	// 2. 플레이
	cnt = 0;
	pos = 0;
	
	do {
	int die_result;
	int coinResult;
	
	// 상태 출력
	board_printBoardStatus();
	
	// 주사위 굴리기
	die_result = rolldie();
	
	// 플레이어 이동
	pos += die_result;
	
	printf("pos: %d (die:%d)\n", pos, die_result);
	
	coinResult = board_getBoardCoin(pos);
	
	printf("coin: %d\n", coinResult);
	
	// 순서 체인지, 상어 이동 
	cnt++;
	
	// 3. 게임 끝(승자 프린트) 
	} while (cnt<5);
		
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");


	printf("======================================================\n");
	printf("******************************************************\n");
	printf("****************  CONGRATULATION!!!!!  ***************\n");
	printf("*#&$*#^&*$&^@($!@(*   BINGO!!!!!   #)!@*(#)*%$({#*)*( \n");
	printf("********************   YOU WIN!!!!!!  ****************\n");
	printf("******************************************************\n");
	printf("======================================================\n\n");

	system("PAUSE");
	return 0;
}
