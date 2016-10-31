#include <iostream>

using namespace std;

int main()
{
    int x[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;
 int tmp = 0;

    for (int i = 0; i < n / 2; i++) {
        tmp = x[i];
        x[i] = x[n - 1 - i];
        x[n - 1 - i] = tmp;
    }
    
    
    cout << "The reversed array is:" << endl;
 
 
    for (int i = 0; i < n; i++) {
        cout <<  x[i] << " ";
    }
    
    cout << endl;

    return 0;
}
