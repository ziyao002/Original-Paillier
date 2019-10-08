#include <iostream>
#include <stdlib.h>
#include "paillier.h"

using namespace std;
using namespace NTL;

int main()
{
	Paillier paillier(512);											// generates paillier parameters from scrach
	
	ZZ m1, m2, c1, c2, sum, product, dec_sum, dec_product;
    m1 = 987354;													// plaintext m1, m2
    m2 = 1236758;

    c1 = paillier.encrypt(m1);										// ciphertext c1 = encryption(m1)
	c2 = paillier.encrypt(m2);										// ciphertext c2 = encryption(m2)
	
	sum = paillier.add(c1, c2);										// Paillier addition: sum = encryption(m1 + m2)
	product = paillier.mul(c1, m2);									// Paillier multiplication: product = encryption(m1 * m2)
	
    dec_sum = paillier.decrypt(sum);								// dec_sum = decryption(sum)
	dec_product = paillier.decrypt(product);						// dec_product = decryption(product))

    if (dec_sum == ((m1 + m2) % paillier.modulus)){
        cout << "Homomorphic addition is successful" << endl;
    }
	
	if (dec_product == (m1 * m2 % paillier.modulus)){
        cout << "Homomorphic multiplication is successful" << endl;
    }

    return 0;
}