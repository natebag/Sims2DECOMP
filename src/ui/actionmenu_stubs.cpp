// actionmenu_stubs.cpp - Stub implementations for Actionmenu
// Auto-generated from symbols.json - 30 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8027F42C | 92 bytes
ActionMenu::MenuItem::MenuItem(void) { }

// 0x8027F488 | 88 bytes
ActionMenu::MenuItem::~MenuItem(void) { }

// 0x8027F4E0 | 180 bytes
void ActionMenu::MenuItem::Setup(cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, bool) { }

// 0x8027F594 | 16 bytes
void ActionMenu::MenuItem::AddItem(ActionMenu::MenuItem *) { }

// 0x8027F5A4 | 104 bytes
void ActionMenu::MenuItem::AddSubItem(ActionMenu::MenuItem *) { }

// 0x8027F60C | 24 bytes
void ActionMenu::MenuItem::GetNthItem(int) { }

// 0x8027F624 | 128 bytes
void ActionMenu::MenuItem::IsObjectInMenu(cXObject *) { }

// 0x8027F6A4 | 144 bytes
void ActionMenu::MenuItem::ClearMenu(void) { }

// 0x8027F734 | 8 bytes
void ActionMenu::MenuItem::GetNext(void) { }

// 0x8027F73C | 8 bytes
void ActionMenu::MenuItem::GetNextConst(void) const { }

// 0x8027F744 | 8 bytes
void ActionMenu::MenuItem::GetSubMenu(void) { }

// 0x8027F74C | 72 bytes
void ActionMenu::MenuItem::GetMenuItemCount(void) const { }

// 0x8027F794 | 168 bytes
ActionMenu::ActionMenu(void) { }

// 0x8027F83C | 136 bytes
ActionMenu::~ActionMenu(void) { }

// 0x8027F8C4 | 36 bytes
void ActionMenu::IsObjectInMenu(cXObject *) { }

// 0x8027F8E8 | 20 bytes
void ActionMenu::Start(HUDTarget *, int) { }

// 0x8027F8FC | 980 bytes
void ActionMenu::Draw(ERC *) { }

// 0x8027FCE4 | 184 bytes
void ActionMenu::Stop(void) { }

// 0x8027FD9C | 120 bytes
void ActionMenu::Animate(void) { }

// 0x8027FE14 | 1024 bytes
void ActionMenu::UpdateIcon(void) { }

// 0x80280214 | 428 bytes
void ActionMenu::FillInMenu(void) { }

// 0x80280648 | 304 bytes
void ActionMenu::AddMenu(cXObject *, BString2 &, unsigned int, ERShader *) { }

// 0x80280778 | 132 bytes
void ActionMenu::AddMenuItem(cXObject *, Interaction *, BString2 &, unsigned int, ERShader *, bool) { }

// 0x802807FC | 116 bytes
void ActionMenu::CompleteMenu(void) { }

// 0x80280870 | 392 bytes
void ActionMenu::ShowMenu(void) { }

// 0x802809F8 | 340 bytes
void ActionMenu::BackOutMenu(void) { }

// 0x80280B4C | 692 bytes
void ActionMenu::AcceptMenu(void) { }

// 0x80280E00 | 84 bytes
void ActionMenu::CloseMenu(void) { }

// 0x80280E54 | 364 bytes
void ActionMenu::TerminateMenu(void) { }

// 0x80280FC0 | 108 bytes
void ActionMenu::GetPlayerSim(void) const { }
