// neighbor_large.cpp - Large functions (257-1024 bytes) from neighbor.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\neighbor.obj
//
// 18 large functions decompiled from neighbor.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC loop codegen (bdnz vs cmpw/blt)
//   - SDA-relative addressing
//   - Division/modulo magic constant differences

#include "types.h"

// Forward declarations
class Neighbor;
class Interests;
class ReconBuffer;
class ENeighborhoodCustomChar;

// Relationship types
typedef int tRelationshipType;

struct PersDataPair {
    int m_guid;     // +0x00
    int m_value;    // +0x04
};

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void memcpy(void* dst, const void* src, unsigned int size);
extern void memmove(void* dst, const void* src, unsigned int size);

// External relationship functions
extern int GetRelationshipLevel(int dailyRel, int lifetimeRel);
extern void* GetNeighborhoodManager();

#if 0  // Reference decompilation - not compiled

// ============================================================================
// Interests::SetInterests(short *)
// Address: 0x800C88C0 | Size: 408 bytes
// NON_MATCHING - GCC register alloc, loop unrolling
//
// Sets interest values from an array of shorts. Copies values into the
// internal interests data structure. Also validates that total interest
// points don't exceed maximum and normalizes if needed.
// ============================================================================
void Interests::SetInterests(short* values) {
    // Interest categories (up to ~18 categories)
    // Interest map at sInterestMap translates indices
    for (int i = 0; i < 18; i++) {
        int mappedIdx = (int)(unsigned char)sInterestMap[i * 3];
        if (mappedIdx >= 0) {
            short val = values[i];
            // Clamp to 0-1000 range
            if (val < 0) val = 0;
            if (val > 1000) val = 1000;
            *(short*)((char*)this + 0x70 + mappedIdx * 2) = val;
        }
    }

    // Calculate total points
    int total = 0;
    for (int i = 0; i < 18; i++) {
        int mappedIdx = (int)(unsigned char)sInterestMap[i * 3];
        if (mappedIdx >= 0) {
            total += *(short*)((char*)this + 0x70 + mappedIdx * 2);
        }
    }

    // Normalize if over maximum (typically 10000)
    int maxTotal = 10000;
    if (total > maxTotal) {
        float scale = (float)maxTotal / (float)total;
        for (int i = 0; i < 18; i++) {
            int mappedIdx = (int)(unsigned char)sInterestMap[i * 3];
            if (mappedIdx >= 0) {
                short* p = (short*)((char*)this + 0x70 + mappedIdx * 2);
                *p = (short)((float)*p * scale);
            }
        }
    }
}

// ============================================================================
// GatherRelationshipLevelValues(void)
// Address: 0x800C8B14 | Size: 308 bytes
// NON_MATCHING - GCC register alloc, SDA addressing
//
// Static function that collects relationship level boundary values from
// global configuration. Populates a lookup table used by
// CalculateRelationshipLevel for determining friend/enemy/acquaintance status.
// ============================================================================
void GatherRelationshipLevelValues() {
    // Read level thresholds from global config
    void* config = GetRelationshipConfig();
    if (config == 0) return;

    // Typically 5 levels: enemy, acquaintance, friend, good friend, best friend
    // Each level has a daily and lifetime threshold
    for (int i = 0; i < 5; i++) {
        int dailyThreshold = ReadConfigInt(config, "RelLevel_Daily", i);
        int lifetimeThreshold = ReadConfigInt(config, "RelLevel_Lifetime", i);

        // Store in static tables
        *(int*)(0x80500620 + i * 4) = dailyThreshold;
        *(int*)(0x80500634 + i * 4) = lifetimeThreshold;
    }
}

