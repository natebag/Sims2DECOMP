#ifndef FAMILY_H
#define FAMILY_H

#include "types.h"

// Forward declarations
class Family;
class FamilyImpl;
class ReconBuffer;
class StringBuffer2;

// ============================================================================
// FamilyMember - Individual family member data
// ============================================================================
class FamilyMember {
public:
    int DoStream(ReconBuffer* buffer, int version);
};

// ============================================================================
// Family - Abstract interface for family management
// vtable at 0x8045edc8 (offset -4664 from 0x80460000)
// ============================================================================
class Family {
public:
    void* m_vtable; // +0x00

    Family();
    ~Family();

    static Family* CreateInstance(int& number);
    static void DestroyInstance(Family* family);
};

// ============================================================================
// FamilyImpl - Concrete family implementation
// Offset layout (from disassembly):
//   +0x00: vtable
//   +0x04: name (EString, inline)
//   +0x08: number (int)
//   +0x0C: house number (int)
//   +0x10: creation order (int)
//   +0x14: funds (int)
//   +0x18: house value (int)
//   +0x1C: friend count (int)
//   +0x20: friend count dirty flag (int)
//   +0x24: members vector begin (int*)
//   +0x28: members vector end (int*)
//   +0x2C: members vector capacity_end (int*)
//   +0x30: ...
//   +0x34: flags bitfield (int)
//         bit 0: hasPhone
//         bit 1: hasBaby
//         bit 2: justMovedIn
//         bit 3: isFreeplay
//         bit 4: hasP1DoneCAS
//         bit 5: hasP2DoneCAS
// Size: 0x38 (56 bytes) per CreateInstance allocation
// ============================================================================
class FamilyImpl {
public:
    void* m_vtable;        // +0x00
    char m_name[4];        // +0x04 (EString inline data)
    int m_number;          // +0x08
    int m_houseNumber;     // +0x0C
    int m_creationOrder;   // +0x10
    int m_funds;           // +0x14
    int m_houseValue;      // +0x18
    int m_friendCount;     // +0x1C
    int m_friendCountDirty;// +0x20
    int* m_membersBegin;   // +0x24
    int* m_membersEnd;     // +0x28
    int* m_membersCapEnd;  // +0x2C
    int m_pad30;           // +0x30
    int m_flags;           // +0x34

    // Member access
    int* GetMemberByGUID(int guid);
    int TestMember(int guid) const;
    int* GetIndexedMember(int index);
    int CountMembers();

    // Name
    void GetName(StringBuffer2* outName);
    void SetName(StringBuffer2* name);

    // Properties
    short GetResfileStorageId(short id);
    int GetNumber();
    void SetNumber(int number);
    int GetHouseNumber();
    void SetHouseNumber(int number);
    int GetCreationOrder();
    void SetCreationOrder(int order);
    int GetFunds();
    void SetFunds(int funds);
    int GetHouseValue();
    void SetHouseValue(int value);

    // Friend count (virtual dispatch through Neighborhood)
    int GetFriendCount();
    int GetNetWorth();
    void SetFriendCount(int count);

    // Flag accessors
    void SetHasPhone(bool hasPhone);
    bool GetHasPhone();
    void SetHasBaby(bool hasBaby);
    bool GetHasBaby();
    void SetJustMovedIn(bool justMovedIn);
    bool GetJustMovedIn();
    void SetIsFreeplay(bool isFreeplay);
    bool GetIsFreeplay();
    void SetHasP1DoneCAS(bool hasDone);
    bool GetHasP1DoneCAS();
    void SetHasP2DoneCAS(bool hasDone);
    bool GetHasP2DoneCAS();

    // Misc
    void ClearFamily();
    int MyDoCommand(short cmd, int arg);
    void* GetInventory();
    void* GetGoalAndUnlockData();
    int GetStatValue(int index) const;
    int GetStatRef(int index, short** outRef);
};

// ============================================================================
// SimpleReconObject<FamilyImpl> - Serialization wrapper
// vtable at 0x8045ec38
// ============================================================================
template <typename T>
class SimpleReconObject {
public:
    void* m_vtable;    // +0x00
    T* m_impl;         // +0x04
    int m_type;        // +0x08

    ~SimpleReconObject();
    void DoStream(ReconBuffer* buffer, int version);
    int GetType();
};

// External function for streaming
extern void ReconBuffer_StreamData(ReconBuffer* buffer, void* data, int size);

#endif // FAMILY_H
