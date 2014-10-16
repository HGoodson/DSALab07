#include "RombergIntegration.h"
#include "RecursiveIntegration.h"
#include "QueueLinked.h"
#include "CSC2110/Double.h"
using CSC2110::Double;
#include <iostream>
using namespace std;
#include "math.h"

RombergIntegration::RombergIntegration()
{}
RombergIntegration::~RombergIntegration()
{}
//a is the lower limit and b is the upper limit
double RombergIntegration::accurateRomberg(MultiVarFunction* f, double a, double b, int level)
{
   Double* db;  //use this variable to place and retrieve values on the queue
   
   
   
   QueueLinked<Double>* q1 = new QueueLinked<Double>();
   QueueLinked<Double>* q2 = new QueueLinked<Double>();
   RecursiveIntegration* RIMath = new RecursiveIntegration();

   int counter = 0;
   int n = 1;  //current number of intervals
   while (counter < level)
   {
   
		double temp = 0;
		temp = RIMath->romberg(f,a,b,level);
		//DO THIS
		//obtain the required number of trapezoid evaluations depending on the number of levels requested
		//put all of the level 0 results on the q1
		db = new Double(temp); 
		q1->enqueue(db);

		n = 2*n;  //double the number of intervals
		counter++;
   }
   //q1 now has all of the level 0 integration results

   double factor;  //use this to compute the current Romberg Factor (4^k stuff)
   int power = 1;  //k, used to compute the Romberg Factor
   bool queue = true;
   //if level 0 has been requested, the loop will not execute
   //the total number of executions of the loop is ??

   //DO THIS
   int iterations = counter;    //can be precomputed
   while (iterations > 0)
   {
	
      //DO THIS
      //use the algorithm described in the lab to improve the accuracy of your level 0 results
	  //factor = ((pow(4,power) *  recent) - late)/(pow(4,power)-1);
	  factor = pow(4,power);
		if(queue == true)
		{
			cout << "In If " << endl;
		Double* first = q1->dequeue();
		cout << "After dequeue" << endl;
		Double* second = q1->peek();
		cout << "After Peek" << endl;
		double tm = first->getValue();
		double teem = second->getValue();
		double resultant = ((factor * teem) - tm)/(factor - 1);
		Double* con = new Double(resultant);
		q2->enqueue(con);
		
		if(q1->size() == 1)
		{
		q1->dequeue();
		power++;
		factor = pow(4,power);
		queue = false;
		}
		
		}

		else
		{
		//mimic first condition with q2 as opposed to q1
		Double* fst = q2->dequeue();
		Double* sec = q2->peek();
		double trash = fst->getValue();
		double garbage = sec->getValue();
		double res = ((factor * garbage) - trash)/(factor - 1);
		Double* sun = new Double(res);
		q1->enqueue(sun);
		if(q2->size() == 1)
		{
		q2->dequeue();
		power++;
		factor = pow(4,power);
		queue = false;
		}
		}


      iterations--;
   }
   //obtain the final answer
   //db = q1->dequeue();
   double result = db->getValue();  

   delete q1;
   delete q2;

   return result;
}