// ============================================================================
// Neighbor::operator=(Neighbor &)
// Address: 0x800C8E94 | Size: 544 bytes
// NON_MATCHING - GCC register alloc, memcpy codegen
//
// Copy assignment operator. Copies all neighbor data including relationships,
// interests, bookmarks, want/fear trees, and aspiration data. Deep copies
// dynamic allocations (relationship list, bookmarks).
// ============================================================================
Neighbor& Neighbor::operator=(Neighbor& other) {
    if (this == &other) {
        return *this;
    }

    // Copy GUID
    m_guid = other.m_guid;

    // Copy relationship data
    // This involves deep copy of relationship list
    if (m_relations != 0) {
        // Clear existing relationships
        ClearRelationships();
    }

    // Copy other's relationships
    if (other.m_relations != 0) {
        // Clone relationship list
        int* otherVtbl = *(int**)other.m_relations;
        int relCount = ((int(*)(void*))*(void**)((char*)otherVtbl + 0x08))(other.m_relations);

        for (int i = 0; i < relCount; i++) {
            int guid = 0;
            int daily = 0;
            int lifetime = 0;
            // Get relationship data by index
            GetRelationshipByIndex(other.m_relations, i, &guid, &daily, &lifetime);
            // Add to our list
            AddRelationship(guid, daily, lifetime);
        }
    }

    // Copy counts
    m_friendCount = other.m_friendCount;
    m_enemyCount = other.m_enemyCount;
    m_reputationValue = other.m_reputationValue;
    m_dirtyFlag = other.m_dirtyFlag;

    // Copy interests block
    memcpy(m_interests, other.m_interests, 0xA0);

    // Copy aspiration score
    m_aspirationScore = other.m_aspirationScore;

    // Copy remaining fields
    memcpy((char*)this + 0x28, (char*)&other + 0x28, 0x48);

    return *this;
}

// ============================================================================
// AddPersDataPair(vector<PersDataPair> &, PersDataPair &)
// Address: 0x800C90BC | Size: 432 bytes
// NON_MATCHING - GCC vector push_back codegen
//
// Adds a PersDataPair to a vector. If the vector has capacity, appends
// directly. Otherwise grows the vector (doubling capacity) and copies
// existing elements. Standard vector push_back pattern.
// ============================================================================
void AddPersDataPair(void* vec, PersDataPair& pair) {
    // vec layout: [begin, end, capacity_end] pointers to PersDataPair
    PersDataPair** pBegin = (PersDataPair**)vec;
    PersDataPair** pEnd = (PersDataPair**)((char*)vec + 4);
    PersDataPair** pCapEnd = (PersDataPair**)((char*)vec + 8);

    PersDataPair* begin = *pBegin;
    PersDataPair* end = *pEnd;
    PersDataPair* capEnd = *pCapEnd;

    if (end < capEnd) {
        // Room available - just append
        *end = pair;
        *pEnd = end + 1;
    } else {
        // Need to grow
        int oldSize = (int)(end - begin);
        int newCap = oldSize > 0 ? oldSize * 2 : 4;

        PersDataPair* newMem = (PersDataPair*)operator_new(newCap * sizeof(PersDataPair));

        // Copy existing
        if (oldSize > 0) {
            memcpy(newMem, begin, oldSize * sizeof(PersDataPair));
        }

        // Append new
        newMem[oldSize] = pair;

        // Free old
        if (begin != 0) {
            operator_delete(begin);
        }

        *pBegin = newMem;
        *pEnd = newMem + oldSize + 1;
        *pCapEnd = newMem + newCap;
    }
}

// ============================================================================
// Neighbor::DoStream(ReconBuffer *, int)
// Address: 0x800C979C | Size: 752 bytes
// NON_MATCHING - GCC register alloc, serialization codegen
//
// Serializes/deserializes all neighbor data to/from a ReconBuffer.
// Streams GUID, relationships, interests, aspiration data, bookmarks,
// want/fear trees, and personality traits.
// ============================================================================
void Neighbor::DoStream(ReconBuffer* buf, int dir) {
    if (buf == 0) return;

    // Stream GUID
    ReconBuffer_StreamInt(buf, &m_guid);

    // Stream relationship data
    int relCount = 0;
    if (dir == 1) {
        // Writing
        if (m_relations != 0) {
            int* vtbl = *(int**)m_relations;
            relCount = ((int(*)(void*))*(void**)((char*)vtbl + 0x08))(m_relations);
        }
    }
    ReconBuffer_StreamInt(buf, &relCount);

    if (dir == 0) {
        // Reading - clear and rebuild relationships
        ClearRelationships();
    }

    for (int i = 0; i < relCount; i++) {
        int guid = 0;
        int daily = 0;
        int lifetime = 0;

        if (dir == 1) {
            GetRelationshipByIndex(m_relations, i, &guid, &daily, &lifetime);
        }

        ReconBuffer_StreamInt(buf, &guid);
        ReconBuffer_StreamInt(buf, &daily);
        ReconBuffer_StreamInt(buf, &lifetime);

        if (dir == 0) {
            AddRelationship(guid, daily, lifetime);
        }
    }

    // Stream counts
    ReconBuffer_StreamShort(buf, &m_friendCount);
    ReconBuffer_StreamShort(buf, &m_enemyCount);
    ReconBuffer_StreamShort(buf, &m_reputationValue);
    ReconBuffer_StreamInt(buf, &m_dirtyFlag);

    // Stream interests
    ReconBuffer_StreamData(buf, m_interests, 0xA0);

    // Stream aspiration score
    ReconBuffer_StreamFloat(buf, &m_aspirationScore);

    // Stream bookmark and want/fear data
    // Bookmarks at +0x28 area
    ReconBuffer_StreamData(buf, (char*)this + 0x28, 0x48);

    // Stream personality traits and other persistent data
    int persVersion = 0;
    ReconBuffer_StreamInt(buf, &persVersion);

    // Stream additional persistent data based on version
    if (persVersion >= 1) {
        // Stream extended personality data
        ReconBuffer_StreamData(buf, (char*)this + 0x114, 0x40);
    }
}

