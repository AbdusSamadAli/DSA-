class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long maxsum=0, minsum=0;      
        stack<int>s;
        vector<int>nge(n,n), pge(n,-1);
        for(int i=0; i<n;i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                nge[s.top()] = i;
                s.pop();
            }
              pge[i] = s.empty() ? -1 : s.top(); 
            s.push(i);
        }
        while(!s.empty()) s.pop();
        vector<int>nse(n,n) , pse(n,-1);
        for(int i=0; i<n;i++){
            while(!s.empty() && nums[s.top()] > nums[i]){
                nse[s.top()] = i;
                s.pop();
            }
              pse[i] = s.empty() ? -1 : s.top(); 
            s.push(i);
        }

        for(int i=0; i<n;i++){
            maxsum += (long long)(i- pge[i]) * (nge[i] - i) * nums[i];
            minsum += (long long)(i- pse[i]) * (nse[i] - i) * nums[i];
        }
        return maxsum - minsum;
    }
};
    
//int n = nums.size();
        //long long result = 0;
        //for(int i=0;i<n-1;i++){
            //int maxno = nums[i], minno = nums[i];
            //for(int j=i+1; j<n;j++){
                //if(nums[j] > maxno) maxno = nums[j];
              //  else if(nums[j] < minno) minno = nums[j];
            //    result  = result + maxno - minno;
          //  }
        //}
        //return result