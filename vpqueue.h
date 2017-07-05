#include<vector>

using namespace std;

template<typename T>
class vpriority_queue
{
public: 
	
	
	vpriority_queue();
	int maxIndex;
	bool recomputeMaxIndex;

	bool empty() { return (pqVector.size() == 0); };
	int size() { return pqVector.size(); };
	
	void push(const T& item)
	{
		pqVector.push_back(item);
		recomputeMaxIndex = true;
		
	};
	
	void pop() 
	{
		if (pqVector.size() > 0)
		{
			if (recomputeMaxIndex == true)
				maxIndex = findMaxIndex();

			pqVector[maxIndex] = pqVector.back();
			pqVector.pop_back();
			
			recomputeMaxIndex = true;
		}
	else
		try
	{

		throw underflow_error("The Queue is empty");
			
	}
	catch (underflow_error e)
	{
		cout << e.what() << endl;
	}
	};

	T& top()
	{
		if (pqVector.size() > 0)
		{
			if (recomputeMaxIndex == true)
			{
				maxIndex = findMaxIndex();
				recomputeMaxIndex = false;
			}
			return pqVector[maxIndex];
		}
		else 
			try
		{
			throw underflow_error("The Queue is empty");
		}
		catch (underflow_error e)
		{
			cout << e.what() << endl;
			
		}
		
	};

	const T& top() const
	{
		if (pqVector.size() > 0)
		{
			if (recomputeMaxIndex == true)
			{
				maxIndex = findMaxIndex();
				recomputeMaxIndex = false;
			}
			return pqVector[maxIndex];
		}
		else
			try
		{
			throw underflow_error("The Queue is empty");
		}
		catch (underflow_error e)
		{
			cout << e.what() << endl;
		}
		
	};
	int findMaxIndex() const
	{
	int mi=0;
	for (int i = 0; i < pqVector.size(); i++)
	if (pqVector[i] > pqVector[mi])
		mi = i;
	
	return mi;
	};
	
	
private:
	std::vector<T> pqVector;
};

 

template<typename T>
vpriority_queue<T>::vpriority_queue()
{
	vector<vpriority_queue> newV;
}