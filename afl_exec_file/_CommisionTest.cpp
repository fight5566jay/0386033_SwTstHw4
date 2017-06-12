#include "Commision.h"
#include <sstream>
#include <iostream>

using namespace std;
string getCommision(const string& sInput)
{
	stringstream ss;
	string sResult;
	ss << sInput;
	const int iLockPrice = 45;
	const int iStockPrice = 30;
	const int iBarrelPrice = 25;
	int iTotalLocks = 0;
	int iTotalStocks = 0;
	int iTotalBarrels = 0;
	int iLocks;
	int iStocks;
	int iBarrels;
	float fCommision;

    if(ss.str().empty()){
        return string("Empty input!!");
    }
    
	ss >> iLocks;
	while (iLocks != -1) {
		if (iLocks < 0 || iLocks > 70) {
			return "Out of range: Locks must be in range [0, 70]";
		}
        
        if(ss.str().empty()){
            return string("illegal number of inputs!! 3n+1");
        }
		ss >> iStocks;
		if (iStocks < 0 || iStocks > 80) {
			return "Out of range: Stocks must be in range [0, 80]";
		}
        
        if(ss.str().empty()){
            return string("illegal number of inputs!! 3n+2");
        }
        ss >> iBarrels;
		if (iBarrels < 0 || iBarrels > 90) {
			return "Out of range: Barrels must be in range [0, 90]";
		}
		iTotalLocks += iLocks;
		iTotalStocks += iStocks;
		iTotalBarrels += iBarrels;
        if(ss.str().empty()){
            return string("illegal number of inputs!! 3n");
        }
		ss >> iLocks;
	}

	float fLockSales = iLockPrice * iTotalLocks;
	float fStockSales = iStockPrice * iTotalStocks;
	float fBarrelSales = iBarrelPrice * iTotalBarrels;
	float fSales = fLockSales + fStockSales + fBarrelSales;

	if (fSales > 1800.0) {
		fCommision = 0.1 * 1000.0;
		fCommision += 0.15 * 800.0;
		fCommision += 0.2 * (fSales - 1800.0);
	}
	else if (fSales > 1000.0) {
		fCommision = 0.1 * 1000.0;
		fCommision += 0.15 * (fSales - 1000.0);
	}
	else
		fCommision = 0.1 * fSales;

	ss.clear();
	ss << fCommision;
	ss >> sResult;
	return sResult;
}

int main(int argc, char* argv[]){
    string str;
    stringstream ss;
    while(!cin.eof()){
        cin >> str;
        ss << str;
        if(str == "-1")
            break;
        ss << " ";
    }
    cout << getCommision(ss.str()) << endl;
    return 0;
}
