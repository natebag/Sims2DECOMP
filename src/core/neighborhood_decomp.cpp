/**
 * Neighborhood System -- Decompiled Implementation
 *
 * Source: src/core/neighborhood_decomp.cpp
 * Headers: include/classes/NeighborhoodImpl.h
 *          include/classes/cFixedWorldImpl.h
 *          include/classes/FamilyImpl.h
 *          include/classes/PlayerFamilyImpl.h
 *          include/classes/Neighbor.h
 *          include/classes/HouseImpl.h
 *          include/classes/HoodManager.h
 *          include/classes/NeighborhoodConstants.h
 * Original ELF: extracted/files/u2_ngc_release_dvd.elf
 * Compiler: SN Systems ProDG for GameCube
 *
 * This file documents the decompiled neighborhood, lot, and family management
 * subsystems from The Sims 2 for GameCube.
 *
 * ============================================================================
 * ARCHITECTURE OVERVIEW
 * ============================================================================
 *
 * The neighborhood system manages the persistent game world:
 *
 *   NeighborhoodImpl (singleton, top-level world state)
 *     |
 *     +-- Neighbor[] (all sims in the neighborhood -- NPCs and playables)
 *     |     +-- WantFear system (per-neighbor wants/fears tracking)
 *     |     +-- Relationship data (friendship/romance/family scores)
 *     |
 *     +-- Family[] (household groups of neighbors)
 *     |     +-- FamilyImpl (base family -- 56 bytes)
 *     |     +-- PlayerFamilyImpl (player family -- 3432 bytes, with inventory/goals)
 *     |
 *     +-- HouseImpl[] (lot/house data per lot)
 *     |     +-- cFixedWorldImpl (tile grid, walls, floors, rooms)
 *     |
 *     +-- HoodManager (high-level operations: move-in, evict, demolish)
 *     +-- NeighborhoodConstants (tuning constants from quickdata)
 *
 * Persistence: NeighborhoodImpl saves/loads via NghResFile (.NGH files).
 * Uses a ReconBuffer-based streaming system (DoStream) for serialization.
 *
 * Global state:
 *   Globs::pNeighborhood  at 0x8050053C (.scommon, r13-relative)
 *   Globs::pFixedWorld     at 0x80500530 (.scommon, r13-relative)
 *
 * ============================================================================
 * NeighborhoodImpl -- NEIGHBORHOOD SINGLETON
 * ============================================================================
 *
 * Size: 0x450 (1104 bytes)
 * Constructor: 0x800CCAD8 (172B)
 * Destructor:  0x800CCB84 (296B)
 * vtable:      0x804604C0 (440 bytes, 110 entries)
 *
 * The neighborhood holds the master list of all Neighbors, Families,
 * and houses. It is the root object for save/load operations.
 *
 * ---- FIELD MAP (from assembly analysis) ----
 *
 * 0x000  f32   m_field_000           -- Used in AddAsPlayerRoommate, AddToFamily
 * 0x004  s16   m_numNeighbors        -- Count of neighbors in array
 * 0x00C  u32   m_neighborArray       -- Pointer to Neighbor* array
 * 0x014  u32   m_field_014           -- Set during LoadHouse
 * 0x01C  u32   m_field_01C           -- Read during Load
 * 0x020  u32   m_dirtyFlag           -- Set by RelationshipsChanged
 * 0x04C  u32   m_houseObject         -- HouseImpl* for current house
 * 0x050  u32   m_fixedWorld          -- cFixedWorldImpl* for current lot
 * 0x054  u32   m_field_054           -- Associated with house loading
 * 0x058  s16   m_numResidents        -- Residents in current house
 * 0x05C  u32   m_familyList          -- vector<Family*> data pointer
 * 0x060  u32   m_familyListBegin     -- vector begin (used by Unload)
 * 0x064  u32   m_familyListEnd       -- vector end
 * 0x06C  s16   m_playerFamilyIdx     -- Index of player's family (-1 = none)
 * 0x06E  s16   m_field_06E           -- Loaded/saved per session
 * 0x070  u32   m_numFamilies         -- Family count (also at vector)
 * 0x074  u32   m_nextNeighborID      -- Auto-increment neighbor ID counter
 * 0x078  u32   m_neighborIDEnd       -- End of neighbor ID range
 * 0x084  u16   m_highestLevelCompleted
 * 0x086  s16   m_field_086           -- DoStream serialized
 * 0x088  u16   m_field_088           -- Saved to file
 *
 * Neighbor houses stored as embedded array at offsets:
 *   0x098, 0x0E4, 0x140, 0x1B8, 0x250, 0x368 -- house data blocks
 *   Each block: 0x4C bytes (76 bytes) containing lot metadata
 *
 * 0x0D0  s16   m_field_0D0           -- MoveOut related
 * 0x0D8  u32   m_field_0D8           -- House loading state
 * 0x0E0  s16   m_field_0E0           -- Save state
 * 0x0E8  u32   m_field_0E8           -- House loading
 * 0x0F0  u32   m_field_0F0           -- House loading
 * 0x0F6  s16   m_field_0F6           -- MoveOut state
 *
 * 0x448  u32   m_field_448           -- Read during Load
 * 0x44C  u32   m_field_44C           -- Read during Load
 *
 * Key method addresses (148 total methods):
 *   Load                    0x800CCF44  2244B  -- Load from NghResFile
 *   Save                    0x800CD930   764B  -- Save to NghResFile
 *   Unload                  0x800CCE18   300B  -- Free all data
 *   DoStream                0x800CDC2C   268B  -- Serialize/deserialize
 *   LoadHouse               0x800D0874  2204B  -- Load a lot
 *   SaveHouse               0x800D1110   388B  -- Save current lot
 *   MoveIn                  0x800CF90C   164B  -- Move family into lot
 *   MoveOut                 0x800CFA4C  1632B  -- Move family out
 *   BaseMakeNewFamily       0x800CEC64   740B  -- Create new family
 *   AddToFamily             0x800CF028   420B  -- Add neighbor to family
 *   RemoveFromFamily        0x800CF1CC   340B  -- Remove from family
 *   AddNewNeighbor          0x800CDF30   496B  -- Create new neighbor
 *   RemoveNeighbor          0x800CE388   128B  -- Remove neighbor
 *   FindNeighborByID        0x800CDD40    56B  -- Lookup by ID
 *   FindNeighborByGUID      0x800CDD78   136B  -- Lookup by GUID
 *   GetFamily               0x800CE968   188B  -- Get family by number
 *   GetFamilyInHouse        0x800CEA24   252B  -- Get family in lot
 *   GetFamilyInfo           0x800D03C0   256B  -- Get display info
 *   GetHouseInfo            0x800D05F8    72B  -- Get lot info
 *   UpdateFamilyNumbers     0x800CD808   296B  -- Reassign family numbers
 *   UpdateFamilyFriendsCount 0x800D00AC  332B  -- Recalc friend counts
 *   NotifyAllNeighbors      0x800D13D4   152B  -- WantFear notifications
 *   NotifyAllResidents      0x800D146C   324B  -- Notify house residents
 *   NotifyAllPersons        0x800D15B0   268B  -- Notify all persons
 */

