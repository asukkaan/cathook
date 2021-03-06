/*
  Created by Jenny White on 29.04.18.
  Copyright (c) 2018 nullworks. All rights reserved.
*/

#pragma once

#include <settings/Bool.hpp>
#include "common.hpp"

// This is a temporary file to put code that needs moving/refactoring in.
extern bool *bSendPackets;
extern std::array<int, 32> bruteint;
extern std::array<Timer, 32> timers;

extern Timer DelayTimer;
extern bool firstcm;

extern bool calculated_can_shoot;
extern float prevflow;
extern int prevflowticks;
#if ENABLE_VISUALS
extern int spectator_target;
extern CLC_VoiceData *voicecrash;
#endif

extern settings::Bool clean_screenshots;
extern settings::Bool crypt_chat;
extern settings::Bool nolerp;
extern settings::Bool no_zoom;
extern settings::Bool disable_visuals;
extern settings::Int print_r;
extern settings::Int print_g;
extern settings::Int print_b;
extern int stored_buttons;
extern settings::Bool null_graphics;
#if ENABLE_VISUALS
extern bool freecam_is_toggled;
#endif
