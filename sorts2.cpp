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

//------------------------------------------------------
//Insertion Sort
//------------------------------------------------------

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

//------------------------------------------------------
//MergeSort
//------------------------------------------------------
// merges two subarrays of array[].
void merge(std::vector<int> &arr, int start, int middle, int end) {

    std::vector<int> leftArray(middle - start + 1);
    std::vector<int> rightArray(end - middle);

    // fill in left array
    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

    // fill in right array
    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

    /* Merge the temp arrays */

    // initial indexes of first and second subarrays
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subarrays back into the main array
    int currentIndex = start;

    // compare each index of the subarrays adding the lowest value to the currentIndex
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    // copy remaining elements of leftArray[] if any
    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    // copy remaining elements of rightArray[] if any
    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

// main function that sorts array[start..end] using merge()
void mergeSort(std::vector<int> &arr, int start, int end) {
    // base case
    if (start < end) {
        // find the middle point
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle); // sort first half
        mergeSort(arr, middle + 1, end);  // sort second half

        // merge the sorted halves
        merge(arr, start, middle, end);
    }
}

//-------------------------------------------------------------
//Quick Sort
//-------------------------------------------------------------

// last element is taken as pivot
int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<int> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}

void PrintVector(vector<int> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
	cout<<"\n\n";
}

int main() {
	
	vector<int> v = { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19 };
	
	cout<<"Vector Before Sorting: "<<endl;
	PrintVector(v);
	
	Quicksort(v,0,v.size()-1);
	
	cout<<"Vector After Sorting: "<<endl;
	PrintVector(v);
		
}

//Main Driver for MergeSort
// int main() {
//     std::vector<int> arr = {12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8};
//     mergeSort(arr, 0, static_cast<int>(arr.size() - 1));
//     for (int i; i < arr.size(); i++) {
//         std::cout << arr[i];
//         if (i < arr.size() - 1) std::cout << ", ";
//     }
//     cout<<endl;
// }

//Main Driver for Insertion Sort
// int main()
// {
//     std::vector<int> arr = {5, 2, 4, 6, 1, 3};
//     insertion_sort(arr);
//     print(arr);
// }

// int main(){
//     cout<<"Hello, World!"<<endl;

//     return 0;
// }