#pragma once

#include <fstream>

#include "pch.h"
#include "LDtkLoader/Entity.hpp"

template<typename T>
ldtk::Point<T> TransformByPivot(const ldtk::FloatPoint& pivot, const ldtk::Point<T>& cur_pos, const int size_x, const int size_y)
{
	return ldtk::Point<T>(
		static_cast<T>(cur_pos.x + pivot.x * size_x),
		static_cast<T>(cur_pos.y + pivot.y * size_y)
	);
}

template<typename T>
std::unordered_map<std::string, T> GetFromJson(const std::string& filepath)
{
	std::ifstream in(filepath);
	if (in.fail())
		throw std::invalid_argument("Failed to open file \"" + filepath + "\" : " + strerror(errno));
	nlohmann::json j;
	in >> j;

	std::unordered_map<std::string, T> m;
	for (const auto& t : j)
	{
		auto n = T(t);
		m.emplace(n.getName(), n);
	}

	return m;
}