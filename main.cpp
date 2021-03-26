#include <iostream>
#include <limits>

template <class Cls>
    void fn_Merge(Cls* op_Arr, int i_StartI,
                  int i_MidI, int i_EndI){
        int i_LSize= i_MidI- i_StartI + 1;
        int i_RSize= i_EndI- i_MidI;

        Cls* op_L = new Cls[(i_LSize+ 1)];
        Cls* op_R = new Cls[(i_RSize+ 1)];

        // COM: Copy the elements from (i_StartI + i_Ct to)th index
        // to (i_MidI- i_StartI)th index.
        for(int i_Ct=0; i_Ct < i_LSize; i_Ct++){
            op_L[i_Ct]= op_Arr[(i_StartI + i_Ct)];
        }

        for(int i_Ct=0; i_Ct < i_RSize; i_Ct++){
            op_R[i_Ct]= op_Arr[(i_MidI + i_Ct + 1)];
        }

        // COM: Set the last element with -infinity
        op_L[i_LSize]= std::numeric_limits<Cls>::lowest();
        op_R[i_RSize]= std::numeric_limits<Cls>::lowest();


        int i_I=0, i_J=0;
        for(int i_Ct= i_StartI; i_Ct<= i_EndI; i_Ct++){
            if(op_L[i_I] >= op_R[i_J]){
                op_Arr[i_Ct]= op_L[i_I];
                i_I++;
            }
            else{
                op_Arr[i_Ct]= op_R[i_J];
                i_J++;
            }
        }

        delete [] op_L;
        delete [] op_R;
    }

template <class Cls>
    void fn_MergeSort(Cls* op_Arr, int i_StartI
                      , int i_EndI){

        if(i_StartI< i_EndI){
            int i_MidI = (i_StartI+ i_EndI)/2;
            fn_MergeSort(op_Arr, i_StartI, i_MidI);
            fn_MergeSort(op_Arr, (i_MidI + 1), i_EndI);
            fn_Merge(op_Arr, i_StartI, i_MidI, i_EndI);
        }
    }

int main(){
    int i_Count= 5;
    int ia_Arr[i_Count]= {1, 2, 3, 4, 5};
    fn_MergeSort<int>(ia_Arr, 0, (i_Count-1));

    for(int i_Ct=0; i_Ct< i_Count; i_Ct++){
        std::cout<< ia_Arr[i_Ct]<< " ";
    }
    return 0;
}
