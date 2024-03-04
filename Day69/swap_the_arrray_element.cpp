#include <iostream>
using namespace std;

class Solution{
  public:
    void swapElements(int arr[], int n){
        
        // Iterate array one by one
        for(int i = 0; i < n-2; i++) {
            // Swap currenct element to ith + 2 index element
            swap(arr[i], arr[i+2]);
        }
    }
};

int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
        Solution obj;

        // calling function to swap the array swap elements
	    obj.swapElements(arr, n);
	    
	    // Printing the modified array
	    for(int i = 0;i<n;i++){
            cout << arr[i] << " ";
        }
	    
	    cout << endl;
	}
	
	return 0;
}
