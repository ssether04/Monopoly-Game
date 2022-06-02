#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#define clear() system("cls")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#define TERM_WIDTH 100
#define printc(bg, fc, str) printf("\033[%d;%dm%s\033[0m", bg, fc, str) //BackgroundColour, Font Colour, String
#define _Red "\033[0;31m"
#define _Green "\033[0;32m"
#define _Blue "\033[0;34m"
#define _Purple "\033[0;35m"
#define _Cyan "\033[0;36m"
#define _Yellow "\033[0;33m"
#define _White "\033[0;37m"
#define _NORMAL "\033[0m"
void over_print(int,int);
int get_player_info();
void end_screen_fun();
int startup();
void game_start();
void print_name_wclr(int);
void print_name_block_wclr(int);
const char* clr_codes[5]={_Red,_Green,_Blue,_Purple,_Cyan};
const char* clr_names[5]={"Red","Green","Blue","Purple","Cyan"};
char clr_choice[]={0,1,2,3,4,-1}; //Will be empty after colour selection
int board[15][2] = {
    {92,48},{70,48},{51,48},{33,48},
    {11,48},{11,37},{11,27},{11,17},
    {11, 2},{33, 7},{51, 7},{70, 7},
    {92,17},{92,27},{92,37}
    };
/*
ANSI CODE FOR COLOURS:
Red \033[0;31m - 0
Green \033[0;32m - 1
Blue \033[0;34m - 2
Purple \033[0;35m - 3
Cyan \033[0;36m - 4
Yellow \033[0;33m
White \033[0;37m
NORMAL \033[0m
*/

/* 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),71); // Example Red
Red - 71
Green - 39
Blue - 23
Purple - 86
Cyan - 55
NORMAL - 7
*/

//File pointer declaration
FILE* start_screen;
FILE* board_draw;
FILE* plyr_stats;
int player_count=0;

//Structure for each player
struct playerprop{
    char name[10];
    int name_len;
    int colour;
    int pos[2];
    long long int money;
    //TODO Properties
}players[4]={{"",0,-1,1000},{"",0,-1,1000},{"",0,-1,1000},{"",0,-1,1000}};

//Prints colour pallete on the right to select from
void print_colors () {
    FILE* colour_pal;
    int cursor_offset=0;
    char colorlines[40];
    colour_pal = fopen("Colour_Selector.txt","r");
    while(!feof(colour_pal)) {
        fgets(colorlines,40,colour_pal);
        gotoxy(150-4,20+(cursor_offset++));
        printf(colorlines);
    }
    fclose(colour_pal);
    for(int i=0;i<5;i++) {
        gotoxy(150,23+i);
        for(int j=0;j<5;j++)
            if(clr_choice[j]==i) printf("%c - %s%s\033[0m",clr_names[i][0],clr_codes[i],clr_names[i]);
    }
}

//End screen after quiting or game over
void end_screen_fun(){
    FILE* end_screen;
    int cursor_offset=0;
    char end_lines[250];
    clear();
    end_screen = fopen("Leaving_Message.txt","r");
    while(!feof(end_screen)) {
        fgets(end_lines,250,end_screen);
        gotoxy(80,20+(cursor_offset++));
        printf(end_lines);
    }
    fclose(end_screen);
    gotoxy(0,100);
    exit(1);
}

//Assigns colour to each player, cannot take colour which is already picked
int assign_clr(int plyr_id,int clr_id) {
    for(int i=0;i<5;i++) {
        if(clr_choice[i]==clr_id) {
            for(int j=0;j<5-i;j++) {
                clr_choice[j+i] = clr_choice[j+i+1];
            }
            players[plyr_id].colour=clr_id;
            return 0;
        }
    }
    return 1;
}

//Print name with colour
void print_name_block_wclr(int plyr_id) {
    int temp_clr[5]={71,39,23,87,55};
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),temp_clr[players[plyr_id].colour]); 
    printf(" %c ",*players[plyr_id].name);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