// ============================================================================
// Forward declarations
// ============================================================================

class NeighborhoodImpl;
class Neighbor;
class Family;
class FamilyImpl;
class PlayerFamilyImpl;
class HouseImpl;
class cFixedWorldImpl;
class HoodManager;
class NeighborhoodConstants;
class NghResFile;
class ReconBuffer;
class ObjSelector;
class cXPerson;
class cSimulator;

// ============================================================================
// NeighborhoodImpl::Load -- Load neighborhood from file
// ============================================================================
// Address: 0x800CCF44  Size: 2244 bytes (561 instructions)
//
// NON_MATCHING -- Decompiled from PPC assembly for documentation.
//
// Loads the entire neighborhood state from an NghResFile. This is the
// primary deserialization entry point for the neighborhood system.
//
// Loading sequence:
//   1. Initialize NeighborhoodConstants if not already done
//   2. Unload any existing neighborhood data
//   3. Load the NeighborhoodImpl base data via ReconLoadObject
//   4. Read the version number (stored at field 0x06E)
//   5. Load the Neighbor list:
//      a. Read neighbor array from file (tag 'NBRS')
//      b. For each neighbor, validate:
//         - Check if neighbor has valid data (field at offset 0x0C != 0)
//         - Log invalid neighbors with name for debugging
//         - Remove invalid neighbors via RemoveNeighbor
//   6. Load the Family list:
//      a. Read family array from file (tag 'FMLY')
//      b. Link families to their members
//   7. Assign the global neighborhood pointer
//   8. Load neighborhood variables
//   9. Validate cross-references

void NeighborhoodImpl::Load(NghResFile* resFile) {
    // Step 1: Initialize constants (one-time)
    // Checks flag at r13-0x7CD4 (s_constantsInitialized)
    if (!s_constantsInitialized) {
        NeighborhoodConstants::UpdateConstants();
        s_constantsInitialized = 1;
    }

    // Save global pointer for cross-references
    // r23 = lwz r13-0x5404 (Globs::pNeighborhood)

    // Step 2: Unload existing data
    this->Unload();  // bl 0x800CCE18

    // Step 3: Load base NeighborhoodImpl via template
    // ReconLoadObject<NeighborhoodImpl>(this, resFile, tag='NGHB', version=1, &status)
    int loadStatus = ReconLoadObject(this, resFile, 'NGHB', 1, &status);

    // Step 4: Read version from loaded data
    // vtable indirect call: GetVersion at vtable offset 0x78/0x7C
    this->m_version = this->GetVersion(35);  // li r4, 0x23

    // Notify global sim data system
    // vtable call on Globs::pSimsData at offset 0xD8/0xDC

    // Step 5: Load neighbor list
    if (loadStatus == 0) {
        // Load vector<Neighbor*> from file
        // Tag 'NBRS', version 1
        loadStatus = DoContainerStream(m_neighborList, resFile, 'NBRS', 1, 0);

        // Iterate and validate each neighbor
        Neighbor** iter = m_neighborList.begin();
        Neighbor** end = m_neighborList.end();
        while (iter != end) {
            Neighbor* neighbor = *iter;
            if (neighbor != nullptr) {
                // Check if neighbor data is valid
                if (neighbor->m_field_00C == 0) {
                    // Log: "Neighborhood::Load removing neighbor with null data"
                    // Print neighbor name for debugging
                    // Then remove: RemoveNeighbor(neighbor)
                    this->RemoveNeighbor(neighbor);
                }
            }
            iter++;
        }

        // Step 6: Load family list
        // ... similar pattern with 'FMLY' tag
    }
}

