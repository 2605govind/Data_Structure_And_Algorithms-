#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	
	Node(int x) : data(x), next(nullptr){}
};

Node* insertAtBegin(Node* head, int element) {
	Node* newNode = new Node(element);
	newNode->next = head;
	head = newNode;
	return head;
}

class HashMap{
	public:
	int size;
	Node **array;
	
	HashMap(){
		size = 10;
		array = new Node*[size];
		for(int i = 0; i<size; i++){
			array[i] = nullptr;
		}
	}	
	
	void insert(int element){
		int index = element%10;
		if(array[index] != nullptr){
			array[index]->next = insertAtBegin(array[index]->next, element);
		}else{
			array[index] = new Node(element);
		}
	}

	bool count(int element){
		int index = element%10;
		if(array[index] == nullptr){
			return false;
		}else{
			Node* head = array[index];
			while(head){
				if(head->data == element) return true;
				head = head->next;
			}
		}
		return false;
	}
};

int main(){
	HashMap mp;
	mp.insert(43);
	mp.insert(23);
	if(mp.count(43)){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	return 0;
}