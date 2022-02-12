#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define bias 199
#define y 21
#define x 80
#define Path '#'
#define PokeMart 'M'
#define PokeCenter 'C'
#define TallGrass ':'
#define Boulder '%'
#define Clearing '.'
#define Tree '^'
#define PC '@'
#define NULL ((void *)0)

typedef struct board{
    char board[y][x];
    int north_exit;
    int south_exit;
    int west_exit;
    int east_exit;
}   board_t;

void generate_boulders_and_clearings(board_t *f){
	int i,j;
	for(i=0; i<21; i++){
		for(j=0; j<80; j++){
			f->board[i][j] = Clearing;
		}
	}
	
	for(i=0;i<80;i++){
		f->board[0][i] = Boulder;
		f->board[20][i] = Boulder;
	}
	
	for(i=0;i<21;i++){
		f->board[i][0] = Boulder;
		f->board[i][79] = Boulder;
	}
}

void generate_grass(board_t *f){
	srand(time(NULL));
	int i,j,try;
    try = rand()%7+1;
	for(int k=0;k<=try;k++){
        i = rand()%19;
        j = rand()%78;
        for (int m = i-5; m < i+5; m++)
        {
            for (int n = j-5; n < j+5; n++)
            {  
                if (m>1 && n>1 && m < 19 && n < 75 )
                {
                    f->board[m][n] = TallGrass;     
                }
            }
        }
	}
}

void generate_path(board_t *World[399][399], int currentY, int currentX, board_t *f){
	int i;
	srand(time(NULL));
	//Boundary detection
	
	if(currentX-1>=0){
		if(World[currentY][currentX-1]){
			board_t *west = World[currentY][currentX-1];
			f->west_exit = west->east_exit;
		}else{
			f->west_exit = rand()%14+3;
		}
	}else{
		f->west_exit = rand()%14+3;
	}

	if(currentX+1<399){
		if(World[currentY][currentX+1]){
			board_t *east = World[currentY][currentX+1];
			f->east_exit = east->west_exit;
		}else{
			f->east_exit = rand()%14+3;
		}
	}else{
		f->east_exit = rand()%14+3;
	}

	if(currentY+1<399){
		if(World[currentY+1][currentX]){
			board_t *south = World[currentY+1][currentX];
			f->south_exit = south->north_exit;
		}else{
			f->south_exit = rand()%74+3;
		}
	}else{
		f->south_exit = rand()%74+3;
	}

	if (currentY-1>=0)
	{
		if(World[currentY-1][currentX]){
		board_t *north = World[currentY-1][currentX];
		f->north_exit = north->south_exit;
		}else{
		f->north_exit = rand()%74+3;
		}
	}else{
		f->north_exit = rand()%74+3;
	}
	
	
	int index_x;
	int index_y;
	int flag;

	while (1)
	{
		index_x = rand()%60+10;
		index_y = rand()%12+4;
		if(index_y != f->east_exit && index_y != f->west_exit
		&& index_x != f->north_exit && index_x != f->south_exit){
			break;
		}
	}

	//west to east
	for(i=0;i<=index_x;i++){
		f-> board[f->west_exit][i] = Path;
	}
	flag = f->west_exit-index_y;
	
	if (flag>0)
	{
		for (int i = f->west_exit; i >= index_y; i--)
		{
			f-> board[i][index_x] = Path;
		}
		
	}else if (flag<0)
	{
		for (int i = index_y; i >= f->west_exit; i--)
		{
			f-> board[i][index_x] = Path;
		}
	}
	//east to west
	for(i=80;i>=index_x;i--){
		f-> board[f->east_exit][i] = Path;
	}

	flag = f->east_exit-index_y;
	
	if (flag>0)
	{
		for (int i = f->east_exit; i >= index_y; i--)
		{
			f-> board[i][index_x] = Path;
		}
		
	}else if (flag<0)
	{
		for (int i = f->east_exit; i <= index_y; i++)
		{
			f-> board[i][index_x] = Path;
		}
	}

	//north 2 south
	for(i=0;i<=index_y;i++){
		f-> board[i][f->north_exit] = Path;
	}

	flag = f->north_exit-index_x;
	
	if (flag>0)
	{
		for (int i = f->north_exit; i >= index_x; i--)
		{
			f-> board[index_y][i] = Path;
		}
		
	}else if (flag<0)
	{
		for (int i = f->north_exit; i <= index_x; i++)
		{
			f-> board[index_y][i] = Path;
		}
	}
	//south 2 north
	for(i=20;i>=index_y;i--){
		f-> board[i][f->south_exit] = Path;
	}

	flag = f->south_exit-index_x;
	
	if (flag>0)
	{
		for (int i = f->south_exit; i >= index_x; i--)
		{
			f-> board[index_y][i] = Path;
		}
		
	}else if (flag<0)
	{
		for (int i = f->south_exit; i <= index_x; i++)
		{
			f-> board[index_y][i] = Path;
		}
	}
}