// ============================================================================
// NeighborhoodImpl::BaseMakeNewFamily -- Create a new family
// ============================================================================
// Address: 0x800CEC64  Size: 740 bytes (185 instructions)
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Core function for creating a new Family object and inserting it into
// the neighborhood's family list. Handles both regular families (56 bytes)
// and player families (3432 bytes with inventory/goals).
//
// Parameters:
//   isPlayerFamily: true = allocate PlayerFamilyImpl, false = FamilyImpl
//   familyNumber:   requested family number (-1 = auto-assign)
//
// The auto-assignment loop searches for the lowest unused family number
// starting from 1. The creation order is tracked to maintain sort order
// (families displayed in creation order on the family selection screen).

Family* NeighborhoodImpl::BaseMakeNewFamily(bool isPlayerFamily, int familyNumber) {
    // Auto-assign family number if not specified
    if (familyNumber < 0) {
        int testNum = 1;
        do {
            // Check if this number is already used
            // Calls GetFamily(testNum) via vtable
            Family* existing = this->GetFamily(testNum);
            if (existing == nullptr) {
                familyNumber = testNum;
                break;
            }
            testNum++;
        } while (true);

        // Safety check: don't exceed max family number
        if (familyNumber > 32767) {
            return nullptr;
        }
    }

    // Determine next creation order
    // Walk all existing families to find max creation order
    int nextCreationOrder = 1;
    Family** iter = m_familyList.begin();     // at offset 0x5C
    Family** end = m_familyList.end();
    while (iter != end) {
        Family* fam = *iter;
        int order = fam->GetCreationOrder();  // vtable call at offsets 0xB8/0xBC
        if (order >= nextCreationOrder) {
            nextCreationOrder = order + 1;
        }
        iter++;
    }

    // Allocate the appropriate family type
    Family* newFamily = nullptr;
    if (isPlayerFamily) {
        // PlayerFamilyImpl: 0xD68 = 3432 bytes
        void* mem = operator new(3432);   // li r3, 0xD68; bl operator new
        newFamily = new(mem) PlayerFamilyImpl(familyNumber);  // bl 0x8012CF68
    } else {
        // FamilyImpl: 0x38 = 56 bytes
        void* mem = operator new(56);     // li r3, 0x38; bl operator new
        newFamily = new(mem) FamilyImpl(familyNumber);        // bl 0x800B5FD4
    }

    if (newFamily == nullptr) {
        return nullptr;
    }

    // Set family metadata
    newFamily->SetCreationOrder(nextCreationOrder);
    newFamily->SetFunds(gMoneyForNewFamily);  // global at 0x804FFA30 (.sbss)

    // Insert into family list (vector<Family*>)
    m_familyList.push_back(newFamily);

    // Sort families by creation order
    // Uses std::sort with SortFamilyByCreation comparator
    sort(m_familyList.begin(), m_familyList.end(), SortFamilyByCreation);

    return newFamily;
}

// ============================================================================
// NeighborhoodImpl::MoveIn -- Move a family into a lot
// ============================================================================
// Address: 0x800CF90C  Size: 164 bytes (41 instructions)
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Assigns a family to a lot number. Validates the lot number (1-16),
// checks the lot isn't already occupied, then sets the family's house
// number and marks it as "just moved in."

int NeighborhoodImpl::MoveIn(Family* family, int lotNumber) {
    // Validate lot number range (1-16)
    if ((unsigned)(lotNumber - 1) > 15) {
        return -1;  // invalid lot
    }

    // Check if lot is already occupied
    // vtable call at offsets 0x128/0x12C: GetFamilyInHouse(lotNumber)
    Family* existing = this->GetFamilyInHouse(lotNumber);
    if (existing != nullptr) {
        return -1;  // lot occupied
    }

    // Set the family's house number
    // vtable call at offsets 0xB0/0xB4: SetHouseNumber(lotNumber)
    family->SetHouseNumber(lotNumber);

    // Mark as "just moved in"
    // vtable call at offsets 0x120/0x124: SetJustMovedIn(true)
    family->SetJustMovedIn(true);

    return 0;  // success
}

// ============================================================================
// FamilyImpl -- FAMILY / HOUSEHOLD DATA
// ============================================================================
//
// Size: 0x38 (56 bytes) -- base family
// Constructor: 0x800B5FD4 (148B)
// Destructor:  0x800B6068 (156B)
// vtable:      0x8045EC60 (360 bytes, 90 entries)
//
// A Family groups Neighbors into a household. Families own lots (houses),
// track shared funds, and maintain household state.
//
// ---- FIELD MAP (from FamilyImpl constructor analysis) ----
//
// 0x000  void** _vtable             -- vtable at 0x8045EC60
// 0x004  u32    m_memberList         -- ENodeList of FamilyMember structs
//                                      (initialized via ENodeList ctor at 0x800A1AD4)
// 0x008  int    m_familyNumber       -- Unique family identifier
// 0x00C  u32    m_field_00C          -- Initialized to 0
// 0x010  int    m_houseNumber        -- Lot number (-1 = homeless)
// 0x014  u32    m_field_014          -- Initialized to 0
// 0x018  u32    m_field_018          -- Initialized to 0
// 0x01C  int    m_funds              -- Simoleons balance
// 0x020  int    m_justMovedIn        -- Set to 1 initially
// 0x024  u32    m_field_024          -- Member count / linked list head
// 0x028  u32    m_field_028          -- Initialized to 0
// 0x02C  u32    m_field_02C          -- Used by LoadByResID
// 0x034  u32    m_field_034          -- Initialized to 0
//
// Constructor flow (from 0x800B5FD4):
//   1. Set vtable to 0x8045EC60  (lis r9, -32698; addi r9, -5024)
//   2. Initialize member list (ENodeList at offset 0x004)
//   3. Store familyNumber at 0x008
//   4. Clear field_024, field_028 to 0
//   5. Initialize member vector at offset 0x02C (with reserved capacity)
//   6. Clear remaining fields
//   7. Set m_houseNumber to -1 (homeless)
//   8. Set m_justMovedIn to 1
//   9. Clear m_field_034 to 0

