#include "headers/Game.h"
//#include "Game.cpp"
#include "headers/logic.h"
#include <iostream>
#include <string>
#include <fstream>

std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
std::vector<char> figures = {'N', 'Q', 'K', 'B', 'R'};
std::ofstream out("../moves.txt");
std::ifstream inp("../play.txt");
//Game new_game;
std::vector<std::string> normal_moves = {"e4", "f6", "e5", "e5"};

void prepare() {
    std::string s;
    std::vector<std::string> all_moves;
    getline(inp, s);
    int t = 0;
    while (s[0] != '1') {
        ++t;
        getline(inp, s);
    }
    all_moves.push_back(s);
    while (getline(inp, s)) {
        all_moves.push_back(s);
    }
    for (int i = 0; i < all_moves.size(); ++ i) {
        int pos = 0;
        while (pos < all_moves[i].size() - 1) {
            if (all_moves[i][pos + 1] == '.') {
                pos += 3;
                s = "";
                while (pos < all_moves[i].size() && all_moves[i][pos] != ' ') {
                    s += all_moves[i][pos];
                    ++pos;
                }
                ++pos;
                normal_moves.push_back(s);
                s = "";
                while (pos < all_moves[i].size() && all_moves[i][pos] != ' ') {
                    s += all_moves[i][pos];
                    ++pos;
                }
                normal_moves.push_back(s);
                ++pos;
            }
        }
    }
}