//Places player on the board
void place_plyr(int plyr_id,int board_pos){
    gotoxy(board[board_pos][0],board[board_pos][1]+(plyr_id+1)%4);
    print_name_block_wclr(plyr_id);
}

//Finds the length of the name of player
void find_len(int plyr_id) {
    int i=0,len=0;
    while(players[plyr_id].name[i++]!='\0') {len++;}
    players[plyr_id].name_len = len;
}


//Main function to get player info
int get_player_info() {
    get_again:
    clear();
    int cursor_offset=0;
    char startlines[50],colour_inp;
    start_screen=fopen("Monopoly.txt","r");
    while(!feof(start_screen)) {
        fgets(startlines,150,start_screen);
        gotoxy(95,20+(cursor_offset++));
        printf(startlines);
    }printf("\n");
    fclose(start_screen);
    gotoxy(90,22+cursor_offset);printf("Enter Number of Players(Max 4 / Min 2): ");scanf("%c",&player_count);player_count-=48;
    if( player_count>4 || player_count<2) {
        gotoxy(90,23+cursor_offset);printf("\033[0;31mINVALID!\033[0m MAX players is 4 and MIN is 2, Please enter 4 or less");
        player_count=0;
        //Sleep(1200); //TODO UNDO
        goto get_again;
    } else if(player_count)
    for(int i=0;i<player_count;i++) {
        enter_again:
        clear();
        cursor_offset=0;
        start_screen=fopen("Monopoly.txt","r");
        while(!feof(start_screen)) {
            fgets(startlines,150,start_screen);
            gotoxy(95,20+(cursor_offset++));
            printf(startlines);
        }printf("\n");
        fclose(start_screen);
        print_colors();
        gotoxy(90,22+cursor_offset);printf("Enter Player %d's Name: ",i+1);scanf("%s",&players[i].name);find_len(i);
        // Checks if name has any special characters
        for(int n=0;n<players[i].name_len;n++) {
            if(players[i].name[n]<97 || players[i].name[n]>122) {
                gotoxy(90,23+cursor_offset);printf("-%c-",players[i].name[n]);
                gotoxy(90,24+cursor_offset);printf("Name has \033[0;31mINVALID\033[0m Characters");
                //Sleep(500); //TODO UNDO
                goto enter_again;
            }
        }
        gotoxy(90,23+cursor_offset);int _lenn=printf("Enter %s's Colour: ",players[i].name);
        int flag = 0;
        while((colour_inp=getch())!=EOF){
            switch(colour_inp) {
                case 'r': flag = assign_clr(i,colour_inp=0);break;
                case 'g': flag = assign_clr(i,colour_inp=1);break;
                case 'b': flag = assign_clr(i,colour_inp=2);break;
                case 'p': flag = assign_clr(i,colour_inp=3);break;
                case 'c': flag = assign_clr(i,colour_inp=4);break;
                default:flag = 2;break;
            }
            if (!flag) break;
            else if(flag!=2) {gotoxy(90,24+cursor_offset);printf("%s%s\033[0m is already designated..",clr_codes[colour_inp],clr_names[colour_inp]);gotoxy(90+_lenn,23+cursor_offset);}
            else {gotoxy(90,24+cursor_offset);printf("\033[0;31mINVALID CHARACTER\033[0m                          ");gotoxy(90+_lenn,23+cursor_offset);}
        }
        gotoxy(90,25+cursor_offset);printf("\033[0;32mSuccessfully\033[0m Assigned %s to %s%s\033[0m",players[i].name,clr_codes[players[i].colour],clr_names[players[i].colour]);
        //Sleep(1200); //TODO UNDO
    }
    clear();
    cursor_offset=0;
    start_screen=fopen("Monopoly.txt","r");
    while(!feof(start_screen)) {
        fgets(startlines,150,start_screen);
        gotoxy(95,20+(cursor_offset++));
        printf(startlines);
    }printf("\n");
    fclose(start_screen);
    // PRINT PLAYERS {CHECKING}
    gotoxy(90,22+cursor_offset);printf("Player 1: %s%s\033[0m",clr_codes[players[0].colour],players[0].name); 
    gotoxy(90,23+cursor_offset);printf("Player 2: %s%s\033[0m",clr_codes[players[1].colour],players[1].name);
    gotoxy(90,24+cursor_offset);(*players[2].name == '\0')?printf("Starting Game...",gotoxy(0,0)):printf("Player 3: %s%s\033[0m",clr_codes[players[2].colour],players[2].name);
    gotoxy(90,25+cursor_offset);(*players[3].name == '\0')?printf("Starting Game...",gotoxy(0,0)):printf("Player 4: %s%s\033[0m",clr_codes[players[3].colour],players[3].name);
    gotoxy(0,0);printf("Starting Game...");
    //First letter of name to Capital to each player
    for(int i=0;i<player_count;i++) {
        if(players[i].name[0]>=97 && players[i].name[0]<=122) {players[i].name[0] -= 32;} 
    }
    //Sleep(2200); //TODO UNDO
}