// ============================================================================
// FamilyImpl::FamilyImpl -- Constructor
// ============================================================================
// Address: 0x800B5FD4  Size: 148 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.

FamilyImpl::FamilyImpl(int familyNumber) {
    // Set vtable
    _vtable = &FamilyImpl_vtable;  // 0x8045EC60

    // Initialize member list at offset 0x004
    // ENodeList::ENodeList(m_memberList)
    ENodeList_Init(&m_memberList);

    // Store family number
    m_familyNumber = familyNumber;

    // Initialize fields
    m_field_024 = 0;        // member tracking
    m_field_028 = 0;
    m_field_00C = 0;
    m_field_014 = 0;
    m_field_018 = 0;
    m_houseNumber = -1;     // li r0, -1; stw r0, 0x10(r30)

    // Initialize vector at offset 0x02C with capacity 0, reserve -1
    // This is the FamilyMember vector
    // vector_init(m_memberVector, 0, -1)

    // Set remaining fields
    m_field_034 = 0;
    m_justMovedIn = 1;      // li r0, 1; stw r0, 0x20(r30)
}

// ============================================================================
// FamilyImpl Key Methods
// ============================================================================
//
// AddMember(int guid)        -- 0x800B6818 (444B)
//   Adds a neighbor (by GUID) to this family. Allocates a FamilyMember
//   entry and inserts into the member list. Updates the member count.
//
// RemoveMember(int guid)     -- 0x800B69D4 (132B)
//   Removes a neighbor from the family. Searches the member list for
//   the matching GUID and removes the entry.
//
// TestMember(cXPerson* person) -- 0x800B62D0 (100B)
//   Checks if a person is a member of this family. Returns bool.
//
// TestMember(int guid)       -- 0x800B6368 (60B)
//   Checks if a GUID belongs to a member. Returns bool.
//
// GetMemberByGUID(int guid)  -- 0x800B6334 (52B)
//   Returns the FamilyMember entry for a given GUID.
//
// GetIndexedMember(int idx)  -- 0x800B63A4 (52B)
//   Returns the FamilyMember at the given index.
//
// CountMembers()             -- 0x800B6414 (20B)
//   Returns the number of members in the family.
//
// GetFriendCount()           -- 0x800B6428 (60B)
//   Returns cumulative friend count across all members.
//
// GetNetWorth()              -- 0x800B6464 (60B)
//   Returns family funds + house value.
//
// DoStream(ReconBuffer*, int) -- 0x800B6548 (264B)
//   Serializes/deserializes the family data. Streams:
//   - Family number, house number, funds, creation order
//   - All flags (hasPhone, hasBaby, justMovedIn, isFreeplay,
//     hasP1DoneCAS, hasP2DoneCAS)
//   - Member list (vector of FamilyMember)
//
// SetFunds(int amount)       -- 0x800B6B40 (32B)
//   Sets the family's simoleons. Clamps to a minimum of 0.
//   // cmpwi r4, 0; bge +8; li r4, 0
//
// Family flag accessors (all at 0x800B6B80..0x800B6C7C):
//   SetHasPhone/GetHasPhone     -- Home phone ownership
//   SetHasBaby/GetHasBaby       -- Baby in household
//   SetJustMovedIn/GetJustMovedIn -- First-time move-in flag
//   SetIsFreeplay/GetIsFreeplay  -- Freeplay mode family
//   SetHasP1DoneCAS/GetHasP1DoneCAS -- Player 1 finished CAS
//   SetHasP2DoneCAS/GetHasP2DoneCAS -- Player 2 finished CAS

// ============================================================================
// PlayerFamilyImpl -- PLAYER-CONTROLLED FAMILY
// ============================================================================
//
// Size: 0xD68 (3432 bytes) -- inherits from FamilyImpl
// Constructor: 0x8012CF68 (104B)
// Destructor:  0x8012CFD0 (104B)
// vtable:      0x80463248 (384 bytes)
//
// PlayerFamilyImpl extends FamilyImpl with player-specific data:
//   - Inventory system (BBI::InventoryItems)
//   - Goal and unlock tracking (GoalAndUnlockData)
//   - Clothing unlock state
//   - Aspiration score total
//   - Stats tracking (career, skills, etc.)
//
// The massive size (3432 bytes vs 56 for regular families) comes from
// embedded inventory data, unlock bitmasks, and stat arrays.
//
// Notable fields:
//   0xD60  u32   m_convertFlag       -- ConvertToRegularFamilyOnWrite flag
//   0xD64  u32   m_totalAspirationScore
//
// ConvertToRegularFamilyOnWrite() sets a flag that causes the family
// to be saved as a regular FamilyImpl (56 bytes) instead of
// PlayerFamilyImpl. Used when a player family is evicted and becomes
// an NPC family.

