#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for(int j = i +1; j <n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }

        swap(arr[i], arr[minIdx]);
    }
}

int main()
{

    vector<int> arr ={ 64, 25, 12, 22, 11};

    selection_sort(arr);
    for(int i:arr){
        cout << i  << " ";
    }

    return 0;
}