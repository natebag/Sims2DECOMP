// rooms.cpp - Room system
// Object file: rooms.obj
// Source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
//
// Compile flags: -mcpu=750 -meabi -mhard-float -O2 -fno-exceptions -fno-rtti
//                -fno-builtin -fno-optimize-sibling-calls
//                -fno-schedule-insns -fno-schedule-insns2

#include "core/rooms.h"

// Static variables
// sTheClient at 0x804FFB08 (SDA: r13 - 24088)
static RoomScoreConstants sTheClient;

// sRoomMgr at 0x804FDD64 (SDA: r13 - 31676)
RoomManager* RoomManager::sRoomMgr;

// ============================================================================
// GetRoomScoreConstantsClient
// Address: 0x801358C8
// Size: 8 bytes (0x008)
// NON_MATCHING - SN uses SDA-relative addressing (addi r3,r13,offset).
// devkitPPC uses absolute addressing (lis/addi pair with relocations).
//
// Returns pointer to static RoomScoreConstants instance.
// ============================================================================
RoomScoreConstants* GetRoomScoreConstantsClient(void) {
    return &sTheClient;
}

// ============================================================================
// RoomManager::InitLights
// Address: 0x80136FB0
// Size: 4 bytes (0x004)
// MATCHING
//
// Empty function - just blr.
// ============================================================================
void RoomManager::InitLights(void) {
}

// ============================================================================
// Room::GetArea
// Address: 0x80138358
// Size: 20 bytes (0x014)
// NON_MATCHING - SN uses srwi+add+srawi for signed /2, GCC uses srawi+addze.
// Both are correct signed division toward zero but different idioms.
//
// Returns m_tileCount / 2.
// ============================================================================
int Room::GetArea(void) {
    return m_tileCount / 2;
}

// ============================================================================
// RoomManager::GetRoomManager
// Address: 0x8013884C
// Size: 8 bytes (0x008)
// NON_MATCHING - SN uses SDA-relative (lwz r3,-31676(r13)), GCC uses
// absolute addressing (lis+lwz with relocations).
//
// Returns static sRoomMgr pointer.
// ============================================================================
RoomManager* RoomManager::GetRoomManager(void) {
    return sRoomMgr;
}

// ============================================================================
// Room::IsPool
// Address: 0x801386D4
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns m_isPool field at +0x94.
// ============================================================================
int Room::IsPool(void) {
    return m_isPool;
}

// ============================================================================
// Room::Rotate
// Address: 0x801386DC
// Size: 40 bytes (0x028)
// NON_MATCHING - SN uses subfic+beqlr, GCC uses neg+beq (different branch
// structure and rotation calculation approach).
//
// Rotates a room side enum by a number of 90-degree turns.
// Returns 0 if side is NONE (0).
// ============================================================================
Room::Sides Room::Rotate(Room::Sides side, int amount) {
    if (side == 0) {
        return (Sides)0;
    }
    return (Sides)(((side + ((4 - amount) & 3) - 1) & 3) + 1);
}

// ============================================================================
// RoomScoreConstants::RoomScoreConstants
// Address: 0x80138900
// Size: 64 bytes (0x040)
// NON_MATCHING - SN uses stmw/lmw for callee-saved registers and r30 for
// this pointer. GCC uses stw/lwz and r31. SN also emits explicit
// mr r3,r30 for return value. Different register conventions.
//
// Calls GlobalConstantsClient::GlobalConstantsClient(3), then sets vtable.
// ============================================================================
RoomScoreConstants::RoomScoreConstants(void)
    : GlobalConstantsClient(3)
{
}

// ============================================================================
// global constructors keyed to RoomManager::sRoomMgr
// Address: 0x80138940
// Size: 44 bytes (0x02C)
// NON_MATCHING - GCC generates different static init patterns than SN.
// SN calls __static_initialization_and_destruction_0(1, 0xFFFF).
// GCC generates _GLOBAL__sub_I_ functions with direct constructor calls.
// ============================================================================
