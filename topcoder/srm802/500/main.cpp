#include <string>
#include <cassert>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

class TheQuestForGold
{
private:
    struct CaveInfo
    {
        int startRow;
        int startCol;
        bool hasTreasure = false;
    };

private:
    CaveInfo loadCave(const vector<string> &cave)
    {
        CaveInfo info;
        size_t rowSize = cave.size();
        size_t colSize = cave[0].size();
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (cave[i][j] == 'S')
                {
                    info.startRow = i;
                    info.startCol = j;
                }
                else if (cave[i][j] == 'T')
                {
                    info.hasTreasure = true;
                }
            }
        }

        return info;
    }

    bool isValidPosition(int maxRow, int maxCol, int row, int col)
    {
        if (row < 0 || row >= maxRow)
        {
            return false;
        }
        if (col < 0 || col >= maxCol)
        {
            return false;
        }

        return true;
    }

    bool isSafe(const vector<string> &cave, int row, int col)
    {
        if (cave[row][col] == 'P')
        {
            return false;
        }

        return true;
    }

    bool find(vector<string> &cave, int row, int col)
    {
        int maxRow = cave.size();
        int maxCol = cave[0].size();

        cave[row][col] = '*';

        vector<int> rows = {row+1, row, row-1, row};
        vector<int> cols = {col, col+1, col, col-1};

        for (int i = 0; i < 4; i++)
        {
            int nextRow = rows[i];
            int nextCol = cols[i];

            if (!isValidPosition(maxRow, maxCol, nextRow, nextCol))
            {
                continue;
            }

            if (!isSafe(cave, nextRow, nextCol))
            {
                return false;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nextRow = rows[i];
            int nextCol = cols[i];

            if (!isValidPosition(maxRow, maxCol, nextRow, nextCol))
            {
                continue;
            }

            char c = cave[nextRow][nextCol];
            if (c == 'T')
            {
                return true;
            }
            else if (c == '*')
            {
                continue;
            }
            else if (find(cave, nextRow, nextCol))
            {
                return true;
            }
        }

        return false;
    }

public:
    string explore(vector<string> cave)
    {
        CaveInfo info = loadCave(cave);

        if (!info.hasTreasure)
        {
            return "no gold";
        }

        bool found = find(cave, info.startRow, info.startCol);
        if (found)
        {
            return "gold";
        }

        return "no gold";
    }
};

void testExample()
{
    TheQuestForGold quest;
    vector<string> cave = {
        "S....",
        ".....",
        "...T.",
        "....."
    };
    assert(quest.explore(cave) == "gold");

    cave = vector<string>({
        "S....",
        "...P.",
        "..PTP",
        "...P."
    });

    assert(quest.explore(cave) == "no gold");

    cave = vector<string>({
        "S....",
        "..P.P",
        ".P.T.",
        "....."
    });

    assert(quest.explore(cave) == "no gold");

    cave = vector<string>({
        "S....",
        "P....",
        "...T.",
        "....."
    });

    assert(quest.explore(cave) == "no gold");

    cave = vector<string>({
        "S....",
        ".....",
        "PPP..",
        ".....",
        ".....",
        ".....",
        "..PPP",
        "..T.."
    });

    assert(quest.explore(cave) == "gold");

    cave = vector<string>({
        ".......",
        ".......",
        "..P.P..",
        "..PPP..",
        "..P.P..",
        ".......",
        ".......",
        "..S...."
    });

    assert(quest.explore(cave) == "no gold");

    cave = vector<string>({
        ".......",
        ".......",
        "..P.P..",
        "..PTP..",
        "..P.P..",
        ".......",
        ".......",
        "..S...."
    });

    assert(quest.explore(cave) == "no gold");
}

int main()
{
    testExample();

    cout << "SUCCESS" << endl;

    return 0;
}
