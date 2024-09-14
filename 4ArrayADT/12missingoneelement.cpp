#include <iostream>
using namespace std;
void printmissingelements(int *arr, int size)
{
    int diff = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] - i != diff)
        {
           
                cout << i+diff << " ";
                diff++;
            break;
        }
    }
}
int main()
{
    int arr[11]={6,7,8,9,11,12,15,16,17,18,19};
    printmissingelements(arr, 11);

}