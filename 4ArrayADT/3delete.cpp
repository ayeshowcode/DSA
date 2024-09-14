#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

void deletee(struct Array *arr, int index)
{
    if (index > 0 && index <= arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}
int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    deletee(&arr, 2);
    display(arr);
}