void generate_center_and_mart(board_t *f,float prob){
	int intprob = prob;
	int ran = rand()%100+1;
	if(ran <= intprob){
		//center
		f->board[1][f->north_exit+1] = PokeCenter;
		f->board[2][f->north_exit+1] = PokeCenter;
		f->board[1][f->north_exit+2] = PokeCenter;
		f->board[2][f->north_exit+2] = PokeCenter;

		//mart
		f->board[f->east_exit-1][77] = PokeMart;
		f->board[f->east_exit-1][78] = PokeMart;
		f->board[f->east_exit-2][77] = PokeMart;
		f->board[f->east_exit-2][78] = PokeMart;
	}
}

void generate_trees(board_t *f){
	for(int i=0;i<30;i++){
		int rand_x = rand()%71+4;
		int rand_y = rand()%12+4;
		if(f->board[rand_y][rand_x] == Clearing){
			f->board[rand_y][rand_x] = Tree;
		}
	}
}

void generate_rocks(board_t *f){
	for(int i=0;i<30;i++){
		int rand_x = rand()%71+4;
		int rand_y = rand()%12+4;
		if(f->board[rand_y][rand_x] == Clearing){
			f->board[rand_y][rand_x] = Boulder;
		}
	}
}
float probability(int currentY, int currentX){
    float p; int d;
    d = sqrt((199 - currentY) * (199-currentY) + (199 - currentX)*(199 - currentX));
    if(currentX == 199 && currentY == 199){
		p = 100;
	}
    else if(d>=200){
		p =  5;
	}
    else{
		p = 50 - ((45 * d) / 200);
	}
    return p;
}

void printMap(board_t *f){
    for(int i = 0; i <y; i++){
    	for(int j = 0; j <x; j++){
    		printf("%c",f->board[i][j]);
    	}
    	printf("\n");
    }
}

void outputlocation(int currentY, int currentX){
	printf("You are now in (%d,%d)\n",currentY-bias, currentX-bias);
	printf("\n");
	printf("\n");
}

void generate_PC(board_t *f){
		int rand_x = rand()%71+4;
		int rand_y = rand()%12+4;
		if(f->board[rand_y][rand_x] == Clearing){
			f->board[rand_y][rand_x] = PC;
		}else{
			generate_PC(f);
		}
		
}

void generate_map(board_t *World[399][399], int currentY, int currentX){
	if(World[currentY][currentX]==NULL){
		srand(time(NULL));
		board_t *f;
		f = malloc(sizeof(board_t));
		generate_boulders_and_clearings(f);
		generate_grass(f);
		generate_trees(f);
		generate_rocks(f);
		generate_path(World, currentY,currentX, f);
		float prob = probability(currentY,currentX);
		generate_center_and_mart(f,prob);
		generate_PC(f);
		World[currentY][currentX] = f;
		printMap(World[currentY][currentX]);
		outputlocation(currentY, currentX);
	}else{
		printMap(World[currentY][currentX]);
		outputlocation(currentY, currentX);
	}

} 



int main(){
	board_t *World[399][399];
	//init
	for(int i = 0; i<399; i++){
		for(int j = 0; j<399 ; j++){
			World[i][j] = NULL;
		}
	}

	
    char input;

	generate_map(World, 199, 199);
	int currentX=199;
	int currentY=199;

	while (1)
	{
		printf("%s","Please input your actions(n,s,e,w,q,f):\n");

		scanf("%s", &input);

		switch (input)
		{
		case 'w': 
			if (currentX-1>=0)
			{
				currentX--;
				generate_map(World,currentY,currentX);
			}else{
				printf("You can't move out of boundary!\n");
			}
			
			continue;
		case 'n':
			if (currentY-1>=0)
			{
					currentY--;
					generate_map(World,currentY,currentX);
			}else{
				printf("You can't move out of boundary!\n");
			}
			
			continue;
		case 's':
			if (currentY+1<399)
			{
				currentY++;
				generate_map(World,currentY,currentX);
			}else{
				printf("You can't move out of boundary!\n");
			}
		
            continue;
        case 'e':
            if (currentX+1<399)
			{
				currentX++;
				generate_map(World,currentY,currentX);
			}else{
				printf("You can't move out of boundary!\n");
			}
			
            continue;
		case 'f':
            printf("%s","Please input X : ");
			int temp0;
			int temp1;
            scanf("%d",&temp0);
			if(temp0>=-199&&temp0<199){
				currentX=temp0+bias;
			}else{
				printf("invalid input, please try again\n");
				continue;
			}
			printf("%s","Plz input y : ");
            scanf("%d",&temp1);
			if(temp1>=-199&&temp1<199){
				currentY=temp1+bias;
			}else{
				printf("invalid input, please try again\n");
				continue;
			}

            generate_map(World, currentY, currentX);
			continue;
		case 'q':
			return 0;
		default:
			printf("%s","invalid input, please try again\n");
			continue;
		}
	}
	return 0;
}