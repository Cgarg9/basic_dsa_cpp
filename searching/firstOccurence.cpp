#include <iostream>
#include <vector>

int firstOccurence(std::vector<int> &v, int e) {
   // binary search 
   int l = 0, r = v.size() - 1, i = -1;
   while (l <= r) {
       int m = l + (r - l) / 2;
       if (v[m] == e) {
           i = m;
           break;
       }
       v[m] > e ? r = m - 1 : l = m + 1;
   }

   // element does not exists
   if (i == -1) return -1;
   
   // searching the left side linearly to find the first occurence
   while (i > 0) {
       if (v[--i] != e) {
           ++i;
           break;
       }
   }
   return i;
}

int main() {
    std::vector<int> v = {-1, 1, 1, 2, 3, 5, 6, 7, 8, 8, 9};
    int element = 1;
    int index = firstOccurence(v, element);
    if (index == -1) std::cout << "Element doesn't exists" << std::endl;
    else std::cout << "First occurence of element is found at index " << index << std::endl;
    return 0;
}
