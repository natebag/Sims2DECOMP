#ifndef ITREETABLE_H
#define ITREETABLE_H

#include "types.h"

// Forward declarations
class ITreeTableEntry;
class ITreeTableAd;
class BString2;
class StringBuffer;

// ObjectDataID forward declaration
struct ObjectDataID;

// Interface for TreeTableAd - advertising/motive effect entry
class ITreeTableAd {
public:
    virtual ~ITreeTableAd() {}

    virtual int QueryInterface(unsigned int iid, void** ppv) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;

    virtual int GetPersonalityAd() const = 0;
    virtual void SetPersonalityAd(int val) = 0;
    virtual int GetMin() const = 0;
    virtual void SetMin(int val) = 0;
    virtual int GetMax() const = 0;
    virtual void SetMax(int val) = 0;
    virtual int GetRange() const = 0;
    virtual void SetRange(int val) = 0;
    virtual ITreeTableAd& operator=(ITreeTableAd& other) = 0;
};

// Interface for TreeTableEntry - a single entry in the behavior tree table
class ITreeTableEntry {
public:
    enum Attenuation {
        // Attenuation types
    };

    virtual ~ITreeTableEntry() {}

    virtual int QueryInterface(unsigned int iid, void** ppv) = 0;
    virtual int AddRef() = 0;
    virtual int Release() = 0;

    virtual short GetIndex() const = 0;
    virtual bool GetAvailableToVisitors() const = 0;
    virtual void SetAvailableToVisitors(bool val) = 0;
    virtual bool GetCanJoin() const = 0;
    virtual void SetCanJoin(bool val) = 0;
    virtual bool GetImmediate() const = 0;
    virtual void SetImmediate(bool val) = 0;
    virtual bool GetAllowConsecutive() const = 0;
    virtual void SetAllowConsecutive(bool val) = 0;
    virtual bool GetAvailableToGhosts() const = 0;
    virtual void SetAvailableToGhosts(bool val) = 0;
    virtual bool GetAvailableToAdults() const = 0;
    virtual void SetAvailableToAdults(bool val) = 0;
    virtual bool GetAvailableToChildrenDemo() const = 0;
    virtual void SetAvailableToChildrenDemo(bool val) = 0;
    virtual bool GetAvailableToVisitingPlayers() const = 0;
    virtual void SetAvailableToVisitingPlayers(bool val) = 0;
    virtual short GetJoinIndex() const = 0;
    virtual void SetJoinIndex(int val) = 0;
    virtual bool GetDebugOnly() const = 0;
    virtual void SetDebugOnly(bool val) = 0;
    virtual bool GetAutoFirstSelect() const = 0;
    virtual void SetAutoFirstSelect(bool val) = 0;
    virtual bool GetManualOnly() const = 0;
    virtual int CountAds() const = 0;
    virtual short* GetRangeRef(int idx) const = 0;
    virtual short* GetMinRef(int idx) const = 0;
    virtual short* GetPersonalityVarRef(int idx) const = 0;
    virtual const ITreeTableAd* GetAd(int idx) const = 0;
    virtual ITreeTableAd* GetAd(int idx) = 0;
    virtual void SetAd(int idx, ITreeTableAd& ad) = 0;
    virtual short GetActionTreeID() const = 0;
    virtual void SetActionTreeID(short val) = 0;
    virtual short GetCheckTreeID() const = 0;
    virtual void SetCheckTreeID(short val) = 0;
    virtual int GetAttenuation() const = 0;
    virtual void SetAttenuation(ITreeTableEntry::Attenuation val) = 0;
    virtual float GetAttenuationValue(bool param) const = 0;
    virtual float GetCustomAttenuationValue() const = 0;
    virtual void SetCustomAttenuation(float val) = 0;
    virtual short GetAutonomyThreshold() const = 0;
    virtual void SetAutonomyThreshold(short val) = 0;
    virtual bool GetIgnorePrefixTree() const = 0;
    virtual void SetIgnorePrefixTree(bool val) = 0;
    virtual bool GetMustRun() const = 0;
    virtual void SetMustRun(bool val) = 0;
    virtual const char* GetName() const = 0;
    virtual void SetName(BString2& name) = 0;
    virtual bool GetUseCustomActivation() const = 0;
    virtual void SetUseCustomActivation(bool val) = 0;
    virtual void GetActivationSubtile(unsigned char& x, unsigned char& y) const = 0;
    virtual void SetActivationSubtile(unsigned char x, unsigned char y) = 0;
    virtual void GetActivationExtents(unsigned char& a, unsigned char& b, unsigned char& c, unsigned char& d) const = 0;
    virtual void SetActivationExtents(unsigned char a, unsigned char b, unsigned char c, unsigned char d) = 0;
    virtual short GetFlags() const = 0;
    virtual void CopyFrom(ITreeTableEntry* other) = 0;
    virtual int GetOrderIndex() const = 0;
    virtual void SetOrderIndex(int val) = 0;
};

// Interface for TreeTable - the behavior tree table itself
class ITreeTable {
public:
    virtual ~ITreeTable() {}
};

#endif // ITREETABLE_H
