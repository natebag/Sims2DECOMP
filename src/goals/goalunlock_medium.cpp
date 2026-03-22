#if 0 // SKIP
// goalunlock_medium.cpp - GoalUnlock medium functions (65-256 bytes)
// Object file: goalunlock.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "goals/goalunlock.h"

// External functions
extern "C" void* ReconBuffer_Read(void*, void*, int);
extern "C" void* ReconBuffer_Write(void*, void*, int);
extern "C" int ObjectDB_GetIndexFromGuid(int);

// Unlock slot counts per type:
// Type 0 (Objects):  32 slots
// Type 1:           208 slots
// Type 2:            24 slots
// Type 3:            32 slots (same as 0)
// Type 4:            32 slots (same as 0)
// Type 5:           128 slots

// Helper: get number of unlock slots for a type
static int GetUnlockSlotCount(int type) {
    switch (type) {
        case IGoalUnlock::kUnlockType_Objects: return 32;
        case IGoalUnlock::kUnlockType_1:       return 208;
        case IGoalUnlock::kUnlockType_2:       return 24;
        case IGoalUnlock::kUnlockType_3:       return 32;
        case IGoalUnlock::kUnlockType_4:       return 32;
        case IGoalUnlock::kUnlockType_5:       return 128;
        default: return 32;
    }
}

// ============================================================================
// GoalUnlock::DoStream
// goalunlock.obj | 0x800B84A8 | 104 bytes
// Serializes/deserializes unlock data
// ============================================================================
// NON_MATCHING: ReconBuffer codegen
void GoalUnlock::DoStream(ReconBuffer* buffer, int version) {
    if (buffer == 0) return;
    // Stream the unlock data array
    if (version >= 1) {
        // Read or write m_unlockData (128 bytes)
    }
}

// ============================================================================
// GoalUnlock::GetUnlockCount
// goalunlock.obj | 0x800B853C | 96 bytes
// Returns number of unlocked items of a given type
// ============================================================================
// NON_MATCHING: bit counting loop
int GoalUnlock::GetUnlockCount(int type) {
    int firstVar = GetFirstUnlockVar(type);
    int slotCount = GetUnlockSlotCount(type);
    int count = 0;
    for (int i = 0; i < slotCount; i++) {
        int byteIdx = (firstVar + i) / 8;
        int bitIdx = (firstVar + i) % 8;
        if (m_unlockData[byteIdx] & (1 << bitIdx)) {
            count++;
        }
    }
    return count;
}

// ============================================================================
// GoalUnlock::GetObjectIndexFromGuid
// goalunlock.obj | 0x800B86D8 | 132 bytes
// Gets the unlock index for an object by GUID
// ============================================================================
// NON_MATCHING: database lookup
int GoalUnlock::GetObjectIndexFromGuid(int guid) {
    return ObjectDB_GetIndexFromGuid(guid);
}

// ============================================================================
// GoalUnlock::GetFirstUnlockVar
// goalunlock.obj | 0x800B875C | 112 bytes
// Returns the first variable index for a given unlock type
// ============================================================================
// NON_MATCHING: switch codegen
int GoalUnlock::GetFirstUnlockVar(int type) {
    switch (type) {
        case IGoalUnlock::kUnlockType_Objects: return 0;
        case IGoalUnlock::kUnlockType_1:       return 32;
        case IGoalUnlock::kUnlockType_2:       return 240;
        case IGoalUnlock::kUnlockType_3:       return 0;  // same as Objects
        case IGoalUnlock::kUnlockType_4:       return 0;  // same as Objects
        case IGoalUnlock::kUnlockType_5:       return 264;
        default: return 0;
    }
}

// ============================================================================
// GoalUnlock::IsUnlocked
// goalunlock.obj | 0x800B87CC | 180 bytes
// Checks if a specific item is unlocked
// ============================================================================
// NON_MATCHING: bit manipulation codegen
int GoalUnlock::IsUnlocked(int type, short index) {
    int firstVar = GetFirstUnlockVar(type);
    int slotCount = GetUnlockSlotCount(type);
    if (index < 0 || index >= slotCount) return 0;
    int bitPos = firstVar + index;
    int byteIdx = bitPos / 8;
    int bitIdx = bitPos % 8;
    return (m_unlockData[byteIdx] & (1 << bitIdx)) ? 1 : 0;
}

// ============================================================================
// GoalUnlock::GrantUnlock
// goalunlock.obj | 0x800B8880 | 204 bytes
// Unlocks a specific item
// ============================================================================
// NON_MATCHING: bit set + notification
void GoalUnlock::GrantUnlock(int type, short index) {
    int firstVar = GetFirstUnlockVar(type);
    int slotCount = GetUnlockSlotCount(type);
    if (index < 0 || index >= slotCount) return;
    int bitPos = firstVar + index;
    int byteIdx = bitPos / 8;
    int bitIdx = bitPos % 8;
    m_unlockData[byteIdx] |= (1 << bitIdx);
    // Mark as recently unlocked
    SetRecentlyUnlocked(type, index, true);
}

// ============================================================================
// GoalUnlock::IsRecentlyUnlocked
// goalunlock.obj | 0x800B8A6C | 184 bytes
// Checks if an item was recently unlocked (for notification)
// ============================================================================
// NON_MATCHING: bit manipulation with offset
int GoalUnlock::IsRecentlyUnlocked(int type, short index) {
    int firstVar = GetFirstUnlockVar(type);
    int slotCount = GetUnlockSlotCount(type);
    if (index < 0 || index >= slotCount) return 0;
    // Recently unlocked bits are stored after the unlock bits
    int recentOffset = 512; // offset to recent flags
    int bitPos = recentOffset + firstVar + index;
    int byteIdx = bitPos / 8;
    int bitIdx = bitPos % 8;
    return (m_unlockData[byteIdx] & (1 << bitIdx)) ? 1 : 0;
}

// ============================================================================
// GoalUnlock::SetRecentlyUnlocked
// goalunlock.obj | 0x800B8B24 | 208 bytes
// Sets or clears the recently-unlocked flag
// ============================================================================
// NON_MATCHING: bit set/clear codegen
void GoalUnlock::SetRecentlyUnlocked(int type, short index, bool recent) {
    int firstVar = GetFirstUnlockVar(type);
    int slotCount = GetUnlockSlotCount(type);
    if (index < 0 || index >= slotCount) return;
    int recentOffset = 512;
    int bitPos = recentOffset + firstVar + index;
    int byteIdx = bitPos / 8;
    int bitIdx = bitPos % 8;
    if (recent) {
        m_unlockData[byteIdx] |= (1 << bitIdx);
    } else {
        m_unlockData[byteIdx] &= ~(1 << bitIdx);
    }
}

// ============================================================================
// GoalUnlock::GetUnlockTotal
// goalunlock.obj | 0x800B8BF4 | 148 bytes
// Returns total number of unlock slots for a type
// ============================================================================
// NON_MATCHING: switch codegen
int GoalUnlock::GetUnlockTotal(int type) {
    return GetUnlockSlotCount(type);
}
#endif