// ============================================================================
// Neighbor::MakeNewActiveBookmark(unsigned int)
// Address: 0x800CBF84 | Size: 404 bytes
// NON_MATCHING - GCC register alloc, bookmark management codegen
//
// Creates a new active bookmark for want/fear tracking. Finds a free
// bookmark slot, initializes it with the given want/fear ID, and marks
// it as active.
// ============================================================================
void Neighbor::MakeNewActiveBookmark(unsigned int wantFearID) {
    // Find a free bookmark slot
    unsigned int startSlot, endSlot;
    GetBookmarkRange(false, startSlot, endSlot);

    int freeSlot = -1;
    for (unsigned int i = startSlot; i < endSlot; i++) {
        // Check if slot is free (bookmark ID == 0)
        int* bookmarkBase = (int*)((char*)this + 0x28);
        if (bookmarkBase[i] == 0) {
            freeSlot = (int)i;
            break;
        }
    }

    if (freeSlot < 0) {
        // No free slot - need to replace one
        freeSlot = (int)FindBookmarkToReplace(startSlot, endSlot);
    }

    if (freeSlot >= 0) {
        // Initialize bookmark
        int* bookmarkBase = (int*)((char*)this + 0x28);
        bookmarkBase[freeSlot] = (int)wantFearID;

        // Mark as active
        u8* activeFlags = (u8*)((char*)this + 0x50);
        activeFlags[freeSlot] = 1;
    }
}

// ============================================================================
// Neighbor::RecalculateRelationshipData(void)
// Address: 0x800C9BA8 | Size: 648 bytes
// NON_MATCHING - GCC register alloc, loop codegen
//
// Recalculates friend/enemy counts and reputation from raw relationship data.
// Iterates through all relationships, computes relationship levels, and
// updates the aggregate counts. Clears the dirty flag when done.
// ============================================================================
void Neighbor::RecalculateRelationshipData() {
    m_friendCount = 0;
    m_enemyCount = 0;
    m_reputationValue = 0;

    if (m_relations == 0) {
        m_dirtyFlag = 0;
        return;
    }

    int* vtbl = *(int**)m_relations;
    int relCount = ((int(*)(void*))*(void**)((char*)vtbl + 0x08))(m_relations);

    int totalRep = 0;
    int friendCount = 0;
    int enemyCount = 0;

    for (int i = 0; i < relCount; i++) {
        int guid = 0;
        int daily = 0;
        int lifetime = 0;
        GetRelationshipByIndex(m_relations, i, &guid, &daily, &lifetime);

        int level = GetRelationshipLevel(daily, lifetime);

        if (level >= 2) {
            // Friend or better
            friendCount++;
            totalRep += daily + lifetime;
        } else if (level <= -2) {
            // Enemy
            enemyCount++;
            totalRep += daily + lifetime;  // Negative values
        } else {
            // Acquaintance - partial reputation contribution
            totalRep += (daily + lifetime) / 4;
        }
    }

    m_friendCount = (short)friendCount;
    m_enemyCount = (short)enemyCount;

    // Calculate reputation (clamped to -100..100)
    if (relCount > 0) {
        int avgRep = totalRep / relCount;
        if (avgRep > 100) avgRep = 100;
        if (avgRep < -100) avgRep = -100;
        m_reputationValue = (short)avgRep;
    }

    m_dirtyFlag = 0;
}

