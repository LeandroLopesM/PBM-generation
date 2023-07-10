#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void init(int j, int k, char arr[][k]){
    for (int y = 0; y < j; y++){
        for (int x = 0; x < k; x++){
            arr[x][y] = 0;
        }
    }
}

int main(void) {
    srand(time(NULL));
    FILE *txt;
    int width = 0;
    int height = 0;
    int start[5];// = {0, 0, 107, 206, 400};
	int starty[5];
    int loops = 0;
    txt = fopen("txt.pbm", "w");

	printf("\nstart[0] = ");
	scanf("%d", &start[0]);
	getchar();

	if(start[0] == -5){
		start[0] = 5;
		start[1] = 3;
		start[2] = 7;
		start[3] = 90;
		start[4] = 4;
		starty[0] = 5;
		starty[1] = 3;
		starty[2] = 7;
		starty[3] = 90;
		starty[4] = 4;
		width = 500;
		height = 500;
		loops = 250;

		goto posttalk;
	}
	if(start[0] == -10){
		width = rand() % 600;
		height = rand() % 600;
		start[0] = rand() % width;
		start[1] = rand() % width;
		start[2] = rand() % width;
		start[3] = rand() % width;
		start[4] = rand() % width;
		starty[0] = rand() % height;
		starty[1] = rand() % height;
		starty[2] = rand() % height;
		starty[3] = rand() % height;
		starty[4] = rand() % height;
		loops = 150;

		system("cls");

		printf("start[0] = %d\nstart[1] = %d\nstart[2] = %d\nstart[3] = %d\nstart[4] = %d\n\nstarty[0] = %d\nstarty[1] = %d\nstarty[2] = %d\nstarty[3] = %d\nstarty[4] = %d\n\nwidth = %d\nheight = %d\nloops = %d\n\n", start[0], start[1], start[2], start[3], start[4], starty[0], starty[1], starty[2], starty[3], starty[4], height, width, loops);

		goto posttalk;
	}

	printf("\nstart[1] = ");
	scanf("%d", &start[1]);
	getchar();
	printf("\nstart[2] = ");
	scanf("%d", &start[2]);
	getchar();
	printf("\nstart[3] = ");
	scanf("%d", &start[3]);
	getchar();
	printf("\nstart[4] = ");
	scanf("%d", &start[4]);
	getchar();

	printf("\nstarty[0] = ");
	scanf("%d", &starty[0]);
	getchar();

	printf("\nstarty[1] = ");
	scanf("%d", &starty[1]);
	getchar();
	printf("\nstarty[2] = ");
	scanf("%d", &starty[2]);
	getchar();
	printf("\nstarty[3] = ");
	scanf("%d", &starty[3]);
	getchar();
	printf("\nstarty[4] = ");
	scanf("%d", &starty[4]);
	getchar();

	printf("Height = ");
	scanf("%d", &height);
	getchar();
	printf("\nWidth = ");
	scanf("%d", &width);
	getchar();
	printf("\nLoops = ");
	scanf("%d", &loops);
	getchar();

	posttalk:

	char arr[height][width];
    
    init(height, width, arr);
    
    if(start[0] != -1) arr[start[0]][starty[0]] = 1;
	if(start[1] != -1) arr[start[1]][starty[1]] = 1;
	if(start[2] != -1) arr[start[2]][starty[2]] = 1;
	if(start[3] != -1) arr[start[3]][starty[3]] = 1;
	if(start[4] != -1) arr[start[4]][starty[4]] = 1;
    
    fprintf(txt, "P1 %d %d\n", width, height);
    
    for(int l = 0; l < loops; l++){
        for(int h = 0; h < height; h++){
            
            for(int x = 0; x < width; x++){
                
                if(arr[h][x] == 1 && h != height - 1){
                    for(int b = -1; b < 2; b++){
                        
                        if(rand() % 2 == 1) arr[x+b][h + 1] = 1;
                        else arr[x+b] [h + 1] = 0;
                    }
                }
            }
        }
        

    }
    
    for(int h = 0; h < height; h++){
        for(int w = 0; w != width; w++){ 
        
            fprintf(txt, "%d", arr[w][h]);
            
        }
        fprintf(txt, "\n");
    }
    
    fclose(txt);

	FILE *runval;

	runval = fopen("values.txt", "w");
	fprintf(runval, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", start[0], start[1], start[2], start[3], start[4], starty[0], starty[1], starty[2], starty[3], starty[4], width, height, loops);

	fclose(runval);

	printf("\nFeito chefe");

    return 0;
}
