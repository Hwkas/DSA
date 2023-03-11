#include <iostream>
using namespace std;

int global_var = 42;

void pass_by_value(int *p){ // can also say call by value

    p = &global_var; 
    /*
        Here the above will not work, because 'p' copy of 'prt' & 
        contains the address of 'var' not 'ptr', so if we try to edit
        the address inside 'p', it will be pointing to another variable.
    */ 

    // *p = global_var;
   /*
        But we can edit the value of the memory locations at which 'ptr' points to,
        because we have the address of 'var'.
   */
}

void pass_by_refrence_double_pointer(int **p){ // can also say call by refrence or pointer to pointer.
    
    *p = &global_var;
    /*
        Here the above code is working, because we have passed the address of 'prt'
        to a double pointer 'p'. So, now we can make the 'ptr' to point to another
        varaible instead 'var' by defrencing the 'p'.

    */
    // **p = global_var;
    /*
        Here we can also the value of the variable, at which ptr points to.
    */
}

void pass_by_refrence_refrence_to_pointer(int *&p){ // can also say call by refrence or reference to a pointer.

    p = &global_var;
    /*
        Here the above code is working, because we are getting the value of 'ptr'
        i.e address of 'var' inside 'p'.
    */

    // *p = global_var;
    /*
        Here we can also the value of the variable, at which ptr points to.
    */
}

int main(){
    int var = 23;
    int *ptr = &var;

    cout<<"Address of ptr: "<<ptr<<" & value of ptr: "<<*ptr<<endl;
    // pass_by_value(ptr);
    // pass_by_refrence_double_pointer(&ptr);
    pass_by_refrence_refrence_to_pointer(ptr);
    cout<<"Address of ptr: "<<ptr<<" & value of ptr: "<<*ptr<<endl;

    return 0;
}
