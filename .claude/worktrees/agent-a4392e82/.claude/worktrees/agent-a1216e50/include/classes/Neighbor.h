#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "types.h"

// Neighbor - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1B8 (440 bytes)
// 47 known fields (5 named), 124 methods

class Neighbor {
public:
    // Constructors / Destructors
    Neighbor(void)  // 0x8026E998
    Neighbor(short, ObjSelector *)  // 0x8026EB00
    Neighbor(Neighbor &)  // 0x8026EC04
    ~Neighbor(void);  // 0x8026EA94

    // Methods
    void SetPersonData(int, short);  // 0x8000DC50 (60B)
    /* ? */ GetID(void);  // 0x8008C784 (48B)
    void SetIsMainCharacter(bool);  // 0x800B1984 (64B)
    /* ? */ GetPersonData(int);  // 0x800B18E0 (64B)
    /* ? */ GetPersonDataArray(void);  // 0x800B18B4 (44B)
    void SetPersonDataVersion(int);  // 0x800B195C (40B)
    /* ? */ GetMotives(void);  // 0x800CD050 (44B)
    /* ? */ GetSelector(void);  // 0x800CCFE4 (44B)
    /* ? */ GetFamily(void);  // 0x8026FD68 (320B)
    void SaveToCharacter(ENeighborhoodCustomChar &);  // 0x80271638 (808B)
    void LoadFromCharacter(ENeighborhoodCustomChar &);  // 0x802713E0 (600B)
    /* ? */ GetGUID(void);  // 0x8026FD10 (44B)
    /* ? */ GetLatestPersDataVersion(void);  // 0x8026F834 (36B)
    /* ? */ GetRelations(void);  // 0x8026EF6C (156B)
    void InitWantsFears(void);  // 0x80271B50 (228B)
    /* ? */ GetRelationship(Neighbor *, int *);  // 0x80270D74 (240B)
    bool IsCharacter(void);  // 0x8026FEA8 (96B)
    void DoStream(ReconBuffer *, int);  // 0x8026F858 (1208B)
    void InitDefaultValues(void);  // 0x80271A3C (276B)
    void operator=(Neighbor &);  // 0x8026ECB4 (696B)
    void FindActiveSlotIndex(WantFear::Bookmark &);  // 0x80272914 (196B)
    /* ? */ GetNumPersistentDataFields(void);  // 0x8026F048 (1840B)
    /* ? */ GetPersistentDataFieldsByIndex(int);  // 0x8026F778 (188B)
    void MakeNewActiveBookmark(unsigned int);  // 0x80274194 (852B)
    void SetGUID(int);  // 0x8026FD3C (44B)
    void RecalculateRelationshipData(void);  // 0x8026FF08 (1236B)
    void CountRelationshipsOfType(tRelationshipType);  // 0x80270944 (556B)
    void RelCountsAsRel(tRelationshipType, tRelationshipType);  // 0x802703DC (564B)
    void CalculateRelationshipLevel(int, int);  // 0x80270610 (424B)
    void CalculateRelationshipLevel(Neighbor *);  // 0x802707B8 (396B)
    /* ? */ GetFriendCount(void);  // 0x80270B70 (84B)
    /* ? */ GetEnemyCount(void);  // 0x80270BC4 (84B)
    /* ? */ GetReputationValue(void);  // 0x80270C18 (84B)
    bool IsMarriedTo(Neighbor *);  // 0x80270C6C (264B)
    /* ? */ GetRelationshipById(int, int *);  // 0x80270E64 (260B)
    void AdjustRelationship(Neighbor *, int);  // 0x80270F68 (384B)
    void RemoveAllRelationships(void);  // 0x802710E8 (100B)
    void CopyRelationships(Neighbor *);  // 0x8027114C (660B)
    /* ? */ GetAspirationScore(void);  // 0x80271960 (80B)
    void SetAspirationScore(float);  // 0x802719B0 (80B)
    void ResetInterests(void);  // 0x80271A00 (60B)
    void SetNeedsWantFearShuffle(bool);  // 0x802785EC (80B)
    void SetJustCreated(bool);  // 0x8027863C (80B)
    void ResetAllWantsAndFears(void);  // 0x80274C1C (184B)
    void StartNewTree(unsigned int);  // 0x8027494C (448B)
    void InitWantFearIcons(void);  // 0x80271C34 (124B)
    void UpdateUIifNeeded(unsigned int, int);  // 0x80274B0C (272B)
    void SpawnWantFearDialog(unsigned int);  // 0x80271CB0 (508B)
    void Notify(WantFear::Notification &, bool);  // 0x80271EAC (800B)
    void AdvanceBookmark(unsigned int);  // 0x802729D8 (1168B)
    void ShuffleWantFear(int);  // 0x80274CD4 (284B)
    void FindDuplicateBookmark(WantFear::Bookmark &);  // 0x802721CC (444B)
    void ForceNewTree(unsigned short);  // 0x80272388 (1420B)
    /* ? */ GetBookmarkRange(bool, unsigned int &, unsigned int &);  // 0x80272ED0 (104B)
    void FindBookmarkToReplace(unsigned int, unsigned int);  // 0x80272F38 (536B)
    /* ? */ GetSlotRange(bool, unsigned int &, unsigned int &);  // 0x80272E68 (104B)
    void CalculateBookmarkAd(WantFear::Bookmark &);  // 0x80273150 (244B)
    void CalculateWantFearAd(WantFear::AdData &, short);  // 0x80273338 (3676B)
    void CalcAdMultiplier(float, float, float);  // 0x80273244 (244B)
    void SelectInactiveBookmark(bool, bool);  // 0x802744E8 (1124B)
    void TestNotify(int);  // 0x80274DF0 (388B)
    /* ? */ GetPerson(void);  // 0x80289734 (44B)
    void SetPerson(cXPerson *);  // 0x80377F98 (40B)
    void NeedsWantFearShuffle(void);  // 0x80378010 (60B)
    /* ? */ GetActiveBookmark(unsigned int);  // 0x8054D498 (168B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AdjustRelationship, CalculateRelationshipLevel, CopyRelationships, ...)
    u8 m_field_002;  // 0x002 [R] (ForceNewTree)
    u8 _pad_003[1];  // 0x003
    s16 m_field_004;  // 0x004 [R/W] (CopyRelationships, FindDuplicateBookmark, ForceNewTree, ...)
    u8 _pad_006[2];  // 0x006
    u16 m_family;  // 0x008 [R/W] (DoStream, ForceNewTree, GetFamily, ...)
    u8 _pad_00A[1];  // 0x00A
    u8 m_field_00B;  // 0x00B [R] (ForceNewTree)
    f32 m_bIsCharacter;  // 0x00C [R/W] (CalculateWantFearAd, DoStream, IsCharacter, ...)
    u32 m_relationshipById_010;  // 0x010 [R/W] (AdjustRelationship, DoStream, GetRelationshipById, ...)
    u32 m_field_014;  // 0x014 [W] (operator=)
    u32 m_uIifNeeded;  // 0x018 [R] (CalculateWantFearAd, SpawnWantFearDialog, UpdateUIifNeeded)
    u16 m_field_01C;  // 0x01C [R/W] (Neighbor, RecalculateRelationshipData)
    u16 m_field_01E;  // 0x01E [W] (Neighbor, RecalculateRelationshipData)
    u16 m_field_020;  // 0x020 [R/W] (Neighbor, RecalculateRelationshipData)
    u16 m_field_022;  // 0x022 [W] (Neighbor, RecalculateRelationshipData)
    u32 m_field_024;  // 0x024 [R/W] (Neighbor, RecalculateRelationshipData, operator=)
    u8 _pad_028[0x30];  // 0x028
    s16 m_field_058;  // 0x058 [R] (RecalculateRelationshipData)
    u8 _pad_05A[0x1A];  // 0x05A
    u16 m_field_074;  // 0x074 [R/W] (LoadFromCharacter, SaveToCharacter)
    u16 m_field_076;  // 0x076 [R/W] (LoadFromCharacter, SaveToCharacter)
    u16 m_field_078;  // 0x078 [R/W] (LoadFromCharacter, SaveToCharacter)
    u16 m_field_07A;  // 0x07A [R/W] (LoadFromCharacter, SaveToCharacter)
    u16 m_field_07C;  // 0x07C [R/W] (LoadFromCharacter, SaveToCharacter)
    u16 m_field_07E;  // 0x07E [R/W] (LoadFromCharacter, SaveToCharacter)
    u8 _pad_080[2];  // 0x080
    s16 m_field_082;  // 0x082 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_084;  // 0x084 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_086;  // 0x086 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_088;  // 0x088 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_08A;  // 0x08A [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_08C;  // 0x08C [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_08E;  // 0x08E [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_090;  // 0x090 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_092;  // 0x092 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_094;  // 0x094 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    u8 _pad_096[2];  // 0x096
    u16 m_field_098;  // 0x098 [W] (LoadFromCharacter)
    u8 m_field_099;  // 0x099 [R] (SaveToCharacter)
    u8 _pad_09A[6];  // 0x09A
    s16 m_field_0A0;  // 0x0A0 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    u8 _pad_0A2[0x1A];  // 0x0A2
    u32 m_field_0BC;  // 0x0BC [R] (RecalculateRelationshipData)
    u32 m_field_0C0;  // 0x0C0 [R] (RecalculateRelationshipData)
    u8 _pad_0C4[0x1C];  // 0x0C4
    s16 m_field_0E0;  // 0x0E0 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_0E2;  // 0x0E2 [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    s16 m_field_0E4;  // 0x0E4 [R/W] (LoadFromCharacter, SaveToCharacter)
    u8 _pad_0E6[8];  // 0x0E6
    s16 m_field_0EE;  // 0x0EE [R/W] (InitDefaultValues, LoadFromCharacter, SaveToCharacter)
    u8 _pad_0F0[0xC];  // 0x0F0
    u16 m_field_0FC;  // 0x0FC [W] (LoadFromCharacter)
    u8 _pad_0FE[6];  // 0x0FE
    u16 m_field_104;  // 0x104 [R/W] (InitDefaultValues)
    u8 _pad_106[0xA];  // 0x106
    f32 m_field_110;  // 0x110 [W] (InitDefaultValues)
    u8 _pad_114[8];  // 0x114
    f32 m_field_11C;  // 0x11C [R] (CalculateWantFearAd)
    u8 _pad_120[0x30];  // 0x120
    f32 m_field_150;  // 0x150 [W] (InitDefaultValues)
    u8 _pad_154[0x40];  // 0x154
    u32 m_field_194;  // 0x194 [R/W] (AdvanceBookmark, DoStream, FindBookmarkToReplace, ...)
    u8 _pad_198[0x1C];  // 0x198
    u32 m_field_1B4;  // 0x1B4 [W] (DoStream, Neighbor, ResetAllWantsAndFears, ...)
};

#endif // NEIGHBOR_H
