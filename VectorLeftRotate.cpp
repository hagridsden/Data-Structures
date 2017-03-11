#include <vector>
#include <iostream>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) 
{
    for(int i=0;i<k;i++)
    {
        a.insert(a.begin()+n+i,a[i]);
    }
    a.erase(a.begin(),a.begin()+k); //erase first k elements
    return a;
}

int main()
{
    int n;
    int k;
    cout<<"Enter number of elements (n) :";
    cin >> n;
    cout<<"\nEnter number for rotation (k) :";
    cin >> k;
    cout<<"Enter "<<n<<" elements:\n";
    vector<int> a(n);   //vector declaration
    
    for(int i=0;i<n;i++)
        cin>>a[i];
 
    
    cout <<"\nLeft Rotation :\n";
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
