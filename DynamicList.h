#pragma once
namespace AlgoGraph {

	template<class T>

	class DynamicList
	{
		private:
			struct Item {
				T		value;
				Item*	next;
				Item*	prev;
			};
			int size;
			Item* head;
			Item* tail;


		public:
		DynamicList() : head(nullptr), tail(nullptr)
		{
			size = 0;
		// start with an empty list (null head & tail)
		}
		~DynamicList()
		{
			// free all items in the list
			while (head != nullptr) {
				Item* temp = head;
				head = head->next;
				delete temp;
			}
		}
		int getSize()
		{
			return size;
		}
		DynamicList(const DynamicList& other) : DynamicList()
		{
			// copy entire contents of other list to this one
			Item* otherhead = other.head;
			while (otherhead != nullptr) {
				AddItemToTail(otherhead->value);
				otherhead = otherhead->next;
			}
		}


		void AddItemToHead(T value)
		{
			size++;
			// create new item and set as head of list
			Item* item = new Item;
			item->value = value;
			item->next = head;
			item->prev = nullptr;
			head = item;

			// handle empty list
			if (tail == nullptr)
				tail = head;
		}
		void AddItemToTail(T value)
		{


			size++;
			// create new item and set as tail of list
			Item* item = new Item;
			item->value = value;
			item->next = nullptr;
			if (head == nullptr)
			{
				head = tail = item;
				item->prev = nullptr;
			}
			else
			{
				item->prev = tail;
				tail->next = item;
				tail = item;
			}
			
		}

		T DeleteItemFromHead()
		{
			// remove head item from list
			Item* temp = head;
			head = head->next;
			head->prev = nullptr;

			// handle empty list
			if (head == temp)
				tail = nullptr;

			// return value of removed item
			T value = temp->value;
			delete temp;
			return value;
		}

		T DeleteItemFromTail()
		{
			// remove tail item from list
			Item* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;

			// handle empty list
			if (head == temp)
				head = nullptr;

			// return value of removed item
			T value = temp->value;
			delete temp;
			return value;
		}
		T GetValueOfHead() const
		{
			return head->value;
		}
		T GetValueOfTail() const
		{
			return tail->value;
		}

		T* ReturnRefrenceToItemByValue(T value)
		{
			Item* current = head;
			while(current!=nullptr)
			{
				if(current->value == value)
					return &(current->value);
				else current = current->next;
			}
			return nullptr;
		}

		void DeleteItemByValue(T value)
		{
			if(head->value == value)
			{
				DeleteItemFromHead();
				return;
			}
			if(tail->value == value)
			{
				DeleteItemFromTail();
				return;
			}
			Item* prev = head;
			Item* current = prev->next;
			while(current != nullptr)
			{
				if(current->value == value)
				{
					prev->next = current->next;
				}
				else
				{
					current = current-> next;
					prev = prev->next;
				}
			}
			delete current;
		}
		
		//Not in use for us but dont understand how it works.
		T& GetItemByIndex(int i_IndexOfItemInList)
		{
			return const_cast<T&>(getItem(i_IndexOfItemInList));
		}
		
		const T& getItem(int idx) const
		{
			// scan the list and reutrn item at index idx
			Item* temp = head;
			for (int i = 0; i < idx; ++i)
			{
				temp = temp->next;
			}
			return temp->value;
		}
	};
}