#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> intArray;

//list of functions
void orderMoT(int &begin, int &mid, int &end);
void swap(int& a, int &b);
void swap(vector<int> &intArray, int &a, int &b);
void quickSort(vector<int>& intArray, int low, int high);
void insertionSort(vector<int>& sublist);
void print(vector<int>& intArray);

//orderMedianOfThree
void orderMoT(int &begin, int &mid, int &end)
{
	//if our beginning is greater than our end
	if (begin > end)
	{
		swap(begin, end);
		orderMoT(begin, mid, end);
	}

	//if our beginning is greater than our mid
	if (begin > mid)
	{
		swap(begin, mid);
		orderMoT(begin, mid, end);
	}

	// if our mid is greater than our end
	if (mid > end)
	{
		swap(mid, end);
		orderMoT(begin, mid, end);
	}
}

void swap(int& a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Swapper
void swap(vector<int> &intArray, int &a, int &b)
{
	int temp = intArray[a];
	intArray[a] = intArray[b];
	intArray[b] = temp;
}


//QuickSort
void quickSort(vector<int>& intArray, int low, int high)
{	
	int begin = intArray[low];
	int end = intArray[high];

	cout << "This is the begin value: " << begin << endl;
	cout << "This is the end value: " << end << endl;

	int mid = intArray[(0 + intArray.size()) / 2];

	cout << "This is the mid value: " << mid << endl;
	//If we partition our array to have the size as the cutoff value, use insertion sort.
	int cutoff = (intArray.size()+1) / 4;

	cout << "This is the cutoff: " << cutoff << endl;
	//find our median of three and return that value as our pivot.

	cout << "Our beginning value: " << begin << " Our last value: " << end << " Our current mid: " << mid << endl;

	orderMoT(begin, mid, end);

	cout << "This is now our first element: " << begin << " This is now our middle element: " << mid << " This is now our last element: " << end << endl;

	intArray[0] = begin;
	intArray[(low + high) / 2] = mid;
	intArray[intArray.size() - 1] = end;

	cout << "Between our high value and low value, our low value is: " << intArray[low] << " And our highest value is: " << intArray[high] << endl;

	//switch the pivot and the j, so that pivot is at the end of the array
	swap(intArray, (intArray.size() - 1), (intArray.size() / 2));

	cout << "After swapping the end value and mid, mid value is now: " << mid << " And the end value is: " << end << endl;

	//set a variable as the first element
	int isLow = intArray[0];

	cout << "This is pointing at the first element: " << isLow << endl;
	//set a variable as the second last element (so we count before the pivot), It has to be -2, because the size is a size, but the last element is actually size -1
	//therefore we want to look at the second last element, at position size - 2.
	int isHigh = intArray[intArray.size() - 2];

	cout << "This is pointing at the second last element: " << isHigh << endl;

	int i = 0, j = intArray.size()-2;

	//I ran into problems here, where the swap had issues with changing the array,
	//while we are still going through the array...
	while (i <= j)
	{
		//if i is less than mid, which we want true
		while (intArray[i] < mid)
			i++;
		//if j is greater than mid, which we want true
		while (intArray[j] > mid)
			j--;
		//if i is less than or equal to j within this while loop...
		if (i <= j)
		{
			//swap them so that i is less than or equal to pivot and j is greater than pivot
			swap(intArray[i], intArray[j]);
			i++;
			j--;
		}
	}

	//swap pivot with the high value so pivot is in its place
	swap(intArray, (intArray.size()-1), i);
	print(intArray);

	//this part does not work, I was working out the idea but I could not figure it out.

	vector<int> sublist;
	//recursion time! divide the list into sublists on either side of the pivot.
	if (j > low)
	{
		if (i - 0 <= cutoff)
		{
			//if the sublist size at any point is less than or equal to cutoff, call insertion sort
			copy(intArray[0], intArray[i], sublist);
			insertionSort(sublist);
		}
		else
		{
			copy(intArray[0], intArray[i], sublist);
			quickSort(sublist, 0, sublist.size() - 1);
		}
	}
	if (i < high)
	{
		if (intArray.size() - 1 <= cutoff)
		{
			//if the sublist size at any point is less than or equal to cutoff, call insertion sort
			copy(intArray[pivot + 1], intArray[intArray.size() - 1], sublist);
			insertionSort(sublist);
		}
		else
		{
			copy(intArray[pivot + 1], intArray[intArray.size() - 1], sublist);
			quickSort(sublist, 0, sublist.size() - 1);
		}
	}

}


//InsertionSort
void insertionSort(vector<int>& sublist)
{
	int j, key;
	int size = sublist.size();
	for (int i = 1; i < size; i++)
	{
		//very first element
		j = i - 1;
		//our second element
		key = sublist[i];
		
		/*move elements of sublist[0..i-1] that
		are greater than key, to one position ahead of their current position*/
		while (j >= 0 && sublist[j] > key)
		{
			sublist[j + 1] = sublist[j];
			j -= 1;
		}
		//place the key into the sublist after it's been sorted to accomodate for key
		sublist[j + 1] = key;
	}
}

//prints out the array
void print(vector<int>& intArray)
{
	int size = intArray.size();
	cout << "The final QuickSort array is: \n";
		for (int i = 0; i < size; i++)
			cout << intArray[i] << " ";
}

//Introduction and calls out the array
int main()
{
	int input = 0;
	cout << "Hello and welcome to the Integer QuickSort Program! \n"
		<< "Type out any integers to input (Enter a character when you're done inputting): \n";
	cin >> input;
	intArray.push_back(input);
	while (cin >> input)
	{
		intArray.push_back(input);
	}

	quickSort(intArray, 0, intArray.size() - 1);
	print(intArray);
	return 0;
}