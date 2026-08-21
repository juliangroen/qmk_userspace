/* blah */

#pragma once

// =============================================================================
// Tap-Hold Configuration for Home Row Mods
// =============================================================================

// Global tapping term (ms) — time to distinguish tap from hold.
// Start at 200, tune with DT_DOWN/DT_UP once flashed.
#define TAPPING_TERM 200

// Per-key tapping term — pinkies/ring fingers get more time
#define TAPPING_TERM_PER_KEY

// Disable double-tap auto-repeat on mod-tap keys.
// Without this, tapping D then immediately holding D for Shift
// produces "ddddddd" instead of activating Shift.
#define QUICK_TAP_TERM 0

// =============================================================================
// Per-key permissive hold — only for thumb layer-taps
// =============================================================================
// Activates hold when another key is pressed AND released while held.
// Less aggressive than HOLD_ON_OTHER_KEY_PRESS — won't misfire on overlaps.
// Enabled only for thumb keys via get_permissive_hold() in keymap.c.
#define PERMISSIVE_HOLD_PER_KEY
