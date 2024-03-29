#ifndef EULER_ANGLES_H
#define EULER_ANGLES_H

#include "Matrix33.h"
#include <iostream>

namespace AML {
	//class is extensible for other sequence of rotations but for now I just used the xyz representation
	class EulerAngles {
	public:
		enum class EulerSequence { ZXZ, XYX, YZY, ZYZ, XZX, YXY, XYZ, YZX, ZXY, XZY, ZYX, YXZ };
		union {
			double data[3];
			struct {
				double phi, theta, psi;
			};
		};
	private:
		EulerSequence seq;

	public:
		EulerAngles();
		EulerAngles(double phi, double theta, double psi, EulerSequence seq = EulerSequence::XYZ);

		EulerSequence getEulerSequence() const { return seq; }

	};
	
	std::ostream& operator<<(std::ostream& os, const EulerAngles &angles);

	Matrix33 euler2DCM(const EulerAngles &angles);
	Matrix33 euler2DCM_XYZ(const EulerAngles &angles);
	EulerAngles dcm2EulerAngles(const Matrix33 &dcm, const EulerAngles::EulerSequence seq = EulerAngles::EulerSequence::XYZ);
	EulerAngles dcm2EulerAngles_XYZ(const Matrix33 &dcm);
	EulerAngles eulerAnglesKinematics(const EulerAngles &angles, const Vector3 &bodyRates);					//w_b is the gyro reading also called body rates
	Matrix33 eulerRatesMatrix_E_XYZ(const EulerAngles &angles);
	EulerAngles integrateEulerAngles(const EulerAngles &angles, const EulerAngles &rates, double dt);
	EulerAngles interpolate(const EulerAngles &startAngles, const EulerAngles &endAngles, double t);

}


#endif