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


    //RNG
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < RNrange; i++)
    {
        rnHolder = (rand() % RNrange);
        v1.push_back(rnHolder);
    }


    // Making a heap from the random values
    std::make_heap(v1.begin(), v1.end());

    std::cout << std::endl;
    std::cout << "\nHere is a heap of 100 random values:\n";
    
    // Display the contents of the heap
    for (iter = v1.begin(); iter != v1.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    // Adding up all the values of the heap vector
    for (int i = 0; i < v1.size(); i++)
    {
        temp += v1[i];
    }

    mean = temp / v1.size();
    
    std::cout << "The mean of the heap values is: " << mean << std::endl;
    std::cout << "Inserting mean value into heap and deleting max value...\n\n";

    v1.push_back(mean);

    push_heap(v1.begin(), v1.end());
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();

    std::cout << "Now the new heap is:\n";

    // Display new heap
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;

    }

    return 0;

}