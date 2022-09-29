#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


/* 5.1
@ Function that accepts an integer N, the size of the input, and returns a vector of size N.
@ Where each element is a random integer uniformly drawn from the range 1 to 1000000.
*/

vector<int>InputGenerator(int N){

    //vector to be returned
    vector<int> GeneratedElements;

    for(int i = 1;i<=N;i++){
        int RandomNumber = 1 + (rand() % 1000);
        GeneratedElements.push_back(RandomNumber);
    }

    return GeneratedElements;

}

void insertion_sort(std::vector<int>& vec)
{
    for(std::size_t j = 1; j < vec.size(); j++)
    {
      int key = vec[j];
      int i = j-1;

      while(i >= 0 && vec[i] > key)
      {
         vec[i+1] = vec[i];
         i--;
      }
      vec[i+1] = key;
    }
}

void print(std::vector<int>& vec) 
{
    for(unsigned i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}


int main()
{
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    insertion_sort(arr);
    print(arr);
}

// int main(){
//     cout<<"Hello, World!"<<endl;

//     return 0;
// }