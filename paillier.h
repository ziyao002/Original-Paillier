#include <NTL/ZZ.h>
#include <NTL/ZZ_pXFactoring.h>

class Paillier {
    public:

    Paillier(const long keyLength);
	
    NTL::ZZ encrypt(const NTL::ZZ& message); 
    NTL::ZZ decrypt(const NTL::ZZ& ciphertext); 
	
	NTL::ZZ add(NTL::ZZ& x, NTL::ZZ& y);
	NTL::ZZ mul(NTL::ZZ& x, NTL::ZZ& y);
	
	NTL::ZZ modulus;
	NTL::ZZ generator;
	
    private:

    NTL::ZZ p, q;
	NTL::ZZ lambda;
	NTL::ZZ lambda_power;
    NTL::ZZ u;

    NTL::ZZ L_function(const NTL::ZZ& n) { return (n - 1) / modulus; }
};

