#include <iostream>
using namespace std;

/*
Hash tabel is like an array

- Hashing function return a key
- The key is then inserted in a
    key search function to retreive 
    the index of the data in the array


Methods for hashing
    1. k mod 10
    2. k mod n
    3. folding method
    4. mid square

Collision resolution techniques
1. Chaning: open hashing
    When there is duplication, then we use link lists:
        - Store pointer in the hashtable
        - Those pointers are heads to a link list
        - Inserting: best way is to iplement a stack insertion method
        
2. Probing: closed hashing
    i.      linear: if the space is filled the move on to the 
                    next index and repeat the process until 
                    an empty slot is found. 
                    loop ((h(k) + i) mod n) until empty.

                    searching is done:
                        loop ((h(k) + i) mod n):
                            if slots is empty : value does not exists
                            elif search value == array[index]: return index
                            else: move onwards
                    
                    primary and secondary cluster
                        - primary cluster: probality of a slot being filled
                        - secondary cluster: identifying the searching trend

    ii.     quadratic: 
    iii.    double
*/