#pragma once

bool CanMove(vector<int> Visited, int x, int y, int BoardSize);

bool KnightSubtour(vector<int>& Visited, int x, int y, int BoardSize);

vector<vector<int>> KnightTour(int BoardSize, int startx, int starty);

vector<vector<int>> KnightTour_Iterative(int BoardSize, int startx, int starty);

bool CanMove2(vector<int>& Board, int x, int y, int BoardSize);

int GetDegree(vector<int> Board, int x, int y, int BoardSize);

bool HaveNextMove(vector<int>& Board, int & x, int & y, int BoardSize);

vector<vector<int>> KnightTour_Heuristic(int BoardSize, int startx, int starty);
