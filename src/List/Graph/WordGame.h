//
// Created by bt024194 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_BERKETUNCEROZU_WORDGAME_H
#define GRAPH_PUZZLE_GAME_BERKETUNCEROZU_WORDGAME_H

#include <string>
#include <vector>
#include "Graph.h"


class WordGame {
private:
    static buildWordGraph(const std::string &location);

    static void addWordsToGraph(list::Graph *wordGraph, const std::vector <std::string> &words);

    static bool areWordsOneCharApart(const std::string &word1, const std::string &word2);
};


#endif //GRAPH_PUZZLE_GAME_BERKETUNCEROZU_WORDGAME_H
