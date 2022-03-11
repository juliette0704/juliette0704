/*
** EPITECH PROJECT, 2021
** concat_params.c
** File description:
** task
*/

char *concat_params(int argc, char **argv)
{
    int j = 0, k = 0;
    int ar = 0;
    int h = 0;
    int b = 0;
    int size = 0;
    char *wrd;
    
    while (argv[ar] != 0) {
        size += my_strlen(argv[ar]);
        ar++;         
    }
    wrd = malloc(sizeof(char) * size + 1);
    while(k < (argc -1)) {
        wrd[j] = argv[k][h];
        h++;
        if(argv[k][h] == '\0') {
            k++;
            j++;
            wrd[j]= '\n';
            h = 0;
        }
        j++;
    }
    while (k <argc){
        wrd[j] = argv[k][h];
        h++;
	if(argv[k][h] == '\0') {
            k++;
            j++;
            h = 0;
	}
        j++;
    }
    return (wrd);
}
