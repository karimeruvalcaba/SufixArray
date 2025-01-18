vector<int> suffixArrayNaive(string S){
  int n = S.length() + 1;
  vector<string> sa;
  vector<string> A(n);
  S = S + "$";
  for (int i = 0; i < n; i++){
    sa.push_back(S.substr(n - i - 1, i+1));
  sort(sa.begin(), sa.end());
  for (int i = 0; i < n; i++){
    A[i] = n - sa[i].size() + 1;
  return A
  }
}
