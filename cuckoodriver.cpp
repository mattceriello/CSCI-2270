#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>
#include <chrono>
#include <ratio>
#include "cuckoo.hpp"
#include "cuckoo.cpp"

using namespace std;

int main(){
    bool flag1 = false;
	cuckoo h;
	h.load1();
	h.load2();
    h.cuckoo1(1, 40000);
}