/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    long long guessNumber(long long n, long long low=1){
        long long mid_num=(low+n)/2;
        
        int x=guess(mid_num);
        
        if(x==1)
            return guessNumber(n, mid_num+1);
        if(x==-1)
            return guessNumber(mid_num-1, low);
        
        return mid_num;
    }
};