//DNA is made of four types of nucleotides – adenine, guanine, cytosine, and thymine.
//These are typically abbreviated by the letters A, G, C, and T, respectively. 
//Programmatically, DNA can be represented as a string of characters, where each character must be one of A, G, C, or T. 

// sequence 1 = G T C C A T A C A
// sequence 2 = T C A T A T C A G

//The similarity of two sequences was calculated as 1−edit_distance/min(lengthquery, lengthtarget)⁠. 
//Two different DNA sequences were used for these tests. 
//We artificially mutated them to achieve different similarities. 



#include <bits/stdc++.h>
using namespace std;

float util_function(string seq1, string seq2)
  {
    int m = seq1.size();
    int n = seq2.size();

    //create a matrix for dp
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
      for(int j=0;j<=n;j++)
      {
        if(i==0)
            dp[i][j] = j;
        else if(j==0)
            dp[i][j] = i;
        else if(seq1[i-1] == seq2[j-1])
            dp[i][j] = dp[i-1][j-1];
        else
          dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
      }
    }

    float answer = 0;

    answer = 100 - ((float)dp[m][n] * 100.0/(float)min(m,n));

    return answer;
  }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string sequence1,sequence2;

    cout<<"Input query Sequence: "<<endl;
    cin>>sequence1;
    cout<<"Input Target Sequence: "<<endl;
    cin>>sequence2;

    cout<<"The similarity between the input Sequences is: ";
    cout<< util_function(sequence1,sequence2);
    cout<<endl;

    return 0;

}
