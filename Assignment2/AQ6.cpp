//Name: Yuvicka
//Roll no.: 1024240016
#include<iostream>
using namespace std;
void transpose(int m[][3],int r,int c,int n){
    int ans[n+1][3];
    ans[0][0]=c;
    ans[0][1]=r;
    ans[0][2]=n;
    int k = 1;
    for (int col = 0; col < c; col++) {
        for (int i = 1; i <= n; i++) {
            if (m[i][1] == col) {
                
                ans[k][0] = m[i][1];
                ans[k][1] = m[i][0];
                ans[k][2] = m[i][2];
                k++;
            }
        }
    }
    cout<<"the triplet matrix is \n";
    for(int i=0;i<n+1;i++){
        cout<<m[i][0]<<" "<<m[i][1]<<" "<<m[i][2]<<" \n";
    }
    cout<<"its transpose is \n";
    for(int i=0;i<n+1;i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" \n";
    }
}
void addition(int m1[][3],int r1,int c1,int n1){
    int r2,c2,n2;
    cout<<"enter total number of rows in the second matrix ";
    cin>>r2;
    cout<<"enter total number of columns in the second matrix ";
    cin>>c2;
    cout<<"enter total number of non zero elements in teh second matrix";
    cin>>n2;
    int m2[n2+1][3];
    m2[0][0]=r2;
    m2[0][1]=c2;
    m2[0][2]=n2;
    for(int i=1;i<=n2;i++){
        cout<<"enter the "<<i<<"th row index , column index,the non zero value at that index for the triplet matrix(in sorted manner of their row) ";
        cin>>m2[i][0]>>m2[i][1]>>m2[i][2];
    }
    cout<<"first triplet matrix is \n";
    for(int i=0;i<n1+1;i++){
        cout<<m1[i][0]<<" "<<m1[i][1]<<" "<<m1[i][2]<<" \n";
    }
    cout<<"second triplet matrix is \n";
    for(int i=0;i<n2+1;i++){
        cout<<m2[i][0]<<" "<<m2[i][1]<<" "<<m2[i][2]<<" \n";
    }
    int ans[n1+n2][3];
    if (m1[0][0] != m2[0][0] || m1[0][1] != m2[0][1]) {
        cout << "Matrices dimensions do not match!\n";
        return;
    }
    
    int i = 1, j = 1, k = 1;
    int m = m1[0][2], n = m2[0][2];
    
    // Merge process
    while (i <= m && j <= n) {
        if (m1[i][0] < m2[j][0] || (m1[i][0] ==m2[j][0] && m1[i][1] < m2[j][1])) {
            ans[k][0] = m1[i][0];
            ans[k][1] = m1[i][1];
            ans[k][2] = m1[i][2];
            i++; k++;
        }
        else if (m2[j][0] < m1[i][0] || (m2[j][0] == m1[i][0] && m2[j][1] < m1[i][1])) {
            ans[k][0] = m2[j][0];
            ans[k][1] = m2[j][1];
            ans[k][2] = m2[j][2];
            j++; k++;
        }
        else { 
            int sum = m1[i][2] + m2[j][2];
            if (sum != 0) {
                ans[k][0] = m1[i][0];
                ans[k][1] = m1[i][1];
                ans[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    
    // Copy remaining elements
    while (i <= m) {
        ans[k][0] = m1[i][0];
        ans[k][1] = m1[i][1];
        ans[k][2] = m1[i][2];
        i++; k++;
    }
    while (j <= n) {
        ans[k][0] = m2[j][0];
        ans[k][1] = m2[j][1];
        ans[k][2] = m2[j][2];
        j++; k++;
    }
    
    // Store dimensions & count
    ans[0][0] = m1[0][0];
    ans[0][1] = m1[0][1];
    ans[0][2] = k - 1;
    
    cout<<" after addition we get \n";
    for(int i=0;i<k;i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" \n";
    }
}
void mul(int m1[][3],int r1,int c1,int n1){

    int r2,c2,n2;
    cout<<"enter total number of rows in the second matrix ";
    cin>>r2;
    cout<<"enter total number of columns in the second matrix ";
    cin>>c2;
    cout<<"enter total number of non zero elements in teh second matrix";
    cin>>n2;
    int m2[n2+1][3];
    m2[0][0]=r2;
    m2[0][1]=c2;
    m2[0][2]=n2;
    for(int i=1;i<=n2;i++){
        cout<<"enter the "<<i<<"th row index , column index,the non zero value at that index for the triplet matrix(in sorted manner of their row) ";
        cin>>m2[i][0]>>m2[i][1]>>m2[i][2];
    }
    cout<<"first triplet matrix is \n";
    for(int i=0;i<n1+1;i++){
        cout<<m1[i][0]<<" "<<m1[i][1]<<" "<<m1[i][2]<<" \n";
    }
    cout<<"second triplet matrix is \n";
    for(int i=0;i<n2+1;i++){
        cout<<m2[i][0]<<" "<<m2[i][1]<<" "<<m2[i][2]<<" \n";
    }
    if (m1[0][1] != m2[0][0]) { 
        cout << "Multiplication not possible!" << endl;
        return;
    }

    // Step 1: Transpose B to make matching columns easier
    int bt[n2][3], k = 1;
    bt[0][0] = m2[0][1];
    bt[0][1] = m2[0][0];
    bt[0][2] = m2[0][2];

    for (int col = 0; col < m2[0][1]; col++) {
        for (int i = 1; i <= m2[0][2]; i++) {
            if (m2[i][1] == col) {
                bt[k][0] = m2[i][1];
                bt[k][1] = m2[i][0];
                bt[k][2] = m2[i][2];
                k++;
            }
        }
    }

    // Step 2: Multiply A with B^T
    int result[n1+n2][3], size = 1;
    result[0][0] = m1[0][0];
    result[0][1] = m2[0][1];
    result[0][2] = 0;

    for (int i = 1; i <= m1[0][2];) {
        int row = m1[i][0];
        for (int j = 1; j <= bt[0][2];) {
            int col = bt[j][0];
            int sum = 0;
            int ti = i, tj = j;

            while (ti <= m1[0][2] && m1[ti][0] == row &&
                   tj <= bt[0][2] && bt[tj][0] == col) {
                if (m1[ti][1] < bt[tj][1]) ti++;
                else if (m1[ti][1] > bt[tj][1]) tj++;
                else {
                    sum += m1[ti][2] * bt[tj][2];
                    ti++; tj++;
                }
            }

            if (sum != 0) {
                result[size][0] = row;
                result[size][1] = col;
                result[size][2] = sum;
                size++;
            }

            while (tj <= bt[0][2] && bt[tj][0] == col) tj++;
        }

        while (i <= m1[0][2] && m1[i][0] == row) i++;
    }

    result[0][2] = size - 1;
}
int main(){
    int r,c,n_zero;
    cout<<"enter total number of rows ";
    cin>>r;
    cout<<"enter total number of columns ";
    cin>>c;
    cout<<"enter total number of non zero elements ";
    cin>>n_zero;
    int triplet[n_zero+1][3];
    triplet[0][0]=r;
    triplet[0][1]=c;
    triplet[0][2]=n_zero;
    for(int i=1;i<=n_zero;i++){
        cout<<"enter the "<<i<<"th row index , column index,the non zero value at that index for the triplet matrix(in sorted manner of their row) ";
        cin>>triplet[i][0]>>triplet[i][1]>>triplet[i][2];
    }
    cout<<"the given triplet matrix is \n";
    for(int i=0;i<n_zero+1;i++){
        cout<<triplet[i][0]<<" "<<triplet[i][1]<<" "<<triplet[i][2]<<" \n";
    }
    cout<<"\tOPERATIONS\n";
    cout<<"1.transpose of a triplet matrix\n";
    cout<<"2.addition of two triplet matrices\n";
    cout<<"3.multiplication of two triplet matrices\n";
    cout<<"enter your choice ";
    int choice;
    cin>>choice;
    switch (choice){
        case 1:{
            cout<<"\tTRANSPOSE\n";
            transpose(triplet,r,c,n_zero);
            break;
        }
        case 2:{
            cout<<"\tADDITION\n";
            addition(triplet,r,c,n_zero);
            break;
        }
        case 3:{
            cout<<"\tMULTIPLICATION\n";
            mul(triplet,r,c,n_zero);
            break;
        }
        default:{
            cout<<"invalid choice\n";
        }
    }
    return 0;
}
