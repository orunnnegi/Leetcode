class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0, start;
        int i = 0;
        while(i < colors.length()){
            start = i;
            while(i < colors.size() && colors[i] == 'A') i++;
            alice += max(0, (i-start-2));
            start = i;
            while(i < colors.size() && colors[i] == 'B') i++;
            bob += max(0, (i-start-2));
        }
        return alice + bob == 0 ? 0 : alice > bob;
    }
};