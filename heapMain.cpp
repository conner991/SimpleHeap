/* -----------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     05-04-2020         1.0  Original version
----------------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>


/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main()
{

    int mean, rnHolder;
    int temp = 0;
    int RNrange = 100;
    std::vector<int> v1;
    std::vector<int>::iterator iter;


    // Random number generator
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < RNrange; i++)
    {
        rnHolder = (rand() % 500);
        v1.push_back(rnHolder);
    }

    // Open output file operator
    std::fstream outFile;
    outFile.open("heapResults.txt", std::ios::out);


    // Making a heap from the random values
    std::make_heap(v1.begin(), v1.end());

    std::cout << std::endl;
    std::cout << "\nHere is a heap of 100 random values:\n";
    outFile << "\nHere is a heap of 100 random values:\n";
    
    // Display the contents of the heap
    for (iter = v1.begin(); iter != v1.end(); iter++)
    {
        std::cout << *iter << " ";
        outFile << *iter << " ";
    }

    std::cout << std::endl;
    outFile << std::endl;

    // Adding up all the values of the heap vector
    for (int i = 0; i < v1.size(); i++)
    {
        temp += v1[i];
    }

    mean = temp / v1.size();
    
    std::cout << "\nThe mean of the heap values is: " << mean << std::endl;
    std::cout << "Inserting mean value into heap and deleting max value...\n\n";
    outFile << "\nThe mean of the heap values is: " << mean << std::endl;
    outFile << "Inserting mean value into heap and deleting max value...\n\n";

    // Add mean to vector, then remake the heap 
    v1.push_back(mean);
    push_heap(v1.begin(), v1.end());
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();

    std::cout << "Now the new heap is:\n";

    // Display new heap
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " ";
        outFile << v1[i] << " ";
    }

    // Sorting heap into ascending order
    std::cout << "\n\nHeap after sorting it into ascending order:\n";
    outFile << "\n\nHeap after sorting it into ascending order:\n";
    std::sort_heap(v1.begin(), v1. end());
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " ";
        outFile << v1[i] << " ";

    }

    std::cout << "\n\nSee heapResults.txt for output file and Short_Report.txt for the summary.\n\n";

    // Close file
    outFile.close();

    return 0;

}