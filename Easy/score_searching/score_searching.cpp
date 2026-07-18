#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin>>n;
  int fail_but_highest=-1;
  int pass_but_lowest=1e9;
  vector<int> students(n);
  for (int i=0;i<n;i++)
  {
    int stud; cin>>stud;
    students[i]=stud;
    if (stud>=60) pass_but_lowest=min(pass_but_lowest,stud);
    else fail_but_highest=max(fail_but_highest,stud);
  }
  sort(students.begin(),students.end());
  for (int i=0;i<n;i++)
  {
    cout<<students[i];
    if (i!=n-1) cout<<" ";
    else cout<<"\n";
  }
  if (fail_but_highest==-1) cout<<"best case";
  else cout<<fail_but_highest;
  cout<<"\n";
  if (pass_but_lowest==1e9) cout<<"worst case";
  else cout<<pass_but_lowest;
  return 0;
}
