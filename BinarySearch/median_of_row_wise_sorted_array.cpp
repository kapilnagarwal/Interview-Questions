int coutSmallerthanMid(vector<int> &row, int mid){
    int low = 0; 
    int high = row.size() - 1;
    while(low <= high){
        int md = (low+high)/2;

        if (row[md] <= mid)
            low = md+1;
        else
            high = md-1;
    }
    return low;
}

int Solution::findMedian(vector<vector<int> > &A) {

    int low = 0;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += coutSmallerthanMid(A[i], mid);
        }

        if (cnt <= (n*m)/2)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
