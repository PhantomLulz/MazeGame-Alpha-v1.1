// GameMaze.cpp : Defines the entry point for the console application.
//

#include "windows.h"
#include <iostream>
#include <vector> 
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

char Map[20][40] = {
	"#######################################",
	"#1#-----#      $          #-----------#",
	"# #-----# ############### #############",
	"#*#-----# #-------# $          *  $   #",
	"# #-----# #-------# ##### ########### #",
	"# #-----# #-------# #---# #---------# #",
	"# #-----# #-------# #---# #---------# #",
	"# ####### ######### ##### #---------# #",
	"#       $ $      *        #---------# #",
	"##################################### #",
	"#                         $           #",
	"#    ##################################",
	"#    #--------------------------------#",
	"# $  ##################################",
	"#        ###*                $        #",
	"########  $  ####### ################ #",
	"#------#     #-----#$#--------------# #",
	"#------#  $  #-----# #--------------# #",
	"#####################################!#"
};

char Map2[20][40] = {
	"#!#####################################",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                 *                   #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                     #",
	"#                                    2#",
	"#######################################"
};

int x = 1;
int y = 1;
int HP = 100;
int maxHP = 100;
int bPoints = 0;
int zed = 0;

bool game_running = true;
bool game_running2 = true;

int main(int argc, _TCHAR* argv[])
{
	system("mode con: cols=40 lines=40");
	system("color 9F");

	struct Level1{
		static int Level01(void) {

			vector<string> healthBar(5);
			healthBar[0] = "__________";
			healthBar[1] = "________";
			healthBar[2] = "______";
			healthBar[3] = "____";
			healthBar[4] = "__";

			while (game_running == true){
				system("cls");
				for (int display = 0; display < 20; display++){
					cout << Map[display] << endl;
				}

				cout << "Hp: " << HP << "/" << maxHP << " " << healthBar[zed] << endl << endl;
				cout << "Points: " << bPoints;

				system("pause>nul");

				if (GetAsyncKeyState(VK_DOWN)){
					int y2 = y + 1;
					if (Map[y2][x] == ' '){
						Map[y][x] = ' ';
						y++;
						Map[y][x] = '1';
					}

					if (Map[y2][x] == '$'){
						Map[y][x] = '*';
						y++;
						bPoints = bPoints + 10;
						Map[y][x] = '1';
					}

					if (Map[y2][x] == '*'){
						Map[y][x] = '*';
						HP = HP - 20;
						y++;
						Map[y][x] = '1';
					}

					if (bPoints == 100 && Map[y2][x] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = true;
					}
				}

				if (GetAsyncKeyState(VK_UP)){
					int y2 = y - 1;
					if (Map[y2][x] == ' '){
						Map[y][x] = ' ';
						y--;
						Map[y][x] = '1';
					}

					if (Map[y2][x] == '$'){
						Map[y][x] = '*';
						y--;
						bPoints = bPoints + 10;
						Map[y][x] = '1';
					}

					if (Map[y2][x] == '*'){
						Map[y][x] = '*';
						HP = HP - 20;
						y--;
						Map[y][x] = '1';
					}

					if (bPoints == 100 && Map[y2][x] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = true;
					}
				}

				if (GetAsyncKeyState(VK_RIGHT)){
					int x2 = x + 1;
					if (Map[y][x2] == ' '){
						Map[y][x] = ' ';
						x++;
						Map[y][x] = '1';
					}

					if (Map[y][x2] == '$'){
						Map[y][x] = '*';
						x++;
						bPoints = bPoints + 10;
						Map[y][x] = '1';
					}

					if (Map[y][x2] == '*'){
						Map[y][x] = '*';
						HP = HP - 20;
						x++;
						Map[y][x] = '1';
					}

					if (bPoints == 100 && Map[y][x2] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = true;
					}
				}

				if (GetAsyncKeyState(VK_LEFT)){
					int x2 = x - 1;
					if (Map[y][x2] == ' '){
						Map[y][x] = ' ';
						x--;
						Map[y][x] = '1';
					}

					if (Map[y][x2] == '$'){
						Map[y][x] = '*';
						x--;
						bPoints = bPoints + 10;
						Map[y][x] = '1';
					}

					if (Map[y][x2] == '*'){
						Map[y][x] = '*';
						HP = HP - 20;
						x--;
						Map[y][x] = '1';
					}

					if (bPoints == 100 && Map[y][x2] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = true;
					}
				}

				if (HP == 80){
					zed = 1;
				}

				if (HP == 60){
					zed = 2;
				}

				if (HP == 40){
					zed = 3;
				}

				if (HP == 20){
					zed = 4;
				}

				if (HP <= 0){
					system("cls");
					cout << "You lose, Game Over!";
					cout << endl << endl << "Score: " << bPoints;
					game_running = false;
					game_running2 = false;
				}
			}
			return 1;
		}
	};
	Level1::Level01();

	struct Level2{
		static int Level02(void) {

			HP = 100;
			zed = 0;

			vector<string> healthBar(5);
			healthBar[0] = "__________";
			healthBar[1] = "________";
			healthBar[2] = "______";
			healthBar[3] = "____";
			healthBar[4] = "__";

			while (game_running2 == true){
				system("cls");
				for (int display = 0; display < 20; display++){
					cout << Map2[display] << endl;
				}

				cout << "Hp: " << HP << "/" << maxHP << " " << healthBar[zed] << endl << endl;
				cout << "Points: " << bPoints;

				system("pause>nul");

				if (GetAsyncKeyState(VK_DOWN)){
					int y2 = y + 1;
					if (Map2[y2][x] == ' '){
						Map2[y][x] = ' ';
						y++;
						Map2[y][x] = '2';
					}

					if (Map2[y2][x] == '$'){
						Map2[y][x] = '*';
						y++;
						bPoints = bPoints + 10;
						Map2[y][x] = '2';
					}

					if (Map2[y2][x] == '*'){
						Map2[y][x] = '*';
						HP = HP - 20;
						y++;
						Map2[y][x] = '2';
					}

					if (bPoints == 200 && Map2[y2][x] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = false;
					}
				}

				if (GetAsyncKeyState(VK_UP)){
					int y2 = y - 1;
					if (Map2[y2][x] == ' '){
						Map2[y][x] = ' ';
						y--;
						Map2[y][x] = '2';
					}

					if (Map2[y2][x] == '$'){
						Map2[y][x] = '*';
						y--;
						bPoints = bPoints + 10;
						Map2[y][x] = '2';
					}

					if (Map2[y2][x] == '*'){
						Map2[y][x] = '*';
						HP = HP - 20;
						y--;
						Map2[y][x] = '2';
					}

					if (bPoints == 200 && Map2[y2][x] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = false;
					}
				}

				if (GetAsyncKeyState(VK_RIGHT)){
					int x2 = x + 1;
					if (Map2[y][x2] == ' '){
						Map2[y][x] = ' ';
						x++;
						Map2[y][x] = '2';
					}

					if (Map2[y][x2] == '$'){
						Map2[y][x] = '*';
						x++;
						bPoints = bPoints + 10;
						Map2[y][x] = '2';
					}

					if (Map2[y][x2] == '*'){
						Map2[y][x] = '*';
						HP = HP - 20;
						x++;
						Map2[y][x] = '2';
					}

					if (bPoints == 200 && Map2[y][x2] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = false;
					}
				}

				if (GetAsyncKeyState(VK_LEFT)){
					int x2 = x - 1;
					if (Map2[y][x2] == ' '){
						Map2[y][x] = ' ';
						x--;
						Map2[y][x] = '2';
					}

					if (Map2[y][x2] == '$'){
						Map2[y][x] = '*';
						x--;
						bPoints = bPoints + 10;
						Map2[y][x] = '2';
					}

					if (Map2[y][x2] == '*'){
						Map2[y][x] = '*';
						HP = HP - 20;
						x--;
						Map2[y][x] = '2';
					}

					if (bPoints == 200 && Map2[y][x2] == '!'){
						system("cls");
						cout << "You Win! Next level." << endl << endl;
						cin.get();
						game_running = false;
						game_running2 = false;
					}
				}

				if (HP == 80){
					zed = 1;
				}

				if (HP == 60){
					zed = 2;
				}

				if (HP == 40){
					zed = 3;
				}

				if (HP == 20){
					zed = 4;
				}

				if (HP <= 0){
					system("cls");
					cout << "You lose, Game Over!";
					cout << endl << endl << "Score: " << bPoints;
					game_running = false;
					game_running2 = false;
				}
			}
			return 1;
		}
	};
	Level2::Level02();

	if (game_running == false && game_running2 == false){
		cin.get();
		return 0;
	}
}