// ============================================================================
// Neighbor::CountRelationshipsOfType(tRelationshipType)
// Address: 0x800CA0E8 | Size: 288 bytes
// NON_MATCHING - GCC register alloc, virtual dispatch
//
// Counts the number of relationships matching the given type (friend, enemy,
// etc.). Iterates through all relationships and checks each one's level.
// ============================================================================
int Neighbor::CountRelationshipsOfType(tRelationshipType type) {
    if (m_dirtyFlag != 0) {
        RecalculateRelationshipData();
    }

    if (m_relations == 0) {
        return 0;
    }

    int* vtbl = *(int**)m_relations;
    int relCount = ((int(*)(void*))*(void**)((char*)vtbl + 0x08))(m_relations);

    int count = 0;
    for (int i = 0; i < relCount; i++) {
        int guid = 0;
        int daily = 0;
        int lifetime = 0;
        GetRelationshipByIndex(m_relations, i, &guid, &daily, &lifetime);

        int level = GetRelationshipLevel(daily, lifetime);
        if (level == type) {
            count++;
        }
    }

    return count;
}

// ============================================================================
// Neighbor::CalculateRelationshipLevel(int, int)
// Address: 0x800C9F10 | Size: 276 bytes
// NON_MATCHING - GCC register alloc, compare chain codegen
//
// Calculates the relationship level from daily and lifetime relationship
// values. Uses threshold tables to determine the level (-3 to 3 scale).
// ============================================================================
int Neighbor::CalculateRelationshipLevel(int daily, int lifetime) {
    // Thresholds loaded from global config
    int* dailyThresholds = (int*)0x80500620;
    int* lifetimeThresholds = (int*)0x80500634;

    // Check from highest to lowest
    for (int level = 4; level >= 0; level--) {
        if (daily >= dailyThresholds[level] && lifetime >= lifetimeThresholds[level]) {
            return level - 2;  // Convert to -2..2 range
        }
    }

    // Default: no relationship
    return 0;
}

// ============================================================================
// Neighbor::LoadFromCharacter(ENeighborhoodCustomChar &)
// Address: 0x800CA604 | Size: 340 bytes
// NON_MATCHING - GCC register alloc, field copy codegen
//
// Loads neighbor data from a custom character definition. Copies personality
// traits, interests, aspiration data, and basic identity from the character
// structure into the neighbor.
// ============================================================================
void Neighbor::LoadFromCharacter(ENeighborhoodCustomChar& character) {
    // Copy GUID
    m_guid = *(int*)((char*)&character + 0x00);

    // Copy personality traits
    memcpy((char*)this + 0x28, (char*)&character + 0x10, 0x20);

    // Copy interests
    memcpy(m_interests, (char*)&character + 0x30, 0xA0);

    // Copy aspiration
    m_aspirationScore = *(float*)((char*)&character + 0xD0);

    // Initialize relationships
    m_friendCount = 0;
    m_enemyCount = 0;
    m_reputationValue = 0;
    m_dirtyFlag = 1;

    // Clear bookmarks
    memset((char*)this + 0x50, 0, 0x20);
}

// ============================================================================
// Neighbor::SaveToCharacter(ENeighborhoodCustomChar &)
// Address: 0x800CA758 | Size: 460 bytes
// NON_MATCHING - GCC register alloc, field copy codegen
//
// Saves neighbor data to a custom character definition. Reverse of
// LoadFromCharacter - copies all personality, interest, and aspiration
// data out to the character structure.
// ============================================================================
void Neighbor::SaveToCharacter(ENeighborhoodCustomChar& character) {
    // Recalculate if dirty
    if (m_dirtyFlag != 0) {
        RecalculateRelationshipData();
    }

    // Copy GUID
    *(int*)((char*)&character + 0x00) = m_guid;

    // Copy personality traits
    memcpy((char*)&character + 0x10, (char*)this + 0x28, 0x20);

    // Copy interests
    memcpy((char*)&character + 0x30, m_interests, 0xA0);

    // Copy aspiration
    *(float*)((char*)&character + 0xD0) = m_aspirationScore;

    // Copy relationship counts
    *(short*)((char*)&character + 0xD4) = m_friendCount;
    *(short*)((char*)&character + 0xD6) = m_enemyCount;
    *(short*)((char*)&character + 0xD8) = m_reputationValue;

    // Copy bookmark data
    memcpy((char*)&character + 0xE0, (char*)this + 0x50, 0x20);
}

