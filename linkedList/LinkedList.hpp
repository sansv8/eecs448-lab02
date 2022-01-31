/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	//Return m_size
	return m_size;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	
	//First, let create an integer that will chech the index of the current node
	int index = 0;

	//First, we loop until isFound is true or 
	//we reach the end of the LinkedList
	//which means that index must be greater than m_size
	while(isFound == false && index < m_size)
	{
		//Next, get the entry of temp
		T entry = temp->getValue();

		//Next, check if the entry equals to the value
		//If entry equals to the value
		if(entry == value)
		{
			//Set isFound to be true and end the loop
			isFound = true;
		}
		//Otherwise, if temp does not equal to value
		else
		{
			//Set temp to be the next node in the list
			temp = temp->getNext();

			//Increase index by 1
			index++;
		}
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	//Firstly, check the size of the list
	//If the size of the list is 0, 
	//then no node can be removed by the list
	if(m_size == 0)
	{
		//Set isRemoved to be false
		isRemoved = false;
	}
	//Otherwise, if the list is not empty
	else
	{
		//Set isRemoved to be true
		isRemoved = true;

		//Next, set secondintoLast to be m_front
		secondintoLast = m_front;

		//Next, go through each node of the LinkedList
		//until the program reaches the 2nd to last node
		//starting from 1 and going to m_size-1
		for(int i = 1; i < m_size-1; i++)
		{
			//Set secondintoLast to be the next node of the list
			secondintoLast = secondintoLast->getNext();
		}

		//Next, set lastNode to be secnondintoLast's next node
		lastNode = secondintoLast->getNext();

		//Next, set secondintoLast's next node to be nullptr
		secondintoLast->setNext(nullptr);

		//Next, delete lastnode
		delete lastNode;

		//Finally, decrease m_size by 1
		m_size--;
	}

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
