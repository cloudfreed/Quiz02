#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] < x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	//Write your code here
	ifstream source("score1.txt");
	string line;
	string mem[20];
	float mixscore[20],sorted[20];
	int i=0,j=1;
	int count=1,real=1;
	while(getline(source,line)){
		mixscore[i]=atof(line.c_str());
		i++;
	}
	sort(mixscore,20);
	for(int i=19;i>=0;i--){
		sorted[19-i] = mixscore[i];
	}
	
	ofstream write("result.txt");
	for(int i=0;i<20;i++){
		if(i==0){
		write <<i+1 <<":" << sorted[i]<<"\n";
		//cout <<i+1 <<":" << sorted[i] <<"\n";
		}
		else if(sorted[i]<sorted[i-1]){
			write <<i+1 <<":" << sorted[i]<<"\n";
			//cout <<i+1 <<":" << sorted[i] <<"\n";
			j=0;
		}
		else if(sorted[i]==sorted[i-1]){
			write <<i-j <<":" << sorted[i]<<"\n";
			//cout <<i-j <<":" << sorted[i] <<"\n";
			j++;
		}
	write.close();

	}

	
	
	return 0;
}

