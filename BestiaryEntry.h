#pragma once

#include <string>
#include "LDtkLoader/thirdparty/json.hpp"

namespace rpge {

	struct ItemDrop
	{
		std::string item_name;
		unsigned int drop_chance = 0;
	};

	struct Loot
	{
		unsigned int gold_min = 0;
		unsigned int gold_max = 0;
		std::vector<ItemDrop> item_drops;
	};

	class BestiaryEntry
	{
	public:
		BestiaryEntry();
		BestiaryEntry(const nlohmann::json& j);
		const std::string& getName() const;
		const Loot& getLoot() const;
	private:
		std::string m_name;
		Loot m_loot;
	};
}