#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define y 24
#define x 80
#define Path '#'
#define PokeMart 'M'
#define PokeCenter 'C'
#define TallGrass ':'
#define Boulder '%'
#define Clearing '.'
#define Tree '^'

typedef struct foo{
    char board[y][x];
    int north_exit;
    int south_exit;
    int west_exit;
    int east_exit;
}   foo_t;

void generate_boulders_and_clearings(foo_t *f){
	int i,j;
	for(i=0; i<21; i++){
		for(j=0; j<80; j++){
			f->board[i][j] = Clearing;
		}
	}
	
	for(i=0;i<80;i++){
		f->board[0][i] = Boulder;
	}
	
	for(i=0;i<80;i++){
		f->board[20][i] = Boulder;
	}
	
	for(i=0;i<21;i++){
		f->board[i][0] = Boulder;
	}
	
	for(i=0;i<21;i++){
		f->board[i][79] = Boulder;
	}
}

void generate_grass(foo_t *f){
	//range for each hori line are 1-70
	//range for veti are 1-19
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
                if (m>1 && n>1 && m < 19 && n < 75)
                {
                    f->board[m][n] = TallGrass;     
                }
            }
        }
	}
}

void generate_path(foo_t *f){
	int i;
	srand(time(NULL));
	//range for hori are 4-75
	//range for verti are 4-16
	int index_north_exit = rand()%71+4;
	int index_south_exit = rand()%71+4;
	int index_west_exit = rand()%12+4;
	int index_east_exit = rand()%12+4;
	int index_x_intersec = rand()%71+4;
	int index_y_intersec = rand()%12+4;
	
	f->north_exit = index_north_exit;
	f->south_exit = index_south_exit;
	f->west_exit = index_west_exit;
	f->east_exit = index_east_exit;

	for(i=0;i<=index_y_intersec;i++){
		f->board[i][index_north_exit] = Path;
	}
	
	for(i=20;i>=index_y_intersec;i--){
		f->board[i][index_south_exit] = Path;
	}
	
	for(i=0;i<=index_x_intersec;i++){
		f->board[index_west_exit][i] = Path;
	}
	
	for(i=80;i>=index_x_intersec;i--){
		f->board[index_east_exit][i] = Path;
	}
	
	if(index_north_exit<index_south_exit){
		for(i=index_north_exit;i<=index_south_exit;i++){
			f->board[index_y_intersec][i] = Path;
		}
	}
	
	else{
		for(i=index_south_exit;i<=index_north_exit;i++){
			f->board[index_y_intersec][i] = Path;
		}
	}
	
	if(index_west_exit<index_east_exit){
		for(i=index_west_exit;i<=index_east_exit;i++){
			f->board[i][index_x_intersec] = Path;
		}
	}
	
	else{
		for(i=index_east_exit;i<=index_west_exit;i++){
			f->board[i][index_x_intersec] = Path;
		}
	}

	// while(f.board[index_west_exit][i] != '#'){
	// 	f->board[index_west_exit][i] = '#';
	// 	i++;
	// }
}

void generate_center_and_mart(foo_t *f){
	//center part
	f->board[1][f->north_exit+1] = PokeCenter;
	f->board[2][f->north_exit+1] = PokeCenter;
	f->board[1][f->north_exit+2] = PokeCenter;
	f->board[2][f->north_exit+2] = PokeCenter;
	//mart part
	f->board[f->east_exit-1][77] = PokeMart;
	f->board[f->east_exit-1][78] = PokeMart;
	f->board[f->east_exit-2][77] = PokeMart;
	f->board[f->east_exit-2][78] = PokeMart;
}

void generate_trees(foo_t *f){
	for(int i=0;i<30;i++){
		int rand_x = rand()%71+4;
		int rand_y = rand()%12+4;
		if(f->board[rand_y][rand_x] == Clearing){
			f->board[rand_y][rand_x] = Tree;
		}
	}
}

void generate_rocks(foo_t *f){
	for(int i=0;i<30;i++){
		int rand_x = rand()%71+4;
		int rand_y = rand()%12+4;
		if(f->board[rand_y][rand_x] == Clearing){
			f->board[rand_y][rand_x] = Boulder;
		}
	}
}

int main(){
	foo_t f;
	generate_boulders_and_clearings(&f);
	generate_grass(&f);
	generate_path(&f);
	generate_center_and_mart(&f);
	generate_trees(&f);
	generate_rocks(&f);
	for(int i = 0; i <y; i++){
    	for(int j = 0; j <x; j++){
    		printf("%c",f.board[i][j]);
    	}
    	printf("\n");
    }
	return 0;
}