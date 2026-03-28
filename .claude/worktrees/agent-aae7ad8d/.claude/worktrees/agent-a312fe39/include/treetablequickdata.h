#ifndef TREETABLEQUICKDATA_H
#define TREETABLEQUICKDATA_H

#include "types.h"
#include "treetab.h"

// Forward declarations
class ITreeTableAd;
class ITreeTableEntry;
class BString2;
class StringBuffer;
struct ObjectDataID;

// TreeTableAd - raw ad data from the resource (8 bytes)
struct TreeTableAd {
    short m_personalityAd; // +0x00
    short m_min;           // +0x02
    short m_range;         // +0x04
    short m_pad;           // +0x06
};

// TreeTableAdQuickData - lightweight wrapper around TreeTableAd*
class TreeTableAdQuickData {
public:
    void* __vtable;         // +0x00
    TreeTableAd* m_pImpl;   // +0x04
    int m_refCount;         // +0x08

    TreeTableAdQuickData(TreeTableAd* pAd);
    ~TreeTableAdQuickData();

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
    TreeTableAdQuickData& operator=(ITreeTableAd& other);
    TreeTableAd* GetImplementation() const;
};

// TreeTableEntryQuickData - lightweight wrapper around TreeTableEntry*
class TreeTableEntryQuickData {
public:
    void* __vtable;                 // +0x00
    TreeTableEntry* m_pImpl;        // +0x04
    TreeTableAdQuickData** m_adsBegin; // +0x08
    TreeTableAdQuickData** m_adsEnd;   // +0x0C
    TreeTableAdQuickData** m_adsCap;   // +0x10
    int m_pad14;                    // +0x14
    int m_refCount;                 // +0x18

    TreeTableEntryQuickData(TreeTableEntry* pEntry);
    ~TreeTableEntryQuickData();

    int QueryInterface(unsigned int iid, void** ppv);
    int AddRef();
    int Release();

    const TreeTableEntryQuickData* GetAd(int idx) const;
    const char* GetName() const;

    // Delegate getters - all forward to m_pImpl
    short GetIndex() const;
    int GetOrderIndex() const;
    bool GetAvailableToVisitors() const;
    bool GetCanJoin() const;
    bool GetImmediate() const;
    bool GetAllowConsecutive() const;
    bool GetAvailableToGhosts() const;
    bool GetAvailableToAdults() const;
    bool GetAvailableToChildrenDemo() const;
    bool GetAvailableToVisitingPlayers() const;
    short GetJoinIndex() const;
    bool GetDebugOnly() const;
    bool GetAutoFirstSelect() const;
    bool GetManualOnly() const;
    int CountAds() const;
    bool GetIgnorePrefixTree() const;
    bool GetMustRun() const;
    short* GetRangeRef(int idx) const;
    short* GetMinRef(int idx) const;
    short* GetPersonalityVarRef(int idx) const;
    short GetActionTreeID() const;
    short GetCheckTreeID() const;
    int GetAttenuation() const;
    float GetAttenuationValue(bool param) const;
    float GetCustomAttenuationValue() const;
    short GetAutonomyThreshold() const;
    short GetFlags() const;
    bool GetUseCustomActivation() const;
    void GetActivationSubtile(unsigned char& x, unsigned char& y) const;
    void GetActivationExtents(unsigned char& a, unsigned char& b, unsigned char& c, unsigned char& d) const;

    // Delegate setters - all just blr (stub) in QuickData
    void SetOrderIndex(int val);
    void SetAvailableToVisitors(bool val);
    void SetCanJoin(bool val);
    void SetImmediate(bool val);
    void SetAllowConsecutive(bool val);
    void SetAvailableToGhosts(bool val);
    void SetAvailableToAdults(bool val);
    void SetAvailableToChildrenDemo(bool val);
    void SetJoinIndex(int val);
    void SetDebugOnly(bool val);
    void SetAutoFirstSelect(bool val);
    void SetAvailableToVisitingPlayers(bool val);
    void SetIgnorePrefixTree(bool val);
    void SetMustRun(bool val);
    int GetAd(int idx);
    void SetAd(int idx, ITreeTableAd& ad);
    void SetActionTreeID(short val);
    void SetCheckTreeID(short val);
    void SetAttenuation(ITreeTableEntry::Attenuation val);
    void SetCustomAttenuation(float val);
    void SetAutonomyThreshold(short val);
    void SetName(BString2& name);
    void SetUseCustomActivation(bool val);
    void SetActivationSubtile(unsigned char x, unsigned char y);
    void SetActivationExtents(unsigned char a, unsigned char b, unsigned char c, unsigned char d);

    TreeTableEntry* GetImplementation() const;
};

// TreeTableQuickData - lightweight wrapper around TreeTable*
class TreeTableQuickData {
public:
    void* __vtable;                          // +0x00
    TreeTable* m_pImpl;                      // +0x04
    TreeTableEntryQuickData** m_entriesBegin; // +0x08
    TreeTableEntryQuickData** m_entriesEnd;   // +0x0C
    TreeTableEntryQuickData** m_entriesCap;   // +0x10
    int m_pad14;                             // +0x14
    int m_pad18;                             // +0x18
    int m_pad1C;                             // +0x1C
    int m_refCount;                          // +0x20

    TreeTableQuickData();
    ~TreeTableQuickData();

    int QueryInterface(unsigned int iid, void** ppv);
    int AddRef();
    int Release();

    const ObjectDataID* GetDataID() const;
    void LoadFromDataID(ObjectDataID& id);
    int SaveDataByID(ObjectDataID& id);
    int GetDataSourceType() const;
    int Load(unsigned int param1, short param2);
    const TreeTableEntryQuickData* GetNthEntry(int n) const;
    int GetEntryByIndex(int idx) const;
    int GetEntryByTreeID(short checkID, short actionID) const;
    int GetNthOrderedEntry(int n) const;
    static TreeTableQuickData* CreateInstance();

    // Stub forwarders - return 0 or stub
    int LoadFromIndex(unsigned int param1, int param2);
    int GetResourceName(StringBuffer& buf) const;
    int SetResourceName(StringBuffer& buf);
    int LoadOnlyNameAndIDFromIndex(unsigned int param1, int param2);
    short GetID() const;
    int CountMotiveAds() const;
    int CountEntries() const;
    short GetPrefixCheckTreeID() const;
    void SwapEntries(int a, int b);
    int GetNthEntry(int n);
    int GetEntryByIndex(int idx);
    int GetNthOrderedEntry(int n);
    void SetName(StringBuffer& name);
    int AreOrderIndicesValid() const;
    int Save(unsigned int param1, short param2);
    int Save();
    int GetIsTuned() const;
    void SetIsTuned(bool val);
    int AddEntry(short a, short b);
    int RemoveEntry(ITreeTableEntry* entry);
    void SetPrefixCheckTreeID(short val);
    TreeTable* GetImplementation() const;
};

#endif // TREETABLEQUICKDATA_H
