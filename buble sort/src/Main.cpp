    #include <iostream>
    using namespace std;
    
    void buble (){
        int n, i,j ,tamp,m;
        int arr[]={10,7,90,5};
        n= sizeof(arr)/sizeof(arr[0]);
         cout<<"Sebelum di sorting : ";
        for ( m=0;m<n; m++){
            cout<<arr[m]<< " ";
        }
        for (i=0;i<n ;i++){
            for (j=0; j<n-1 ;j++){
                if (arr[j]>arr[j+1]){
                    tamp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=tamp;
                }
            }
            
           
        }
       cout<< " \nsesudah di sorting : ";
        for (int k= 0 ;k<n;k++){
            cout<<arr[k]<<" ";
    }
    }
    int main()
    {
     
     buble();
        return 0;
    }
