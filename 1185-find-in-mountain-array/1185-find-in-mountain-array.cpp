/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:



    int findInMountainArray(int target, MountainArray &mountainArr) {
        // My approach is quite straight forward

/*If i m able to find the pivot element or the peak element I would be able to determine if the 
element is on the left or the right side of the array then it would be quite easy to find the 
minimum index..... If the element is found on the left side then i dont need to search for it in
the right side*/

    // Finding the peak element using binary search
    int n= mountainArr.length();


    int low= 0; int high= n-1;
    while(low<high){
        int mid= low+((high-low)/2);
        if(mountainArr.get(mid)>=mountainArr.get(mid+1)) high= mid;
        else low= mid+1;
    }

    int p= low;


    int l= 0 , h= p;
    while(l<=h){
        int m= l+((h-l)/2);
        if(mountainArr.get(m)<target) l= m+1;
        else if(mountainArr.get(m)>target)h= m-1;
        else return m;
    }
    l= p, h= n-1;
    while(l<=h){
         int m= l+((h-l)/2);
        if(mountainArr.get(m)>target) l= m+1;
        else if(mountainArr.get(m)<target)h= m-1;
        else return m; 
    }
    return -1; 
    }
};