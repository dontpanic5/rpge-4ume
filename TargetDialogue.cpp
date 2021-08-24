#include "TargetDialogue.h"

using namespace std;
using namespace rpge;

DialogueLine makeDLine(const nlohmann::json& j)
{
	DialogueLine l;
	if (j.contains("actor"))
	{
		l.actor = j["actor"].get<string>();
	}
	l.line = j["line"].get<string>();

	return l;
}

TargetDialogue::TargetDialogue(const nlohmann::json& j) : m_name(j["name"].get<std::string>())
{
	if (j.contains("specials"))
	{
		for (const auto& j_special : j["specials"])
		{
			vector<DialogueLine> d;
			for (const auto& j_line : j_special["dialogue"])
			{
				d.push_back(makeDLine(j_line));
			}
			m_special_dialogue.insert({ j_special["condition"].get<string>(), d });
		}
	}

	for (const auto& j_default : j["defaults"])
	{
		vector<DialogueLine> v;
		for (const auto& j_dialogue : j_default)
		{
			v.push_back(makeDLine(j_dialogue));
		}
		m_default_dialogue.push_back(v);
	}
}

TargetDialogue::TargetDialogue() {}

const string& TargetDialogue::getName() const
{
	return m_name;
}