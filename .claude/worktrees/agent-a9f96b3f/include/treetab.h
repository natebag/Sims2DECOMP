#ifndef TREETAB_H
#define TREETAB_H

#include "types.h"

// Forward declarations
class ITreeTableAd;

// Minimal ITreeTableEntry forward with Attenuation enum
class ITreeTableEntry {
public:
    enum Attenuation {
        ATTENUATION_NONE = 0,
        ATTENUATION_LOW = 1,
        ATTENUATION_MEDIUM = 2,
        ATTENUATION_HIGH = 3,
        ATTENUATION_CUSTOM = 4
    };
};
class BString2;

// TreeTableEntry - an entry in the original TreeTable (read-only, from resource)
// Layout: 36-byte (0x24) entries stored in a counted array
// The count is stored as an int at entries[-1] (4 bytes before the array)
struct TreeTableEntry {
    short m_checkTreeID;           // +0x00
    short m_actionTreeID;          // +0x02
    int   m_adsPtr;                // +0x04 - pointer to ads array
    float m_customAttenuationValue;// +0x08
    int   m_pad0C;                 // +0x0C
    int   m_flags;                 // +0x10 - flags bitfield (32-bit in QuickData)
    short m_index;                 // +0x14
    short m_autonomyThreshold;     // +0x16
    short m_joinIndex;             // +0x18
    short m_orderIndex;            // +0x1A
    int   m_namePtr;               // +0x1C - pointer to name structure
    int   m_activationData;        // +0x20 - packed activation subtile/extents
};

// TreeTable - the main tree table, holds a dynamic array of entries
class TreeTable {
public:
    TreeTableEntry* m_pEntries; // +0x00 - pointer to entry array
    // Additional fields (short ID at +4, short motiveAdCount at +6, etc.)

    const TreeTableEntry* GetNthEntry(int n) const;
    int GetIndexOfResource(short resourceID) const;
    int GetIndexByTreeID(short checkID, short actionID) const;
    int GetIndexOfNthOrderedEntry(int n) const;
};

// TreeTableAdScratch - scratch copy of a TreeTableAd (mutable)
// Has vtable at +0x00
class TreeTableAdScratch {
public:
    void* __vtable;        // +0x00
    short m_personalityAd; // +0x04
    short m_min;           // +0x06
    short m_range;         // +0x08
    short m_pad;           // +0x0A
    int   m_refCount;      // +0x0C
    // Total: 0x10 (16 bytes)

    TreeTableAdScratch();
    ~TreeTableAdScratch();

    int QueryInterface(unsigned int iid, void** ppv);
    int AddRef();
    int Release();

    int GetPersonalityAd() const;
    void SetPersonalityAd(int val);
    int GetMin() const;
    void SetMin(int val);
    int GetMax() const;
    void SetMax(int val);
    int GetRange() const;
    void SetRange(int val);

    TreeTableAdScratch& operator=(ITreeTableAd& other);
};

// A single ad within TTabScratchEntry (inlined in the ads array)
// Same layout as TreeTableAdScratch - 16 bytes each
struct TTabScratchAd {
    void* __vtable;        // +0x00
    short m_personalityAd; // +0x04
    short m_min;           // +0x06
    short m_range;         // +0x08
    short m_pad;           // +0x0A
    int   m_refCount;      // +0x0C
};

// TTabScratchEntry - scratch/mutable copy of a TreeTableEntry
// Has vtable at +0x00
// Total size: 0x11C (284 bytes)
class TTabScratchEntry {
public:
    void* __vtable;                 // +0x00
    short m_checkTreeID;            // +0x04
    short m_actionTreeID;           // +0x06
    TTabScratchAd m_ads[16];        // +0x08 (each 16 bytes = 256 total, to +0x108)
    int   m_attenuation;            // +0x108 (264)
    float m_customAttenuationValue; // +0x10C (268)
    short m_flags;                  // +0x110 (272)
    short m_index;                  // +0x112 (274)
    short m_autonomyThreshold;      // +0x114 (276)
    short m_joinIndex;              // +0x116 (278)
    int   m_refCount;               // +0x118 (280)

    TTabScratchEntry();
    ~TTabScratchEntry();

    void CopyFrom(ITreeTableEntry* src);

    int QueryInterface(unsigned int iid, void** ppv);
    int AddRef();
    int Release();

    // Getters/Setters
    short GetIndex() const;
    bool GetAvailableToVisitors() const;
    void SetAvailableToVisitors(bool val);
    bool GetCanJoin() const;
    void SetCanJoin(bool val);
    bool GetImmediate() const;
    void SetImmediate(bool val);
    bool GetAllowConsecutive() const;
    void SetAllowConsecutive(bool val);
    bool GetAvailableToGhosts() const;
    void SetAvailableToGhosts(bool val);
    bool GetAvailableToAdults() const;
    void SetAvailableToAdults(bool val);
    bool GetAvailableToChildrenDemo() const;
    void SetAvailableToChildrenDemo(bool val);
    bool GetAvailableToVisitingPlayers() const;
    void SetAvailableToVisitingPlayers(bool val);
    short GetJoinIndex() const;
    void SetJoinIndex(int val);
    bool GetDebugOnly() const;
    void SetDebugOnly(bool val);
    bool GetAutoFirstSelect() const;
    void SetAutoFirstSelect(bool val);
    bool GetIgnorePrefixTree() const;
    void SetIgnorePrefixTree(bool val);
    bool GetMustRun() const;
    void SetMustRun(bool val);
    bool GetManualOnly() const;
    int CountAds() const;
    short* GetRangeRef(int idx) const;
    short* GetMinRef(int idx) const;
    short* GetPersonalityVarRef(int idx) const;
    short* GetRangeRef(int idx);
    short* GetMinRef(int idx);
    short* GetPersonalityVarRef(int idx);
    const TTabScratchAd* GetAd(int idx) const;
    TTabScratchAd* GetAd(int idx);
    void SetAd(int idx, ITreeTableAd& ad);
    short GetActionTreeID() const;
    void SetActionTreeID(short val);
    short GetCheckTreeID() const;
    void SetCheckTreeID(short val);
    int GetAttenuation() const;
    void SetAttenuation(ITreeTableEntry::Attenuation val);
    float GetAttenuationValue(bool param) const;
    float GetCustomAttenuationValue() const;
    void SetCustomAttenuation(float val);
    short GetAutonomyThreshold() const;
    void SetAutonomyThreshold(short val);
    const char* GetName() const;
    void SetName(BString2& name);
    short GetFlags() const;
    int GetOrderIndex() const;
    void SetOrderIndex(int val);
    bool GetUseCustomActivation() const;
    void SetUseCustomActivation(bool val);
    void GetActivationSubtile(unsigned char& x, unsigned char& y) const;
    void SetActivationSubtile(unsigned char x, unsigned char y);
    void GetActivationExtents(unsigned char& a, unsigned char& b, unsigned char& c, unsigned char& d) const;
    void SetActivationExtents(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
};

// Helper function
float CalculateAttenuationValue(bool param1, int attenuation, float customValue);

// Template search function
template<typename T>
T* FindRes(T* begin, T* end, int key);

#endif // TREETAB_H
