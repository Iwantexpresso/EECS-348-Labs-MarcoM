#include <stdio.h>
#include <string.h>

float calculateAverage(float arr[], int n) {
  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum / n;


}
int main() {

float Arr[12] ={23458.01,
40112.00,
56011.85,
37820.88,
37904.67,
60200.22,
72400.31,
56210.89,
67230.84,
68233.12,
80950.34,
95225.22};

int width = 10;
int len = 12;

char Months[12][10]= {"January","February","March","April","May","June",
"July","August","September","October","November", "December"};


printf("Monthly Sales Report for:\n");

for (int i = 0; i < 12; i++) {
  printf("%-*s\t%.2f\n",width, Months[i], Arr[i]  );
  
  }

printf("\nSales Summary: \n");

float min;
float max;
// min index code 
for (int i = 0; i < 12; i++) {
  int min_index = i;
  for(int j =0;j<12; j++){
     if ( Arr[j] < min_index){
      min_index = j;
  
     } 
}
min = Arr[min_index];
printf("Min: %-*s\t%.2f\n",width, Months[min_index], Arr[min_index]);
break;


}
// max index code
for (int i = 0; i < 12; i++) {
  int max_index = i;
  for(int j =0;j<12; j++){
     if ( Arr[j] > max_index){
      max_index = j;
     
     } 
}
max = Arr[max_index];
printf("Max: %-*s\t%.2f\n",width, Months[max_index], Arr[max_index]);
break;


}
// Average index code
float avg;
avg = calculateAverage(Arr,12);
printf("Average:\t%.2f\n", avg);

 float movingAvg;
  printf("\nSix-Month Moving Average Report:\n");
  for(int i=0; i<6; i++) {
    movingAvg = calculateAverage(Arr+i, 6);
    printf("%-*s - %-*s $%.2f\n",width, Months[i],width,Months[i+5], movingAvg); 
  }
//sorting for last question
char SMonths[12][10] = {"December","November","July","October", "September","June", "August","March","February", "May","April","January"};
float sort_Arr[12] ={23458.01,
40112.00,
56011.85,
37820.88,
37904.67,
60200.22,
72400.31,
56210.89,
67230.84,
68233.12,
80950.34,
95225.22};

// Insertion sort 
for(int i=1; i<12; i++) {

  float key = sort_Arr[i];
  int j = i-1;
 
  while(j>=0 && sort_Arr[j] < key) {
    sort_Arr[j+1] = sort_Arr[j];
    j--;
  }

  sort_Arr[j+1] = key;


  


}

// Print sorted sales
printf("\nSales Report (Highest to Lowest):\n");
for(int i=0; i<12; i++) {

  // Get original index  

  printf("%-*s\t$%.2f\n",width, SMonths[i], sort_Arr[i]);

}










return 0;
}
