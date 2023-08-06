// Chess.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include<fstream>
#include<conio.h>
#include<iostream>
using namespace std;

ofstream fout("D:\\Programming Fundamentals\\chess_record.txt"/*,ios::app*/);
void setup_chess(char chess[][8]){
	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 8; b++){
			chess[a][b] = ' ';
		}
	}
	for (int i = 0; i < 8; i++){
		if ((i>1) && (i < 6)){
			for (int j = 0; j < 8; j++){
				chess[i][j] = ' ';
			}
		}
		if (i == 1){
			for (int j = 0; j < 8; j++){
				chess[i][j] = 'p'; // white pawns
			}
		}
		if (i==6){
				for (int j = 0; j < 8; j++){
					chess[i][j] = 'P'; //black pawns
				}
			}
		if ((i == 0) || (i == 7)){
			switch (i){
			case(0) :
				for (int j = 0; j < 8; j++){
					switch (j){
					case(0) :
						chess[i][j] = 'r';
						break;
					case(7) :
						chess[i][j] = 'r';//white rook
						break;
					case(1) :
						chess[i][j] = 'n';//white knight
						break;
					case(6) :
						chess[i][j] = 'n';//white knight
						break;
					case(3) :
						chess[i][j] = 'q';//white queen
						break;
					case(4) :
						chess[i][j] = 'k';//white king
						break;
					case(2) :
						chess[i][j] = 'b';//white bishop 
						break;
					case(5) :
						chess[i][j] = 'b';//white bishop
						break;
					default:
						break;
					}
				}
					break;
			case(7) :
				for (int j = 0; j < 8; j++){
					switch (j){
					case(0) :
						chess[i][j] = 'R';//br
						break;
					case(7) :
						chess[i][j] = 'R';//br
						break;
					case(1) :
						chess[i][j] = 'N';//bkn
						break;
					case(6) :
						chess[i][j] = 'N';//bkn
						break;
					case(2) :
						chess[i][j] = 'B';//bb
						break;
					case(3) :
						chess[i][j] = 'K';
						break;
					case(4) :
						chess[i][j] = 'Q';//bq
						break;
					case(5) :
						chess[i][j] = 'B';//bb
						break;
					default:
						break;
					}
				}
					break;
			default:
				break;
			}
		}

	}
}       //
void print_board(char chess[][8]){

	char z = 'a';
	cout << endl;
	cout << "     ";

	for (int i = 0; i < 8; i++,z++){
		cout << z << "   ";
	}
	cout << endl;
	cout << "    ___ ___ ___ ___ ___ ___ ___ ___" << endl;
	
	for (int i = 0; i < 8; i++){
		cout <<" "<< i <<" | ";
		for (int j = 0; j < 8; j++){
			cout << chess[i][j] << " | ";
		}
		cout << endl ;
		cout <<"   |___|___|___|___|___|___|___|___|"<< endl;
	
	}
}
bool check_boundary_pawn_w(char chess[][8], char sp[], char dp[]){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((i == y) && (j == x)){
		return check = false;
	}
	if (j == x){
		if (check == false){
			if (i == 1){
				for (int a = i + 1, b = j, c = 0; c < 2; c++, a++){
					if (a == y){
						check = true;
					}
				}
			}
			else{
				for (int a = i + 1, b = j, c = 0; c < 1; c++, a++){
					if ((a == y)){
						check = true;
					}
				}
			}
		}
	}
	else{
		if (check == false){
			for (int a = i + 1, b = j + 1, c = 0; c < 1; c++, a++, b++){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
		if (check == false){
			for (int a = i + 1, b = j - 1, c = 0; c < 1; c++, a++, b--){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
	}
	return check;
}
bool check_piece_pawn_w(char chess[][8], char sp[], char dp[]){
	bool check = true;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if (j == x){
		if (i == 1){
			for (int a = i + 1, b = j;a!=y+1 ;  a++){
				if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
					check = false;
				}
			}
		}
		else{
			for (int a = i+ 1,b=j;a!=y+1; a++){
				if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
					check = false;
				}
			}
		}
	}
	else{
		if (j < x){
			for (int a = i + 1, b = j + 1; ((a != y + 1) && (b != x + 1)); a++, b++){
				if (((chess[a][b] >= 65) && (chess[a][b] <= 90))){
					check = true;
				}
				else{
					check = false;
				}
			}
		}
		if (j > x){
			for (int a = i + 1, b = j - 1; ((a != y + 1) && (b != x - 1)); a++, b--){
				if ((chess[a][b] >= 65) && (chess[a][b] <= 90)){
					check = true;
				}
				else{
					check = false;
				}
			}
		}
	}
	return check;

}
bool check_boundary_pawn_b(char chess[][8], char sp[], char dp[]){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((i == y) && (j == x)){
		return check = false;
	}
	if (j == x){
		if (check == false){
			if (i == 6){
				for (int a = i - 1, b = j, c = 0; c < 2; c++, a--){
					if (a == y){
						check = true;
					}
				}
			}
			else{
				for (int a = i - 1, b = j, c = 0; c < 1; c++, a--){
					if (a == y){
						check = true;
					}
				}
			}
		}
	}
	else{
		if (check == false){
			for (int a = i - 1, b = j + 1, c = 0; c < 1; c++, a--, b++){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
		if (check == false){
			for (int a = i - 1, b = j - 1, c = 0; c < 1; c++, a--, b--){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
	}
	return check;
}
bool check_piece_pawn_b(char chess[][8], char sp[], char dp[]){
	bool check = true;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if (j == x){
		if (i == 6){
			for (int a = i - 1, b = j; a != y - 1; a--){
				if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
					check = false;
				}
			}
		}
		else{
			for (int a = i - 1, b = j; a != y - 1; a--){
				if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
					check = false;
				}
			}
		}
	}
	else{
		if (j < x){
			for (int a = i - 1, b = j + 1; ((a != y - 1) && (b != x + 1)); a--, b++){
				if ((chess[a][b] >= 65) && (chess[a][b] <= 90)){
					check = false;
				}
				if ((chess[a][b] >= 97) && (chess[a][b] <= 122)){
					check = true;
				}
				else{
					check = false;
				}
			}
		}
		if (j > x){
			for (int a = i - 1, b = j - 1; ((a != y - 1) && (b != x - 1)); a--, b--){
				if ((chess[a][b] >= 65) && (chess[a][b] <= 90)){
					check = false;
				}
				if ((chess[a][b] >= 97) && (chess[a][b] <= 122)){
					check = true;
				}
				else{
					check = false;
				}
			}
		}
	}
	return check;

}
bool check_boundary_rook(char chess[][8], char sp[], char dp[]){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'r') || (chess[i][j] == 'R')){
		if ((i == y) && (j == x)){
			return check = false;
		}
		if (j == x){
			if (check == false){
				for (int a = i + 1; a < 8; a++){
					if (a == y){
						check = true;
					}
				}
			}
			if (check == false){
				for (int a = i - 1; a >= 0; a--){
					if (a == y){
						check = true;
					}
				}
			}
		}
		if (i == y){

			if (check == false){
				for (int a = (j + 1); a < 8; a++){
					if ((a == x)){
						check = true;
					}
				}
			}
			if (check == false){
				for (int a = j - 1; a >= 0; a--){
					if ((a == x)){
						check = true;
					}
				}
			}
		}
	}
	return check;
}
bool check_piece_rook(char chess[][8], char sp[], char dp[]){
	bool check = true;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;

	if ((chess[i][j] == 'r') || (chess[i][j] == 'R')){
		if (j == x){
			if (i < y){
				for (int a = i + 1, b = j; a != y; a++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j; a != y; a--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (i == y){
			if (j < x){
				for (int a = i, b = j + 1; b != x; b++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (j > x){
				for (int a = i, b = j - 1; b != x; b--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (chess[i][j] == 'r'){
			if ((chess[y][x] >= 97) && (chess[y][x] <= 122)){
				check = false;
			}
		}
		if (chess[i][j] == 'R'){
			if ((chess[y][x] >= 65) && (chess[y][x] <= 90)){
				check = false;
			}
		}
	}

	return check;
}
bool check_boundary_bishop(char chess[][8], char sp[], char dp[]){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'b') || (chess[i][j] == 'B')){
		if ((i == y) && (j == x)){
			return check = false;
		}
		if (check == false){
			for (int a = i - 1, b = j + 1; ((a >= 0) && (b < 8)); a--, b++){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
		if (check == false){
			for (int a = i - 1, b = j - 1; ((a >= 0) && (b >= 0)); a--, b--){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
		if (check == false){
			for (int a = i + 1, b = j - 1; ((a < 8) && (b >= 0)); a++, b--){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
		if (check == false){
			for (int a = i + 1, b = j + 1; ((a < 8) && (b < 8)); a++, b++){
				if ((b == x) && (a == y)){
					check = true;
				}
			}
		}
	}
	return check;

}
bool check_boundary_queen(char chess[][8], char sp[], char dp[]){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'q') || (chess[i][j] == 'Q')){
		if ((i == y) && (j == x)){
			return check = false;
		}
		if (j < x){
			if (i < y){
				for (int a = i + 1, b = j + 1; ((a < 8) && (b < 8)); a++, b++){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j + 1; ((a >= 0) && (b < 8)); a--, b++){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
		}
		if (j > x){
			if (i < y){
				for (int a = i + 1, b = j - 1; ((a < 8) && (b >= 0)); a++, b--){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j - 1; ((a >= 0) && (b >= 0)); a--, b--){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
		}
		if (j == x){
			if (i < y){
				for (int a = i + 1, b = j; a < 8; a++){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j; a >= 0; a--){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
		}
		if (i == y){
			if (j < x){
				for (int a = i, b = j + 1; b < 8; b++){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
			if (j > x){
				for (int a = i, b = j - 1; b >= 0; b--){
					if ((a == y) && (b == x)){
						check = true;
					}
				}
			}
		}
	}
	return check;
}
bool check_piece_bishop(char chess[][8], char sp[], char dp[]){
	bool check = true;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;

	if ((chess[i][j] == 'b') || (chess[i][j] == 'B')){
		if (j < x){
			if (i < y){
				for (int a = i + 1, b = j + 1; ((a != y) && (b != x)); a++, b++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j + 1; ((a != y) && (b != x)); a--, b++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (j > x){
			if (i < y){
				for (int a = i + 1, b = j - 1; ((a != y) && (b != x)); a++, b--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j - 1; ((a != y) && (b != x)); a--, b--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (chess[i][j] == 'b'){
			if ((chess[y][x] >= 97) && (chess[y][x] <= 122)){
				check = false;
			}
		}
		if (chess[i][j] == 'B'){
			if ((chess[y][x] >= 65) && (chess[y][x] <= 90)){
				check = false;
			}
		}
	}

	return check;
}
bool check_piece_queen(char chess[][8], char sp[], char dp[]){
	bool check = true;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'q') || (chess[i][j] == 'Q')){
		if (j < x){
			if (i < y){
				for (int a = i + 1, b = j + 1; ((a != y) && (b != x)); a++, b++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j + 1; ((a != y) && (b != x)); a--, b++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (j > x){
			if (i < y){
				for (int a = i + 1, b = j - 1; ((a != y) && (b != x)); a++, b--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j - 1; ((a != y) && (b != x)); a--, b--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (j == x){
			if (i < y){
				for (int a = i + 1, b = j; a != y; a++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (i > y){
				for (int a = i - 1, b = j; a != y; a--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (i == y){
			if (j < x){
				for (int a = i, b = j + 1; b != x; b++){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
			if (j > x){
				for (int a = i, b = j - 1; b != x; b--){
					if (((chess[a][b] >= 97) && (chess[a][b] <= 122)) || ((chess[a][b] >= 65) && (chess[a][b] <= 90))){
						check = false;
					}
				}
			}
		}
		if (chess[i][j] == 'Q'){
			if ((chess[y][x] >= 65) && (chess[y][x] <= 90)){
				check = false;
			}
		}
		if (chess[i][j] == 'q'){
			if ((chess[y][x] >= 97) && (chess[y][x] <= 122)){
				check = false;
			}
		}
	}

	return check;
}
bool check_boundary_king(char chess[][8], char sp[], char dp[]){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'k') || (chess[i][j] == 'K')){
		if ((i == y) && (j == x)){
			return check = false;
		}
		if (check == false){
			if (((i - 1) == y) && ((j) == x)){
				check = true;
			}
		}
		if (check == false){
			if (((j + 1) == x) && ((i - 1) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j + 1) == x) && ((i) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j + 1) == x) && ((i + 1) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j) == x) && ((i + 1) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j - 1) == x) && ((i + 1) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j - 1) == x) && ((i) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j - 1) == x) && ((i - 1) == y)){
				check = true;
			}
		}
	}
	return check;

}
bool check_piece_king(char chess[][8], char sp[], char dp[]){
	bool check = true;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'n')){
		if (((i - 1) == y) && ((j) == x)){
			if ((chess[i - 1][j] >= 97 && (chess[i - 1][j] <= 122))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j + 1) == x)){
			if ((chess[i - 1][j + 1] >= 97 && (chess[i - 1][j + 1] <= 122))){
				check = false;
			}
		}
		if (((i) == y) && ((j + 1) == x)){
			if ((chess[i][j + 1] >= 97 && (chess[i][j + 1] <= 122))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j + 1) == x)){
			if ((chess[i + 1][j + 1] >= 97 && (chess[i + 1][j + 1] <= 122))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j) == x)){
			if ((chess[i + 1][j] >= 97 && (chess[i + 1][j] <= 122))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j - 1) == x)){
			if ((chess[i + 1][j - 1] >= 97 && (chess[i + 1][j - 1] <= 122))){
				check = false;
			}
		}
		if (((i) == y) && ((j - 1) == x)){
			if ((chess[i][j - 1] >= 97 && (chess[i][j - 1] <= 122))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j - 1) == x)){
			if ((chess[i - 1][j - 2] >= 97 && (chess[i - 1][j - 2] <= 122))){
				check = false;
			}
		}
	}
	if ((chess[i][j] == 'N')){
		if (((i - 1) == y) && ((j) == x)){
			if ((chess[i - 1][j] >= 65 && (chess[i - 1][j] <= 90))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j + 1) == x)){
			if ((chess[i - 1][j + 1] >= 65 && (chess[i - 1][j + 1] <= 90))){
				check = false;
			}
		}
		if (((i) == y) && ((j + 1) == x)){
			if ((chess[i][j + 1] >= 65 && (chess[i][j + 1] <= 90))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j + 1) == x)){
			if ((chess[i + 1][j + 1] >= 65 && (chess[i + 1][j + 1] <= 90))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j) == x)){
			if ((chess[i + 1][j] >= 65 && (chess[i + 1][j] <= 90))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j - 1) == x)){
			if ((chess[i + 1][j - 1] >= 65 && (chess[i + 1][j - 1] <= 122))){
				check = false;
			}
		}
		if (((i) == y) && ((j - 1) == x)){
			if ((chess[i][j - 1] >= 65 && (chess[i][j - 1] <= 90))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j - 1) == x)){
			if ((chess[i - 1][j - 2] >= 65 && (chess[i - 1][j - 2] <= 90))){
				check = false;
			}
		}
	}
	return check;

}
bool check_boundary_knight(char chess[][8], char sp[], char dp[]){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'n') || (chess[i][j] == 'N')){
		if ((i == y) && (j == x)){
			return check = false;
		}
		if (check == false){
			if (((i - 2) == y) && ((j - 1) == x)){
				check = true;
			}
		}
		if (check == false){
			if (((j + 1) == x) && ((i - 2) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j + 2) == x) && ((i - 1) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j + 2) == x) && ((i + 1) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j + 1) == x) && ((i + 2) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j - 1) == x) && ((i + 2) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j - 2) == x) && ((i + 1) == y)){
				check = true;
			}
		}
		if (check == false){
			if (((j - 2) == x) && ((i - 1) == y)){
				check = true;
			}
		}
	}
	return check;

}
bool check_piece_knight(char chess[][8], char sp[], char dp[]){
	bool check = true;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if ((chess[i][j] == 'n')){
		if (((i - 2) == y) && ((j - 1) == x)){
			if ((chess[i - 2][j - 1] >= 97 && (chess[i - 2][j - 1] <= 122))){
				check = false;
			}
		}
		if (((i - 2) == y) && ((j + 1) == x)){
			if ((chess[i - 2][j + 1] >= 97 && (chess[i - 2][j + 1] <= 122))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j + 2) == x)){
			if ((chess[i - 1][j + 2] >= 97 && (chess[i - 1][j + 2] <= 122))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j + 2) == x)){
			if ((chess[i + 1][j + 2] >= 97 && (chess[i + 1][j + 2] <= 122))){
				check = false;
			}
		}
		if (((i + 2) == y) && ((j + 1) == x)){
			if ((chess[i + 2][j + 1] >= 97 && (chess[i + 2][j + 1] <= 122))){
				check = false;
			}
		}
		if (((i + 2) == y) && ((j - 1) == x)){
			if ((chess[i + 2][j - 1] >= 97 && (chess[i + 2][j - 1] <= 122))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j - 2) == x)){
			if ((chess[i + 1][j - 2] >= 97 && (chess[i + 1][j - 2] <= 122))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j - 2) == x)){
			if ((chess[i - 1][j - 2] >= 97 && (chess[i - 1][j - 2] <= 122))){
				check = false;
			}
		}
	}
	if ((chess[i][j] == 'N')){
		if (((i - 2) == y) && ((j - 1) == x)){
			if ((chess[i - 2][j - 1] >= 65 && (chess[i - 2][j - 1] <= 90))){
				check = false;
			}
		}
		if (((i - 2) == y) && ((j + 1) == x)){
			if ((chess[i - 2][j + 1] >= 65 && (chess[i - 2][j + 1] <= 90))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j + 2) == x)){
			if ((chess[i - 1][j + 2] >= 65 && (chess[i - 1][j + 2] <= 90))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j + 2) == x)){
			if ((chess[i + 1][j + 2] >= 65 && (chess[i + 1][j + 2] <= 90))){
				check = false;
			}
		}
		if (((i + 2) == y) && ((j + 1) == x)){
			if ((chess[i + 2][j + 1] >= 65 && (chess[i + 2][j + 1] <= 90))){
				check = false;
			}
		}
		if (((i + 2) == y) && ((j - 1) == x)){
			if ((chess[i + 2][j - 1] >= 65 && (chess[i + 2][j - 1] <= 90))){
				check = false;
			}
		}
		if (((i + 1) == y) && ((j - 2) == x)){
			if ((chess[i + 1][j - 2] >= 65 && (chess[i + 1][j - 2] <= 90))){
				check = false;
			}
		}
		if (((i - 1) == y) && ((j - 2) == x)){
			if ((chess[i - 1][j - 2] >= 65 && (chess[i - 1][j - 2] <= 90))){
				check = false;
			}
		}
	}
	return check;

}
void move_execution(char chess[][8], char sp[], char dp[]){
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	chess[y][x] = chess[i][j];
	chess[i][j] = ' ';
}
bool check_pawn_promotion(char chess[][8], char user){
	bool check = false;
	if (user == 'b'){
		for (int i = 0; i == 0; i++){
			for (int j = 0; j < 8; j++){
				if (chess[i][j] == 'P'){
					check = true;
				}
			}
		}
	}
	if (user == 'w'){
		for (int i = 7; i == 7; i++){
			for (int j = 0; j < 8; j++){
				if (chess[i][j] == 'p'){
					check = true;
				}
			}
		}
	}
	return check;
}
bool king_check(char chess[][8], char user){
	bool check = false;
	if (user == 'w'){
		for (int a = 0; a < 8; a++){
			for (int b = 0; b < 8; b++){
				if ((chess[a][b] >= 65) && (chess[a][b] <= 90)){
					switch (chess[a][b]){
					case('P') :

						for (int i = a - 1, j = b + 1, c = 0; c < 1; i--, j++, c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a - 1, j = b - 1, c = 0; c < 1; i--, j--, c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('R') :

						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('B') :

						for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									i = -1;
								}
							}
						}

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('Q') :
						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('N') :
						for (int i = a - 2, j = b + 1, c = 0; c < 1; c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}
							  for (int i = a - 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b + 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					default:
						break;
					}
				}
			}
		}
		if (check == false){
			return check;
		}
	}
	if (user == 'b'){
		for (int a = 0; a < 8; a++){
			for (int b = 0; b < 8; b++){
				if ((chess[a][b] >= 97) && (chess[a][b] <= 122)){
					switch (chess[a][b]){
					case('p') :

						for (int i = a + 1, j = b + 1, c = 0; c < 1; i++, j++, c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b - 1, c = 0; c < 1; i++, j--, c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('r') :

						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('b') :

						for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('q') :
						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('n') :
						for (int i = a - 2, j = b + 1, c = 0; c < 1; c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}
							  for (int i = a - 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b + 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					default:
						break;
					}
				}
			}
		}
		if (check == false){
			return check;
		}
	}
}
bool check_mate(char chess[][8], char user){
	bool check = false;
	if (user == 'b'){
		for (int a = 0; a < 8; a++){
			for (int b = 0; b < 8; b++){
				if ((chess[a][b] >= 65) && (chess[a][b] <= 90)){
					switch (chess[a][b]){
					case('P') :

						for (int i = a - 1, j = b + 1, c = 0; c < 1; i--, j++, c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a - 1, j = b - 1, c = 0; c < 1; i--, j--, c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('R') :

						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('B') :

						for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									i = -1;
								}
							}
						}

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('Q') :
						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('N') :
						for (int i = a - 2, j = b + 1, c = 0; c < 1; c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'k')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}
							  for (int i = a - 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b + 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'k')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					default:
						break;
					}
				}
			}
		}
		if (check == false){
			return check;
		}
	}
	if (user == 'w'){
		for (int a = 0; a < 8; a++){
			for (int b = 0; b < 8; b++){
				if ((chess[a][b] >= 97) && (chess[a][b] <= 122)){
					switch (chess[a][b]){
					case('p') :

						for (int i = a + 1, j = b + 1, c = 0; c < 1; i++, j++, c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b - 1, c = 0; c < 1; i++, j--, c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('r') :

						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('b') :

						for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('q') :
						for (int i = a - 1, j = b; ((i >= 0)); i--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}

							  for (int i = a + 1, j = b; ((i < 8)); i++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a, j = b - 1; ((j >= 0)); j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a, j = b + 1; ((j < 8)); j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 1; ((i >= 0) && (j >= 0)); j--, i--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a + 1, j = b + 1; ((i < 8) && (j < 8)); i++, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }

							  for (int i = a - 1, j = b + 1; ((i >= 0) && (j < 8)); i--, j++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 1; ((j >= 0) && (i < 8)); i++, j--){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					case('n') :
						for (int i = a - 2, j = b + 1, c = 0; c < 1; c++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								if ((chess[i][j] == 'K')){
									return check = true;
								}
								else{
									check = false;
									break;
								}
							}
						}
							  for (int i = a - 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b + 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b + 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 2, j = b - 1, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a + 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  for (int i = a - 1, j = b - 2, c = 0; c < 1; c++){
								  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
									  if ((chess[i][j] == 'K')){
										  return check = true;
									  }
									  else{
										  check = false;
										  break;
									  }
								  }
							  }
							  break;
					default:
						break;
					}
				}
			}
		}
		if (check == false){
			return check;
		}
	}
}
bool stalemate(char chess[][8], char user){
	bool check = true;
	if (king_check(chess, user) == false){
		if (user == 'w'){
			for (int a = 0; a < 8; a++){
				for (int b = 0; b < 8; b++){
					if ((chess[a][b] >= 97) && (chess[a][b] <= 122)){
						switch (chess[a][b]){
						case('p') :
							if (check == true){
								for (int i = a + 1, j = b + 1, c = 0; c == 0; i++, j++, c++){
									int count = 0;
									if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}
								  if (check == true){
									  for (int i = a + 1, j = b, c = 0; c == 0; i++, j++, c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b - 1, c = 0; c == 0; i++, j--, c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('r') :
							if (check == true){
								for (int i = a - 1, j = b; i == (a - 1); i--){
									int count = 0;
									if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}

								  if (check == true){
									  for (int i = a + 1, j = b; i == (a + 1); i++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a, j = b - 1; j == (b - 1); j--){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a, j = b + 1; j == (b + 1); j++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('b') :
							if (check == true){
								for (int i = a - 1, j = b - 1; ((i == (a - 1)) && (j == (b - 1))); j--, i--){
									int count = 0;
									if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}

								  if (check == true){
									  for (int i = a + 1, j = b + 1; ((i == (a + 1)) && (j == (b + 1))); j++, i++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a - 1, j = b + 1; ((i == (a - 1)) && (j == (b + 1))); j++, i--){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b - 1; ((i == (a + 1)) && (j == (b - 1))); j--, i++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('q') :
							if (check == true){
								for (int i = a - 1, j = b; i == (a - 1); i--){
									int count = 0;
									if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}

								  if (check == true){
									  for (int i = a + 1, j = b; i == (a + 1); i++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a, j = b - 1; j == (b - 1); j--){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a, j = b + 1; j == (b + 1); j++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a - 1, j = b - 1; ((i == (a - 1)) && (j == (b - 1))); j--, i--){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a + 1, j = b + 1; ((i == (a + 1)) && (j == (b + 1))); j++, i++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a - 1, j = b + 1; ((i == (a - 1)) && (j == (b + 1))); j++, i--){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b - 1; ((i == (a + 1)) && (j == (b - 1))); j--, i++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('n') :
							if (check == true){
								for (int i = a - 2, j = b + 1, c = 0; c == 0; c++){
									int count = 0;
									if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}
								  if (check == true){
									  for (int i = a - 2, j = b - 1, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a - 1, j = b + 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b + 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 2, j = b + 1, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 2, j = b - 1, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b - 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a - 1, j = b - 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						default:
							break;
						}
					}
				}
			}


		}
		if (user == 'b'){
			for (int a = 0; a < 8; a++){
				for (int b = 0; b < 8; b++){
					if ((chess[a][b] >= 65) && (chess[a][b] <= 90)){
						switch (chess[a][b]){
						case('P') :
							if (check == true){
								for (int i = a - 1, j = b - 1, c = 0; c == 0; i--, j--, c++){
									int count = 0;
									if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}
								  if (check == true){
									  for (int i = a - 1, j = b, c = 0; c == 0; i--, j++, c++){
										  int count = 0;
										  if (((chess[i][j] >= 97) && (chess[i][j] <= 122)) || ((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a - 1, j = b - 1, c = 0; c == 0; i--, j--, c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('R') :
							if (check == true){
								for (int i = a - 1, j = b; i == (a - 1); i--){
									int count = 0;
									if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}

								  if (check == true){
									  for (int i = a + 1, j = b; i == (a + 1); i++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a, j = b - 1; j == (b - 1); j--){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a, j = b + 1; j == (b + 1); j++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('B') :
							if (check == true){
								for (int i = a - 1, j = b - 1; ((i == (a - 1)) && (j == (b - 1))); j--, i--){
									int count = 0;
									if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}

								  if (check == true){
									  for (int i = a + 1, j = b + 1; ((i == (a + 1)) && (j == (b + 1))); j++, i++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a - 1, j = b + 1; ((i == (a - 1)) && (j == (b + 1))); j++, i--){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b - 1; ((i == (a + 1)) && (j == (b - 1))); j--, i++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('Q') :
							if (check == true){
								for (int i = a - 1, j = b; i == (a - 1); i--){
									int count = 0;
									if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}

								  if (check == true){
									  for (int i = a + 1, j = b; i == (a + 1); i++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a, j = b - 1; j == (b - 1); j--){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a, j = b + 1; j == (b + 1); j++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a - 1, j = b - 1; ((i == (a - 1)) && (j == (b - 1))); j--, i--){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a + 1, j = b + 1; ((i == (a + 1)) && (j == (b + 1))); j++, i++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }

								  if (check == true){
									  for (int i = a - 1, j = b + 1; ((i == (a - 1)) && (j == (b + 1))); j++, i--){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b - 1; ((i == (a + 1)) && (j == (b - 1))); j--, i++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						case('N') :
							if (check == true){
								for (int i = a - 2, j = b + 1, c = 0; c == 0; c++){
									int count = 0;
									if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
										count++;
									}
									if (count == 0){
										return check = false;
									}
								}
							}
								  if (check == true){
									  for (int i = a - 2, j = b - 1, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a - 1, j = b + 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b + 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 2, j = b + 1, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 2, j = b - 1, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a + 1, j = b - 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  if (check == true){
									  for (int i = a - 1, j = b - 2, c = 0; c == 0; c++){
										  int count = 0;
										  if (((chess[i][j] >= 65) && (chess[i][j] <= 90))){
											  count++;
										  }
										  if (count == 0){
											  return check = false;
										  }
									  }
								  }
								  break;
						default:
							break;
						}
					}
				}
			}


		}
		return check;
	}
	else{
		return false;
	}

}
bool check_en_passante(char chess[][8], char sp[], char dp[], char user){
	bool check = false;
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if (user == 'w'){
		if (((i + 1) == y) && ((j + 1) == x)){
			if (chess[i][j + 1] == 'P'){
				check = true;
			}
		}
		if (((i + 1) == y) && ((j - 1) == x)){
			if (chess[i][j - 1] == 'P'){
				check = true;
			}
		}
	}
	if (user == 'b'){
		if (((i - 1) == y) && ((j + 1) == x)){
			if (chess[i][j + 1] == 'p'){
				check = true;
			}
		}
		if (((i - 1) == y) && ((j - 1) == x)){
			if (chess[i][j - 1] == 'p'){
				check = true;
			}
		}
	}
	return check;
}
void en_passante(char chess[][8], char sp[], char dp[], char user){
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if (user == 'w'){
		if (((i + 1) == y) && ((j + 1) == x)){
			if (chess[i][j + 1] == 80){
				chess[i][j + 1] = ' ';
				chess[y][x] = 'p';
				chess[i][j] = ' ';
			}
		}
		if (((i + 1) == y) && ((j - 1) == x)){
			if (chess[i][j - 1] == 80){
				chess[i][j - 1] = ' ';
				chess[y][x] = 'p';
				chess[i][j] = ' ';
			}
		}
	}
	if (user == 'b'){
		if (((i - 1) == y) && ((j + 1) == x)){
			if (chess[i][j + 1] == 112){
				chess[i][j + 1] = ' ';
				chess[y][x] = 'P';
				chess[i][j] = ' ';
			}
		}
		if (((i - 1) == y) && ((j - 1) == x)){
			if (chess[i][j - 1] == 112){
				chess[i][j - 1] = ' ';
				chess[y][x] = 'P';
				chess[i][j] = ' ';
			}
		}
	}
}
void pawn_promotion(char chess[][8], char sp[], char dp[], char user){
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	if (check_pawn_promotion(chess, user)){
		if (user == 'w'){
			system("cls");
			print_board(chess);
			cout << endl;
			cout << "Congratulations!!Your pawn is being promoted" << endl;
			cout << "Choose a piece : r , b , q , n" << endl;
			char temp;
			cin >> temp;
			switch (temp){
			case('r') :
				if (chess[y][x] == 'p'){
					chess[y][x] = 'r';
				}
					  break;
			case('b') :
				if (chess[y][x] == 'p'){
					chess[y][x] = 'b';
				}
					  break;
			case('q') :
				if (chess[y][x] == 'p'){
					chess[y][x] = 'q';
				}
					  break;
			case('n') :
				if (chess[y][x] == 'p'){
					chess[y][x] = 'n';
				}
					  break;
			default:
				break;
			}
		}
		if (user == 'b'){
			system("cls");
			print_board(chess);
			cout << endl;
			cout << "Congratulations!!Your pawn is being promoted" << endl;
			cout << "Choose a piece : R , B , Q , N" << endl;
			char temp;
			cin >> temp;
			switch (temp){
			case('R') :
				if (chess[y][x] == 'P'){
					chess[y][x] = 'R';
				}
					  break;
			case('B') :
				if (chess[y][x] == 'P'){
					chess[y][x] = 'B';
				}
					  break;
			case('Q') :
				if (chess[y][x] == 'P'){
					chess[y][x] = 'Q';
				}
					  break;
			case('N') :
				if (chess[y][x] == 'P'){
					chess[y][x] = 'N';
				}
					  break;
			default:
				break;
			}
		}
	}
}
bool check_castling(char chess[][8], char sp[], char dp[], char user, int w_king_moves, int b_king_moves){
	bool check = false;
	int a = sp[1] - 48;
	int x = dp[1] - 48;
	int b = sp[0] - 97;
	int y = dp[0] - 97;
	int count = 0;
	if (user == 'b'){
		if (king_check(chess, user) == false){
			if (b_king_moves == 0){
				if (b == (y - 2)){
					if ((chess[7][7] == 'R')){
						count = 0;
						for (int i = 7, j = 3 + 1; ((i < 8) && (j < 7)); j++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								count++;
							}
						}
						if (count == 0){
							return check = true;
						}
					}
				}
				if (b == y + 2){
					if ((chess[7][0] == 'R')){
						count = 0;
						for (int i = 7, j = 3 - 1; ((i < 8) && (j > 0)); j--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								count++;
							}
						}
						if (count == 0){
							return check = true;
						}
					}
				}
			}
		}
		return check;
	}
	if (user == 'w'){
		if (king_check(chess, user) == false){
			if (w_king_moves == 0){
				if (b == y - 2){
					if ((chess[0][7] == 'r')){
						count = 0;
						for (int i = 0, j = 4 + 1; ((i < 8) && (j != 7)); j++){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								count++;
							}
						}
						if (count == 0){
							return check = true;
						}
					}
				}

				if (b == y + 2){
					if ((chess[0][0] == 'r')){
						for (int i = 0, j = 4 - 1; ((i < 8) && (j > 0)); j--){
							if (((chess[i][j] >= 65) && (chess[i][j] <= 90)) || ((chess[i][j] >= 97) && (chess[i][j] <= 122))){
								count++;
							}
						}
						if (count == 0){
							return check = true;
						}
					}
				}
			}
		}
		return check;
	}
}
void castling(char chess[][8], char sp[], char dp[], char user, int w_king_moves, int b_king_moves){
	int a = sp[1] - 48;
	int x = dp[1] - 48;
	int b = sp[0] - 97;
	int y = dp[0] - 97;
	if (user == 'w'){
		chess[a][b] = ' ';
		chess[x][y] = 'k';
		if (b < y){
			chess[0][7] = ' ';
			chess[x][y - 1] = 'r';
		}
		if (b > y){
			chess[0][0] = ' ';
			chess[x][y + 1] = 'r';
		}
		w_king_moves++;
	}
	if (user == 'b'){
		chess[a][b] = ' ';
		chess[x][y] = 'K';
		if (b < y){
			chess[7][7] = ' ';
			chess[x][y - 1] = 'R';
		}
		if (b > y){
			chess[7][0] = ' ';
			chess[x][y + 1] = 'R';
		}
		b_king_moves++;
	}
}
void play_and_record_chess(char chess[][8], char sp[], char dp[], char &user, int &w_king_moves, int &b_king_moves){
	bool kingCheck = false;
	system("cls");
	cout << endl;
	cout << " Press ESC to exit" << endl << endl;
	cout << " Small letters are white pieces" << endl;
	cout << " Capital letters are black pieces" << endl;
	print_board(chess);
	cout << endl;
	if (user == 'w'){
		cout << " White move" << endl;
	}
	if (user == 'b'){
		cout << " Black move" << endl;
	}
	cout << endl;

	if (king_check(chess, user)){
		kingCheck = true;
		if (user == 'w'){
			cout << " White king in check!!" << endl;
		}
		if (user == 'b'){
			cout << " Black king in check!!" << endl;
		}
		cout << endl;
	}
	if (check_mate(chess, user)){
		cout << "checkmate!!" << endl;
		if (user == 'w'){
			cout <<endl<< "white player wins!!" <<endl<< endl;
			return;
		}
		else{
			cout <<endl<< "black player wins!!" <<endl<< endl;
			return;
		}
	}
	if (stalemate(chess, user)){
		cout <<endl<< "Stalemate!!" <<endl<< endl;
		return;
	}
	_kbhit();
	if (_getch() != 27){
		cout << " Enter source point : ";
		cin >> sp;
		cout << " Enter destination point : ";
		cin >> dp;
	} 
	else{
		fout.close();
		char temp[10];
		ifstream filein("D:\\Programming Fundamentals\\chess_record.txt");
		ofstream fileout("D:\\Programming Fundamentals\\chess_record1.txt");
		while (filein.getline(temp, 10)){
			fileout << temp << endl;
		}
		filein.close();
		fileout.close();
		return;
	}
	if ((sp[0] < 97) || (sp[0] > 104) || (dp[0] < 97) || (dp[0] > 104) || (dp[1] < 48) || (dp[1] > 55) || (sp[1] < 48) || (sp[1] > 55)){
		cout <<endl<< "Invalid Input"<<endl << endl;
		system("pause");
		play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
	}
	int i = sp[1] - 48;
	int y = dp[1] - 48;
	int j = sp[0] - 97;
	int x = dp[0] - 97;
	switch (chess[i][j]){
	case('b') :
		if (user == 'w'){
			if (check_boundary_bishop(chess, sp, dp)){
				if (check_piece_bishop(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					
					if (king_check(chess, user)){
						chess[i][j] = 'b';
						chess[y][x] = temp;
						if (kingCheck){
							cout<<endl << " King is still in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
					}
					else{
						fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'b';
					}
					system("cls");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);


				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('B') :
		if (user == 'b'){
			if (check_boundary_bishop(chess, sp, dp)){
				if (check_piece_bishop(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					
					if (king_check(chess, user)){
						chess[i][j] = 'B';
						chess[y][x] = temp;
						if (kingCheck){
							cout << endl << " King is still in check!!" << endl << endl;
							system("pause");
						}
						else{
							cout << endl << "This move will result in check!!" << endl << endl;
							system("pause");
						}
					}
					else{
						
						fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'w';
					}
					system("cls");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('r') :
		if (user == 'w'){
			if (check_boundary_rook(chess, sp, dp)){
				if (check_piece_rook(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					if (king_check(chess, user)){
						chess[i][j] = 'r';
						chess[y][x] = temp;
						if (kingCheck){
							cout << endl << " King is still in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							cout << endl << " This move will result in check!!" << endl << endl;
							system("pause");
						}
					}
					else{
						
						fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'b';
					}
					system("cls");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

					//print_board(chess);
				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('R') :
		if (user == 'b'){
			if (check_boundary_rook(chess, sp, dp)){
				if (check_piece_rook(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					if (king_check(chess, user)){
						chess[i][j] = 'R';
						chess[y][x] = temp;
						if (kingCheck){
							cout<<endl << " King is still in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
					}
					else{

						fout << user << sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'w';
					}
					system("cls");
					
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

					//print_board(chess);
				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('q') :
		if (user == 'w'){
			if (check_boundary_queen(chess, sp, dp)){
				if (check_piece_queen(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					if (king_check(chess, user)){
						chess[i][j] = 'q';
						chess[y][x] = temp;
						if (kingCheck){
							cout<<endl << " King is still in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
					}
					else{
						
						fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'b';
					}
					system("cls");
					
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('Q') :
		if (user == 'b'){
			if (check_boundary_queen(chess, sp, dp)){
				if (check_piece_queen(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					if (king_check(chess, user)){
						chess[i][j] = 'Q';
						chess[y][x] = temp;
						if (kingCheck){
							cout<<endl << " King is still in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
					}
					else{
						
						fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'w';
					}
					system("cls");
					
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

					//print_board(chess);
				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('p') :
		if (user == 'w'){
			if (check_en_passante(chess, sp, dp, user)){
				char temp = chess[i][j - 1];
				char temp1 = chess[i][j + 1];
				char temp2 = chess[y][x];
				en_passante(chess, sp, dp, user);
				if (king_check(chess, user)){
					chess[i][j] = 'p';
					chess[i][j + 1] = temp1;
					chess[i][j - 1] = temp;
					chess[y][x] = temp2;
					if (kingCheck){
						cout<<endl << " King is still in check!!" <<endl<< endl;
						system("pause");
					}
					else{
						cout<<endl << "This move will result in check!!" <<endl<< endl;
						system("pause");
					}
				}
				else{
					fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
					user = 'b';
				}
				system("cls");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
			else{
				if (check_boundary_pawn_w(chess, sp, dp)){
					if (check_piece_pawn_w(chess, sp, dp)){
						char temp=chess[y][x];
						move_execution(chess, sp, dp);
						if (king_check(chess, user)){
							chess[i][j] = 'p';
							chess[y][x] = temp;
							if (kingCheck){
								cout<<endl << " King is still in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
						}
						else{
							
							fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
							user = 'b';
						}
						pawn_promotion(chess, sp, dp, user);
						system("cls");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

						//print_board(chess);
					}
					else{
						cout << endl << "Invalid move" <<endl<< endl;
						system("pause");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
					}
				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}

		break;
	case('P') :
		if (user == 'b'){
			if (check_en_passante(chess, sp, dp, user)){
				char temp = chess[i][j - 1];
				char temp1 = chess[i][j + 1];
				char temp2 = chess[y][x];
				en_passante(chess, sp, dp, user);
				if (king_check(chess, user)){
					chess[i][j] = 'P';
					chess[i][j + 1] = temp1;
					chess[i][j - 1] = temp;
					chess[y][x] = temp2;
					if (kingCheck){
						cout<<endl << " King is still in check!!" <<endl<< endl;
						system("pause");
					}
					else{
						cout<<endl << "This move will result in check!!" <<endl<< endl;
						system("pause");
					}
				}
				else{
					
					fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
					user = 'w';
				}
				system("cls");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
			else{
				if (check_boundary_pawn_b(chess, sp, dp)){
					if (check_piece_pawn_b(chess, sp, dp)){
						char temp = chess[y][x];
						move_execution(chess, sp, dp);
						if (king_check(chess, user)){
							chess[i][j] = 'P';
							chess[y][x] = temp;
							if (kingCheck){
								cout<<endl << " King is still in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
						}
						else{
							
							fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
							user = 'w';
						}
						pawn_promotion(chess, sp, dp, user);
						system("cls");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

						//print_board(chess);
					}
					else{
						cout << endl << "Invalid move" <<endl<< endl;
						system("pause");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
					}
				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('n') :
		if (user == 'w'){
			if (check_boundary_knight(chess, sp, dp)){
				if (check_piece_knight(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					if (king_check(chess, user)){
						chess[i][j] = 'n';
						chess[y][x] = temp;
						if (kingCheck){
							cout<<endl << " King is still in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
					}
					else{
						
						fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'b';
					}
					system("cls");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);

					//print_board(chess);
				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('N') :
		if (user == 'b'){
			if (check_boundary_knight(chess, sp, dp)){
				if (check_piece_knight(chess, sp, dp)){
					char temp = chess[y][x];
					move_execution(chess, sp, dp);
					if (king_check(chess, user)){
						chess[i][j] = 'N';
						chess[y][x] = temp;
						if (kingCheck){
							cout<<endl << " King is still in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
					}
					else{
						
						fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
						user = 'w';
					}
					system("cls");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
			else{
				cout << endl << "Invalid move" <<endl<< endl;
				system("pause");
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}
		break;
	case('k') :
		if (user == 'w'){
			if (check_castling(chess, sp, dp, user, w_king_moves, b_king_moves)){
				castling(chess, sp, dp, user, w_king_moves, b_king_moves);
				system("cls");
				
				fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
				user = 'b';
				w_king_moves++;
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
			else{
				if (check_boundary_king(chess, sp, dp)){
					if (check_piece_king(chess, sp, dp)){
						char temp = chess[y][x];
						move_execution(chess, sp, dp);
						if (king_check(chess, user)){
							chess[i][j] = 'k';
							chess[y][x] = temp;
							if (kingCheck){
								cout<<endl << " King is still in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
						}
						else{
							
							fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
							user = 'b';
						}
						w_king_moves++;
						system("cls");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
						//print_board(chess);
					}
					else{
						cout << endl << "Invalid move" <<endl<< endl;
						system("pause");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
					}
				}

				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}

		break;
	case('K') :
		if (user == 'b'){
			if (check_castling(chess, sp, dp, user, w_king_moves, b_king_moves)){
				castling(chess, sp, dp, user, w_king_moves, b_king_moves);
				system("cls");
				
				fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
				user = 'w';
				b_king_moves++;
				play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
			}
			else{
				if (check_boundary_king(chess, sp, dp)){
					if (check_piece_king(chess, sp, dp)){
						char temp = chess[y][x];
						move_execution(chess, sp, dp);
						if (king_check(chess, user)){
							chess[i][j] = 'K';
							chess[y][x] = temp;
							if (kingCheck){
								cout<<endl << " King is still in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
						}
						else{
							
							fout <<user<< sp[0] << sp[1] << "-" << dp[0] << dp[1] << endl;
							user = 'w';
						}
						b_king_moves++;
						system("cls");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
						//print_board(chess);
					}
					else{
						cout << endl << "Invalid move" <<endl<< endl;
						system("pause");
						play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
					}
				}

				else{
					cout << endl << "Invalid move" <<endl<< endl;
					system("pause");
					play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
				}
			}
		}
		else{
			cout << endl << "Invalid move" <<endl<< endl;
			system("pause");
			play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		}

		break;
	
	default:
		cout << endl << "Invalid move" <<endl<< endl;
		system("pause");
		play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
		break;
	}
}
void load_game(char chess[][8], char sp[], char dp[], char &user, int &w_king_moves, int &b_king_moves){
	ifstream fin("D:\\Programming Fundamentals\\chess_record1.txt");
	if (fin.fail()){
		cout << "could not locate file" << endl;
	}
	else{
		char temp[10];
		w_king_moves = 0;
		b_king_moves = 0;
		while (fin.getline(temp, 10)){
			user = temp[0];
			sp[0] = temp[1];
			sp[1] = temp[2];
			dp[0] = temp[4];
			dp[1] = temp[5];
			cout << endl;
			int i = sp[1] - 48;
			int y = dp[1] - 48;
			int j = sp[0] - 97;
			int x = dp[0] - 97;
			switch (chess[i][j]){
			case('b') :
				if (user == 'w'){
					if (check_boundary_bishop(chess, sp, dp)){
						if (check_piece_bishop(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);

							if (king_check(chess, user)){
								chess[i][j] = 'b';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'b';
							}
							system("cls");
							print_board(chess);


						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('B') :
				if (user == 'b'){
					if (check_boundary_bishop(chess, sp, dp)){
						if (check_piece_bishop(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);

							if (king_check(chess, user)){
								chess[i][j] = 'B';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'w';
							}
							system("cls");
							print_board(chess);

						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('r') :
				if (user == 'w'){
					if (check_boundary_rook(chess, sp, dp)){
						if (check_piece_rook(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);
							if (king_check(chess, user)){
								chess[i][j] = 'r';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'b';
							}
							system("cls");
							print_board(chess);
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('R') :
				if (user == 'b'){
					if (check_boundary_rook(chess, sp, dp)){
						if (check_piece_rook(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);
							if (king_check(chess, user)){
								chess[i][j] = 'R';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'w';
							}
							system("cls");

							print_board(chess);
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('q') :
				if (user == 'w'){
					if (check_boundary_queen(chess, sp, dp)){
						if (check_piece_queen(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);
							if (king_check(chess, user)){
								chess[i][j] = 'q';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'b';
							}
							system("cls");

							print_board(chess);

						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('Q') :
				if (user == 'b'){
					if (check_boundary_queen(chess, sp, dp)){
						if (check_piece_queen(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);
							if (king_check(chess, user)){
								chess[i][j] = 'Q';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'w';
							}
							system("cls");
							print_board(chess);
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('p') :
				if (user == 'w'){
					if (check_en_passante(chess, sp, dp, user)){
						char temp = chess[i][j - 1];
						char temp1 = chess[i][j + 1];
						char temp2 = chess[y][x];
						en_passante(chess, sp, dp, user);
						if (king_check(chess, user)){
							chess[i][j] = 'p';
							chess[i][j + 1] = temp1;
							chess[i][j - 1] = temp;
							chess[y][x] = temp2;
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							user = 'b';
						}
						system("cls");
						print_board(chess);
					}
					else{
						if (check_boundary_pawn_w(chess, sp, dp)){
							if (check_piece_pawn_w(chess, sp, dp)){
								char temp = chess[y][x];
								move_execution(chess, sp, dp);
								if (king_check(chess, user)){
									chess[i][j] = 'p';
									chess[y][x] = temp;
									cout<<endl << "This move will result in check!!" <<endl<< endl;
									system("pause");
								}
								else{
									user = 'b';
								}
								pawn_promotion(chess, sp, dp, user);
								system("cls");
								print_board(chess);
							}
							else{
								system("cls");
								cout << " Invalid move" << endl << endl;
								system("pause");
								print_board(chess);
							}
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('P') :
				if (user == 'b'){
					if (check_en_passante(chess, sp, dp, user)){
						char temp = chess[i][j - 1];
						char temp1 = chess[i][j + 1];
						char temp2 = chess[y][x];
						en_passante(chess, sp, dp, user);
						if (king_check(chess, user)){
							chess[i][j] = 'P';
							chess[i][j + 1] = temp1;
							chess[i][j - 1] = temp;
							chess[y][x] = temp2;
							cout<<endl << "This move will result in check!!" <<endl<< endl;
							system("pause");
						}
						else{
							user = 'w';
						}
						system("cls");
						print_board(chess);
					}
					else{
						if (check_boundary_pawn_b(chess, sp, dp)){
							if (check_piece_pawn_b(chess, sp, dp)){
								char temp = chess[y][x];
								move_execution(chess, sp, dp);
								if (king_check(chess, user)){
									chess[i][j] = 'P';
									chess[y][x] = temp;
									cout<<endl << "This move will result in check!!" <<endl<< endl;
									system("pause");
								}
								else{
									user = 'w';
								}
								pawn_promotion(chess, sp, dp, user);
								system("cls");
								print_board(chess);
							}
							else{
								system("cls");
								cout << " Invalid move" << endl << endl;
								system("pause");
								print_board(chess);
							}
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('n') :
				if (user == 'w'){
					if (check_boundary_knight(chess, sp, dp)){
						if (check_piece_knight(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);
							if (king_check(chess, user)){
								chess[i][j] = 'n';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'b';
							}
							system("cls");
							print_board(chess);
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('N') :
				if (user == 'b'){
					if (check_boundary_knight(chess, sp, dp)){
						if (check_piece_knight(chess, sp, dp)){
							char temp = chess[y][x];
							move_execution(chess, sp, dp);
							if (king_check(chess, user)){
								chess[i][j] = 'N';
								chess[y][x] = temp;
								cout<<endl << "This move will result in check!!" <<endl<< endl;
								system("pause");
							}
							else{
								user = 'w';
							}
							system("cls");
							print_board(chess);
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
					else{
						system("cls");
						cout << " Invalid move" << endl << endl;
						system("pause");
						print_board(chess);
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('k') :
				if (user == 'w'){
					if (check_castling(chess, sp, dp, user, w_king_moves, b_king_moves)){
						castling(chess, sp, dp, user, w_king_moves, b_king_moves);
						system("cls");
						user = 'b';
						w_king_moves++;
						print_board(chess);
					}
					else{
						if (check_boundary_king(chess, sp, dp)){
							if (check_piece_king(chess, sp, dp)){
								char temp = chess[y][x];
								move_execution(chess, sp, dp);
								if (king_check(chess, user)){
									chess[i][j] = 'k';
									chess[y][x] = temp;
									cout<<endl << "This move will result in check!!" <<endl<< endl;
									system("pause");
								}
								else{
									user = 'b';
								}
								w_king_moves++;
								system("cls");
								print_board(chess);
							}
							else{
								system("cls");
								cout << " Invalid move" << endl << endl;
								system("pause");
								print_board(chess);
							}
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			case('K') :
				if (user == 'b'){
					if (check_castling(chess, sp, dp, user, w_king_moves, b_king_moves)){
						castling(chess, sp, dp, user, w_king_moves, b_king_moves);
						system("cls");
						user = 'w';
						b_king_moves++;
						print_board(chess);
					}
					else{
						if (check_boundary_king(chess, sp, dp)){
							if (check_piece_king(chess, sp, dp)){
								char temp = chess[y][x];
								move_execution(chess, sp, dp);
								if (king_check(chess, user)){
									chess[i][j] = 'K';
									chess[y][x] = temp;
									cout<<endl << "This move will result in check!!" <<endl<< endl;
									system("pause");
								}
								else{
									user = 'w';
								}
								b_king_moves++;
								system("cls");
								print_board(chess);
							}
							else{
								system("cls");
								cout << " Invalid move" << endl << endl;
								system("pause");
								print_board(chess);
							}
						}
						else{
							system("cls");
							cout << " Invalid move" << endl << endl;
							system("pause");
							print_board(chess);
						}
					}
				}
				else{
					system("cls");
					cout << " Invalid move" << endl << endl;
					system("pause");
					print_board(chess);
				}
				break;
			default:
				system("cls");
				print_board(chess);
				system("pause");
				break;
			}
			system("cls");
			print_board(chess);
			system("pause");
		}
		play_and_record_chess(chess, sp, dp, user, w_king_moves, b_king_moves);
	}
}
void display_options(char chess[][8], char sp[], char dp[], char &users,int &w_king_moves,int & b_king_moves){
	cout << endl << "	Welcome to Chess!!" << endl << "		by Usama Waseem" << endl << endl;
	cout << endl << "Do you want to start a new game or load your previous game? " << endl;
	cout << " 1 : start a new game" << endl;
	cout << " 2 : load previous game" << endl;
	int temp;
	cin >> temp;
	if (temp == 1){
		play_and_record_chess(chess, sp, dp, users,w_king_moves,b_king_moves);
	}
	if (temp == 2){
		load_game(chess, sp, dp, users,w_king_moves,b_king_moves);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char chess[8][8];
	char user = 'w';
	char sp[3], dp[3];
	int w_king_moves = 0, b_king_moves = 0;
	setup_chess(chess);
	display_options(chess, sp, dp, user,w_king_moves,b_king_moves);
	return 0;
}