//Startup Screen/Menu
int startup() {
    clear();
    char st_inp;
    int cursor_offset=0;
    char start_lines[50];
    start_screen=fopen("Monopoly.txt","r");
    while(!feof(start_screen)) {
        fgets(start_lines,150,start_screen);
        gotoxy(95,20+(cursor_offset++));
        printf(start_lines);
    }printf("\n");
    fclose(start_screen);
    gotoxy(98,22+cursor_offset);printf("Press P to Play");
    gotoxy(124,22+cursor_offset);printf("Press Q to Quit\n");                              
    gotoxy(0,0);
    while((st_inp=getch())!=EOF){
        switch(st_inp) {
            case 'q': end_screen_fun();
            case 'p': get_player_info();goto end;
        }
    }
    end:
        return 1;
}


//Game start
void game_start(){
    clear();
    int cursor_offset=0,x_offset=0,x_name_offset=0,x_money_offset=0;
    char board_lines[110];
    char plyr_statlines[40];
    board_draw = fopen("main.txt","r");
    while(!feof(board_draw)) {
        fgets(board_lines,110,board_draw);
        gotoxy(0,1+(cursor_offset++));
        printf(board_lines);        
    }printf("\n");
    fclose(board_draw);
    for(int j=0;j<player_count;j++) {
        for(int i=0;i<15;i++) {
            place_plyr(j,i);
        }
    }
    // Player Stats
    for(int p=0;p<player_count;p++){
        plyr_stats = fopen("player_stats.txt","r");
        cursor_offset=0;
        while(!feof(plyr_stats)) {
            fgets(plyr_statlines,40,plyr_stats);
            gotoxy(121+x_offset,1+(cursor_offset++));
            printf(plyr_statlines);
        }
        fclose(plyr_stats);
        gotoxy(130+x_name_offset,2);printf("%s%s\033[0m",clr_codes[players[p].colour],players[p].name);
        gotoxy(130+x_money_offset,5);printf("%d",players[p].money);
        x_name_offset+=30;
        x_money_offset+=30;
        x_offset+=30; 
    }
    gotoxy(0,55);
}
//Main fucntion
int main() {
    startup();
    game_start();
    exit(1);
}

// PRINTING CARDS
// char card_lines[100];
//     int line=1,cursor_offset=0;
//     FILE* card_disp;
//     int crd_no=4;
//     card_disp=fopen("Cards.txt","r");
//     while(!feof(card_disp)) {
//             fgets(card_lines,100,card_disp);
//         if(line >(crd_no-1)*16 && line<=((crd_no)*16)+1){
//             gotoxy(95,20+(cursor_offset++));
//             printf(card_lines);
//         } if(line == crd_no*16) break;
//         line++;
//     }printf("\n");
//     fclose(card_disp);
//TODO REMOVE COMMENTS ON Sleep()//

/*
ANSI CODE FOR COLOURS:
Red \033[0;31m - 0
Green \033[0;32m - 1
Blue \033[0;34m - 2
Purple \033[0;35m - 3
Cyan \033[0;36m - 4
Yellow \033[0;33m
White \033[0;37m
NORMAL \033[0m
*/