// ============================================================================
// Neighbor::SpawnWantFearDialog(unsigned int) const
// Address: 0x800CAB20 | Size: 496 bytes
// NON_MATCHING - GCC register alloc, UI dispatch codegen
//
// Triggers the UI dialog for a want or fear event. Looks up the want/fear
// definition by ID, creates a dialog config, and dispatches through the
// APT UI system to show the notification.
// ============================================================================
void Neighbor::SpawnWantFearDialog(unsigned int wantFearID) const {
    // Look up want/fear definition
    void* wfDef = GetWantFearDef(wantFearID);
    if (wfDef == 0) return;

    // Get the dialog template based on type
    int wfType = *(int*)((char*)wfDef + 0x00);
    bool isWant = (wfType == 0);

    // Create dialog configuration
    char dialogConfig[64];
    memset(dialogConfig, 0, 64);

    // Set dialog type
    *(int*)((char*)dialogConfig + 0x00) = isWant ? 1 : 2;

    // Set text from definition
    *(int*)((char*)dialogConfig + 0x04) = *(int*)((char*)wfDef + 0x04);

    // Set icon
    *(int*)((char*)dialogConfig + 0x08) = *(int*)((char*)wfDef + 0x08);

    // Set value
    *(int*)((char*)dialogConfig + 0x0C) = *(int*)((char*)wfDef + 0x0C);

    // Get APT manager and show dialog
    void* aptMgr = GetAPTManager();
    if (aptMgr != 0) {
        ShowWantFearPopup(aptMgr, dialogConfig);
    }
}

// ============================================================================
// Neighbor::Notify(WantFear::Notification &, bool)
// Address: 0x800CAD10 | Size: 452 bytes
// NON_MATCHING - GCC register alloc, notification dispatch
//
// Processes a want/fear notification. Checks if the notification matches
// any active bookmarks. If so, updates the bookmark status and triggers
// the appropriate UI feedback (dialog, score change).
// ============================================================================
void Neighbor::Notify(void* notification, bool isPlayerAction) {
    if (notification == 0) return;

    unsigned int notifyID = *(unsigned int*)((char*)notification + 0x00);
    int notifyType = *(int*)((char*)notification + 0x04);

    // Search active bookmarks for matching want/fear
    unsigned int startSlot, endSlot;
    GetBookmarkRange(false, startSlot, endSlot);

    for (unsigned int i = startSlot; i < endSlot; i++) {
        int* bookmarkBase = (int*)((char*)this + 0x28);
        unsigned int bookmarkID = (unsigned int)bookmarkBase[i];

        if (bookmarkID == 0) continue;

        // Check if notification matches this bookmark
        if (bookmarkID == notifyID) {
            // Match found - process completion
            u8* activeFlags = (u8*)((char*)this + 0x50);

            if (activeFlags[i] == 1) {
                // Bookmark was active
                activeFlags[i] = 2;  // Mark as completed

                // Update aspiration score
                void* wfDef = GetWantFearDef(notifyID);
                if (wfDef != 0) {
                    int scoreChange = *(int*)((char*)wfDef + 0x0C);
                    m_aspirationScore += (float)scoreChange;
                }

                // Show dialog if this is a player-visible event
                if (isPlayerAction) {
                    SpawnWantFearDialog(notifyID);
                }

                // Advance to next bookmark
                AdvanceBookmark(i);
            }
            break;
        }
    }
}