// ============================================================================
// NeighborhoodImpl::AddToFamily -- Add a neighbor to a family
// ============================================================================
// Address: 0x800CF028  Size: 420 bytes (105 instructions)
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Links a Neighbor into a Family. Updates both the family's member list
// and the neighbor's family reference. Also updates the neighborhood-level
// tracking (family friends count, etc.).
//
// Flow:
//   1. Get the neighbor's GUID (via Neighbor::GetFamily -> GUID lookup)
//   2. Check if neighbor is already in this family (via vtable TestMember)
//   3. If not a member, call Family::AddMember(guid)
//   4. Update neighborhood tracking via UpdateFamilyNumbers
//   5. Update the lot system if family is in a house
//   6. If neighbor has a person object (cXPerson), update its family ref

int NeighborhoodImpl::AddToFamily(Neighbor* neighbor, Family* family) {
    // Get neighbor's GUID
    // vtable call at family vtable offsets 0x58/0x5C (family->GetMemberList)
    int guid = neighbor->GetGUID();

    // Check if already a member
    // family vtable call TestMember at 0x48/0x4C
    bool alreadyMember = family->TestMember(guid);
    if (alreadyMember) {
        return -1;  // already in this family
    }

    // Add to family
    family->AddMember(guid);  // bl 0x800B6818

    // Update neighborhood tracking
    this->UpdateFamilyNumbers();

    // Update lot system
    // Check if family is in a house via vtable GetHouseNumber
    // If so, update the house's resident list

    // Update person's family reference
    // Access global Globs via r13
    // If the neighbor has an associated cXPerson, update it
    // cXPerson vtable call at 0xE8/0xEC

    return 0;
}

// ============================================================================
// Neighbor -- INDIVIDUAL SIM DATA
// ============================================================================
//
// Size: 0x1B8 (440 bytes)
// Constructor: 0x800C9A9C (via constructor at 0x8026E998)
// vtable:      multiple (varies by neighbor type)
//
// A Neighbor represents a single Sim in the neighborhood, whether playable
// or NPC. It stores persistent data that survives across lot loads:
//
// ---- FIELD MAP ----
//
// 0x000  void** _vtable
// 0x002  u8    m_field_002           -- Used in ForceNewTree (wants/fears)
// 0x004  s16   m_field_004           -- Linked list or index field
// 0x008  u16   m_familyNumber        -- Which family this neighbor belongs to
// 0x00B  u8    m_field_00B           -- ForceNewTree flags
// 0x00C  f32   m_isCharacter         -- Character flag (1.0 = character NPC)
//                                      Also read by CalculateWantFearAd
// 0x010  u32   m_relationshipData    -- Pointer to relationship array
// 0x014  u32   m_field_014           -- Copy operator storage
// 0x018  u32   m_uiData              -- UI data pointer (want/fear dialogs)
// 0x01C  u16   m_friendCount         -- Cached friend count
// 0x01E  u16   m_enemyCount          -- Cached enemy count
// 0x020  u16   m_reputationValue     -- Neighborhood reputation
// 0x022  u16   m_field_022           -- Relationship tracking
// 0x024  u32   m_field_024           -- Relationship data/count
//
// Person data block (0x074-0x094):
//   0x074-0x07E  u16[6]  -- Personal interest values (6 interests)
//   0x082  s16   m_neatSloppy         -- Personality: Neat(+) vs Sloppy(-)
//   0x084  s16   m_outgoingShy        -- Personality: Outgoing vs Shy
//   0x086  s16   m_activeLazy         -- Personality: Active vs Lazy
//   0x088  s16   m_playfulSerious     -- Personality: Playful vs Serious
//   0x08A  s16   m_niceMean           -- Personality: Nice vs Mean
//   0x08C  s16   m_field_08C          -- Additional personality trait
//   0x08E  s16   m_field_08E          -- Additional personality trait
//   0x090  s16   m_field_090          -- Additional personality trait
//   0x092  s16   m_field_092          -- Additional personality trait
//   0x094  s16   m_field_094          -- Additional personality trait
//   0x098  u16   m_field_098          -- LoadFromCharacter
//   0x0A0  s16   m_field_0A0          -- Default value: loaded/saved
//
// Relationship data (0x0BC-0x0C0):
//   0x0BC  u32   m_relationshipList   -- Pointer to relationship array
//   0x0C0  u32   m_relationshipCount  -- Number of relationships
//
// Aspiration/Wants/Fears (0x0E0-0x1B4):
//   0x0E0  s16   m_aspirationType     -- Aspiration category
//   0x0E2  s16   m_aspirationLevel    -- Current aspiration level
//   0x0E4  s16   m_field_0E4          -- Aspiration data
//   0x0EE  s16   m_field_0EE          -- Default value set
//   0x104  u16   m_field_104          -- Default value set
//   0x110  f32   m_aspirationScore    -- Current aspiration score
//   0x11C  f32   m_field_11C          -- Used by CalculateWantFearAd
//   0x150  f32   m_field_150          -- Default value set
//   0x194  u32   m_wantFearData       -- Active wants/fears bookmarks
//   0x1B4  u32   m_field_1B4          -- Wants/fears state flags
//
// Key methods:
//   GetFamily()               -- 0x800C9A9C (180B) -- look up Family by m_familyNumber
//   RecalculateRelationshipData() -- 0x8026FF08 (1236B) -- rebuild cached counts
//   AdjustRelationship(Neighbor*, int) -- 0x80270F68 (384B) -- modify relationship score
//   IsMarriedTo(Neighbor*)    -- 0x80270C6C (264B) -- check marriage status
//   Notify(WantFear::Notification&, bool) -- 0x80271EAC (800B) -- process event
//   InitWantsFears()          -- 0x80271B50 (228B) -- initialize want/fear system
//   ShuffleWantFear(int)      -- 0x80274CD4 (284B) -- randomize wants/fears

