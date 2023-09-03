#include <stdio.h>
#include <stdlib.h>

int path(char ** lab,int length,int depth,int start_x,int start_y) {
    lab[start_y][start_x] = '*';
    if (start_x == 0 || start_y == 0 || start_x == length-1 || start_y == depth-1) {
        return 1;
    }

    if (start_y+1 < depth && lab[start_y+1][start_x]==' ') {
        if (path(lab,length,depth,start_x,start_y+1)) {
            return 1;
        }
    }
    if (start_x+1 < length && lab[start_y][start_x+1]==' ') {
        if (path(lab,length,depth,start_x+1,start_y)) {
            return 1;
        }
    }
    if (start_y-1 >= 0 && lab[start_y-1][start_x]==' ') {
        if (path(lab,length,depth,start_x,start_y-1)) {
            return 1;
        }
    }
    if (start_x-1 >= 0 && lab[start_y][start_x-1]==' ') {
        if (path(lab,length,depth,start_x-1,start_y)) {
            return 1;
        }
    }
    lab[start_y][start_x] = ' ';
    return 0;
}

void no_path (char ** lab,int length,int depth,int start_x,int start_y) {
    lab[start_y][start_x] = '.';
    if (start_y+1 < depth && lab[start_y+1][start_x]==' ') {
        no_path(lab,length,depth,start_x,start_y+1);
    }
    if (start_x+1 < length && lab[start_y][start_x+1]==' ') {
        no_path(lab,length,depth,start_x+1,start_y);
    }
    if (start_y-1 >= 0 && lab[start_y-1][start_x]==' ') {
        no_path(lab,length,depth,start_x,start_y-1);
    }
    if (start_x-1 >= 0 && lab[start_y][start_x-1]==' ') {
        no_path(lab,length,depth,start_x-1,start_y);
    }
}
int main() {
    
    int start_x,start_y,i,length=0,depth=0,j,k=0,m,n,x_size=3,y_size=3;
    char ** lab;
    char temp;

    /*get the initial x and y value where we start*/
    scanf("%d %d\n",&start_x,&start_y);

    /*the 2d dynamic array implementation with min size*/
    lab = (char **) malloc(sizeof(char *)*y_size);
    for (i=0;i<3;i++) {
        lab[i] = (char *) malloc(sizeof(char)*x_size);
    }

    /*putting values into array 
    increasing the size accordingly*/
    while ((temp = getchar()) != EOF) {
        x_size=3;
        length=0;
        j=0;
        if (k>=y_size) {
            y_size *= 2;
            lab = (char **) realloc(lab,sizeof(char *)*y_size);
            }
        lab[k] = (char *) malloc(sizeof(char)*x_size);
        while (temp != '\n' && temp != EOF) {
            if (j>=x_size-1) {
                x_size *= 2;
                lab[k] = (char *) realloc(lab[k],sizeof(char)*x_size); 
            }
            lab[k][j] = temp;
            j++;
            length++;
            temp = getchar();
        }
        k++;
        depth++;
    }
    
    if (path(lab,length,depth,start_x,start_y)) {
        for (m=0;m<depth;m++) {
            for (n=0;n<length;n++) {
                printf("%c",lab[m][n]);
            }
            printf("\n");
        }
    }
    else {
        no_path(lab,length,depth,start_x,start_y);
        for (m=0;m<depth;m++) {
            for (n=0;n<length;n++) {
                printf("%c",lab[m][n]);
            }
            printf("\n");
        }
    }
    
    
    return 0;
}

