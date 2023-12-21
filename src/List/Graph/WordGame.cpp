#include "WordGame.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Edge.h"
#include "EdgeList.h"



static list::Graph *buildWordGraph(const std::string &location) {
    list::Graph *wordGraph = new list::Graph(30);

    std::ifstream file("turkish-dictionary.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << "turkish-dictionary.txt" << std::endl;
        return nullptr;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> words = split(line, ' ');
        addWordsToGraph(wordGraph, words);
    }

    file.close();
    return wordGraph;
}

static bool areWordsOneCharApart(const std::string &word1,const std::string &word2) {
    int differences = 0;
    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[i]) {
            differences++;
        }
        if (differences > 1) {
            return false;
        }
    }
    return differences == 1;
}

static void addWordsToGraph(list::Graph *wordGraph, const std::vector<std::string> &words) {
    for (int i = 0; i < words.size(); i++) {
        std::string currentWord = words[i];
        wordGraph->addEdge(currentWord, currentWord);


    for (int j = i + 1; j < words.size(); j++) {
        std::string nextWord = words[j];
        if (areWordsOneCharApart(currentWord, nextWord)) {
            wordGraph->addEdge(currentWord, nextWord);
            wordGraph->addEdge(nextWord, currentWord);
        }
    }}
}