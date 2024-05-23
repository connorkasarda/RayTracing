#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3
{
public:
	/**
	@brief Constructor w/o initial values
	*/
	Vector3() : coords{ 0.0, 0.0, 0.0 }
	{

	}

	/**
	@brief Constructor w/ initial values
	*/
	Vector3(double c0, double c1, double c2) : coords{ c0, c1, c2 }
	{

	}

	/**
	@brief Destructor set to default
	*/
	~Vector3() = default;
	
	/**
	@brief Retrieves value of x or coords[0]
	@return x value
	*/
	inline double x() const
	{
		return coords[0];
	}

	/**
	@brief Retrieves value of y or coords[1]
	@return y value
	*/
	inline double y() const
	{
		return coords[1];
	}

	/**
	@brief Retrieves value of z or coords[2]
	@return z value
	*/
	inline double z() const
	{
		return coords[2];
	}

	/**
	@brief Accesses component of Vector3 for read-only
	@return Component value
	*/
	inline double operator[](int i) const
	{
		return coords[i];
	}

	/**
	@brief Accesses component of Vector3 for modifications
	@return Component reference
	*/
	inline double& operator[](int i)
	{
		return coords[i];
	}

	/**
	@brief Adds Vector3s and assigns to this
	@return Updated Vector3 from add & assign
	*/
	inline Vector3& operator+=(const Vector3& rhs)
	{
		coords[0] += rhs.coords[0];
		coords[1] += rhs.coords[1];
		coords[2] += rhs.coords[2];
		return *this;
	}

	/**
	@brief Multiplies Vector3s and assigns to this
	@return Updated Vector3 from multiply & assign
	*/
	inline Vector3& operator*=(const Vector3& rhs)
	{
		coords[0] *= rhs.coords[0];
		coords[1] *= rhs.coords[1];
		coords[2] *= rhs.coords[2];
		return *this;
	}

	/**
	@brief Multiplies Vector3 and scalar and assigns to this
	@return Updated Vector3 from multiply & assign
	*/
	inline Vector3& operator*=(double rhs)
	{
		coords[0] *= rhs;
		coords[1] *= rhs;
		coords[2] *= rhs;
		return *this;
	}

	/**
	@brief Divides Vector3 by scalar and assigns to this
	@return Updated Vector3 from divide & assign
	*/
	inline Vector3& operator/=(double rhs)
	{
		coords[0] /= rhs;
		coords[1] /= rhs;
		coords[2] /= rhs;
		return *this;
	}

	/**
	@brief Returns magntitude of Vector3
	@return Magnitude or length of Vector3
	*/
	inline double length() const
	{
		return std::sqrt(
			coords[0] * coords[0] +
			coords[1] * coords[1] +
			coords[2] * coords[2]
		);
	}

private:
	/**
	@brief Stores the x, y, z values of the Vector 3 compactly
	*/
	double coords[3] {};
};

/**
@brief Adds 2 Vector3s
@return resultant Vector3 from addition
*/
inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(
		lhs.x() + rhs.x(),
		lhs.y() + rhs.y(),
		lhs.z() + rhs.z()
	);
}

/**
@brief Subs 2 Vector3s
@return resultant Vector3 from subtraction
*/
inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(
		lhs.x() - rhs.x(),
		lhs.y() - rhs.y(),
		lhs.z() - rhs.z()
	);
}

/**
@brief Multiplies Vector3s
@return resultant Vector3 from multiplication
*/
inline Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(
		lhs.x() * rhs.x(),
		lhs.y() * rhs.y(),
		lhs.z() * rhs.z()
	);
}

/**
@brief Multiplies Vector3 by scalar
@return resultant Vector3 from multiplication
*/
inline Vector3 operator*(const Vector3& lhs, double rhs)
{
	return Vector3(
		lhs.x() * rhs,
		lhs.y() * rhs,
		lhs.z() * rhs
	);
}

/**
@brief Multiplies scalar by Vector3
@return resultant Vector3 from multiplication
*/
inline Vector3 operator*(double lhs, const Vector3& rhs)
{
	return Vector3(
		lhs * rhs.x(),
		lhs * rhs.y(),
		lhs * rhs.z()
	);
}

/**
@brief Dot product of Vector3s
@return resultant double from dot product
*/
inline double dot(const Vector3& lhs, const Vector3& rhs)
{
	return lhs.x() * rhs.x() +
		lhs.y() * rhs.y() +
		lhs.z() * rhs.z();
}

/**
@brief Cross product of Vector3s
@reutrn resultant Vector3 from cross product
*/
inline Vector3 cross(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(
		lhs.y() * rhs.z() - lhs.z() * rhs.y(),
		lhs.z() * rhs.x() - lhs.x() * rhs.z(),
		lhs.x() * rhs.y() - lhs.y() * rhs.x()
	);
}

/**
@brief Divides Vector3 by scalar
@return resultant Vector3 from division
*/
inline Vector3 operator/(const Vector3& lhs, double rhs)
{
	return Vector3(
		lhs.x() / rhs,
		lhs.y() / rhs,
		lhs.z() / rhs
	);
}

#endif