// ============================================================================
// cFixedWorldImpl -- LOT TILE GRID
// ============================================================================
//
// Size: 0x62+ (98+ bytes, actual size depends on allocated arrays)
// Constructor: 0x8014C524 (156B)
// Destructor:  0x8014C5C0 (112B)
// vtable:      0x80465388 (320 bytes)
// Commander vtable: 0x80465368 (32 bytes)
//
// cFixedWorldImpl manages the tile-based lot grid. It owns the floor tiles,
// wall segments, room assignments, and routing flags for a single lot.
//
// ---- FIELD MAP ----
//
// 0x000  void** _vtable             -- Main vtable (0x80465388)
// 0x004  ---    m_wallData           -- Wall collision data structure
//                                      (initialized via ctor at 0x800B4214)
// 0x010  void** _commanderVtable    -- Commander interface vtable (0x80465368)
// 0x014  int    m_xSize              -- Lot width in tiles
// 0x018  int    m_ySize              -- Lot height in tiles
// 0x01C  int    m_routableMinX       -- Routable area bounds
// 0x020  int    m_routableMinY
// 0x024  int    m_routableMaxX
// 0x028  int    m_routableMaxY
// 0x02C  u32*   m_floorArray         -- Floor tile pattern array (xSize * ySize)
// 0x030  u16*   m_roomArray          -- Room ID per tile
// 0x034  u8*    m_flagsArray         -- Per-tile flags (outside, routing, etc.)
// 0x038  u32*   m_wallStorageArray   -- Wall segment data per tile
// 0x03C  int    m_allocatedX         -- Currently allocated array width
// 0x040  int    m_allocatedY         -- Currently allocated array height
// 0x048  s16    m_field_048          -- OutOfRoutableExtent check
// 0x058  s16    m_field_058          -- OutOfBounds check
// 0x060  s16    m_field_060          -- OutOfGrid check
//
// The arrays at 0x02C-0x038 are dynamically allocated when SetSize is called.
// They are freed by DeleteArrays and reallocated if the lot size changes.
//
// Key methods:
//   SetSize(int x, int y, bool) -- 0x8014C630 (1168B)
//     Allocates/reallocates all tile arrays. If preserveData is true,
//     copies existing tile data to the new arrays (for lot resizing).
//     Minimum lot size is 8x8 (enforced by bounds check).
//     Creates temporary cFixedWorldImpl objects to hold old data during resize.
//
//   ComputeRooms(int)    -- 0x8014D624 (11760B!) -- THE LARGEST FUNCTION
//     Flood-fills room assignments from wall data. This massive function
//     (nearly 12KB of code) implements a sophisticated room detection
//     algorithm that handles multi-story rooms, outdoor areas, and
//     irregular wall configurations.
//
//   ComputeArchValue(bool*) -- 0x80150414 (836B)
//     Calculates the architectural value of the lot based on room sizes,
//     wall coverage, and floor quality.
//
//   GetWall(CTilePt&)    -- 0x8014CDD4 (748B)
//     Returns the wall data for a tile position. Handles boundary
//     conditions and multi-layer wall segments.
//
//   SetWall(CTilePt&, TileWalls) -- 0x8014D0C0 (1380B)
//     Sets wall data for a tile. Propagates wall changes to adjacent
//     tiles (walls are shared between tiles).
//
//   OffsetWorld(CTilePt&) -- 0x801507F4 (4044B)
//     Shifts the entire world grid by an offset. Used when expanding
//     the lot or repositioning the build area.

// ============================================================================
// cFixedWorldImpl::cFixedWorldImpl -- Constructor
// ============================================================================
// Address: 0x8014C524  Size: 156 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.

cFixedWorldImpl::cFixedWorldImpl(int xSize, int ySize) {
    // Set main vtable
    _vtable = &cFixedWorldImpl_vtable;  // 0x80465388

    // Initialize wall data structure at offset 0x004
    // bl 0x800B4214 (wall data init)

    // Set commander vtable at offset 0x010
    _commanderVtable = &cFixedWorldImpl_Commander_vtable;  // 0x80465368
    // Also update main vtable (overwritten after commander init)
    _vtable = &cFixedWorldImpl_vtable;  // written again at 0x8014C57C

    // Clear all array pointers and sizes
    m_wallStorageArray = 0;  // offset 0x038
    m_xSize = 0;             // offset 0x014
    m_ySize = 0;             // offset 0x018
    m_floorArray = 0;        // offset 0x02C
    m_roomArray = 0;         // offset 0x030
    m_flagsArray = 0;        // offset 0x034
    m_allocatedX = 0;        // offset 0x03C
    m_allocatedY = 0;        // offset 0x040

    // Now allocate arrays for the requested size
    SetSize(xSize, ySize, false);  // bl 0x8014C630

    // Initialize physics/collision
    // bl 0x80145EF0 (some init function)
}

// ============================================================================
// cFixedWorldImpl::SetSize -- Allocate/resize lot arrays
// ============================================================================
// Address: 0x8014C630  Size: 1168 bytes (292 instructions)
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Allocates all per-tile arrays for the lot. If the lot already has the
// requested size, returns immediately. If preserveData is true, copies
// existing tile data to new arrays before freeing the old ones.

