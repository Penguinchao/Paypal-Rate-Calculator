//(c) Christian Russell 2015
/*This program will compare paypal's micropayment and regular payment rates to 
 *help you decide which method is best for you. Find your average payment on the
 *table, then the program tells you which method gives you more revenue after
 *the service charge.
 //-------------------------------------------------------------------------------------
 *The default values were taken in May 2015, so they may be changed when you use
 *this program. To update the rates, change the constant variables at the beginning
 *of the main function. Charge variables are the minimum charges, and rate variables
 *are the percentage (in decimal format) of your transaction that is charged.
 *https://www.paypal.com/us/webapps/mpp/merchant-fees
 */
#include <iostream>
using namespace std;

double getGross(double revenue, double rate, double charge); 
/*User gives it a transaction amount, a service charge rate,
 * and a minimum charge rate, then it returns what money is 
 * left after charge */

//double getIncome(double gross, double minCharge); 
/*Takes the amount after charge rate, then compares it 
 *to the minimum charge. if min charge is higher, returns that */

int main(){
    //double rev = 100;
    const double regrate = .029;
    const double regcharge = .3;
    const double microCharge = .05;
    const double microRate = .05;
    double displayRate = .25;
    double displayStart = 0;
    double displayMax = 15;
    for(double i = displayStart; i<=displayMax; i = i + displayRate){
      double regTot = getGross(i, regrate, regcharge);
      double microTot = getGross(i, microRate, microCharge);;
      cout << i << ":\tREG: " << regTot << "\tMICRO: " << microTot;
      if(microTot > regTot){
        cout << "\tMICRO is greater";
      }else if(regTot > microTot){
        cout << "\tREG is greater";
      }else{
        cout << "EVEN";
      }
      cout << endl;
    }
}

double getGross(double revenue, double rate, double charge){
    double grossProfit = ( revenue - ( revenue * rate ) - charge );
    return grossProfit;
}
