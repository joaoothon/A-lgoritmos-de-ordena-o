#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

int swap(int vet[], int i, int j){
  int temp = vet[i];
  vet[i] = vet[j];
  vet[j] = temp;
  return 0;
}
int print_vet(int vet[], int len){
  for(int i = 0; i < len; i++){
    cout<<vet[i]<<" ";
  }
  cout<<endl;
  return 0;
}
int make_vet(int vet[], int len){
  int j = len;
  for(int i = 0; i < len; i++){
    vet[i] = j;
    j--;
  }
  return 0;
}
//--------------------------------------------------
int insertion_sort(int vet[], int len){
  for(int i = 0; i < len; i++){
    int j = i;
    while(j>=0 && vet[j] > vet[j+1]){
      swap(vet, j, j+1);
      j--;
    }
  }
  return 0;
}
int selection_sort(int vet[], int len){
  for(int i = 0; i < len; i++){
    int min = i;
    for(int j = i; j < len; j++){
      if(vet[j] < vet[min]){
        min = j;
      }
    swap(vet, min, i);
    }
    
  }

  return 0;
}
int bubble_sort(int vet[], int len){
  for(int i = 0; i < len; i++){
    for(int j = i; j < len; j++){
      if(vet[j] > vet[j+1]){
        swap(vet, j, j+1);
      }
    }
  }
  return 0;
}
int shell_sort(int vet[], int len){
  for (int gap = len / 2; gap > 0; gap /= 2) {
    for (int i = 0; i + gap < len; i++) {
      int j = i;
      while (j >= 0 && vet[j] > vet[j + gap]) {
        swap(vet, j, j + gap);
        j -= gap;
      }
    }
  }
  return 0;
}
int quick_sort(int vet[], int low, int high){
  if(low < high){
    int pivot = vet[high];
    int j = low;
    for(int i = low; i < high; i++){
      if(vet[i] < pivot){
        swap(vet, i, j);
        j++;
      }
    }
    swap(vet, j, high);

    quick_sort(vet, low, j-1);
    quick_sort(vet, j+1, high);
  }

  return 0;
}
int merge(int vet[], int low, int high, int mid){
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
    	while (i <= mid && j <= high){
        	if (vet[i] < vet[j]){
            		c[k] = vet[i];
            		k++;
            		i++;
        	}
        	else{
            		c[k] = vet[j];
            		k++;
            		j++;
        	}
    	}
    	while (i <= mid){
        	c[k] = vet[i];
        	k++;
        	i++;
    	}
    	while (j <= high){
        	c[k] = vet[j];
        	k++;
        	j++;
    	}
    	for (i = low; i < k; i++){
        	vet[i] = c[i];
    	}

  return 0;
}

int mergeSort(int vet[] , int low, int high){
	if(low<high){
		int mid;
		mid = (low+high)/2;
		mergeSort(vet, low, mid);
		mergeSort(vet, mid+1, high);
		merge(vet,low,high,mid);
	}

  return 0;

}
//--------------------------------------------------

int main() {
  
  
  ofstream arquivo;
  arquivo.open("time.txt");
  
  float vet_time[100];
  int size_vet = 1000;
  for(int i = 0; i < 100; i++){
    int vet[size_vet];
    make_vet(vet, size_vet);

    
    clock_t start_time = clock();
    bubble_sort(vet, size_vet);
    clock_t end_time = clock(); 
    double delta_tempo = (end_time - start_time)/ (double) CLOCKS_PER_SEC;
    
    vet_time[i] = delta_tempo*100;
    
    size_vet += 1000; 
    
    
    
    
  }
  for(int i = 0; i < 100; i++){
    arquivo<<int(vet_time[i])<<endl;
  }
  
  arquivo.close();
  
  cout<<"termino :)"<<endl;
  return 0;
}