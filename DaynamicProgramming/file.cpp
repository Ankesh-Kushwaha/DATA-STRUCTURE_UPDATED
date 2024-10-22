#include<iostream>
using namespace std;

int main()
{
   int arr[6] = {2, 6, 8, 10, 5, 8};
   int start = 0, end = 5, mid;

   while (start <= end)
   {
      mid = start + (end - start) / 2;

      // Boundary conditions to avoid out-of-bounds access
      if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == 5 || arr[mid] > arr[mid + 1]))
      {
         cout << "Peak element found at index: " << mid;
         break; // Exit the loop after finding the peak
      }
      else if (mid > 0 && arr[mid] > arr[mid - 1])
      {
         start = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
   }

   return 0;
}
