#include <gmpxx.h>
#include <gmp.h>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

mpz_class generate (mpz_class bits) {
	mpz_class a;	
	while (mpz_probab_prime_p (a.get_mpz_t(), 30) == 0) {
		gmp_randclass r1 (gmp_randinit_default);
		r1.seed(rand());
		a = r1.get_z_bits(bits);
	}
	return a;
}

mpz_class encrypt (mpz_class m, mpz_class e, mpz_class n) {
	mpz_class c;
	mpz_powm (c.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
	return c;
}

mpz_class decryot (mpz_class c, mpz_class d, mpz_class n) {
	mpz_class m;
	mpz_powm (m.get_mpz_t(), c.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
	return m;
}

int main (int argc, char *argv[]) {
	mpz_class p, q, e, d, n, phi, m, c;
	mpz_class bits;
	if ((string)argv[1] == "80") {
		bits = 1024;
	}
	else if ((string)argv[1] == "112") {
		bits = 2048;
	}
	else if ((string)argv[1] == "128") {
		bits = 3072;
	}
	else if ((string)argv[1] == "192") {
		bits = 7680;
	}
	else if ((string)argv[1] == "256") {
		bits = 15360;
	}
	else {
		cout << "Invalid Security Level." <<"\n";
		return 0;
	}


	srand(time(NULL));

	p = generate (bits / 2);
	q = generate (bits / 2);
	n = p*q;
	phi = (p-1)*(q-1);
	e = (generate (bits))%phi;
	int inv = mpz_invert (d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());


	cout << "p = " << p << "\n";
	cout << "q = " << q << "\n";
	cout << "n = " << n << "\n";
	cout << "e = " << e << "\n";
	cout << "d = " << d << "\n";

	while (1) {
		cout << "Encypt(e)/Decrypt(d)/Quit(q)?" << "\n";
		char mode;
		cin >> mode;

		if (mode == 'e') {
			cout << "Encrypt Text: " << "\n";
			cin >> m;
			c = encrypt (m, e, n);
			cout << "The ciphertext is " << c << "\n";
		}
		else if (mode == 'd') {
			cout << "Decrypt Text: " << "\n";
			cin >> c;
			m = encrypt (c, d, n);
			cout << "The plaintext is " << m << "\n";
		}
		else if (mode == 'q') {
			break;
		}
		else cout << "Invalid Input" << "\n";
	}
	
	return 0;
}
