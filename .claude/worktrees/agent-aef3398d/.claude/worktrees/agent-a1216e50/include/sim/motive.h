#ifndef MOTIVE_H
#define MOTIVE_H

#include "types.h"

// Forward declarations
class ReconBuffer;
class Neighborhood;
class NeighborhoodImpl;
class Family;
class FamilyImpl;
class Neighbor;
class StringBuffer2;
struct __sFILE;
class StringSet;

// ============================================================================
// GlobalConstantsClient - Base class for constants clients
// (forward declared, defined in core/rooms.h)
// ============================================================================
class GlobalConstantsClient;

// ============================================================================
// MotiveConstantsClient - Client for motive-related constants
// vtable at 0x8045f740
// SDA-relative at r13 - 24444 (sTheClient at 0x804ff9a4)
// ============================================================================
class MotiveConstantsClient {
public:
    MotiveConstantsClient();
    // vtable pointer at +0x00
};

MotiveConstantsClient* GetMotiveConstantsClient();

// ============================================================================
// MotiveCurveSet - Motive decay curve system
// ============================================================================
class MotiveCurveSet {
public:
    void PrintMotiveGraph(__sFILE* file, StringSet* strings);
    void PrintMotiveGraph(char* filename);
};

// ============================================================================
// NeighborhoodConstants - Constants for neighborhood system
// vtable at 0x80460498
// ============================================================================
class NeighborhoodConstants {
public:
    NeighborhoodConstants();
};

NeighborhoodConstants* GetNeighborhoodConstantsClient();

// ============================================================================
// Neighborhood - Abstract interface for neighborhood data
// vtable at 0x80460678 (offset +1656 from base)
// ============================================================================
class Neighborhood {
public:
    void* m_vtable; // +0x00

    Neighborhood();
    ~Neighborhood();

    static Neighborhood* CreateInstance();
    static void DestroyInstance(Neighborhood* neighborhood);
};

// ============================================================================
// NeighborhoodImpl - Concrete neighborhood implementation
// Offset layout (from disassembly):
//   +0x00: vtable
//   +0x04: name (EString inline)
//   +0x4C: neighborHouses vector begin (int*)
//   +0x50: neighborHouses vector end (int*)
//   +0x5C: families vector begin (FamilyImpl**)
//   +0x60: families vector end (FamilyImpl**)
//   +0x70: house number (int)
//   +0x74: neighbors vector begin (Neighbor**)
//   +0x78: neighbors vector end (Neighbor**)
//   +0x84: highest level completed (short) + neighborhood vars array
// Size: 0xCC (204 bytes) per CreateInstance allocation
// ============================================================================
class NeighborhoodImpl {
public:
    void* m_vtable;                // +0x00
    char m_name[0x48];             // +0x04 (EString and other data)
    int* m_neighborHousesBegin;    // +0x4C
    int* m_neighborHousesEnd;      // +0x50
    char m_pad54[8];               // +0x54
    FamilyImpl** m_familiesBegin;  // +0x5C
    FamilyImpl** m_familiesEnd;    // +0x60
    char m_pad64[0x0C];            // +0x64
    int m_houseNumber;             // +0x70
    Neighbor** m_neighborsBegin;   // +0x74
    Neighbor** m_neighborsEnd;     // +0x78
    char m_pad7C[8];               // +0x7C
    short m_neighborhoodVars[1];   // +0x84 (array of shorts, first is highestLevelCompleted)

    // Neighborhood management
    void PostSim();
    int GetHouseNumberForLevel(int level);
    Neighbor* FindNeighborByID(int id);

    // Family management
    int GetNumFamilies();
    FamilyImpl* GetFamilyByIndex(int index);
    Family* MakeNewFamily();
    int GetFamilyFriendsCount(Family* family);

    // House management
    int GetHouseNumber();
    void UnloadHouse();
    void GetLotPosition(int lot, int* outX, int* outY);
    void SetHouseNum(int num);

    // Neighborhood data
    const char* GetNeighborhoodName();
    short GetHighestLevelCompleted();
    short GetNeighborhoodVar(int index) const;
    short* GetNeighborhoodVarRef(int index);
    void SetNeighborhoodVar(int index, short value);

    // Neighbor houses
    int GetNumNeighborHouses();
    int* GetNeighborHouseByIndex(int index);

    // Misc
    NeighborhoodImpl* GetImpl();
    int IsFreeplayLot(int lot);

private:
    // Internal - recalculate family friends
    void RecalculateFamilyFriends();
    // Internal - create family with params
    Family* CreateFamily(int param, int number);
};

// ============================================================================
// SimpleReconObject<NeighborhoodImpl> - Serialization wrapper
// vtable at 0x80460470
// ============================================================================

// ============================================================================
// Player - Player management
// Size: 0x0C (12 bytes)
// ============================================================================
class Player {
public:
    int m_pad00;    // +0x00
    int m_pad04;    // +0x04
    int m_pad08;    // +0x08

    Player();

    static void* GetInteractorColor();
};

// Static data
extern float s_interactorColor[3]; // at 0x80485594, 12 bytes

// Lot position table
extern int sLotPositions[9][2]; // at 0x804862dc

#endif // MOTIVE_H
