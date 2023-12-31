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
   
   // searching the left side linearly to find the first occurence
   while (i > 0) {
       if (v[--i] != e) {
           ++i;
           break;
       }
   }

   // returns -1 if element does not exists
   return i;
}

int firstOccurence_b(std::vector<int> &v, int e) {
    // returns -1 if element is not found
    int l = 0, r = v.size() - 1, i = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == e) {
            i = m;
            // searching the left for first occurence using binary search
            r = m - 1;
        } else {
            v[m] > e ? r = m - 1 : l = m + 1;
        }
    }
    return i;
}

int main() {
    std::vector<int> v = {-1, 1, 1, 2, 3, 5, 6, 7, 8, 8, 9};
    int element = 9;
    int index = firstOccurence(v, element);
    int idx = firstOccurence_b(v, element);
    std::cout << "firstOccurence function's output" << std::endl;
    if (index == -1) std::cout << "Element doesn't exists" << std::endl;
    else std::cout << "First occurence of element is found at index " << index << std::endl;
    std::cout << "firstOccurence_b function's output" << std::endl;
    if (idx == -1) std::cout << "Element doesn't exists" << std::endl;
    else std::cout << "First occrence of element is found at index " << idx << std::endl;
    return 0;
}
