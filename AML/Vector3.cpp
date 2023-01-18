#include "Vector3.h"
#include <cmath>
#include <iostream>


namespace AML {
	//Constructors
	Vector3::Vector3() : x(0.0), y(0.0), z(0.0){}
	Vector3::Vector3(double val) : x(val), y(val), z(val) {}
	Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
	Vector3::Vector3(const double data[3]) : x(data[0]), y(data[1]), z(data[2]) {}

	//operators
	//assignments for vector
	Vector3& Vector3::operator+=(const Vector3& rhs){
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	Vector3& Vector3::operator-=(const Vector3& rhs){
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	Vector3& Vector3::operator*=(const Vector3& rhs){
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}
	Vector3& Vector3::operator/=(const Vector3& rhs){
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	Vector3& Vector3::operator+=(double rhs){
		x += rhs;
		y += rhs;
		z += rhs;
		return *this;
	}
	Vector3& Vector3::operator-=(double rhs){
		x -= rhs;
		y -= rhs;
		z -= rhs;
		return *this;
	}
	Vector3& Vector3::operator*=(double rhs){
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}
	Vector3& Vector3::operator/=(double rhs){
		x /= rhs;
		y /= rhs;
		z /= rhs;
		return *this;
	}

	const Vector3 Vector3::xAxis(){ return Vector3(1.0, 0.0, 0.0); }
	const Vector3 Vector3::yAxis(){ return Vector3(0.0, 1.0, 0.0); }
	const Vector3 Vector3::zAxis(){ return Vector3(0.0, 0.0, 1.0); }

	// vector to vector element wise operations
	Vector3 operator-(const Vector3& rhs){ return Vector3(-rhs.x, -rhs.y, -rhs.z); }
	Vector3 operator+(const Vector3& lhs, const Vector3& rhs){ return (Vector3(lhs) += rhs); }
	Vector3 operator-(const Vector3& lhs, const Vector3& rhs){ return (Vector3(lhs) -= rhs); }
	Vector3 operator*(const Vector3& lhs, const Vector3& rhs){ return (Vector3(lhs) *= rhs); }
	Vector3 operator/(const Vector3& lhs, const Vector3& rhs){ return (Vector3(lhs) /= rhs); }

	// vector to scalar element wise operations
	Vector3 operator+(const Vector3& lhs, double rhs){ return (Vector3(lhs) += rhs); }
	Vector3 operator-(const Vector3& lhs, double rhs){ return (Vector3(lhs) -= rhs); }
	Vector3 operator*(const Vector3& lhs, double rhs){ return (Vector3(lhs) *= rhs); }
	Vector3 operator/(const Vector3& lhs, double rhs){ return (Vector3(lhs) /= rhs); }
	Vector3 operator+(double lhs, const Vector3& rhs){ return (Vector3(lhs) += rhs); }
	Vector3 operator-(double lhs, const Vector3& rhs){ return (Vector3(lhs) -= rhs); }
	Vector3 operator*(double lhs, const Vector3& rhs){ return (Vector3(lhs) *= rhs); }
	Vector3 operator/(double lhs, const Vector3& rhs){ return (Vector3(lhs) /= rhs); }

	double norm(const Vector3& v){ return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);}
	void normalize(Vector3& v){
		double mag = norm(v);
		if(mag > 0.0) v /= mag;
	}
	Vector3 unit(const Vector3& v){
		double mag = norm(v);
		if(mag > 0.0) return (Vector3(v) / mag);
		else 		  return Vector3(v);
	}
	Vector3 cross(const Vector3& lhs, const Vector3& rhs){
		double x = lhs.y * rhs.z - rhs.y * lhs.z;
		double y = -(lhs.x * rhs.z - rhs.x * lhs.z);
		double z = lhs.x * rhs.y - rhs.x * lhs.y;
		return Vector3(x, y, z);
	}
	double dot(const Vector3& lhs, const Vector3& rhs){
		return (lhs.x * rhs.x +  lhs.y * rhs.y + lhs.z * rhs.z);
	}

	std::ostream& operator<<(std::ostream& os, Vector3& v){
		std::cout << "[" << v.x << ", " << v.y << ", " << v.z << "]" << std::endl;
		return os;
	}
};