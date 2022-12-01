#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Part 1: Find the Maximum number of calories held by an elf.
int maxElfCalories()
{
    std::fstream puzzleInput;
    std::string filename = "../source/puzzleinput.txt";
    puzzleInput.open(filename, std::ios::in);

    int maxCalories{0};

    if(puzzleInput.is_open())
    {
        std::string line;
        int elfCalories{0};

        while(puzzleInput)
        {
            getline(puzzleInput, line, '\n');

            if(line == "")
            {
                elfCalories = 0;
            }

            else
            {
                elfCalories += std::stoi(line);

                if(elfCalories > maxCalories)
                    maxCalories = elfCalories;
            }

            if(!puzzleInput)
                break;            
        }
    }

    else std::cout << "Could not open puzzleinput.txt!\n";

    puzzleInput.close();

    return maxCalories;
}

// Find the top 3 elves with the most calories, and return the total amount of calories they hold
// Very quick and dirty, there is definitely a better way to do this.
int topThreeElfCalories()
{
    std::fstream puzzleInput;
    std::string filename = "../source/puzzleinput.txt";
    puzzleInput.open(filename, std::ios::in);

    std::vector<int> maxCalories{0, 0, 0};

    if(puzzleInput.is_open())
    {
        std::string line;
        int elfCalories{0};

        while(puzzleInput)
        {
            getline(puzzleInput, line, '\n');

            if(line == "")
            {
                elfCalories = 0;
            }

            else
            {
                elfCalories += std::stoi(line);

                if(elfCalories > maxCalories[2])
                {
                    maxCalories.pop_back();

                    if(elfCalories > maxCalories[1])
                    {
                        maxCalories.push_back(maxCalories[1]);

                        if(elfCalories > maxCalories[0])
                        {
                            maxCalories[1] = maxCalories[0];
                            maxCalories[0] = elfCalories;
                        }

                        else maxCalories[1] = elfCalories;
                    }
                    else maxCalories.push_back(elfCalories);
                }
            }

            if(!puzzleInput)
                break;            
        }
    }

    else std::cout << "Could not open puzzleinput.txt!\n";

    puzzleInput.close();

    return (maxCalories[0] + maxCalories[1] + maxCalories[2]);
}

int main()
{
    std::cout << "Maximum calories held by a single elf: " << maxElfCalories() << '\n';

    std::cout << "Calories held by top 3 elves: " << topThreeElfCalories() << std::endl;
}
