#include "string_matching.h"
#include<iostream>
using namespace std;
using namespace part7::chap32;

int main(){
    auto idx = StringMatching::RabinKarp(
        "nitin",
        "nnitin"
    );
    
    cout<<" Runing test "<<idx;
    return 0;
}