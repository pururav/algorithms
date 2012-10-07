// Sort.h
#ifndef SORT_H	
#define SORT_H
#include <vector>
#include <string>

template<class T>
class BaseSort
{
public:
	BaseSort(const std::vector<T>& elements)
		:elements_(elements)
	{};
	virtual ~BaseSort()
	{
		elements_.clear();
	}
	virtual void sort(int begin, int end)=0;
protected:
	std::vector<int> elements_;

};
template<class T>
class QuickSort:public BaseSort<T>
{
	// average nlogn complexity
public:
	QuickSort(const std::vector<T>& elements)
		:BaseSort<T>(elements)
	{};
	~QuickSort()
	{};
	virtual void sort(int begin, int end);
	int randomizedPartition(int begin, int end);
};
template<class T>
class BubbleSort:public BaseSort<T>
{
	// O(n) complexity
public:
	BubbleSort(const std::vector<T>& elements)
		:BaseSort<T>(elements)
	{};
	~BubbleSort()
	{};
	virtual void sort(int begin, int end);
};

template<class T>
class HeapSort:public BaseSort<T>
{
	// nlogn complexity
public:
	HeapSort(const std::vector<T>& elements)
		:BaseSort<T>(elements)
	{};
	~HeapSort()
	{};
	virtual void sort(int begin, int end);
	virtual void heapify(int c);

};
template<class T>
class InsertionSort:public BaseSort<T>
{
	// nlogn complexity
public:
	InsertionSort(const std::vector<T>& elements)
		:BaseSort<T>(elements)
	{};
	~InsertionSort()
	{};
	virtual void sort(int begin, int end);
};

class sortException
{
	std::string exceptionMsg_;
public:
	sortException(const std::string msg):exceptionMsg_(msg)
	{};
	std::string exception()
	{
		return exceptionMsg_;
	}
};

#endif // SORT_H
