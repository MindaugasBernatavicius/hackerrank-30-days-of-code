int main(){
  int t;
  int age;
  cin >> t;
  for(int i=0; i < t; i++){
    cin >> age;
      Person p(age);
      p.amIOld();
      for(int j=0; j < 3; j++){
        p.yearPasses(); 
      }
      p.amIOld();

  cout << '\n';
  }

  return 0;
}
