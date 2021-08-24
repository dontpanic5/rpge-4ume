#pragma once

#include <string>
#include "LDtkLoader/thirdparty/json.hpp"

namespace rpge {

	struct DialogueLine
	{
		std::string actor;
		std::string line;
	};

	class TargetDialogue
	{
	public:
		TargetDialogue();
		TargetDialogue(const nlohmann::json& j);
		const std::string& getName() const;
	private:
		const std::string m_name;
		std::unordered_map<std::string, std::vector<DialogueLine>> m_special_dialogue;
		std::vector<std::vector<DialogueLine>> m_default_dialogue;
	};
}