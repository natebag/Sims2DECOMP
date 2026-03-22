// wantfear_stubs.cpp - Stub implementations for Wantfear
// Auto-generated from symbols.json - 10 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x802108A0 | 516 bytes
void WantFear::Event::GetEventText(signed char, BString2 &) const { }

// 0x80211278 | 1328 bytes
void WantFear::Bookmark::GetText(BString2 &, Neighbor *, bool) const { }

// 0x802118D4 | 280 bytes
void WantFear::Bookmark::GetBaseShader(Neighbor *) const { }

// 0x80211A14 | 396 bytes
void WantFear::Bookmark::GetBackgroundShader(Neighbor *) const { }

// 0x80211BA0 | 452 bytes
void WantFear::Bookmark::SatisfiedBy(WantFear::Notification &) const { }

// 0x80211D64 | 436 bytes
void WantFear::Bookmark::IsValid(Neighbor *, bool) const { }

// 0x80211F18 | 364 bytes
void WantFear::Bookmark::IsCompleted(Neighbor *) const { }

// 0x80212084 | 644 bytes
void WantFear::Bookmark::ApplyReward(Neighbor *) { }

// 0x80212434 | 348 bytes
void WantFear::Bookmark::DoStream(ReconBuffer *, int) { }

// 0x80212590 | 204 bytes
void WantFear::Bookmark::GetDebugNotification(void) const { }
