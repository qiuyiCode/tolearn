#include <iostream>
#include "list.h"
using namespace std;

void print_elem(int x){
    cout << x << ' ';
}

int main(){
    pnode link;
    init(&link);
    addNewItemtoHead(&link,5);
    addNewItemtoHead(&link,4);
    insert(&link,1,10);
    addNewItemtoHead(&link,3);
    addNewItemtoHead(&link,2);
    deleteItem(&link,5);
    insert(&link,0,110);
    Reverse_link(&link);
    Traversal(&link,print_elem);
}