#include <iostream>
#include <string>
#include <cmath>

#include "../AML/AML.h"

using namespace AML;

int main (int argc, char **argv){
	Vector3 v1(1.0, 2.0, 3.0);
	Vector3 v2(4.0, 5.0, 6.0);
	Vector3 v3(7.0, 2.0, 3.0);

	//std::cout << v1 << std::endl;
	//std::cout << v2 << std::endl;
	//std::cout << v3 << std::endl;

	//Vector3 z = Vector3(v1);
	//Matrix33 mz = DCM::rotationAroundZ(30);
	//Matrix33 my = DCM::rotationAroundY(30);
	//Matrix33 mx = DCM::rotationAroundX(30);
	//Matrix33 m2(v1, v2, v3);
	//Matrix33 m = mx*my*mz;
	////normalizeDCM(m);

	//std::cout << determinant(m) << std::endl;
	//std::cout << m2 + m2*2.0 << std::endl;
	////normalizeDCM(m2);
	////std::cout << m2 << std::endl;
	//std::cout << m << std::endl;
	//std::cout << m2*m2 << std::endl;
	//std::cout << isValidDCM(m) << std::endl;
	//std::cout << (m*transpose(m) == Matrix33::identity()) << std::endl;

	//double data[3][3] = {
	//	{1, 0, 0}, 
	//	{0, 0.54833, 0.841453}, 
	//	{0, -0.841453, 0.54033}
	//};
	//Matrix33 m4(data);
	//std::cout << m4 << std::endl;
	//std::cout << m4*transpose(m4) << std::endl;
	//normalizeDCM(m4);
	//std::cout << m4 << std::endl;
	//std::cout << m4*transpose(m4) << std::endl;
	//std::cout << isValidDCM(m4) << std::endl;

	Matrix33 R = Matrix33::identity();
	for(int i = 0; i < 100; i++){
		Matrix33 Rdot = dcmKinematicsBodyRates(R, Vector3(1.0, 0.0, 0.0));
		R = integrateDCM(R, Rdot, 0.01);
		std::cout << R << std::endl;
	}
	std::cout << R*transpose(R)  << std::endl;
	std::cout << isValidDCM(R) << std::endl;

	//Matrix33 m1(v1, v2, v3);
	//Matrix33 m2(v2, v1, v3);
	//Matrix33 invM1 = inverse(m1);

	//std::cout << m1 << std::endl;
	//std::cout << m1*m1 << std::endl;
	//std::cout << inverse(m1) << std::endl;
	//std::cout << m1 * inverse(m1) << std::endl;

	return 0;
}