#include<iostream>
using namespace std;

class HashMap{
	int size;
	int *array;
	public:
	HashMap(){
		size = 10;
		array = new int[size];
		for(int i = 0; i<size; i++){
			array[i] = -1;
		}
	}

	void insert(int element){
		int index = element%size;
		if(array[index] == -1){
			array[index] = element;
		}else{
			int i = 1;
			while(1){
				index = (index%size + i)%size;
				i++;
				if(array[index] == -1){
					array[index] = element;
					break;
				}

				if(i > size) {
					cout<<"In vailied element"<<endl;
					break;
				}
			}
			
		}
	}

	bool count(int element){
		int index = element%size;
		if(array[index] == element){
			return true;
		}else{
			int i = 1;
			while(1){
				index = (index%size + i)%size;
				i++;
				if(array[index] == element){
					return true;
				}

				if(i > size) {
					cout<<"Element is not present"<<endl;
					return false;
				}
			}
			
		}

		return false;
	}

	void print(){
			for(int i = 0; i<size; i++){
				cout<<array[i]<<endl;
			}
	}
	
};

int main(){
	int arr[7] = {43,135,72,23,99,19,82};
	HashMap hm;
	for(int i = 0; i<7; i++){
		hm.insert(arr[i]);

	}

	// hm.print();
	

	if(hm.count(82)){
		cout<<"yes";
	}else{
		cout<<"no";
	}

	return 0;
}