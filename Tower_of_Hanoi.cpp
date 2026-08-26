void hanoi(int n, int start, int target){
    int helper = 6 - (start + target);
    if(n==1){
        cout<< start <<" "<< target <<endl;
    }
    else{
        hanoi(n-1, start, helper);
        cout<< start <<" "<< target <<endl;
        hanoi(n-1, helper, target);
    }
}
