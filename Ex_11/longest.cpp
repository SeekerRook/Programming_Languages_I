//The program contains functions from geekforgeeks.org
#include <bits/stdc++.h>

using namespace std;

int Num = 1000000000;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second < b.second;
  
    return a.first < b.first;
}
  

int findInd(vector<pair<int, int> >& preSum, int n, int val)
{
    int l = 0;
    int h = n - 1;
    int mid;

    int ans = -1;
  

    while (l <= h) {
        mid = (l + h) / 2;
        if (preSum[mid].first <= val) {
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
  
    return ans;
}

int LongestSub(int arr[], int n, int x)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] -= x;

    int maxlen = 0;
  

    vector<pair<int, int> > preSum;
  

    int sum = 0;
  
    int minInd[n];
  
   
    for (i = 0; i < n; i++) {
        sum = sum + arr[i];
        preSum.push_back({ sum, i });
    }
  
    sort(preSum.begin(), preSum.end(), compare);
 
    minInd[0] = preSum[0].second;
  
    for (i = 1; i < n; i++) {
        minInd[i] = min(minInd[i - 1], preSum[i].second);
    }
  
    sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + arr[i];
  

        if (sum >= 0)
            maxlen = i + 1;
  

        else {
            int ind = findInd(preSum, n, sum);
            if (ind != -1 && minInd[ind] < i)
                maxlen = max(maxlen, i - minInd[ind]);
        }
    }
  
    return maxlen;
}

void read(char* filename,int &Days, int &Hospitals,int *days){

    ifstream file;//initializtion
    char *file_name = filename;
    file.open(file_name);
    if (file.is_open()){

        file >> Days >> Hospitals ;
        int temp;
        int i = 0;
        while(file >> temp){
            days[i] = -1*temp;
            i++;
        }
    }
    else {cout << "Unable to open "<<file_name<<'\n';}

}

int main(int argc, char **argv)
{
    int n , h;
    int *ptr;
	ptr = (int*) malloc(Num*sizeof(int));
    read(argv[1],n,h,ptr); 
    cout << LongestSub(ptr, n, h)<< '\n';
    return 0;
}
