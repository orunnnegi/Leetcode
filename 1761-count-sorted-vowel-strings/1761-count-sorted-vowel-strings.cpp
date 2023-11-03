class Solution {
public:
    int countVowelStrings(int n) {
        /*The solution for this problem works on the principle of pentatope number in number theory*/

//         In number theory, a pentatope number is a number in the fifth cell of any row of Pascal's triangle starting with the 5-term row 1 4 6 4 1, either from left to right or from right to left. It is named because it represents the number of 3-dimensional unit spheres which can be packed into a pentatope (a 4-dimensional tetrahedron) of increasing side lengths.

// The first few numbers of this kind are:

// 1, 5, 15, 35, 70, 126, 210, 330, 495, 715, 1001, 1365 

    // Formula for Pentatope Number= (n^4)/ 4!

    return (n+1)*(n+2)*(n+3)*(n+4)/24;

    }
};