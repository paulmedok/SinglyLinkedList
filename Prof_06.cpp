// Prof_06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"

using namespace std;

bool Desc(int maPrev, int maCur){
	return (maPrev < maCur) ? true : false;
}

bool Asc(int maPrev, int maCur){
	return (maPrev > maCur) ? true : false;
}

class List{
	struct Node{
		int ma;
		Node *pNext;
		Node(int init) : ma(init), pNext(0){}
	};

	Node *pBeg, *pEnd, *pTemp;
	int nCount;

	public:
	List() : pBeg(0), pEnd(0) {
		cout << "Constructor List" << endl;
	}

	List(List const &Right) : pBeg(0), pEnd(0){
		cout << "Copying Constructor List" << endl;
		Node *pCur;// = new Node(0);
		pCur = Right.pBeg;
		while (pCur!= 0){
			Node *pTemp = new Node(0);
			pTemp->ma = pCur->ma;
			if (pBeg == 0) pBeg = pEnd = pTemp;
			else{
				pEnd->pNext = pTemp;
				pEnd = pTemp;
			}
			pCur = pCur->pNext;
		}
	}
	
	~List(){
		cout << "Destructor List" << endl;
		Node *pCur = pBeg;
		while (pCur != 0){
			pTemp = pCur->pNext;
			delete pCur;
			pCur = pTemp;
		}
	}

	void PushBack(int a){
		pTemp = new Node(0);
		pTemp->ma = a;
		pTemp->pNext = 0;
		if (pBeg == 0) pBeg = pEnd = pTemp;
		else{
			pEnd->pNext = pTemp;
			pEnd = pTemp;
		}
	}

	void ShowList(){
		Node *pCur = pBeg;
		cout << endl << "List of object " << this << ":" << endl;
		while (pCur != 0){
			cout << pCur->ma << " ";
	#ifdef _DEBUG
			cout << pCur << " ";
	#endif
			pCur = pCur->pNext;
		}
		cout << endl;
	#ifdef _DEBUG
		cout << "pBeg: " << pBeg << endl;
		cout << "pEnd: " << pEnd << endl;
	#endif
		delete pCur;
	}

	void SearchItem(int findElem){
		Node *pCur = pBeg;
		int index = 1;
		bool flag = false;
		while (pCur != 0){
			if (pCur->ma == findElem){
				cout << "List item " << findElem << " was found in list Node " << pCur << " on " << index << " list position" << endl;
				flag = true;
			}
			pCur = pCur->pNext;
			index++;
		}
		if (!flag) cout << endl << "No item " << findElem << " was found in list" << endl;
		cout << endl;
	}

	void DeleteItem(int DeleteIndex){
		Node *pCur = pBeg;
		Node *pPrev = 0;
		Node *pTemp = 0;
		int index = 1;
		while (pCur != 0){
			if (DeleteIndex == 1){ // Begin element
				pBeg = pCur->pNext;
				delete pCur;
				return;
			}
			else{
				if (index == DeleteIndex){
					if (pCur->pNext == 0){ // End element
						pEnd = pPrev;
						pPrev->pNext = 0;
						delete pCur;
						return;
					}
					pPrev->pNext = pCur->pNext; // Middle element
					delete pCur;
					return;
				}	
			}
			pPrev = pCur;
			pCur = pCur->pNext;
			index++;
		}
	}

	void DeleteItemByValue(int value){
		Node *pCur = pBeg;
		Node *pPrev = 0;
		Node *pTemp = 0;
		//int index = 1;
		while (pCur != 0){
			if (pCur->ma == value){
				//List Begin
				if (pCur == pBeg){
					pBeg = pCur->pNext;
					pTemp = pCur->pNext;
				}
				else{
					//List End
					if (pCur == pEnd){
						pEnd = pPrev;
						pPrev->pNext = 0;
						pTemp = 0;
					}
					else{
					//List Middle
						pPrev->pNext = pCur->pNext;
						pTemp = pCur->pNext;
					}
				}	
				delete pCur;
				pCur = pTemp;
			}
			else {
				pPrev = pCur;
				pCur = pCur->pNext;
			}
		}
	}

	void PopBack(){
		Node *pCur = pBeg;
		Node *pPrev = 0;
		while (pCur != 0){
			if (pCur == pEnd){
				pEnd = pPrev;
				pPrev->pNext = 0;
				delete pCur;
				return;
			}
			else{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
		}
	}

	void SortListBubble(bool(*pFn)(int,int)){
		cout << "Sort" << endl;
		bool flag = true;
		Node *pCur = pBeg;
		Node *pPrev = 0;
		int temp;
		while (flag){ //Bubble Sort
			flag = false;

			while (pCur != 0){
				if (pPrev != 0){
					if (pFn(pPrev->ma, pCur->ma)/*(pPrev->ma) > (pCur->ma)*/){

						temp = pCur->ma;
						pCur->ma = pPrev->ma;
						pPrev->ma = temp;

						flag = true;
					}	
				}
				pPrev = pCur;
				pCur = pCur->pNext;
			}
#ifdef _DEBUG
			ShowList();
#endif
			pCur = pBeg;
			pPrev = 0;
		}
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	{
		
		List l1;
		for (int i = 0; i < 15; i++){
			l1.PushBack(rand() % 100);
		}

		/*l1.PushBack(1);
		//l1.PushBack(2);
		l1.PushBack(78);
		l1.PushBack(4);
		l1.PushBack(66);
		l1.PushBack(78);
		l1.PushBack(23);*/
		l1.PushBack(93);
		l1.PushBack(78);

		l1.ShowList();

		//l1.SortListBubble();

		//List l2 = l1;
		//l2.ShowList();
		l1.SearchItem(78);

		l1.DeleteItem(93);
		//l1.ShowList();
		//l1.PushBack(78);
		l1.DeleteItemByValue(78);
		//l1.ShowList();
		
		//l1.ShowList();
		l1.PopBack();
		l1.ShowList();

		l1.SortListBubble(Desc);
		l1.ShowList();
		l1.SortListBubble(Asc);
		l1.ShowList();
	}



	if (_CrtDumpMemoryLeaks())
		cout << endl << "************" << endl << "MemoryLeaks!!!" << endl << "************" << endl;
	else
		cout << endl << "************" << endl << "Memory OK" << endl << "************" << endl;

	system("pause");
	return 0;
}

