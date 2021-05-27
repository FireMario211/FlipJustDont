#pragma once
#include "pch.h"

namespace PlayLayer {
	inline bool(__thiscall* init)(gd::PlayLayer* self, void* level);
	bool __fastcall hook(gd::PlayLayer* self, int, void* level);
}
