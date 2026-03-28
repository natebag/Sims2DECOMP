#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "types.h"

// Forward declarations
class Neighbor;
class ReconBuffer;
class StringBuffer2;
class Family;

// ============================================================================
// PersistentDataField - Field descriptor for persistent data
// ============================================================================
struct PersistentDataField {
    int m_offset;   // +0x00
    int m_size;     // +0x04
};

// ============================================================================
// Interests - Interest system for Sims
// ============================================================================
class Interests {
public:
    // Static initializer called from neighbor.obj
    static void InitInterestMap();
    static void DestroyInterestMap();

    static char sInterestMap[56]; // at 0x804240f0, 56 bytes
    static float kInterestCutoffs[2]; // at 0x80500614
};

// ============================================================================
// RelationList - List of relationships (vtable-dispatched)
// ============================================================================
class RelationList {
public:
    void* m_vtable; // +0x00 - vtable pointer
    // ... additional fields
};

// ============================================================================
// ObjSelector - Object selection helper
// ============================================================================
class ObjSelector {
public:
    // +0x8C: sim description pointer
    void* GetSimDescription() const;
};

// ============================================================================
// WantFear::Tree - Want/Fear tree
// ============================================================================
namespace WantFear {
    class Tree {
    public:
        // +0x28: nodes array pointer
        void* GetNodeById(short id) const;
    };
}

// ============================================================================
// Neighbor - Represents a sim neighbor
// Offset layout (from disassembly):
//   +0x04: GUID (int) - via lha at +4 in GetGUID variant
//   +0x08: GUID (int)
//   +0x10: relations (RelationList*)
//   +0x1C: friend count (short)
//   +0x1E: enemy count (short)
//   +0x20: reputation value (short)
//   +0x24: dirty flag (int) - if non-zero, calls recalculate
//   +0x70: interests data (starts here, size 0x70-based)
//   +0x110: aspiration score (float)
// ============================================================================
class Neighbor {
public:
    void* m_vtable;              // +0x00
    int m_pad04;                 // +0x04
    int m_guid;                  // +0x08
    int m_pad0C;                 // +0x0C
    RelationList* m_relations;   // +0x10
    char m_pad14[8];             // +0x14
    short m_friendCount;         // +0x1C
    short m_enemyCount;          // +0x1E
    short m_reputationValue;     // +0x20
    short m_pad22;               // +0x22
    int m_dirtyFlag;             // +0x24
    char m_pad28[0x48];          // +0x28
    char m_interests[0xA0];      // +0x70 (Interests data)
    float m_aspirationScore;     // +0x110

    // Getters/Setters
    RelationList* GetRelations() const;
    int GetGUID();
    void SetGUID(int guid);
    short GetFriendCount();
    short GetEnemyCount();
    short GetReputationValue();
    int GetRelationship(Neighbor* other, int* outValue);
    void RemoveAllRelationships();
    float GetAspirationScore();
    void SetAspirationScore(float score);
    void ResetInterests();

    // Slot/bookmark ranges
    void GetSlotRange(bool isPlayer2, unsigned int& outStart, unsigned int& outEnd);
    void GetBookmarkRange(bool isPlayer2, unsigned int& outStart, unsigned int& outEnd);

    // Persistent data
    static PersistentDataField* GetPersistentDataFieldsByIndex(int index);
    static int GetLatestPersDataVersion();

private:
    // Internal recalculation
    void RecalculateRelationshipCounts();
    int GetRelationshipByGUID(int guid);
};

#endif // NEIGHBOR_H