bool cFixedWorldImpl::SetSize(int xSize, int ySize, bool preserveData) {
    // Check if size already matches
    if (m_xSize == xSize && m_ySize == ySize) {
        return true;
    }

    // Validate minimum size via vtable call GetMaxSize
    int maxSize = this->GetMaxSize();
    if (xSize > maxSize || ySize > maxSize) {
        return false;
    }
    if (xSize <= 7 || ySize <= 7) {
        return false;
    }

    if (preserveData) {
        // Create 3 temporary cFixedWorldImpl objects to hold old data
        // Each temp world is 0x18 (24) bytes -- just enough to hold the
        // array pointers and sizes
        // bl 0x800D1B1C -- copy lot data to temp world
        // Then free old arrays, allocate new ones, copy data back

        // Temp world 1: floor/room data
        cFixedWorldImpl* temp1 = new cFixedWorldImpl();
        // Copy current data to temp1
        // ... allocation and copy logic ...

        // Temp world 2: wall data
        cFixedWorldImpl* temp2 = new cFixedWorldImpl();

        // Temp world 3: flag data
        cFixedWorldImpl* temp3 = new cFixedWorldImpl();
    }

    // Free existing arrays
    DeleteArrays();

    // Allocate new arrays
    int tileCount = xSize * ySize;
    m_floorArray = new FloorPattern[tileCount];
    m_roomArray = new u16[tileCount];
    m_flagsArray = new u8[tileCount];
    m_wallStorageArray = new TileWallStorage[tileCount];

    // Store new sizes
    m_xSize = xSize;
    m_ySize = ySize;
    m_allocatedX = xSize;
    m_allocatedY = ySize;

    // Set routable area bounds (inset by some margin)
    m_routableMinX = 0;
    m_routableMinY = 0;
    m_routableMaxX = xSize;
    m_routableMaxY = ySize;

    // Initialize all tiles to default values
    // memset floors to grass, rooms to 0, flags to "outside"

    if (preserveData) {
        // Copy data back from temp worlds
        // Free temp worlds
    }

    return true;
}

// ============================================================================
// HouseImpl -- LOT / HOUSE DATA
// ============================================================================
//
// Size: 0x74 (116 bytes)
// Constructor: 0x800BC494 (via 0x8024AC28)
// vtable:      at .data section
//
// HouseImpl represents a single lot in the neighborhood. It owns:
//   - The cFixedWorldImpl (tile grid) for the lot
//   - Object placement data
//   - Budget/value tracking
//   - Family assignment
//
// Key methods:
//   Initialize()        -- 0x8024AD30 (1060B) -- Set up lot from scratch
//   LoadFile(iResFile*) -- 0x8024B4E0 (3072B) -- Load lot from save file
//   SaveFile(iResFile*) -- 0x8024C32C (340B)  -- Save lot to file
//   SetLotSize(int,int) -- 0x8024B344 (412B)  -- Resize the lot
//   Destroy()           -- 0x8024B154 (288B)  -- Free all lot data
//   IsResident(cXPerson*) -- 0x8024C9CC (376B) -- Check if person lives here
//   GetHouseStats(HouseStats&) -- 0x8024CD94 (864B) -- Calculate lot stats
//   ComputeAndStoreLotData()   -- 0x8024C0E0 (588B) -- Compute derived data

// ============================================================================
// HoodManager -- HIGH-LEVEL NEIGHBORHOOD OPERATIONS
// ============================================================================
//
// Size: 0x618C (24972 bytes -- nearly 25KB!)
// vtable: at .data section
//
// HoodManager performs complex multi-step neighborhood operations that
// affect multiple systems simultaneously.
//
// Key methods:
//   MoveInFamily(int lot, Family*, bool) -- 0x800C3D44 (348B)
//     Moves a family into a lot. Updates the lot's family reference,
//     spawns family members as cXPerson objects, and sets initial positions.
//
//   EvictFamily(int lot, bool) -- 0x800C4584 (1520B)
//     Removes a family from a lot. Handles selling furniture, saving
//     family data, removing person objects, and resetting the lot.
//
//   EvictFamilyAndLiquidateAssets(int lot) -- 0x800C41E4 (928B)
//     Evicts and sells everything. Family gets cash value of all objects.
//
//   DemolishCurrentHouse(int lot) -- 0x800C4E00 (2504B)
//     Destroys the house structure. Removes all walls, floors, and objects
//     but keeps the lot and family data. Expensive operation.
//
//   ResetToPristine() -- 0x800C57C8 (6660B!!)
//     Resets the ENTIRE neighborhood to its initial state. This is the
//     "New Game" function. At 6660 bytes, it's one of the largest
//     functions in the game. It must:
//     - Remove all families
//     - Delete all custom neighbors
//     - Reset all lots to empty
//     - Clear all relationship data
//     - Reset all unlock progress
//     - Reinitialize all NPC characters
//
//   ResetNeighbors() -- 0x800C71CC (1240B)
//     Resets all neighbor data to defaults without clearing the lot.
//
//   GetMatrix(Neighbor*, Neighbor*, RelMatrix**, int*) -- 0x800C76A4 (228B)
//     Gets the relationship matrix entry between two neighbors.
//     The relationship system uses a matrix (RelMatrix) to store
//     bidirectional relationship scores.
//
//   GetRelatedPeople(int, cXPerson*, void*) -- 0x800C7C48 (716B)
//     Finds all people related to a given person. Used for family
//     tree display and inheritance calculations.

// ============================================================================
// NeighborhoodImpl::GetFamilyNetWorth -- Calculate family total assets
// ============================================================================
// Address: 0x800CF7D0  Size: 316 bytes
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Returns the total net worth of a family: cash funds + house value.
// Iterates through family members to accumulate additional asset values.

