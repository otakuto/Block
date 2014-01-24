#pragma once
#include "stdafx.hpp"

template<typename ContainerA, typename ContainerB>
class CollisionManager
{
public:
	using Detector = std::function<bool(typename ContainerA::value_type const &valueA, typename ContainerB::value_type const &valueB)>;
	using Collision = std::function<void(typename ContainerA::value_type &valueA, typename ContainerB::value_type &valueB)>;

public:
	CollisionManager(ContainerA &containerA, ContainerB &containerB, Detector detector, Collision collision)
		:
		containerA(containerA),
		containerB(containerB),
		detector(detector),
		collision(collision)
	{
	}

	~CollisionManager()
	{
	}

public:
	void Detection()
	{
		if (containerA.size() < containerB.size())
		{
			for (auto &valueA : containerA)
			{
				for (auto &valueB : containerB)
				{
					if (detector(valueA, valueB))
					{
						collision(valueA, valueB);
					}
				}
			}
		}
		else
		{
			for (auto &valueB : containerB)
			{
				for (auto &valueA : containerA)
				{
					if (detector(valueA, valueB))
					{
						collision(valueA, valueB);
					}
				}
			}
		}
	}

protected:
	ContainerA &containerA;
	ContainerB &containerB;
	Detector detector;
	Collision collision;
};

