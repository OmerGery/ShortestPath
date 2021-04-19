#include "Tav.h"
#include "hufNode.h"

namespace huf
{
	class minHeap
	{
		private:
			hufNode** heapArray;
			int maxSize;
			int heapSize;
			int allocated;


		public:
			minHeap(int capacity);
			minHeap(hufNode* tav[], int size);
			~minHeap();
			static int Left(int node);
			static int Right(int left);
			static int Parent(int node);
			void FixHeap(int node);
			hufNode* Min();
			hufNode* DeleteMin();
			void Insert(hufNode* item);
			bool isEmpty();
			void make_empty();

	};
}