void return_move_positions(const Game& new_game, int t, std::string mv = "") {
    prepare();
    mv = normal_moves[t];
    //define move
    char figure = 'P';
    bool if_attack = false;
    bool if_white = (t + 1) % 2;
    bool if_long_castle = (mv[0] == 'O' && mv.size() == 6);
    bool if_short_castle = (mv[0] == 'O' && mv.size() == 4);
    int from_coordinates = 0; //если две фигуры могут походить на одну клетку
    std::pair<int, int> move_coordinates = {0, 0};
    std::string tmp;
    for (char i : mv) {
        if (i - 'a' >= 0 && i - 'a' < 8) {
            tmp += i;
        }
        if (i - '0' >= 0 && i - '0' < 8) {
            tmp += i;
        }
    }
    if (tmp.size() == 3) {
        from_coordinates = tmp[0] - 'a';
        move_coordinates = {tmp[1] - 'a', tmp[2] - '0'};
    }
    else {
        move_coordinates = {tmp[0] - 'a', tmp[1] - '0'};
    }
    --move_coordinates.first;
    std::vector<int> full_move = {0, 0, move_coordinates.first, move_coordinates.second};
    for (auto i : figures) {
        if (mv[0] == i) {
            figure = i;
            break;
        }
    }
    if (mv[0] == 'x' || mv[1] == 'x') if_attack = true;
    //
    //figures trearment
    switch (figure) {
        case 'P':
            if (!if_attack) {
                if (if_white) {
                    Position* pos = new_game.return_position();
                    if (move_coordinates.second - 1 >= 0 && pos->board_[move_coordinates.first - 1][move_coordinates.second]->get_piece_name() == PAWN && pos->board_[move_coordinates.first - 1][move_coordinates.second]->get_color() == WHITE) {
                        full_move[0] = move_coordinates.first - 1;
                        full_move[1] = move_coordinates.second;
                    }
                    if (move_coordinates.second - 2 >= 0 && pos->board_[move_coordinates.first - 2][move_coordinates.second]->get_piece_name() == PAWN && pos->board_[move_coordinates.first - 2][move_coordinates.second]->get_color() == WHITE) {
                        full_move[0] = move_coordinates.first - 2;
                        full_move[1] = move_coordinates.second;
                    }
                }
                if (!if_white) {
                    Position* pos = new_game.return_position();
                    if (move_coordinates.second + 1 >= 0 && pos->board_[move_coordinates.first + 1][move_coordinates.second]->get_piece_name() == PAWN && pos->board_[move_coordinates.first + 1][move_coordinates.second]->get_color() == BLACK) {
                        full_move[0] = move_coordinates.first + 1;
                        full_move[1] = move_coordinates.second;
                    }
                    if (move_coordinates.second + 2 >= 0 && pos->board_[move_coordinates.first + 2][move_coordinates.second]->get_piece_name() == PAWN && pos->board_[move_coordinates.first + 2][move_coordinates.second]->get_color() == BLACK) {
                        full_move[0] = move_coordinates.first + 2;
                        full_move[1] = move_coordinates.second;
                    }
                }
            }
            if (if_attack) {
                if (if_white) {
                    Position* pos = new_game.return_position();
                    if (move_coordinates.second - 1 >= 0 && move_coordinates.first - 1 >= 0 && pos->board_[move_coordinates.first - 1][move_coordinates.second - 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first - 1][move_coordinates.second - 1]->get_color() == WHITE) {
                        full_move[0] = move_coordinates.first - 1;
                        full_move[1] = move_coordinates.second - 1;
                    }
                    if (move_coordinates.second + 1 <= 7 && move_coordinates.first + 1 <= 7 && pos->board_[move_coordinates.first + 1][move_coordinates.second + 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first + 1][move_coordinates.second + 1]->get_color() == WHITE) {
                        full_move[0] = move_coordinates.first + 1;
                        full_move[1] = move_coordinates.second + 1;
                    }
                    if (move_coordinates.second + 1 <= 7 && move_coordinates.first - 1 >= 0 && pos->board_[move_coordinates.first - 1][move_coordinates.second + 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first - 1][move_coordinates.second + 1]->get_color() == WHITE) {
                        full_move[0] = move_coordinates.first + 1;
                        full_move[1] = move_coordinates.second + 1;
                    }
                    if (move_coordinates.second - 1 >= 0 && move_coordinates.first + 1 <= 7 && pos->board_[move_coordinates.first + 1][move_coordinates.second - 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first + 1][move_coordinates.second - 1]->get_color() == WHITE) {
                        full_move[0] = move_coordinates.first + 1;
                        full_move[1] = move_coordinates.second + 1;
                    }
                }
                if (!if_white) {
                    Position* pos = new_game.return_position();
                    if (move_coordinates.second - 1 >= 0 && move_coordinates.first - 1 >= 0 && pos->board_[move_coordinates.first - 1][move_coordinates.second - 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first - 1][move_coordinates.second - 1]->get_color() == BLACK) {
                        full_move[0] = move_coordinates.first - 1;
                        full_move[1] = move_coordinates.second - 1;
                    }
                    if (move_coordinates.second + 1 <= 7 && move_coordinates.first + 1 <= 7 && pos->board_[move_coordinates.first + 1][move_coordinates.second + 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first + 1][move_coordinates.second + 1]->get_color() == BLACK) {
                        full_move[0] = move_coordinates.first + 1;
                        full_move[1] = move_coordinates.second + 1;
                    }
                    if (move_coordinates.second + 1 <= 7 && move_coordinates.first - 1 >= 0 && pos->board_[move_coordinates.first - 1][move_coordinates.second + 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first - 1][move_coordinates.second + 1]->get_color() == BLACK) {
                        full_move[0] = move_coordinates.first + 1;
                        full_move[1] = move_coordinates.second + 1;
                    }
                    if (move_coordinates.second - 1 >= 0 && move_coordinates.first + 1 <= 7 && pos->board_[move_coordinates.first + 1][move_coordinates.second - 1]->get_piece_name() == PAWN && pos->board_[move_coordinates.first + 1][move_coordinates.second - 1]->get_color() == BLACK) {
                        full_move[0] = move_coordinates.first + 1;
                        full_move[1] = move_coordinates.second + 1;
                    }
                }
            }
    }
    out << full_move[0] + 'a' << full_move[1] << ' ' << full_move[2] + 'a' << full_move[3];
}

int main() {

}