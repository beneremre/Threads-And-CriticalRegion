#include <cstdlib>
#include <pthread.h>
#include <iostream>

using namespace std;

int seatList[2][50]= {0};
int turn = 0;
int counT = 0;


void printFunc()
{
	for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cout << seatList[i][j];
        }cout << endl;           
    }
}


int randomNum(int num)
{
	num = rand() %100+1;
	return num;
}

void *func1 (void *)
{
	while(counT < 100)
	{
	 while(turn!=0);
	 int num = randomNum(num);
	
	 if(num%2 == 0) // second row
	 {
		if(seatList[1][num/2-1] == 0)
		{
			seatList[1][num/2-1] = 1;
			cout << "Thread-1 is entring the critical region" << endl;
			cout << "Seat number " << num << " is reserved by thread-1" << endl;
			cout << "Thread-1 is leaving the critical region" << endl;
			counT++;
		}

	 }
	 else //first row
	{
		if(seatList[0][(num-1)/2] == 0)
		{
			seatList[0][(num-1)/2] = 1;
			cout << "Thread-1 is entring the critical region" << endl;
			cout << "Seat number " << num << " is reserved by thread-1" << endl;
			cout << "Thread-1 is leaving the critical region" << endl;
			counT++;
		}	
			
	}		
	 turn = 1;
}
}

void *func2 (void *)
{
	while(counT < 100)
	{
	 while(turn!=1);
	
	 int num = randomNum(num);
	
	 if(num%2 == 0) // ikinci
	 {
		if(seatList[1][num/2-1] == 0)
		{
			seatList[1][num/2-1] = 2;
			cout << "Thread-2 is entring the critical region" << endl;
			cout << "Seat number " << num << " is reserved by thread-2" << endl;
			cout << "Thread-2 is leaving the critical region" << endl;
			counT++;
		}

	 }
	 else
	 {
		if(seatList[0][(num-1)/2] == 0)
		{
			seatList[0][(num-1)/2] = 2;
			cout << "Thread-2 is entring the critical region" << endl;
			cout << "Seat number " << num << " is reserved by thread-2" << endl;
			cout << "Thread-2 is leaving the critical region" << endl;
			counT++;
		}
		
		turn = 2;	
	}
}
}

void *func3 (void *)
{
	while(counT < 100)
	{
	 while(turn!=2);
	 int num = randomNum(num);
	
	 if(num%2 == 0) // ikinci
	 {
		if(seatList[1][num/2-1] == 0)
		{
			seatList[1][num/2-1] = 3;
			cout << "Thread-3 is entring the critical region" << endl;
			cout << "Seat number " << num << " is reserved by thread-3" << endl;
			cout << "Thread-3 is leaving the critical region" << endl;
			counT++;
		}
	 }
	 else
	 {
		if(seatList[0][(num-1)/2] == 0)
		{
			seatList[0][(num-1)/2] = 3;
			cout << "Thread-3 is entring the critical region" << endl;
			cout << "Seat number " << num << " is reserved by thread-3" << endl;
			cout << "Thread-3 is leaving the critical region" << endl;
			counT++;
		}
	}
	turn = 0;
}
}


int main()
{
	pthread_t thread1, thread2, thread3;

	pthread_create(&thread1,NULL,func1,NULL);
	pthread_create(&thread2,NULL,func2,NULL);
	pthread_create(&thread3,NULL,func3,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);

	printFunc();

	return 0;

}

