#include <iostream>
#include <string>
#include <cmath>

#include <AML.h>

using namespace AML;

int main (int argc, char **argv){
	Vector3 v1(1.0, 2.0, 3.0);
	Vector3 v2(4.0, 5.0, 6.0);
	Vector3 v3(7.0, 2.0, 3.0);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << dot(v1, v2) << std::endl;

	Matrix33 m1(v1, v2, v3);
	Matrix33 m2(v2, v1, v3);
	Matrix33 invM1 = inverse(m1);

	std::cout << m1 << std::endl;
	std::cout << m1*m1 << std::endl;
	std::cout << inverse(m1) << std::endl;
	std::cout << m1 * inverse(m1) << std::endl;

	return 0;
}