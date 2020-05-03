#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;



void idle(int count)
{
    while (count > 0)
    {
		count--;
    }
}



void singlethread(int count)
{
    idle(count);
    idle(count);
    idle(count);
}



void multithread(int count)
{
    thread t1(idle, count);
    thread t2(idle, count);
    thread t3(idle, count);

    t1.join();
    t2.join();
    t3.join();
}



int main()
{
	int count = 9999999999;
	time_point<system_clock> beg, end;
	
	// Single
	cout << "Beginning single threaded tasks." << endl;
	beg = system_clock::now();
	singlethread(count);
	end = system_clock::now();
	cout << "Single threaded completed in " << duration_cast<milliseconds>(end - beg).count() << " milliseconds." << endl << endl;

	// Multi
	cout << "Beginning multi threaded tasks." << endl;
	beg = system_clock::now();
	multithread(count);
	end = system_clock::now();
	cout << "Multi threaded completed in " << duration_cast<milliseconds>(end - beg).count() << " milliseconds." << endl;
	
	return 0;
}