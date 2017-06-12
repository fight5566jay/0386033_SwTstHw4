#include "klee_src/include/klee/klee.h"
#include <sstream>

using namespace std;
const int iTriangleMinLength = 1;
const int iTriangleMaxLength = 200;
string getRangeMsg()
{
    stringstream ss;
    ss << "[" << iTriangleMinLength << ", " << iTriangleMaxLength << "]";
	return ss.str();
}

bool outOfRange(const int& iVal)
{
	return (iVal < iTriangleMinLength) || (iVal > iTriangleMaxLength);
}
string getTriangleType(const int & iSideA, const int & iSideB, const int & iSideC)
{
	string sAns;
	stringstream ss;

	if (outOfRange(iSideA)) {
		return "Value of the side A is not in the range of " + getRangeMsg();
	}

	if (outOfRange(iSideB)) {
		return "Value of the side B is not in the range of " + getRangeMsg();
	}

	if (outOfRange(iSideC)) {
		return "Value of the side C is not in the range of " + getRangeMsg();
	}
	
	if((iSideA + iSideB <= iSideC) || (iSideA + iSideC <= iSideB) || (iSideB + iSideC <= iSideA))
		return string("Not a triangle");

	if (iSideA == iSideB && iSideA == iSideC)
		return string("Equilateral");
	if (iSideA == iSideB || iSideA == iSideC || iSideB == iSideC)
		return string("Isosceles");
	return string("Scalene");

}

int main(){
    int a, b, c, iResult;
    klee_make_symbolic(&a, sizeof(a), "a");
    klee_make_symbolic(&b, sizeof(b), "b");
    klee_make_symbolic(&c, sizeof(c), "c");
    string sTriangleType = getTriangleType(a, b, c);
    if(sTriangleType == "Equilateral")
        iResult = 1;
    else if(sTriangleType == "Isosceles")
        iResult = 2;
    else if(sTriangleType == "Scalene")
        iResult = 3;
    else
        iResult = -1;
    return iResult;
}