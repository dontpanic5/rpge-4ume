#pragma once
#include "LDtkLoader/Entity.hpp"
#include "BestiaryEntry.h"
#include "TargetDialogue.h"

namespace rpge {

	class Entity
	{
	public:
		Entity(const ldtk::Entity& e, int cell_size);
		Entity(const ldtk::Entity& e, int cell_size, const rpge::BestiaryEntry&);
		Entity(const ldtk::Entity& e, int cell_size, const rpge::TargetDialogue&);
		Entity(const ldtk::Entity& e, int cell_size, const rpge::BestiaryEntry&, const rpge::TargetDialogue&);

		auto GetEntity() const -> const ldtk::Entity&;
		const ldtk::FloatPoint& GetPos() const;
		void Move(float elapsedTime);

	private:
		const ldtk::Entity& m_entity;
		ldtk::FloatPoint m_pos;
		ldtk::IntPoint m_dest;

		int m_gold = 0;
		std::vector<std::string> m_items;

		const rpge::TargetDialogue& m_dialogue;

		int m_patrol_idx = 0;
		bool m_patrolling_forward = true;

		bool m_moves;

		const int m_cell_size;

		float GetLegDist();
		void SetNextDest(ldtk::ArrayField<ldtk::IntPoint> patrol);
	};

}