#include "headers/Game.h"
#include <iostream>
#include <string>

std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
std::vector<char> figures = {'N', 'Q', 'K', 'B', 'R'};
std::ifstream inp("logic/play.txt");
std::vector<std::string> normal_moves = {};

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
    std::vector<bool> flags = {false, false};
    for (int i = 0; i < all_moves.size(); ++i) {
        int pos = 0;
        if (i == 4) {
            pos++;
            pos--;
        }
        while (pos < all_moves[i].size() - 1) {
            while (!flags[0] && !flags[1] && all_moves[i][pos] != '.') {
                ++pos;
            }
            if (all_moves[i][pos] == '.' || flags[0] || flags[1]) {
                if (!flags[0] && !flags[1]) pos += 2;
                s = "";
                while (!(flags[1] && !flags[0]) &&
                       ((!flags[0] && pos == 0) || (pos < all_moves[i].size() && all_moves[i][pos] != ' '))) {
                    s += all_moves[i][pos];
                    ++pos;
                }
                if (!(!flags[0] && flags[1])) ++pos;
                if (s != "") {
                    normal_moves.push_back(s);
                    flags[0] = false;
                } else if (!flags[1]) {
                    flags[0] = true;
                }
                s = "";
                while (((!flags[0] && flags[1]) || (!flags[0] && !flags[1])) &&
                       (pos < all_moves[i].size() && all_moves[i][pos] != ' ')) {
                    s += all_moves[i][pos];
                    ++pos;
                }
                if (s != "") {
                    normal_moves.push_back(s);
                    flags[1] = false;
                } else {
                    flags[1] = true;
                }
                ++pos;
            }
        }
    }
}

void convert_move(const Game &new_game, std::vector<int> &full_move, COLOR color, PIECE_NAME piece,
                  std::pair<int, int> move_coordinates, int from_coordinates, bool if_from_row) {
    std::shared_ptr<Position> pos = new_game.return_position();
    for (int i = 0; i < pos->board_.size(); ++i) {
        for (int j = 0; j < pos->board_.size(); ++j) {
            if (pos->board_[i][j]->GetPieceName() == piece &&
                pos->board_[i][j]->GetColor() == color) {
                if (pos->board_[i][j]->DefineMove(i, j, move_coordinates.first,
                                                  move_coordinates.second,
                                                  *pos)->IsValid()) {
                    if (from_coordinates != -1) {
                        if (if_from_row && from_coordinates == i) {
                            full_move[0] = i;
                            full_move[1] = j;
                        }
                        if (!if_from_row && from_coordinates == j) {
                            full_move[0] = i;
                            full_move[1] = j;
                        }
                    } else {
                        full_move[0] = i;
                        full_move[1] = j;
                    }
                }
            }
        }
    }
}