int NeighborhoodImpl::GetFamilyNetWorth(Family* family) {
    // Get base funds
    int funds = family->GetFunds();

    // Add house value if family is in a house
    int houseNum = family->GetHouseNumber();
    if (houseNum > 0) {
        int houseValue = family->GetHouseValue();
        funds += houseValue;
    }

    // May add additional per-member values (skills, career assets)
    return funds;
}

// ============================================================================
// NeighborhoodImpl::LoadHouse -- Load a lot from the save file
// ============================================================================
// Address: 0x800D0874  Size: 2204 bytes (551 instructions)
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Loads a complete lot (house + objects + characters) from the NghResFile.
// This is the main lot loading entry point called when entering a lot.
//
// Loading sequence:
//   1. Set house number
//   2. Load HouseImpl data from file
//   3. Load cFixedWorldImpl (tile grid, walls, floors)
//   4. Load all objects placed on the lot
//   5. Load resident person data (LoadPersistentData for each resident)
//   6. Initialize the simulation for this lot
//   7. Set up visitor/NPC spawn points

// ============================================================================
// NeighborhoodImpl::MoveOut -- Move family out of a lot
// ============================================================================
// Address: 0x800CFA4C  Size: 1632 bytes (408 instructions)
//
// NON_MATCHING -- Decompiled from PPC assembly.
//
// Handles the complex process of a family leaving their lot:
//   1. Save the current lot state to file
//   2. Save persistent data for all family members
//   3. Clear the family's house number
//   4. Remove person objects from the simulation
//   5. Optionally sell objects (if liquidating)
//   6. Update neighborhood family list
//   7. Trigger lot unload

// ============================================================================
// NEIGHBORHOOD SAVE FILE FORMAT (.NGH)
// ============================================================================
//
// The neighborhood is persisted via NghResFile, which wraps EA's iResFile
// binary format. Key resource tags:
//
//   'NGHB'  -- NeighborhoodImpl base data (via ReconLoadObject/ReconSaveObject)
//   'NBRS'  -- Neighbor array (vector<Neighbor*>)
//   'FMLY'  -- Family array
//   'HOUS'  -- House data per lot
//   'WRLD'  -- cFixedWorldImpl tile data
//   'OBJL'  -- Object list per lot
//   'PERS'  -- Persistent person data (per cXPerson)
//
// Each tag uses version numbers for forward compatibility.
// ReconBuffer handles endian conversion and alignment.
//
// Save methods:
//   NeighborhoodImpl::Save(NghResFile*, int) -- 0x800CD930 (764B)
//   NeighborhoodImpl::SaveHouse(NghResFile*) -- 0x800D1110 (388B)
//   NeighborhoodImpl::SavePersistentData(cXPerson*) -- 0x800CE408 (340B)
//   FamilyImpl::SaveFamily(iResFile*, int)  -- 0x800B6754 (128B)

// ============================================================================
// LOT MANAGEMENT
// ============================================================================
//
// Lots are numbered 1-16 in the neighborhood. The lot system supports:
//   - Up to 16 lots total (validated by MoveIn: cmplwi r0, 15)
//   - Each lot has a fixed position: GetLotPosition(int, int*, int*)
//   - Lots can be "freeplay" lots: IsFreeplayLot(int)
//   - Lots track occupancy: GetFamilyInHouse(int)
//   - House prices are computed: GetHousePrice(cSimulator*)
//
// The lot comparison function (compareHouses at 0x800D078C, 232B) is used
// to sort lots for the neighborhood map display.
//
// HouseInfo struct (filled by GetHouseInfo):
//   Contains lot name, price, family name, thumbnail ID, and occupied flag.
//
// FamilyInfo struct (filled by GetFamilyInfo):
//   Contains family name, member count, funds, friend count, and lot number.

// ============================================================================
// RELATIONSHIP SYSTEM (via Neighbor)
// ============================================================================
//
// Relationships between neighbors are stored as scored pairs.
// The RelMatrix (managed by HoodManager) stores bidirectional scores.
//
// Relationship levels (from CalculateRelationshipLevel):
//   tRelationshipType enum values control friend/enemy/romance thresholds.
//   CountRelationshipsOfType counts how many of each type a neighbor has.
//
// Key operations:
//   AdjustRelationship(Neighbor*, int) -- Add/subtract relationship score
//   IsMarriedTo(Neighbor*)             -- Check marriage status
//   RemoveAllRelationships()            -- Clear all (used on delete)
//   CopyRelationships(Neighbor*)        -- Clone from another neighbor

// ============================================================================
// NOTIFICATION SYSTEM
// ============================================================================
//
// The neighborhood uses a notification system to propagate events:
//
//   NotifyAllNeighbors(Notification&, Neighbor*)
//     -- Notifies every neighbor in the neighborhood (for global events
//        like "someone got married")
//
//   NotifyAllResidents(Notification&, Neighbor*)
//     -- Notifies only residents of the current house (for local events
//        like "fire in the kitchen")
//
//   NotifyAllPersons(Notification&, Neighbor*)
//     -- Notifies all active person objects (currently simulated sims)
//
// These drive the WantFear system: when a notification matches a neighbor's
// active Want or Fear, it triggers fulfillment or panic.
//
// WantFear event constants (from .sdata2):
//   WantFear::kEventFamilyFundsOfX   at 0x80500648 (2 bytes)
//   WantFear::kEventFamilyFundsPlat  at 0x8050064A (2 bytes)
