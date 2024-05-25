#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

// Helps us dissociate a point and a direction
using Point3 = Vector3;

class Ray
{
public:
	/**
	@brief Constructor w/o parameters
	*/
	Ray()
	{

	}

	/**
	@brief Constructor w/ parameters
	*/
	Ray(const Point3& ori, const Vector3& dir)
		: origin(ori), direction(dir)
	{

	}

	/**
	@brief Retrieves origin point
	@return Ray's origin point
	*/
	inline const Point3& getOrigin() const
	{
		return origin;
	}

	/**
	@brief Retrieves direction vector
	@return Ray's direction vector
	*/
	inline const Vector3& getDirection() const
	{
		return direction;
	}

	/**
	@brief Retrieves ray's location given t
	@param t the "time"
	@return Ray's location
	*/
	inline Point3 at(double t) const
	{
		return origin + t * direction;
	}
private:
	/**
	@brief Where the ray starts

	To help differentiate between a point in space and a direction in space,
	origin uses Point3 alias for Vector3.
	*/
	Point3 origin {};
	
	/**
	@brief Which way the ray points
	*/
	Vector3 direction {};
};

#endif