// ============================================================================
// Neighbor::AdvanceBookmark(unsigned int)
// Address: 0x800CB32C | Size: 356 bytes
// NON_MATCHING - GCC register alloc, tree traversal codegen
//
// Advances a bookmark to the next want/fear in the tree. Finds the next
// node in the want/fear tree and updates the bookmark slot.
// ============================================================================
void Neighbor::AdvanceBookmark(unsigned int slot) {
    int* bookmarkBase = (int*)((char*)this + 0x28);
    unsigned int currentID = (unsigned int)bookmarkBase[slot];

    if (currentID == 0) return;

    // Get the want/fear tree
    void* wfTree = GetWantFearTree();
    if (wfTree == 0) {
        // No tree - clear bookmark
        bookmarkBase[slot] = 0;
        u8* activeFlags = (u8*)((char*)this + 0x50);
        activeFlags[slot] = 0;
        return;
    }

    // Find next node in tree
    void* nextNode = GetNextWantFearNode(wfTree, currentID);
    if (nextNode != 0) {
        unsigned int nextID = *(unsigned int*)((char*)nextNode + 0x00);
        bookmarkBase[slot] = (int)nextID;
        u8* activeFlags = (u8*)((char*)this + 0x50);
        activeFlags[slot] = 1;  // Mark as active
    } else {
        // End of tree branch - try to select a new inactive bookmark
        bookmarkBase[slot] = 0;
        u8* activeFlags = (u8*)((char*)this + 0x50);
        activeFlags[slot] = 0;
        SelectInactiveBookmark(true, false);
    }
}

// ============================================================================
// Neighbor::ForceNewTree(unsigned short)
// Address: 0x800CAF58 | Size: 888 bytes
// NON_MATCHING - GCC register alloc, tree building codegen
//
// Forces a new want/fear tree to be generated for the neighbor. Clears
// all existing bookmarks and trees, then generates a new tree based on
// the given aspiration type. Populates initial bookmarks from the new tree.
// ============================================================================
void Neighbor::ForceNewTree(unsigned short aspirationType) {
    // Clear all existing bookmarks
    unsigned int startSlot, endSlot;
    GetBookmarkRange(false, startSlot, endSlot);

    int* bookmarkBase = (int*)((char*)this + 0x28);
    u8* activeFlags = (u8*)((char*)this + 0x50);

    for (unsigned int i = startSlot; i < endSlot; i++) {
        bookmarkBase[i] = 0;
        activeFlags[i] = 0;
    }

    // Clear existing tree
    void* oldTree = GetWantFearTree();
    if (oldTree != 0) {
        DestroyWantFearTree(oldTree);
        SetWantFearTree(0);
    }

    // Generate new tree based on aspiration type
    void* newTree = CreateWantFearTree(aspirationType);
    if (newTree == 0) return;

    SetWantFearTree(newTree);

    // Populate initial bookmarks from tree root nodes
    int numRoots = GetTreeRootCount(newTree);
    int slotsAvailable = (int)(endSlot - startSlot);
    int slotsToFill = numRoots < slotsAvailable ? numRoots : slotsAvailable;

    for (int i = 0; i < slotsToFill; i++) {
        void* rootNode = GetTreeRootNode(newTree, i);
        if (rootNode != 0) {
            unsigned int nodeID = *(unsigned int*)((char*)rootNode + 0x00);
            bookmarkBase[startSlot + i] = (int)nodeID;
            activeFlags[startSlot + i] = 1;
        }
    }

    // If there are empty slots, try to fill from deeper in the tree
    for (unsigned int i = startSlot + slotsToFill; i < endSlot; i++) {
        SelectInactiveBookmark(false, false);
    }
}

// ============================================================================
// Neighbor::FindBookmarkToReplace(unsigned int, unsigned int)
// Address: 0x800CB4E8 | Size: 268 bytes
// NON_MATCHING - GCC register alloc, scoring codegen
//
// Finds the best bookmark slot to replace when all slots are full.
// Scores each bookmark based on age and completion status, then returns
// the slot with the lowest score (least important to keep).
// ============================================================================
int Neighbor::FindBookmarkToReplace(unsigned int startSlot, unsigned int endSlot) {
    int bestSlot = -1;
    int bestScore = 0x7FFFFFFF;  // Max int

    int* bookmarkBase = (int*)((char*)this + 0x28);
    u8* activeFlags = (u8*)((char*)this + 0x50);

    for (unsigned int i = startSlot; i < endSlot; i++) {
        int bookmarkID = bookmarkBase[i];
        if (bookmarkID == 0) {
            // Empty slot - use it immediately
            return (int)i;
        }

        // Score based on priority
        int score = 0;

        // Completed bookmarks have lowest priority
        if (activeFlags[i] == 2) {
            score = 0;
        } else if (activeFlags[i] == 0) {
            // Inactive
            score = 100;
        } else {
            // Active - higher priority
            score = 1000;

            // Adjust by want/fear value
            void* wfDef = GetWantFearDef((unsigned int)bookmarkID);
            if (wfDef != 0) {
                int value = *(int*)((char*)wfDef + 0x0C);
                score += (value > 0 ? value : -value);
            }
        }

        if (score < bestScore) {
            bestScore = score;
            bestSlot = (int)i;
        }
    }

    return bestSlot;
}

