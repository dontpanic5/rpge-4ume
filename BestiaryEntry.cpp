#include "BestiaryEntry.h"

using namespace std;
using namespace rpge;

BestiaryEntry::BestiaryEntry(const nlohmann::json& j) : m_name(j["name"].get<std::string>())
{
	const auto& j_loot = j["loot"];
	if (!j_loot.is_null())
	{
		m_loot.gold_max = j_loot["gold_max"].get<unsigned int>();
		m_loot.gold_min = j_loot["gold_min"].get<unsigned int>();
		const auto& j_items = j_loot["item_drops"];
		if (!j_items.is_null())
		{
			for (auto& item : j_items)
			{
				ItemDrop i;
				i.item_name = item["item_name"].get<string>();
				i.drop_chance = item["drop_chance"].get<unsigned int>();
				m_loot.item_drops.push_back(i);
			}
		}
	}
}

string BestiaryEntry::getName()
{
	return m_name;
}

Loot BestiaryEntry::getLoot()
{
	return m_loot;
}