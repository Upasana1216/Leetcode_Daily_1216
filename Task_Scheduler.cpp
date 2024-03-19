class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> m(26,0);

        for(char i: tasks){
            m[i-'A']++;
        }

        for(int i=0; i<26; i++){
            if(m[i])
                pq.push(m[i]);
        }

        int time =0;
        while(!pq.empty()){
            vector<int> remain;
            int cycle = n+1;

            while(cycle && !pq.empty()){
                int max_freq = pq.top();
                pq.pop();

                if(max_freq > 1){
                    remain.push_back(max_freq-1);
                }
                ++time;
                --cycle;
            }

            for(int count:remain){
                pq.push(count);
            }

            if(pq.empty())
                break;
            time+=cycle;
        }

        return time;
    }
};
