// Prefix Sum & Division/Modulo
// Next few questions requires some mathematics and divisbility rule.


// For divisiiblity related problem (subarray divisible by K) , we need to know if
// subarray between [j,i] i.e. psum_i - psum_j = q . K
// If we take modulo on both side
// psum_i %K - psum_j%K = 0;
// So while iterating we look for psum_i%K
// And also update in similar way i.e. countMap[psum %K]++


// Negative remainder :
// As per Euclidean division algorithm, Given two integers a and b, with b ≠ 0, a = bq + r , where 0 ≤ r < |b| 
// Point to note is remainder(r) must always be a +ve number.
// What happen either of a or b is -ve , for example -5 % 2 = ?
// For example -5 = 2 *(-3) + 1 (r is 1)
// But if you do same in C++, r`` would be -1, this is due to C++ implementation. To fix this we would do (r + 2(b) ) % 2(b) , that would give 1. If remainder is +ve , 
// it wont harm either So for prefix sum problem, we can do psum_j = ( ( (psum + i) %K ) + K)%K and find this value in hashmap. So we add ith element to psum and for negative offset we add+K``` and take modulo again.




class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = ((sum + nums[i]) % k + k) % k; // have to write this way
            count += mp[sum]; // **equal value.. r - l == 0 => r == l   
            mp[sum]++;
        }
        return count;
    }
};

// if(mp.count(sum)){
//   count += mp[sum];
// }