void return_move_positions(const Game &new_game, int t, std::string mv = "") {
    if (t == 0) prepare();
    std::ofstream out("logic/moves.txt");
    if (t == 69) {
        ++t;
        --t;
    }
    if (t >= normal_moves.size()) {
        std::cout << "We are out of turns" << std::endl;
        return;
    }
    mv = normal_moves[t];
    //define move
    char figure = 'P';
    bool if_attack = false;
    bool if_white = (t + 1) % 2;
    bool if_long_castle = (mv[0] == 'O' && mv.size() == 6);
    bool if_short_castle = (mv[0] == 'O' && mv.size() == 4);
    int from_coordinates = -1;
    bool if_from_row = true;//если две фигуры могут походить на одну клетку
    std::pair<int, int> move_coordinates = {0, 0};
    std::string tmp;
    if (mv == "O-O") {
        if_short_castle = true;
    }
    if (mv == "O-O-O") {
        if_long_castle = true;
    }
    for (char i: mv) {
        if (i - 'a' >= 0 && i - 'a' <= 8) {
            tmp += i;
        }
        if (i - '0' >= 0 && i - '0' <= 8) {
            tmp += i;
        }
    }
    if (tmp.size() == 3) {
        if (tmp[0] - 'a' >= 0 && tmp[0] - 'a' < 8) {
            if_from_row = false;
            from_coordinates = tmp[0] - 'a';
        } else {
            from_coordinates = tmp[0] - '0' - 1;
        }
        move_coordinates = {tmp[2] - '0', tmp[1] - 'a'};
    } else {
        move_coordinates = {tmp[1] - '0', tmp[0] - 'a'};
    }
    --move_coordinates.first;
    std::vector<int> full_move = {0, 0, move_coordinates.first, move_coordinates.second};
    for (auto i: figures) {
        if (mv[0] == i) {
            figure = i;
            break;
        }
    }
    if (mv[0] == 'x' || mv[1] == 'x') if_attack = true;
    //
    //figures trearment
    if (if_short_castle) {
        if (if_white) {
            std::shared_ptr<Position> pos = new_game.return_position();
            if (pos->board_[0][4]->DefineMove(0, 4, 0, 6, *pos)->IsValid()) {
                full_move[0] = 0;
                full_move[1] = 4;
                full_move[2] = 0;
                full_move[3] = 6;
            };
        }
        if (!if_white) {
            std::shared_ptr<Position> pos = new_game.return_position();
            if (pos->board_[7][4]->DefineMove(7, 4, 7, 6, *pos)->IsValid()) {
                full_move[0] = 7;
                full_move[1] = 4;
                full_move[2] = 7;
                full_move[3] = 6;
            };
        }
    } else if (if_long_castle) {
        if (if_white) {
            std::shared_ptr<Position> pos = new_game.return_position();
            if (pos->board_[0][4]->DefineMove(0, 4, 0, 2, *pos)->IsValid()) {
                full_move[0] = 0;
                full_move[1] = 4;
                full_move[2] = 0;
                full_move[3] = 2;
            };
        }
        if (!if_white) {
            std::shared_ptr<Position> pos = new_game.return_position();
            if (pos->board_[7][4]->DefineMove(7, 4, 7, 2, *pos)->IsValid()) {
                full_move[0] = 7;
                full_move[1] = 4;
                full_move[2] = 7;
                full_move[3] = 2;
            };
        }
    } else {
        switch (figure) {
            case 'P':
                if (!if_attack) {
                    if (if_white) {
                        std::shared_ptr<Position> pos = new_game.return_position();
                        if (move_coordinates.first - 1 >= 0 &&
                            pos->board_[move_coordinates.first - 1][move_coordinates.second]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first - 1][move_coordinates.second]->GetColor() ==
                            COLOR::WHITE) {
                            if (pos->board_[move_coordinates.first - 1][move_coordinates.second]->DefineMove(
                                    move_coordinates.first - 1, move_coordinates.second, move_coordinates.first,
                                    move_coordinates.second,
                                    *pos)->IsValid()) {
                                full_move[0] = move_coordinates.first - 1;
                                full_move[1] = move_coordinates.second;
                            }
                        }
                        if (move_coordinates.first - 2 >= 0 &&
                            pos->board_[move_coordinates.first - 2][move_coordinates.second]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first - 2][move_coordinates.second]->GetColor() ==
                            COLOR::WHITE) {
                            if (pos->board_[move_coordinates.first - 2][move_coordinates.second]->DefineMove(
                                    move_coordinates.first - 2, move_coordinates.second, move_coordinates.first,
                                    move_coordinates.second,
                                    *pos)->IsValid()) {
                                full_move[0] = move_coordinates.first - 2;
                                full_move[1] = move_coordinates.second;
                            }
                        }
                    }
                    if (!if_white) {
                        std::shared_ptr<Position> pos = new_game.return_position();
                        if (move_coordinates.first + 1 >= 0 &&
                            pos->board_[move_coordinates.first + 1][move_coordinates.second]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first + 1][move_coordinates.second]->GetColor() ==
                            COLOR::BLACK) {
                            if (pos->board_[move_coordinates.first + 1][move_coordinates.second]->DefineMove(
                                    move_coordinates.first + 1, move_coordinates.second, move_coordinates.first,
                                    move_coordinates.second,
                                    *pos)->IsValid()) {
                                full_move[0] = move_coordinates.first + 1;
                                full_move[1] = move_coordinates.second;
                            }
                        }
                        if (move_coordinates.first + 2 >= 0 &&
                            pos->board_[move_coordinates.first + 2][move_coordinates.second]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first + 2][move_coordinates.second]->GetColor() ==
                            COLOR::BLACK) {
                            if (pos->board_[move_coordinates.first + 2][move_coordinates.second]->DefineMove(
                                    move_coordinates.first + 2, move_coordinates.second, move_coordinates.first,
                                    move_coordinates.second,
                                    *pos)->IsValid()) {
                                full_move[0] = move_coordinates.first + 2;
                                full_move[1] = move_coordinates.second;
                            }
                        }
                    }
                }
                if (if_attack) {
                    if (if_white) {
                        std::shared_ptr<Position> pos = new_game.return_position();
                        if (move_coordinates.second - 1 >= 0 && move_coordinates.first - 1 >= 0 &&
                            pos->board_[move_coordinates.first - 1][move_coordinates.second - 1]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first - 1][move_coordinates.second - 1]->GetColor() ==
                            COLOR::WHITE) {
                            if (if_from_row && move_coordinates.first - 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first - 1;
                                full_move[1] = move_coordinates.second - 1;
                            }
                            if (!if_from_row && move_coordinates.second - 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first - 1;
                                full_move[1] = move_coordinates.second - 1;
                            }
                        }
                        if (move_coordinates.second + 1 <= 7 && move_coordinates.first - 1 >= 0 &&
                            pos->board_[move_coordinates.first - 1][move_coordinates.second + 1]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first - 1][move_coordinates.second + 1]->GetColor() ==
                            COLOR::WHITE) {
                            if (if_from_row && move_coordinates.first - 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first - 1;
                                full_move[1] = move_coordinates.second + 1;
                            }
                            if (!if_from_row && move_coordinates.second + 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first - 1;
                                full_move[1] = move_coordinates.second + 1;
                            }
                        }
                    }
                    if (!if_white) {
                        std::shared_ptr<Position> pos = new_game.return_position();
                        if (move_coordinates.second + 1 <= 7 && move_coordinates.first + 1 <= 7 &&
                            pos->board_[move_coordinates.first + 1][move_coordinates.second + 1]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first + 1][move_coordinates.second + 1]->GetColor() ==
                            COLOR::BLACK) {
                            if (if_from_row && move_coordinates.first + 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first + 1;
                                full_move[1] = move_coordinates.second + 1;
                            }
                            if (!if_from_row && move_coordinates.second + 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first + 1;
                                full_move[1] = move_coordinates.second + 1;
                            }
                        }
                        if (move_coordinates.second - 1 >= 0 && move_coordinates.first + 1 <= 7 &&
                            pos->board_[move_coordinates.first + 1][move_coordinates.second - 1]->GetPieceName() ==
                            PIECE_NAME::PAWN &&
                            pos->board_[move_coordinates.first + 1][move_coordinates.second - 1]->GetColor() ==
                            COLOR::BLACK) {
                            if (if_from_row && move_coordinates.first + 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first + 1;
                                full_move[1] = move_coordinates.second - 1;
                            }
                            if (!if_from_row && move_coordinates.second - 1 == from_coordinates) {
                                full_move[0] = move_coordinates.first + 1;
                                full_move[1] = move_coordinates.second - 1;
                            }
                        }
                    }
                }
                break;
            case 'Q':
                if (if_white) convert_move(new_game, full_move, COLOR::WHITE, PIECE_NAME::QUEEN, move_coordinates, from_coordinates
                , if_from_row);
                else convert_move(new_game, full_move, COLOR::BLACK, PIECE_NAME::QUEEN, move_coordinates, from_coordinates, if_from_row);
                break;
            case 'K':
                if (if_white) convert_move(new_game, full_move, COLOR::WHITE, PIECE_NAME::KING, move_coordinates, from_coordinates
                            , if_from_row);
                else convert_move(new_game, full_move, COLOR::BLACK, PIECE_NAME::KING, move_coordinates, from_coordinates, if_from_row);
                break;
            case 'N':
                if (if_white) convert_move(new_game, full_move, COLOR::WHITE, PIECE_NAME::KNIGHT, move_coordinates, from_coordinates
                            , if_from_row);
                else convert_move(new_game, full_move, COLOR::BLACK, PIECE_NAME::KNIGHT, move_coordinates, from_coordinates, if_from_row);
                break;
            case 'R':
                if (if_white) convert_move(new_game, full_move, COLOR::WHITE, PIECE_NAME::ROOK, move_coordinates, from_coordinates
                            , if_from_row);
                else convert_move(new_game, full_move, COLOR::BLACK, PIECE_NAME::ROOK, move_coordinates, from_coordinates, if_from_row);
                break;
            case 'B':
                if (if_white) convert_move(new_game, full_move, COLOR::WHITE, PIECE_NAME::BISHOP, move_coordinates, from_coordinates
                            , if_from_row);
                else convert_move(new_game, full_move, COLOR::BLACK, PIECE_NAME::BISHOP, move_coordinates, from_coordinates, if_from_row);
                break;
        }
    }
    out << letters[full_move[1]] << full_move[0] + 1 << ' ' << letters[full_move[3]] << full_move[2] + 1;
}

int main() {

}