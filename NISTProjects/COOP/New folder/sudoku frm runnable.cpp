#include <iostream>
#include <array>
#include <string>
//This is a program to solve sudoku game.
//Input must be a string less than 81 character.
//Input sudoku puzzle without space or enter.
//Iuput 0 for empty.
//When the input string less than 81, it will fill 0 after the end of input.

std::pair<bool, std::array<int, 81>> solve(const char* input)
{
    std::array<int, 81> ans;
    int* map = ans.data(); // The map of numbers with 0 for empty
    int empty[81]; // The index of each empty gird
    int c = 0;  // The current index we accessed
    int i, j, k; // The current row, column, region index we accessed
    int b; // The temporary bit set
    int empty_count = 0; // The count of empty gird
    int filled = 0; // The count of filled empty gird
    int col[9], row[9], region[9]; //Bit set of each column, row and region
    for (i = 0; i < 9; i++)
    {
        col[i] = row[i] = region[i] = 01776; // Binary number 1111111110
    }
    while (*input)
    {
        if (*input == '0') // Empty gird
        {
            empty[empty_count++] = c;
            map[c] = 0;

        }
         else if ((*input) <= '9' && (*input) >= '1') // Non empty gird
        {
            i = c / 9;
            j = c % 9;
            k = (c / 27) * 3 + ((c % 9) / 3);
            map[c] = (*input) - '0';
            b = (1 << map[c]); // Check if the gird is wrong
            if ((b & row[i] & col[j] & region[k]) == 0) {
                return std::pair<bool, std::array<int, 81>>(false, ans);
            }
            // Fill the bit to 0 for the row, column and region
            row[i] ^= b;
            col[j] ^= b;
            region[k] ^= b;
        }
        else
        {
            break;
        }
        input++;
        c++;
    }
    for (; c < 81; c++) //Fill empty for left girds
    {
        empty[empty_count++] = c;
        map[c] = 0;
    }
    while (filled < empty_count) //Fill numbers until all number has been filled
    {
        c = empty[filled];
        i = c / 9;
        j = c % 9;
        k = (c / 27) * 3 + ((c % 9) / 3);
         if (map[c] > 0)  //If this gird has been filled before, then reset it
        {
            b = (1 << map[c]); //Reset the bit to 1
            row[i] |= b;
            col[j] |= b;
            region[k] |= b;
        }
        while (map[c] <= 9) //Fill current gird if the number was not appeared in current row, col or region
        {
            map[c] ++;
            b = (1 << map[c]); //Get the bit of the number and check if it has alerdy existed.
            if (row[i] & col[j] & region[k] & b)
            {
                break;
            }
        }
        if (map[c] > 9) // If there is no number to fill, back to the gird we filled before
        {
            map[c] = 0;
            filled--;
            if (filled < 0) // If current is the first gird, then there is no answer for the puzzle
            {
                return std::pair<bool, std::array<int, 81>>(false, ans);
            }
        }
        else
        {
            //After we filled this gird, set the bit to 0
            row[i] ^= b;
            col[j] ^= b;
            region[k] ^= b;
            filled++;
        }
    }
    return std::pair<bool, std::array<int, 81>>(true, ans);
}

int main()
{
    std::string input;
    std::cin >> input;
    std::pair<bool, std::array<int, 81>> pair = solve(input.c_str());
    if (pair.first)
    {
        std::array<int, 81> ans = pair.second;
        for (int i = 0; i < 81; i++)
        {
            std::cout << ans[i];
            if (i % 9 == 8)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << " ";
            }
        }
    }
    else
    {
        std::cout << "No answer" << std::endl;
    }
}
