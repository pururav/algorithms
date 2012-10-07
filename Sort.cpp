#include "Sort.h"
#include <time.h>
#include <iostream>

using namespace std;

template<class T>
void QuickSort<T>::sort(int begin, int end)
{
	if(begin < end)
	{
		int pivot = randomizedPartition(begin,end);
		sort(begin,pivot-1);
		sort(pivot+1,end);
	}
}

template<class T>
int QuickSort<T>::randomizedPartition(int begin, int end)
{
	// randomization to avoid worst case performance of n^2
  //	static int coount = 0;
	std::srand(time(NULL));
	int randp= begin + rand()%(end- begin+1);
	T tmp = this->elements_[end];
	this->elements_[end] = this->elements_[randp];
	this->elements_[randp] = tmp;
	int i = begin -1;
	double x = this->elements_[end];
	for(int j = begin; j < end; j++)
	{
		if(this->elements_[j] <= x)
		{
			i++;
			tmp = this->elements_[i];
			this->elements_[i] = this->elements_[j];
			this->elements_[j] = tmp;
		}
	}
	i++;
	tmp = this->elements_[end];
	this->elements_[end] = this->elements_[i];
	this->elements_[i] = tmp;
	return i;
}
template<class T>
void BubbleSort<T>::sort(int begin, int end)
{
	if(begin > end)
		throw sortException(std::string(" wrong indices begin > end "));
	if(begin < end)
	{
		for(int i=begin;i<=end;i++)
		{
			for(int j=begin;j<i;j++)
			{
				if(this->elements_[i] < this->elements_[j])
				{
					T temp=this->elements_[i]; //swap 
					this->elements_[i]=this->elements_[j];
					this->elements_[j]=temp;
				}
			}

		}
	}
}
template<class T>
void HeapSort<T>::sort(int begin, int end)
{
	if(begin > end)
		throw sortException(std::string(" wrong indices begin > end "));
	if(begin < end)
	{
		for ( int i = end ; i > 0 ; i-- )
		{
			T ivalue = this->elements_[i] ;
			this->elements_[i] = this->elements_[0] ;
			this->elements_[0]=ivalue;
			heapify(i);
		}
	}
}
template<class T>
void HeapSort<T>::heapify(int c)
{
	for ( int i = 1 ; i < c ; i++ )
	{
		T val = this->elements_[i] ;
		int s = i ;
		int f = ( s - 1 ) / 2 ;
		while ( s > 0 && this->elements_[f] < val )
		{
			this->elements_[s] = this->elements_[f] ;
			s = f ;
			f = ( s - 1 ) / 2 ;
		}
		this->elements_[s] = val ;
	}
}
template<class T>
void InsertionSort<T>::sort(int begin, int end)
{
	if(begin > end)
		throw sortException(std::string(" wrong indices begin > end "));
	if(begin < end)
	{
		int i;
		T key;
		for(int j=1;j<=end;j++)
		{
			key=this->elements_[j];
			i=j-1;
			while(i>=0 && this->elements_[i]>key)
			{
				this->elements_[i+1]=this->elements_[i];
				i--;
			 }
			 this->elements_[i+1]=key;
		  }
	}
}

int main()
{
	const int n = 10; // number of elements in tha array to be sorted
	std::vector<int> elements;
	for(int i=0; i < n; i++)
	{
		elements.push_back(n - i);
	}		
	std::vector<BaseSort<int>*> sortingMethods;
	// QuickSort
	QuickSort<int> qs(elements);
	sortingMethods.push_back( &qs );
	// BubbleSort
	BubbleSort<int> bs(elements);
	sortingMethods.push_back( &bs );
	//Heapsort
	HeapSort<int> hs(elements);
	sortingMethods.push_back( &hs );
	//InsertionSort
	InsertionSort<int> is(elements);
	sortingMethods.push_back( &is );
	for(std::vector<BaseSort<int>*>::iterator it=sortingMethods.begin(); it != sortingMethods.end(); it++)
	{
		try
		{
			(*it)->sort(0,n-1);
		}
		catch(sortException& e)
		{
			cout << e.exception() <<endl;
		}
	}
	return 0;
}