// ============================================================================
// Neighbor::SelectInactiveBookmark(bool, bool)
// Address: 0x800CC118 | Size: 616 bytes
// NON_MATCHING - GCC register alloc, tree traversal codegen
//
// Selects a new inactive bookmark from the want/fear tree. Walks the tree
// looking for nodes that aren't already assigned to any bookmark slot.
// If forceNew is true, picks a random eligible node. If showDialog is true,
// shows the dialog for the newly selected want/fear.
// ============================================================================
void Neighbor::SelectInactiveBookmark(bool forceNew, bool showDialog) {
    void* wfTree = GetWantFearTree();
    if (wfTree == 0) return;

    unsigned int startSlot, endSlot;
    GetBookmarkRange(false, startSlot, endSlot);

    int* bookmarkBase = (int*)((char*)this + 0x28);
    u8* activeFlags = (u8*)((char*)this + 0x50);

    // Find a free slot
    int freeSlot = -1;
    for (unsigned int i = startSlot; i < endSlot; i++) {
        if (bookmarkBase[i] == 0) {
            freeSlot = (int)i;
            break;
        }
    }

    if (freeSlot < 0 && !forceNew) {
        return;  // No free slot
    }

    if (freeSlot < 0) {
        freeSlot = FindBookmarkToReplace(startSlot, endSlot);
    }

    if (freeSlot < 0) return;

    // Walk tree to find unused node
    int nodeCount = GetTreeNodeCount(wfTree);
    for (int i = 0; i < nodeCount; i++) {
        void* node = GetTreeNodeByIndex(wfTree, i);
        if (node == 0) continue;

        unsigned int nodeID = *(unsigned int*)((char*)node + 0x00);

        // Check if already bookmarked
        bool alreadyUsed = false;
        for (unsigned int j = startSlot; j < endSlot; j++) {
            if ((unsigned int)bookmarkBase[j] == nodeID) {
                alreadyUsed = true;
                break;
            }
        }

        if (!alreadyUsed) {
            // Found unused node - assign it
            bookmarkBase[freeSlot] = (int)nodeID;
            activeFlags[freeSlot] = 1;

            if (showDialog) {
                SpawnWantFearDialog(nodeID);
            }
            return;
        }
    }

    // No unused nodes found - clear the slot
    bookmarkBase[freeSlot] = 0;
    activeFlags[freeSlot] = 0;
}

// ============================================================================
// vector<PersDataPair, allocator<PersDataPair> >::reserve(unsigned int)
// Address: 0x803A50A0 | Size: 360 bytes
// NON_MATCHING - GCC STL vector reserve implementation
//
// Standard STL vector::reserve - ensures capacity for at least n elements.
// If current capacity is less than n, allocates new storage, copies
// existing elements, and frees old storage.
// ============================================================================
void vector_PersDataPair_reserve(void* vec, unsigned int newCap) {
    PersDataPair** pBegin = (PersDataPair**)vec;
    PersDataPair** pEnd = (PersDataPair**)((char*)vec + 4);
    PersDataPair** pCapEnd = (PersDataPair**)((char*)vec + 8);

    PersDataPair* begin = *pBegin;
    PersDataPair* capEnd = *pCapEnd;

    unsigned int currentCap = (unsigned int)(capEnd - begin);
    if (newCap <= currentCap) {
        return;  // Already enough capacity
    }

    PersDataPair* end = *pEnd;
    int currentSize = (int)(end - begin);

    // Allocate new storage
    PersDataPair* newMem = (PersDataPair*)operator_new(newCap * sizeof(PersDataPair));

    // Copy existing elements
    if (currentSize > 0) {
        memcpy(newMem, begin, currentSize * sizeof(PersDataPair));
    }

    // Free old storage
    if (begin != 0) {
        operator_delete(begin);
    }

    // Update pointers
    *pBegin = newMem;
    *pEnd = newMem + currentSize;
    *pCapEnd = newMem + newCap;
}

#endif // Reference decompilation
