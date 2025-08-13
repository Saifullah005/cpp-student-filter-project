#include<iostream>
#include<math.h>
#include<iomanip>
#include<climits>
#include<string.h>
using namespace std;
struct students{
    int score;
    string name;
};


void sortDescending(int scores[], string names[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                swap(scores[j], scores[j + 1]);
                swap(names[j], names[j + 1]);
            }
        }
    }
}

bool vowel(string name){
   
        return (name[0] == 'a' || name[0] == 'e' || name[0] == 'i' || name[0] == 'o' || name[0] == 'u' || name[0] == 'A' || name[0] == 'E' ||name[0] == 'O' || name[0] == 'I' || name[0] == 'U');
}
int main(){
    int n ,sum1= 0, count1 = 0;
    cout<<"Enter the number of enteries: ";
    cin>>n;
    students student[n];
    
    for(int i=0 ;i<n; i++){
        cout<<"Enter name for student "<<i+1<<endl;
        cin>>student[i].name;
        cout<<"Enter the score of student: "<<i+1<<endl;
        cin>>student[i].score;
        sum1+=student[i].score;
        count1++;
    }
    
    float class_avg = (float)sum1/count1;
    
    string filtered_list[n];
    
    int filtered_score[n],count = 0 ,sum = 0;
    
    for(int i = 0 ;i <n ; i++){
        if(student[i].score > class_avg && vowel(student[i].name)==true){
            filtered_list[count] = student[i].name;
            filtered_score[count] = student[i].score;
            sum += filtered_score[count];
            count++;
        }
    }
 
    if(count==0){
        cout<<"No matching students in the filtered list";
        return 1;
    }
    
    cout<<"The class average is: "<<class_avg<<endl;
    cout<<"The number of filtered students are: "<<count<<endl;
  
    sortDescending(filtered_score, filtered_list, count);
    cout<<"The students in filtered list are: "<<endl;
    for(int i = 0; i < count ;i++){
       cout<<"Name: "<<filtered_list[i]<<endl;
       cout<<"Score: "<<filtered_score[i]<<endl;
    }
     cout<<"The highest scorer is: "<< filtered_list[0]<<" with score: "<<filtered_score[0];
     cout<<"The lowest scorer is: "<< filtered_list[count-1]<<" with score: "<<filtered_score[count-1];
    float filtered_avg = (float)sum / count;
     cout<<"The average score of the filtered list is: "<<filtered_avg;
    return 0;
}
