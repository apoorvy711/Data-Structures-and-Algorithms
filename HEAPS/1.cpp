#include<bits/stdc++.h>
using namespace std;



//INSERTION -MAXHEAP
class Max_Heap{
    public:
    vector<int>heap;
    void insert(int val){
        heap.push_back(val);
        int index=heap.size()-1;

        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]<heap[index]){
                swap(heap[parent],heap[index]);
                index=parent;
            }
            else{
                break;
            }
        }


    }
    void print_heap(){
        for(auto &it:heap){
            cout<<it<<" ";
        }  
        cout<<endl;
    }
};

//INSERTION-MINHEAP
class Min_heap{
    public:
    vector<int>heap;
    void insert(int val){
        heap.push_back(val);
        int index=heap.size()-1;

        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]>heap[index]){
                swap(heap[parent],heap[index]);
                index=parent;
            }
            else{
                break;
            }
        }


    }
    void print_heap(){
        for(auto &it:heap){
            cout<<it<<" ";
        }  
        cout<<endl;
    }
};

//DELETION -MAXHEAP 
class max_heap{
    public:
    vector<int>heap;
    void insert(int val){
        heap.push_back(val);
        int index=heap.size()-1;

        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]<heap[index]){
                swap(heap[parent],heap[index]);
                index=parent;
            }
            else{
                break;
            }
        }
    }

    void delete_MAX(){
        if(heap.size()==0){
            cout<<"the heap is empty";
            return;
        }
        
        cout<<"deleted"<<heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        int n=heap.size();

        int index=0;

        while(index<n){
            int left=2*index+1;
            int right=2*index+2;
            int largest=index;

            if(left<n && heap[left]>heap[largest]) largest=left;
            if(right<n && heap[right]> heap[largest]) largest=right;

            if(largest !=index){
                swap(heap[index],heap[largest]);
                index=largest;
            }
            else{
                break;
            }
        } 
    }


    void print_heap(){
        for(auto &it:heap){
            cout<<it<<" ";
        }  
        cout<<endl;
    }
};

//DELETION-MINHEAP
class min_heap{
    public:
    vector<int>heap;
    void insert(int val){
        heap.push_back(val);
        int index=heap.size()-1;

        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]<heap[index]){
                swap(heap[parent],heap[index]);
                index=parent;
            }
            else{
                break;
            }
        }
    }

    void delete_MIN(){
        if(heap.size()==0){
            cout<<"the heap is empty";
            return;
        }
        
        cout<<"deleted"<<heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        int n=heap.size();

        int index=0;

        while(index<n){
            int left=2*index+1;
            int right=2*index+2;
            int smallest=index;

            if(left<n && heap[left]<heap[smallest]) smallest=left;
            if(right<n && heap[right]< heap[smallest]) smallest=right;

            if(smallest !=index){
                swap(heap[index],heap[smallest]);
                index=smallest;
            }
            else{
                break;
            }
        } 
    }


    void print_heap(){
        for(auto &it:heap){
            cout<<it<<" ";
        }  
        cout<<endl;
    }
};

//HEAPIFY
void heapify(vector<int>&heap,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]> heap[largest]) largest=right;

    if(largest !=i){
        swap(heap[i],heap[largest]);
        heapify(heap,n,largest);
    }

}

void buildMAXHEAP(vector<int>&heap){
    int n=heap.size();
    for(int i=n/2 - 1;i>=0;i--){
        heapify(heap,n,i);
    }

}

//HEAPSORT 
void heapifY(vector<int>&heap,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]> heap[largest]) largest=right;

    if(largest !=i){
        swap(heap[i],heap[largest]);
        heapifY(heap,n,largest);
    }
}

void heapSort(vector<int>&heap){
    int n=heap.size();
    for(int i=n/2 - 1;i>=0;i--){
        heapifY(heap,n,i);
    }
    for(int i=n- 1;i>=0;i--){
        swap(heap[0],heap[i]);
        heapifY(heap,i,0);
    }

}

int main(){
    /*
    //INSERTION
    Max_Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(54);

    h.print_heap();

    Min_heap i;
    i.insert(50);
    i.insert(55);
    i.insert(53);
    i.insert(54);

    i.print_heap();
    
    
    //DELETION
    max_heap H;
    H.insert(40);
    H.insert(30);
    H.insert(35);
    H.insert(10); 
    H.insert(5);
    H.insert(20);
    H.insert(25);

    H.print_heap();

    H.delete_MAX();

    H.print_heap();

   

    min_heap I;
    I.insert(40);
    I.insert(30);
    I.insert(35);
    I.insert(10); 
    I.insert(5);
    I.insert(20);
    I.insert(25);

    I.print_heap();

    I.delete_MIN();

    I.print_heap();
  
    
   vector<int>heap={4,10,3,5,1};

   buildMAXHEAP(heap);
   for(auto &it:heap){
    cout<<it<<" ";
   }
   cout<<endl;
   

   */
   vector<int>heap={4,10,3,5,1};
   heapSort(heap);
   for(auto &it:heap){
    cout<<it<<" ";
   }
   cout<<endl;


    return 0;

}