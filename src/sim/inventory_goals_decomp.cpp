// inventory_goals_decomp.cpp - Decompiled inventory, goals/unlocks, and wants/fears systems
// Original object files: inventory.obj, goalunlock.obj, wantfear.obj
//
// ============================================================================
// SYSTEM OVERVIEW: INVENTORY, GOALS & WANTS/FEARS
// ============================================================================
//
// These three systems drive The Sims 2 GC gameplay progression:
//
// 1. INVENTORY (BBI::InventoryItem / BBI::InventoryItems)
//    - Fixed-size container of 36 item slots (pointers to heap-allocated items)
//    - Each item has: category (u8), count (u8), colorIndex (u8), subcategory (u8),
//      guid (int), and a vtable pointer for polymorphic streaming
//    - Categories: 0=None, 1=Object (furniture/appliance), 2=BuildMode
//      (walls/floors/stairs), 3=PackagedItem (special bundled items)
//    - Subcategories for BuildMode: eItemSubcategory enum differentiates walls,
//      wallpaper, floor tiles, fences, etc.
//    - Items are reference-counted via count byte (max 99 per stack)
//    - Max 12 unique BuildMode items (category 2) in inventory at once
//    - Category assignment uses ObjDefinition field at offset +0x50 (type 512 = packed)
//      and field at offset +0x12 (object type ranges: 0-3=None, 4/7/15=Object,
//      5-6=None, 8=BuildMode, 9-14=None)
//
// 2. GOAL UNLOCK (GoalUnlock)
//    - Tracks unlocked content via a bitfield array at this+0x04, size 128 bytes
//    - Six UnlockType categories with different counts:
//        Type 0 (Lot objects):   32 unlocks, first var index 0
//        Type 1 (Career):       208 unlocks, first var index 31
//        Type 2 (Social):        24 unlocks, first var index 4
//        Type 3 (Build):         32 unlocks, first var index 7
//        Type 4 (Clothing):      32 unlocks, first var index 11
//        Type 5 (Objects):      128 unlocks, first var index 15
//    - Bitfield is organized as an array of 16-bit words. For unlock index N:
//        word_index = (N*2) / 16     (which 16-bit word)
//        bit_index  = (N*2) % 16     (which bit within word)
//    - "Recently unlocked" uses adjacent bit (N*2+1) in same bitfield
//    - Object unlocks are driven by a global table at 0x80485E7C (8 bytes per entry:
//      4-byte GUID + 2-byte simoleon threshold + 2-byte padding), up to 128 entries
//    - GrantObjectUnlocks converts a money amount to a "level" by dividing by 42
//      (via mulhw with magic constant 0x51EB851F) and checks each object entry's
//      threshold against it
//    - Serialization streams 39 halfwords for save version <= 16, 64 halfwords for > 16
//
// 3. WANTS/FEARS (WantFear::Bookmark / WantFearManager)
//    - Based on a tree structure: WantFearManager loads "want trees" from resources
//    - Each tree contains nodes (32 bytes each) with event references, branch info
//    - Events are 36 bytes each, stored contiguously, looked up by ID (linear search)
//    - A "Bookmark" references a specific node in a tree: {treeId, node*, adIndex, countdown}
//    - Neighbors hold 20 active bookmark slots (at neighbor offset +0x194, 12 bytes each)
//      plus 7 display icon slots (at neighbor offset +0x198/+0x198+icons)
//    - Event types: 0x01 = Platinum (special high-value want), 0x80 = Fear (negative)
//    - Node flags: bit 0 = hidden, bit 1 = target override (countdown holds target)
//    - Notification flow: game event -> Neighbor::Notify -> checks each active bookmark
//      via SatisfiedBy -> if matched, decrements countdown -> if 0, applies reward
//    - ApplyReward grants aspiration points (positive for wants, negative for fears)
//    - After satisfaction, ShuffleWantFear picks replacement using PickNewRoot with
//      weighted lottery selection
//    - Story trees (m_storyFlag & 1) provide narrative-linked progression wants
//    - Category shaders map event types to UI display icons
//    - Constants: kMaxAdMax=4 (max ads per node), kNoActiveIndex=0xFFFF,
//      kNoBookmarkIndex=0xFFFF, kNoTarget=0xFFFF
//    - Special events: kEventBuildBuyCategory, kEventBuildBuyWorth,
//      kEventFamilyFundsOfX, kEventFamilyFundsPlat, kEventAddARoom,
//      kEventBuildWalls, kEventBuyXLights, kEventBuyXChairs
//
// ============================================================================

#include "types.h"

#ifndef NULL
#define NULL 0
#endif

// External functions (from ReconBuffer streaming API)
extern "C" {
    void* ReconBuffer_StreamBytes(void* buf, void* data, int count);
    void* ReconBuffer_StreamInt(void* buf, void* data, int count);
    void* ReconBuffer_StreamHalfwords(void* buf, void* data, int count);
    void* operator_new_fn(u32 size);
    void  operator_delete_fn(void* ptr);
    void  memset(void* dst, int val, u32 n);
    int   RandomInt(int max);
}

// Placement new support
inline void* operator new(unsigned int, void* p) { return p; }

// Forward declarations
class ObjSelector;
class ObjDefinition;

// ReconBuffer stub
class ReconBuffer {
public:
    int  m_mode;       // 0 = read
    int  m_position;   // current position
};

// WantFear namespace types
namespace WantFear {
    struct Node {
        u16  eventRef;
        u8   flags;
        u8   _pad;
        s16  defaultTarget;
        s16  field_06;
        s16  field_08;
        u8   numBranches;
        u8   firstChildIndex;
        u32  field_0C;
        u8   adData[8];
        u32  field_18;
        u8   field_1C;
        u8   field_1D;
        u8   _pad2[2];
    };
    struct Event {
        u16 m_eventId;
        u8  type;
        u8  category;
        u8  _data[32];
    };
    struct Tree {
        u16   m_treeId;
        u8    storyFlag;
        u8    _pad;
        void* childIndexData;
        Node* nodes;
        u32   _extra[8];
    };
    struct Bookmark {
        u16    treeId;
        u16    m_countdown;
        Node*  m_node;
        u16    adIndex;
        u16    _pad;

        bool SatisfiedBy(struct Notification& n) { (void)n; return false; }
        bool IsFear() const { return false; }
        bool IsPlatinum() const { return false; }
        void ApplyReward(class Neighbor* n) { (void)n; }
    };
    struct Notification {
        u16 eventType;
        s16 m_target;
        u32 _extra[4];
    };
    enum TargetType { kTargetType_None = 0 };
}

// WantFearManager class
class WantFearManager {
public:
    WantFear::Event*   m_events;
    int                m_eventCount;
    WantFear::Tree*    m_trees;
    int                m_treeCount;
    void*              m_categoryShaders;
    int                m_categoryShaderCount;

    WantFearManager();
    ~WantFearManager();
    const WantFear::Event* GetEventByIndex(int index) const;
    const WantFear::Tree*  GetTreeByIndex(int index) const;
    const WantFear::Event* GetEvent(unsigned short eventId) const;
    const WantFear::Tree*  GetTree(unsigned short treeId) const;
    int    Lottery(unsigned int* weights, unsigned int count) const;
    void   PickNewRoot(class Neighbor* neighbor, bool isFear);
    void   LoadWants();
    const WantFear::Node* GetStoryTreeRoot(short aspirationType, short chapter) const;
    u32    GetCategoryShader(WantFear::TargetType type, short param);
    void   CaptureLog(bool enable);
};

// Global pointers (from SDA / r13)
extern WantFearManager* g_pWantFearManager;  // 0x80475EEC

// Global object unlock table
struct ObjectUnlockEntry {
    u32 guid;
    s16 simoleonThreshold;
    s16 _pad;
};
extern ObjectUnlockEntry g_objectUnlockTable[128];  // at 0x80485E7C

// Neighbor class (partial -- only fields used here)
class Neighbor {
public:
    u8                 _pad[0x194];
    WantFear::Bookmark* m_activeBookmarks; // +0x194
    void*              m_wantFearIcons[7]; // +0x198

    int  Notify(WantFear::Notification& notification, bool broadcastFears);
    void ShuffleWantFear(int slotIdx);
    void ReplaceBookmark(int slotIdx);
    void RefreshBookmarkIcon(int slotIdx, int mode);
    int  GetRandomEmptySlot(int type);
};

// BBI namespace class declarations (must come before method definitions)
namespace BBI {

class InventoryItem {
public:
    // Enumerations nested in class
    enum eItemCategory {
        kItemCategory_None         = 0,
        kItemCategory_Object       = 1,
        kItemCategory_BuildMode    = 2,
        kItemCategory_PackagedItem = 3,
    };
    enum eItemSubcategory {
        kItemSubcategory_None      = 0,
        kItemSubcategory_Wall      = 1,
        kItemSubcategory_Wallpaper = 2,
        kItemSubcategory_Floor     = 3,
        kItemSubcategory_Fence     = 4,
        kItemSubcategory_Stairs    = 5,
        kItemSubcategory_Generic   = 6,
    };

    // Fields (layout from constructor analysis)
    u8   m_category;     // 0x00
    u8   m_count;        // 0x01
    u8   m_colorIndex;   // 0x02
    u8   m_subcategory;  // 0x03
    s32  m_guid;         // 0x04
    u32* m_vtable;       // 0x08

    InventoryItem();
    ~InventoryItem();
    eItemCategory    GetItemCategory() const;
    void             SetItemCategory(eItemCategory cat);
    eItemSubcategory GetItemSubcategory() const;
    void             SetItemSubcategory(eItemSubcategory subcat);
    int              GetItemGuid() const;
    void             SetItemGuid(int guid);
    int              GetItemCount() const;
    void             SetItemCount(int count);
    unsigned char    GetItemColorIndex() const;
    void             SetItemColorIndex(unsigned char index);
    bool             CopyTo(InventoryItem* dest) const;
    bool             DoStream(ReconBuffer* buf, int version);
};

class InventoryItems {
public:
    InventoryItem* m_items[36]; // 0x00 - 0x8F

    InventoryItems();
    ~InventoryItems();
    int              GetContainerSize() const;
    InventoryItem*   GetItemAtIndex(int index) const;
    int              GetNewItemIndex() const;
    InventoryItem*   GetItemByGuid(int guid, unsigned char colorIndex) const;
    int              GetItemIndexByGuid(int guid, unsigned char colorIndex) const;
    bool             IsItemInInventory(int guid) const;
    int              GetItemCount() const;
    int              CountItemsByGuid(int guid) const;
    int              CountItemsByCategory(InventoryItem::eItemCategory category) const;
    bool             CanAddItemsByGuid(int guid, int count, unsigned char colorIndex) const;
    int              AddItemsByGuid(int guid, int count, unsigned char colorIndex);
    int              RemoveItemsByGuid(int guid, int count, unsigned char colorIndex);
    bool             DeleteItem(InventoryItem* item);
    void             Clear();
    InventoryItem*   GetBuilderItem(InventoryItem::eItemSubcategory subcat, int guid) const;
    int              GetBuilderItemIndex(InventoryItem::eItemSubcategory subcat, int guid) const;
    bool             CanAddBuilderItem(InventoryItem::eItemSubcategory subcat, int guid, int count) const;
    int              AddBuilderItem(InventoryItem::eItemSubcategory subcat, int guid, int count);
    bool             RemoveBuilderItem(InventoryItem::eItemSubcategory subcat, int guid);
    int              GetBuilderItemCount(InventoryItem::eItemSubcategory subcat) const;
    InventoryItem*   CreateNewItemFromGuid(int guid) const;
    InventoryItem*   CreateNewBuilderItem(InventoryItem::eItemSubcategory subcat, int guid) const;
    InventoryItem::eItemCategory GetItemCategoryFromObjDefinition(ObjDefinition* def);
    bool             DoStream(ReconBuffer* buf, int version);
    bool             DoStreamWrite(ReconBuffer* buf, int version);
    bool             DoStreamRead(ReconBuffer* buf, int version);
};

} // namespace BBI (closed here, reopened below for method bodies)


// ============================================================================
// BBI::InventoryItem — Individual inventory item (12 bytes + vtable)
// ============================================================================
//
// Memory layout (from constructor + field access analysis):
//   0x00: u8   m_category       (eItemCategory)
//   0x01: u8   m_count          (0-99, stack size)
//   0x02: u8   m_colorIndex     (color variant)
//   0x03: u8   m_subcategory    (eItemSubcategory, for build mode items)
//   0x04: s32  m_guid           (unique object identifier)
//   0x08: u32* m_vtable         (virtual function table at 0x8045B920)
//
// vtable layout (from 0x8045B920, 40 bytes = 10 entries):
//   +0x00: ???
//   +0x10: DoStream vfunc offset (lha r3, 16(r9))
//   +0x14: DoStream vfunc pointer
//   +0x18: destructor offset
//   +0x1C: destructor pointer

namespace BBI {

// ============================================================================
// BBI::InventoryItem::InventoryItem
// Address: 0x8004A060, Size: 48 bytes
// MATCHING
// ============================================================================
InventoryItem::InventoryItem() {
    // vtable at 0x8045B920 = -32698 << 16 + (-18144) = 0x8045B920
    m_vtable = (u32*)0x8045B920;
    m_subcategory = 0;
    m_guid = 0;
    m_category = 0;
    m_count = 0;
    m_colorIndex = 0;
}

// ============================================================================
// BBI::InventoryItem::~InventoryItem
// Address: 0x8004A090, Size: 52 bytes
// MATCHING
// Restores vtable, conditionally frees (flag & 1 => operator delete)
// ============================================================================
InventoryItem::~InventoryItem() {
    m_vtable = (u32*)0x8045B920;
    // if (flags & 1) operator_delete(this);
    // (handled by compiler-generated destructor dispatch)
}

// ============================================================================
// BBI::InventoryItem::GetItemCategory
// Address: 0x8004A0F8, Size: 12 bytes
// MATCHING
// Returns signed byte at offset 0x00
// ============================================================================
InventoryItem::eItemCategory InventoryItem::GetItemCategory() const {
    return (eItemCategory)(s8)m_category;
}

// ============================================================================
// BBI::InventoryItem::SetItemCategory
// Address: 0x8004A0C4, Size: 52 bytes
// MATCHING
// Calls GetItemCategory first (compiler artifact), then stores
// ============================================================================
void InventoryItem::SetItemCategory(eItemCategory cat) {
    GetItemCategory();  // compiler artifact - SN compiler reads before write
    m_category = (u8)cat;
}

// ============================================================================
// BBI::InventoryItem::GetItemSubcategory
// Address: 0x8004A138, Size: 12 bytes
// MATCHING
// Returns signed byte at offset 0x03
// ============================================================================
InventoryItem::eItemSubcategory InventoryItem::GetItemSubcategory() const {
    return (eItemSubcategory)(s8)m_subcategory;
}

// ============================================================================
// BBI::InventoryItem::SetItemSubcategory
// Address: 0x8004A104, Size: 52 bytes
// MATCHING (same pattern as SetItemCategory)
// ============================================================================
void InventoryItem::SetItemSubcategory(eItemSubcategory subcat) {
    GetItemSubcategory();
    m_subcategory = (u8)subcat;
}

// ============================================================================
// BBI::InventoryItem::GetItemGuid
// Address: 0x8004A20C, Size: 8 bytes
// MATCHING
// Returns 32-bit int at offset 0x04
// ============================================================================
int InventoryItem::GetItemGuid() const {
    return m_guid;
}

// ============================================================================
// BBI::InventoryItem::SetItemGuid
// Address: 0x8004A214, Size: 52 bytes
// MATCHING (reads guid first, same SN compiler pattern)
// ============================================================================
void InventoryItem::SetItemGuid(int guid) {
    GetItemGuid();
    m_guid = guid;
}

// ============================================================================
// BBI::InventoryItem::GetItemCount
// Address: 0x8004A298, Size: 12 bytes
// MATCHING
// Returns unsigned byte at offset 0x01
// ============================================================================
int InventoryItem::GetItemCount() const {
    return m_count;
}

// ============================================================================
// BBI::InventoryItem::SetItemCount
// Address: 0x8004A248, Size: 80 bytes
// MATCHING
// Clamps count to [0, 99] range
// ============================================================================
void InventoryItem::SetItemCount(int count) {
    GetItemCount();  // compiler artifact
    if (count < 0) {
        count = 0;
    } else if (count > 99) {
        count = 99;
    }
    m_count = (u8)count;
}

// ============================================================================
// BBI::InventoryItem::GetItemColorIndex
// Address: 0x8004A2D8, Size: 8 bytes
// MATCHING
// ============================================================================
unsigned char InventoryItem::GetItemColorIndex() const {
    return m_colorIndex;
}

// ============================================================================
// BBI::InventoryItem::SetItemColorIndex
// Address: 0x8004A2A4, Size: 52 bytes
// MATCHING
// ============================================================================
void InventoryItem::SetItemColorIndex(unsigned char index) {
    GetItemColorIndex();
    m_colorIndex = index;
}

// ============================================================================
// BBI::InventoryItem::CopyTo
// Address: 0x8004A2E0, Size: 60 bytes
// MATCHING
// Copies raw bytes of this item to destination (preserves dest vtable)
// ============================================================================
bool InventoryItem::CopyTo(InventoryItem* dest) const {
    if (dest == nullptr) return false;
    // Copy first 8 bytes (category, count, color, subcat, guid) directly
    // Preserves destination's vtable pointer
    u32 word0 = *(u32*)&m_category;
    u32 word1 = m_guid;
    *(u32*)&dest->m_category = word0;
    dest->m_guid = word1;
    // vtable preserved via stack spill (compiler artifact)
    return true;
}

// ============================================================================
// BBI::InventoryItem::DoStream
// Address: 0x8004A144, Size: 200 bytes
// NON_MATCHING - streaming call sequence, padding loop
// Streams individual fields: category, count, colorIndex, subcategory, guid
// Then pads remaining bytes in the 12-byte record
// ============================================================================
bool InventoryItem::DoStream(ReconBuffer* buf, int version) {
    if (buf == nullptr) return false;

    int prevPos = buf->m_position;  // offset +0x08

    // Stream each field as a single byte/int
    ReconBuffer_StreamBytes(buf, &m_category, 1);
    ReconBuffer_StreamBytes(buf, &m_count, 1);
    ReconBuffer_StreamBytes(buf, &m_colorIndex, 1);
    ReconBuffer_StreamBytes(buf, &m_subcategory, 1);
    ReconBuffer_StreamInt(buf, &m_guid, 1);

    // Pad to fixed record size if not reading (buf->m_mode == 0 means read)
    if (buf->m_mode == 0) {
        int bytesWritten = buf->m_position - prevPos;
        int remaining = 8 - bytesWritten;
        if (remaining > 0) {
            u8 padding = 0;
            while (remaining > 0) {
                ReconBuffer_StreamBytes(buf, &padding, 1);
                remaining--;
            }
        }
    }
    return true;
}


// ============================================================================
// BBI::InventoryItems — Container of 36 inventory item pointers
// ============================================================================
//
// Memory layout:
//   0x00 - 0x8F: InventoryItem* m_items[36]  (36 pointers, 144 bytes)
//
// The container is a flat array of 36 pointers. nullptr means empty slot.
// Items are heap-allocated (operator new(12)) and owned by the container.
// Maximum 36 total items, maximum 12 build-mode items, max 99 per stack.

static const int kInventorySlotCount = 36;   // 0x24
static const int kMaxBuildModeItems  = 12;   // 0x0C - including the one being added
static const int kMaxStackCount      = 99;   // 0x63

// ============================================================================
// BBI::InventoryItems::InventoryItems
// Address: 0x8004A31C, Size: 32 bytes
// MATCHING
// Zeros all 36 slots using a CTR loop (36 iterations, clearing backwards)
// ============================================================================
InventoryItems::InventoryItems() {
    // Loop: r11=36 (ctr), starts at this+0x8C (end), stores 0, decrements
    for (int i = kInventorySlotCount - 1; i >= 0; i--) {
        m_items[i] = nullptr;
    }
}

// ============================================================================
// BBI::InventoryItems::~InventoryItems
// Address: 0x8004A33C, Size: 64 bytes
// NON_MATCHING - destructor dispatch sequence
// Calls Clear() to free all items, no additional cleanup
// ============================================================================
InventoryItems::~InventoryItems() {
    Clear();
}

// ============================================================================
// BBI::InventoryItems::GetContainerSize
// Address: 0x8004AA5C, Size: 8 bytes
// MATCHING
// Always returns 36
// ============================================================================
int InventoryItems::GetContainerSize() const {
    return kInventorySlotCount;
}

// ============================================================================
// BBI::InventoryItems::GetItemAtIndex
// Address: 0x8004AA64, Size: 28 bytes
// MATCHING
// Bounds-checked array access
// ============================================================================
InventoryItem* InventoryItems::GetItemAtIndex(int index) const {
    if (index > 35) return nullptr;
    return m_items[index];
}

// ============================================================================
// BBI::InventoryItems::GetNewItemIndex
// Address: 0x8004AFA8, Size: 68 bytes
// MATCHING
// Linear scan for first nullptr slot. Returns -1 if full.
// ============================================================================
int InventoryItems::GetNewItemIndex() const {
    int result = -1;
    // Check slot 0 first (unrolled)
    if (m_items[0] == nullptr) {
        return 0;
    }
    // Then scan 1..35
    for (int i = 1; i <= 35; i++) {
        if (m_items[i] == nullptr) {
            result = i;
            break;
        }
    }
    return result;
}

// ============================================================================
// BBI::InventoryItems::GetItemByGuid
// Address: 0x8004A9A4, Size: 68 bytes
// MATCHING
// Looks up item by GUID and color index. Delegates to GetItemIndexByGuid.
// ============================================================================
InventoryItem* InventoryItems::GetItemByGuid(int guid, unsigned char colorIndex) const {
    int index = GetItemIndexByGuid(guid, colorIndex);
    if (index == -1) return nullptr;
    return m_items[index];
}

// ============================================================================
// BBI::InventoryItems::GetItemIndexByGuid
// Address: 0x8004AFEC, Size: 140 bytes
// MATCHING
// Linear search matching both GUID and color index
// ============================================================================
int InventoryItems::GetItemIndexByGuid(int guid, unsigned char colorIndex) const {
    int size = GetContainerSize();
    for (int i = 0; i < size; i++) {
        InventoryItem* item = m_items[i];
        if (item == nullptr) continue;
        if (item->GetItemGuid() != guid) continue;
        if (item->GetItemColorIndex() != colorIndex) continue;
        return i;
    }
    return -1;
}

// ============================================================================
// BBI::InventoryItems::IsItemInInventory
// Address: 0x8004A9E8, Size: 116 bytes
// MATCHING
// Returns true if any item with matching GUID exists (ignores color)
// ============================================================================
bool InventoryItems::IsItemInInventory(int guid) const {
    int size = GetContainerSize();
    for (int i = 0; i < size; i++) {
        InventoryItem* item = m_items[i];
        if (item == nullptr) continue;
        if (item->GetItemGuid() == guid) return true;
    }
    return false;
}

// ============================================================================
// BBI::InventoryItems::GetItemCount
// Address: 0x8004A7A0, Size: 96 bytes
// MATCHING
// Counts non-null slots (number of distinct item stacks)
// ============================================================================
int InventoryItems::GetItemCount() const {
    int count = 0;
    int size = GetContainerSize();
    for (int i = 0; i < size; i++) {
        if (m_items[i] != nullptr) {
            count++;
        }
    }
    return count;
}

// ============================================================================
// BBI::InventoryItems::CountItemsByGuid
// Address: 0x8004A800, Size: 120 bytes
// MATCHING
// Sums up GetItemCount() for all items matching the given GUID
// ============================================================================
int InventoryItems::CountItemsByGuid(int guid) const {
    int total = 0;
    int size = GetContainerSize();
    for (int i = 0; i < size; i++) {
        InventoryItem* item = m_items[i];
        if (item == nullptr) continue;
        if (item->GetItemGuid() != guid) continue;
        total += item->GetItemCount();
    }
    return total;
}

// ============================================================================
// BBI::InventoryItems::CountItemsByCategory
// Address: 0x8004A878, Size: 140 bytes
// MATCHING
// Counts items in a specific category. Rejects categories outside [1,3].
// ============================================================================
int InventoryItems::CountItemsByCategory(InventoryItem::eItemCategory category) const {
    if (category < 1 || category > 3) return 0;
    int count = 0;
    int size = GetContainerSize();
    for (int i = 0; i < size; i++) {
        InventoryItem* item = m_items[i];
        if (item == nullptr) continue;
        if (item->GetItemCategory() == category) {
            count++;
        }
    }
    return count;
}

// ============================================================================
// BBI::InventoryItems::CanAddItemsByGuid
// Address: 0x8004A37C, Size: 236 bytes
// NON_MATCHING - CR bit manipulation for boolean return
// Checks if 'count' items with given GUID can be added.
// If item already exists: checks (current + count) <= 99
// If item is new: looks up ObjDefinition via global catalog, checks category
//   capacity (max 12 build-mode items)
// ============================================================================
bool InventoryItems::CanAddItemsByGuid(int guid, int count, unsigned char colorIndex) const {
    if (guid == 0) return false;
    if (count <= 0) return false;

    // Check if item already in inventory (same guid + color)
    InventoryItem* existing = GetItemByGuid(guid, colorIndex);
    if (existing != nullptr) {
        // Can add if total <= 99
        return (existing->GetItemCount() + count) <= kMaxStackCount;
    }

    // Item not in inventory - need to check if there's room
    // Look up the global catalog to get ObjDefinition
    // g_pObjectModuleImpl (at r13-21508) -> GetObjectByGuid(guid)
    // Then check category and enforce max 12 build-mode items
    // If category is build-mode, ensure CountItemsByCategory(2)+1 <= 12 and count <= 99
    // Stubbed: requires global catalog access
    return false;
}

// ============================================================================
// BBI::InventoryItems::AddItemsByGuid
// Address: 0x8004A468, Size: 188 bytes
// NON_MATCHING - register allocation
// Adds 'count' items with given GUID. Creates new item if needed.
// Returns number of items that couldn't be added (overflow past 99).
// ============================================================================
int InventoryItems::AddItemsByGuid(int guid, int count, unsigned char colorIndex) {
    if (guid == 0) return 0;
    if (count == 0) return 0;

    // Try to find existing item with same guid+color
    InventoryItem* item = GetItemByGuid(guid, colorIndex);
    if (item == nullptr) {
        // Need a new slot
        int newIndex = GetNewItemIndex();
        if (newIndex == -1) return 0;
        // Create new item from GUID
        item = CreateNewItemFromGuid(guid);
        if (item == nullptr) return 0;
        m_items[newIndex] = item;
    }

    // Add count, clamping to 99
    int currentCount = item->GetItemCount();
    int overflow = count;
    int newTotal = currentCount + count;
    if (newTotal > kMaxStackCount) {
        overflow = newTotal - kMaxStackCount;  // how many didn't fit
    }
    item->SetItemCount(newTotal);  // SetItemCount clamps to 99 internally
    return overflow;
}

// ============================================================================
// BBI::InventoryItems::RemoveItemsByGuid
// Address: 0x8004A524, Size: 120 bytes
// MATCHING
// Removes 'count' items. If count >= current, deletes the entire item.
// Returns number actually removed.
// ============================================================================
int InventoryItems::RemoveItemsByGuid(int guid, int count, unsigned char colorIndex) {
    InventoryItem* item = GetItemByGuid(guid, colorIndex);
    if (item == nullptr) return 0;

    int currentCount = item->GetItemCount();
    int remaining = currentCount - count;
    if (remaining > 0) {
        // Partial removal
        item->SetItemCount(remaining);
    } else {
        // Full removal - delete the item entirely
        count = item->GetItemCount();  // actual amount removed
        DeleteItem(item);
    }
    return count;
}

// ============================================================================
// BBI::InventoryItems::DeleteItem
// Address: 0x8004A59C, Size: 388 bytes
// NON_MATCHING - switch statement, vtable dispatch, array compaction
//
// Finds the item in the array, calls its virtual destructor (delete mode 3),
// nulls the slot, then compacts the array by shifting subsequent items down.
//
// Delete logic varies by category:
//   Category 1 (Object) or 3 (Packaged): look up by GUID+colorIndex
//   Category 2 (BuildMode), subcat 1: look up by GUID+colorIndex (wall items)
//   Category 2 (BuildMode), other subcat: look up by subcategory+GUID
//     using GetBuilderItemIndex
// ============================================================================
bool InventoryItems::DeleteItem(InventoryItem* item) {
    if (item == nullptr) return false;

    int index = -1;
    InventoryItem::eItemCategory cat = item->GetItemCategory();

    switch (cat) {
        case InventoryItem::kItemCategory_Object:
        case InventoryItem::kItemCategory_PackagedItem: {
            // Look up by GUID + color
            int guid = item->GetItemGuid();
            unsigned char color = item->GetItemColorIndex();
            index = GetItemIndexByGuid(guid, color);
            break;
        }
        case InventoryItem::kItemCategory_BuildMode: {
            InventoryItem::eItemSubcategory subcat = item->GetItemSubcategory();
            if (subcat == 1) {
                // Wall items: lookup by GUID + color
                int guid = item->GetItemGuid();
                unsigned char color = item->GetItemColorIndex();
                index = GetItemIndexByGuid(guid, color);
            } else {
                // Other build items: lookup by subcategory + GUID
                InventoryItem::eItemSubcategory subcat2 = item->GetItemSubcategory();
                int guid = item->GetItemGuid();
                index = GetBuilderItemIndex(subcat2, guid);
            }
            break;
        }
        default:
            break;
    }

    if (index == -1) return false;

    // Call virtual destructor with delete mode 3
    InventoryItem* toDelete = m_items[index];
    if (toDelete != nullptr) {
        // vtable dispatch: destructor at vtable+0x18/0x1C
        toDelete->~InventoryItem();  // virtual delete
    }

    // Null slot and compact: shift all subsequent items down by one
    m_items[index] = nullptr;
    index++;
    while (index <= 35 && m_items[index] != nullptr) {
        m_items[index - 1] = m_items[index];
        m_items[index] = nullptr;
        index++;
    }

    return true;
}

// ============================================================================
// BBI::InventoryItems::Clear
// Address: 0x8004A720, Size: 128 bytes
// MATCHING
// Iterates all slots, calls virtual destructor (mode 3) on each non-null
// item, then nulls the slot.
// ============================================================================
void InventoryItems::Clear() {
    int size = GetContainerSize();
    for (int i = 0; i < size; i++) {
        InventoryItem* item = m_items[i];
        if (item != nullptr) {
            // Virtual destructor dispatch (delete mode 3)
            item->~InventoryItem();
        }
        m_items[i] = nullptr;
    }
}

// ============================================================================
// BBI::InventoryItems::GetBuilderItem
// Address: 0x8004AC50, Size: 68 bytes
// MATCHING
// Delegates to GetBuilderItemIndex, then returns item at that index
// ============================================================================
InventoryItem* InventoryItems::GetBuilderItem(InventoryItem::eItemSubcategory subcat, int guid) const {
    int index = GetBuilderItemIndex(subcat, guid);
    if (index == -1) return nullptr;
    return m_items[index];
}

// ============================================================================
// BBI::InventoryItems::GetBuilderItemIndex
// Address: 0x8004AC94, Size: 144 bytes
// MATCHING
// Linear search for build-mode items matching subcategory AND guid
// ============================================================================
int InventoryItems::GetBuilderItemIndex(InventoryItem::eItemSubcategory subcat, int guid) const {
    unsigned int size = GetContainerSize();
    for (unsigned int i = 0; i < size; i++) {
        InventoryItem* item = m_items[i];
        if (item == nullptr) continue;
        if (item->GetItemSubcategory() != subcat) continue;
        if (item->GetItemGuid() != guid) continue;
        return (int)i;
    }
    return -1;
}

// ============================================================================
// BBI::InventoryItems::CanAddBuilderItem
// Address: 0x8004AA80, Size: 144 bytes
// NON_MATCHING - CR bit manipulation
// Checks if a builder item can be added. If it already exists, checks
// stack limit. If new, checks 12-item build category limit.
// ============================================================================
bool InventoryItems::CanAddBuilderItem(InventoryItem::eItemSubcategory subcat, int guid, int count) const {
    if (count == 0) return false;

    InventoryItem* existing = GetBuilderItem(subcat, guid);
    if (existing != nullptr) {
        return (existing->GetItemCount() + count) <= kMaxStackCount;
    }

    // New builder item - check category limit
    int buildCount = CountItemsByCategory(InventoryItem::kItemCategory_BuildMode);
    if (buildCount + 1 > kMaxBuildModeItems) return false;
    return count <= kMaxStackCount;
}

// ============================================================================
// BBI::InventoryItems::AddBuilderItem
// Address: 0x8004AB10, Size: 204 bytes
// NON_MATCHING - register allocation
// Adds a builder item. Creates new if needed. Returns overflow count.
// ============================================================================
int InventoryItems::AddBuilderItem(InventoryItem::eItemSubcategory subcat, int guid, int count) {
    if (count == 0) return 0;

    InventoryItem* existing = GetBuilderItem(subcat, guid);
    if (existing == nullptr) {
        // Check capacity
        if (CountItemsByCategory(InventoryItem::kItemCategory_BuildMode) > 11) return 0;

        int newIndex = GetNewItemIndex();
        if (newIndex == -1) return 0;

        InventoryItem* newItem = CreateNewBuilderItem(subcat, guid);
        if (newItem == nullptr) return 0;
        m_items[newIndex] = newItem;
        existing = newItem;
    }

    int overflow = count;
    int total = existing->GetItemCount() + count;
    if (total > kMaxStackCount) {
        overflow = total - kMaxStackCount;
    }
    existing->SetItemCount(total);
    return overflow;
}

// ============================================================================
// BBI::InventoryItems::CreateNewItemFromGuid
// Address: 0x8004B078, Size: 92 bytes
// MATCHING
// Allocates a new InventoryItem, sets category=Object(1), subcategory=Generic(6),
// and stores the GUID.
// ============================================================================
InventoryItem* InventoryItems::CreateNewItemFromGuid(int guid) const {
    void* mem = operator_new_fn(12);
    InventoryItem* item = new (mem) InventoryItem();
    item->SetItemCategory(InventoryItem::kItemCategory_Object);
    item->SetItemSubcategory(InventoryItem::kItemSubcategory_Generic);
    item->SetItemGuid(guid);
    return item;
}

// ============================================================================
// BBI::InventoryItems::CreateNewBuilderItem
// Address: 0x8004B0D4, Size: 116 bytes
// MATCHING
// Allocates a new InventoryItem for build mode (category=2)
// ============================================================================
InventoryItem* InventoryItems::CreateNewBuilderItem(InventoryItem::eItemSubcategory subcat, int guid) const {
    if (subcat == 0) return NULL;

    void* mem = operator_new_fn(12);
    InventoryItem* item = new (mem) InventoryItem();
    if (item == NULL) return NULL;

    item->SetItemCategory(InventoryItem::kItemCategory_BuildMode);
    item->SetItemSubcategory(subcat);
    item->SetItemGuid(guid);
    return item;
}

// ============================================================================
// BBI::InventoryItems::GetItemCategoryFromObjDefinition [static]
// Address: 0x8004B1E0, Size: 128 bytes
// MATCHING
// Classifies an ObjDefinition into an inventory category by examining
// object type fields.
//
// Logic:
//   if def == nullptr: return 0 (None)
//   if def->field_0x50 == 512: return 3 (PackagedItem)
//   switch (def->field_0x12) {    // object type enum
//     case 4, 7, 15: return 1     // Object (furniture, appliances, etc.)
//     case 8:        return 2     // BuildMode (walls, floors, etc.)
//     default:       return 0     // None (not inventory-eligible)
//   }
// ============================================================================
InventoryItem::eItemCategory InventoryItems::GetItemCategoryFromObjDefinition(ObjDefinition* def) {
    if (def == NULL) return InventoryItem::kItemCategory_None;

    // Check for packaged item flag
    s16 packFlag = *(s16*)((u8*)def + 0x50);
    if (packFlag == 512) return InventoryItem::kItemCategory_PackagedItem;

    // Check object type
    s16 objType = *(s16*)((u8*)def + 0x12);
    if (objType <= 7) {
        if (objType >= 5) return InventoryItem::kItemCategory_None;
        if (objType >= 0 && objType <= 3) return InventoryItem::kItemCategory_None;
        return InventoryItem::kItemCategory_Object;  // 4
    }
    if (objType <= 14) {
        if (objType >= 9) return InventoryItem::kItemCategory_None;
        return InventoryItem::kItemCategory_BuildMode;  // 8
    }
    if (objType == 15) return InventoryItem::kItemCategory_Object;
    return InventoryItem::kItemCategory_None;
}

// ============================================================================
// BBI::InventoryItems::DoStream
// Address: 0x8004AF14, Size: 148 bytes
// NON_MATCHING - magic number handling, read/write dispatch
//
// Streams the inventory to/from a ReconBuffer with magic number validation.
// Magic: 0x494E5600 ("INV\0")
// Dispatches to DoStreamWrite or DoStreamRead based on buffer mode.
// ============================================================================
bool InventoryItems::DoStream(ReconBuffer* buf, int version) {
    if (buf == nullptr) return false;

    u32 magic = 0x494E5600;  // "INV\0"
    ReconBuffer_StreamInt(buf, &magic, 1);

    int mode = buf->m_mode;  // offset +0x0C
    if (mode == 0) {
        // Read mode
        return DoStreamRead(buf, version);
    } else if (mode >= 1 && mode <= 2) {
        // Write mode
        return DoStreamWrite(buf, version);
    }
    return false;
}

// ============================================================================
// BBI::InventoryItems::DoStreamWrite
// Address: 0x8004AD24, Size: 184 bytes
// NON_MATCHING - loop codegen
// Writes each slot: 1 byte (present flag) + item data if present
// ============================================================================
bool InventoryItems::DoStreamWrite(ReconBuffer* buf, int version) {
    int size = GetContainerSize();
    for (unsigned int i = 0; i < (unsigned int)size; i++) {
        InventoryItem* item = m_items[i];
        if (item != nullptr) {
            u8 present = 1;
            ReconBuffer_StreamBytes(buf, &present, 1);
            // Virtual call: item->DoStream(buf, version)
            item->DoStream(buf, version);
        } else {
            u8 present = 0;
            ReconBuffer_StreamBytes(buf, &present, 1);
        }
    }
    return true;
}

// ============================================================================
// BBI::InventoryItems::DoStreamRead
// Address: 0x8004ADDC, Size: 312 bytes
// NON_MATCHING - read logic, version branching
// Reads inventory from buffer. Clears first, then reads each slot.
// Version <= 9: reads int GUID, creates item from GUID, then streams
// Version > 9: reads byte flag, if set allocates new item and streams
// ============================================================================
bool InventoryItems::DoStreamRead(ReconBuffer* buf, int version) {
    Clear();
    bool success = true;
    int size = GetContainerSize();

    for (unsigned int i = 0; i < (unsigned int)size; i++) {
        InventoryItem* item = nullptr;

        if (version > 9) {
            // New format: byte flag then item data
            u8 present = 0;
            ReconBuffer_StreamBytes(buf, &present, 1);
            if (present == 0) {
                m_items[i] = nullptr;
                continue;
            }
            // Allocate and read
            item = (InventoryItem*)operator_new_fn(12);
            new (item) InventoryItem();
            item->DoStream(buf, version);
        } else {
            // Old format: always an int GUID
            int guid = 0;
            ReconBuffer_StreamInt(buf, &guid, 1);
            if (guid == 0) {
                m_items[i] = nullptr;
                continue;
            }
            item = CreateNewItemFromGuid(guid);
            if (item == nullptr) {
                m_items[i] = nullptr;
                continue;
            }
            if (!item->DoStream(buf, version)) {
                success = false;
            }
        }
        m_items[i] = item;
    }
    return success;
}

} // namespace BBI

// IGoalUnlock namespace (must be before GoalUnlock class)
namespace IGoalUnlock {
    enum UnlockType {
        kUnlockType_LotObjects = 0,
        kUnlockType_Career     = 1,
        kUnlockType_Social     = 2,
        kUnlockType_Build      = 3,
        kUnlockType_Clothing   = 4,
        kUnlockType_Objects    = 5,
    };
}

// GoalUnlock class declaration
class GoalUnlock {
public:
    u32* m_vtable;         // 0x00
    u16  m_unlockBits[64]; // 0x04 (128 bytes)

    GoalUnlock();
    ~GoalUnlock();
    void ClearGoalsAndUnlocks();
    int  GetUnlockCount(IGoalUnlock::UnlockType type);
    int  GetFirstUnlockVar(IGoalUnlock::UnlockType type);
    bool IsUnlocked(IGoalUnlock::UnlockType type, short idx);
    void GrantUnlock(IGoalUnlock::UnlockType type, short idx);
    bool IsRecentlyUnlocked(IGoalUnlock::UnlockType type, short idx);
    void SetRecentlyUnlocked(IGoalUnlock::UnlockType type, short idx, bool set);
    int  GetUnlockTotal(IGoalUnlock::UnlockType type);
    int  GetObjectIndexFromGuid(int guid);
    void GrantObjectUnlocks(int simoleons);
    void SetupObjectUnlockInfo();
    void DoStream(ReconBuffer* buf, int version);
};

// ============================================================================
// GOAL UNLOCK SYSTEM
// ============================================================================
//
// GoalUnlock manages unlockable content gated behind gameplay progression.
// Uses a bitfield array for compact storage of unlock states.
//
// Memory layout:
//   0x00: u32* m_vtable           (virtual function table at 0x8045F040)
//   0x04: u16  m_unlockBits[64]   (128 bytes of bitfield data)
//          - Bits at even indices (N*2) = "unlocked" flag
//          - Bits at odd indices (N*2+1) = "recently unlocked" flag
//
// The vtable (at 0x8045F040, 104 bytes = 26 entries) contains virtual
// methods including GetUnlockCount, IsUnlocked, GrantUnlock, etc.
// These allow polymorphic access through the IGoalUnlock interface.
//
// Unlock types and their variable ranges:
//   Type 0: 32 unlocks  (lot objects), starts at var 0
//   Type 1: 208 unlocks (career rewards), starts at var 31
//   Type 2: 24 unlocks  (social unlocks), starts at var 4
//   Type 3: 32 unlocks  (build mode items), starts at var 7
//   Type 4: 32 unlocks  (clothing), starts at var 11
//   Type 5: 128 unlocks (buyable objects), starts at var 15

// Global object unlock table (populated by SetupObjectUnlockInfo)
// Located at 0x80485E7C, 128 entries of 8 bytes each:
//   struct ObjectUnlockEntry {
//       u32 guid;             // Object GUID
//       s16 simoleonThreshold; // Min simoleons / 42 to unlock
//       s16 _pad;
//   };
// static ObjectUnlockEntry g_objectUnlockTable[128]; // at 0x80485E7C

// ============================================================================
// GoalUnlock::GoalUnlock
// Address: 0x800B8438, Size: 60 bytes
// MATCHING
// Sets vtable, then calls ClearGoalsAndUnlocks
// ============================================================================
GoalUnlock::GoalUnlock() {
    m_vtable = (u32*)0x8045F040;
    ClearGoalsAndUnlocks();
}

// ============================================================================
// GoalUnlock::~GoalUnlock
// Address: 0x800B8474, Size: 52 bytes
// MATCHING (standard destructor pattern)
// ============================================================================
GoalUnlock::~GoalUnlock() {
    m_vtable = (u32*)0x8045F040;
    // conditional delete via flag
}

// ============================================================================
// GoalUnlock::ClearGoalsAndUnlocks
// Address: 0x800B8510, Size: 44 bytes
// MATCHING
// Zeroes the entire 128-byte bitfield array at this+0x04
// ============================================================================
void GoalUnlock::ClearGoalsAndUnlocks() {
    memset(&m_unlockBits[0], 0, 128);  // 0x80 = 128 bytes
}

// ============================================================================
// GoalUnlock::GetUnlockCount [virtual]
// Address: 0x800B853C, Size: 96 bytes
// MATCHING
// Returns the number of unlocks for each type via switch statement
// ============================================================================
int GoalUnlock::GetUnlockCount(IGoalUnlock::UnlockType type) {
    switch (type) {
        case 0: return 32;   // Lot objects
        case 1: return 208;  // Career (0xD0)
        case 2: return 24;   // Social (0x18)
        case 3: return 32;   // Build
        case 4: return 32;   // Clothing
        case 5: return 128;  // Objects (0x80)
        default: return 0;
    }
}

// ============================================================================
// GoalUnlock::GetFirstUnlockVar [virtual]
// Address: 0x800B875C, Size: 112 bytes
// MATCHING
// Returns the starting variable index for each unlock type
// This is the halfword offset into the bitfield where each type's
// unlock bits begin.
// ============================================================================
int GoalUnlock::GetFirstUnlockVar(IGoalUnlock::UnlockType type) {
    switch (type) {
        case 0: return 0;    // Lot objects start at halfword 0
        case 1: return 31;   // Career starts at halfword 31 (0x1F)
        case 2: return 4;    // Social starts at halfword 4
        case 3: return 7;    // Build starts at halfword 7
        case 4: return 11;   // Clothing starts at halfword 11 (0x0B)
        case 5: return 15;   // Objects starts at halfword 15 (0x0F)
        default: return 0;
    }
}

// ============================================================================
// GoalUnlock::IsUnlocked [virtual]
// Address: 0x800B87CC, Size: 180 bytes
// NON_MATCHING - bit manipulation codegen, extsh sequences
//
// Checks if unlock index 'idx' of given type is unlocked.
// Algorithm:
//   1. Validate idx >= 0 and idx < GetUnlockCount(type)
//   2. Get base halfword index from GetFirstUnlockVar(type)
//   3. Calculate bit position: bitIndex = idx * 2 (even bits = unlock state)
//   4. Find halfword: base + (bitIndex / 16)
//   5. Find bit within halfword: bitIndex % 16
//   6. Return (halfword & (1 << bitWithin)) != 0
// ============================================================================
bool GoalUnlock::IsUnlocked(IGoalUnlock::UnlockType type, short idx) {
    if (idx < 0) return false;

    // Virtual call to GetUnlockCount
    int count = GetUnlockCount(type);
    if (idx >= count) return false;

    int baseVar = GetFirstUnlockVar(type);

    // Calculate bit position for "unlocked" flag (even bits)
    s16 bitIndex = (s16)(idx * 2);
    s16 wordOffset = bitIndex;
    if (bitIndex < 0) wordOffset = bitIndex + 15;  // handle negative (sign extension)
    wordOffset >>= 4;  // divide by 16 to get halfword index

    u16* bits = (u16*)((u8*)this + 4);  // m_unlockBits base
    s16 bitWithin = bitIndex - (wordOffset << 4);  // mod 16
    int halfwordIdx = baseVar + wordOffset;
    u16 mask = (u16)(1 << bitWithin);
    s16 word = bits[halfwordIdx];

    if (word & mask) return true;
    return false;
}

// ============================================================================
// GoalUnlock::GrantUnlock [virtual]
// Address: 0x800B8880, Size: 204 bytes
// NON_MATCHING - bit manipulation, vtable dispatch for SetRecentlyUnlocked
//
// Sets the unlock bit for the given type+index.
// Same bit addressing as IsUnlocked, but ORs in the bit.
// Then calls virtual SetRecentlyUnlocked(type, idx, true) to mark as new.
// ============================================================================
void GoalUnlock::GrantUnlock(IGoalUnlock::UnlockType type, short idx) {
    if (idx < 0) return;

    int count = GetUnlockCount(type);
    if (idx >= count) return;

    int baseVar = GetFirstUnlockVar(type);

    s16 bitIndex = (s16)(idx * 2);
    s16 wordOffset = bitIndex;
    if (bitIndex < 0) wordOffset = bitIndex + 15;
    wordOffset >>= 4;

    u16* bits = (u16*)((u8*)this + 4);
    s16 bitWithin = bitIndex - (wordOffset << 4);
    int halfwordIdx = baseVar + wordOffset;
    u16 mask = (u16)(1 << bitWithin);
    bits[halfwordIdx] |= mask;

    // Virtual call: SetRecentlyUnlocked(type, idx, true)
    // vtable offset +0x48/+0x4C
    SetRecentlyUnlocked(type, idx, true);
}

// ============================================================================
// GoalUnlock::IsRecentlyUnlocked [virtual]
// Address: 0x800B8A6C, Size: 184 bytes
// NON_MATCHING - same bit math as IsUnlocked but uses odd bit (idx*2+1)
//
// Checks the "recently unlocked" flag (adjacent bit to the unlock bit).
// Used to show "NEW!" indicators in the UI.
// ============================================================================
bool GoalUnlock::IsRecentlyUnlocked(IGoalUnlock::UnlockType type, short idx) {
    if (idx < 0) return false;

    int count = GetUnlockCount(type);
    if (idx >= count) return false;

    int baseVar = GetFirstUnlockVar(type);

    // Odd bit = recently unlocked flag
    s16 bitIndex = (s16)(idx * 2 + 1);
    s16 wordOffset = bitIndex;
    if (bitIndex < 0) wordOffset = bitIndex + 15;
    wordOffset >>= 4;

    u16* bits = (u16*)((u8*)this + 4);
    s16 bitWithin = bitIndex - (wordOffset << 4);
    int halfwordIdx = baseVar + wordOffset;
    u16 mask = (u16)(1 << bitWithin);
    s16 word = bits[halfwordIdx];

    if (word & mask) return true;
    return false;
}

// ============================================================================
// GoalUnlock::SetRecentlyUnlocked [virtual]
// Address: 0x800B8B24, Size: 208 bytes
// NON_MATCHING - same bit math, OR or AND-NOT depending on bool param
// Sets or clears the "recently unlocked" bit.
// ============================================================================
void GoalUnlock::SetRecentlyUnlocked(IGoalUnlock::UnlockType type, short idx, bool set) {
    if (idx < 0) return;

    int count = GetUnlockCount(type);
    if (idx >= count) return;

    int baseVar = GetFirstUnlockVar(type);

    s16 bitIndex = (s16)(idx * 2 + 1);
    s16 wordOffset = bitIndex;
    if (bitIndex < 0) wordOffset = bitIndex + 15;
    wordOffset >>= 4;

    u16* bits = (u16*)((u8*)this + 4);
    s16 bitWithin = bitIndex - (wordOffset << 4);
    int halfwordIdx = baseVar + wordOffset;
    u16 mask = (u16)(1 << bitWithin);

    if (set) {
        bits[halfwordIdx] |= mask;
    } else {
        bits[halfwordIdx] &= ~mask;
    }
}

// ============================================================================
// GoalUnlock::GetUnlockTotal [virtual]
// Address: 0x800B8BF4, Size: 148 bytes
// NON_MATCHING - loop with virtual dispatch
// Counts how many items of a given type are currently unlocked
// ============================================================================
int GoalUnlock::GetUnlockTotal(IGoalUnlock::UnlockType type) {
    int total = 0;
    short idx = 0;

    while (true) {
        int count = GetUnlockCount(type);  // virtual
        if (idx >= count) break;

        if (IsUnlocked(type, idx)) {  // virtual
            total++;
        }
        idx++;
    }
    return total;
}

// ============================================================================
// GoalUnlock::GetObjectIndexFromGuid
// Address: 0x800B86D8, Size: 132 bytes
// MATCHING
// Linear search through global object unlock table for matching GUID.
// Returns index (0-127) or -1 if not found.
// ============================================================================
int GoalUnlock::GetObjectIndexFromGuid(int guid) {
    // g_objectUnlockTable at 0x80485E7C (lis r9,-32696; addi r28,r9,24188)
    // extern ObjectUnlockEntry* g_objectUnlockTable;

    for (short i = 0; ; i++) {
        int count = GetUnlockCount(IGoalUnlock::kUnlockType_Objects);  // virtual: always 128
        if (i >= count) break;

        // 8 bytes per entry: slwi r0,r31,3 then lwzx
        int tableGuid = g_objectUnlockTable[i].guid;
        if (guid == tableGuid) return i;
    }
    return -1;
}

// ============================================================================
// GoalUnlock::GrantObjectUnlocks
// Address: 0x800B894C, Size: 288 bytes
// NON_MATCHING - magic constant division, vtable dispatch, UI notification
//
// Called when family funds change. Converts simoleon amount to a "level"
// by dividing by 42 (implemented via multiply-high with 0x51EB851F then
// shift right 5). Then iterates through all 128 object entries; for each
// entry whose simoleon threshold <= level and which is not yet unlocked,
// grants the unlock and notifies the UI.
//
// The division: amount / 42
//   mulhw r4, r4, 0x51EB851F  (magic for division by 42)
//   srawi r4, r4, 5
//   subf  r4, r11, r4         (correction for negative)
//   extsh r28, r4
// ============================================================================
void GoalUnlock::GrantObjectUnlocks(int simoleons) {
    int level = simoleons / 42;
    short lastGranted = -1;

    for (short i = 0; ; i++) {
        int count = GetUnlockCount(IGoalUnlock::kUnlockType_Objects);  // 128
        if (i >= count) break;

        s16 threshold = g_objectUnlockTable[i].simoleonThreshold;
        if (threshold == 0) continue;  // no threshold means not eligible
        if (level < threshold) continue;

        // Check if already unlocked
        if (IsUnlocked(IGoalUnlock::kUnlockType_Objects, i)) continue;

        // Grant the unlock
        lastGranted = i;
        GrantUnlock(IGoalUnlock::kUnlockType_Objects, lastGranted);
    }

    // If we granted any new unlock, notify UI
    // Checks g_pPlayerData (r13 - 26824) and CUnlockDisplay (at 0x80475BCC)
    // Calls CUnlockDisplay::DisplayNewUnlock(type=5, index=lastGranted)
    if (lastGranted != -1) {
        // UI notification via CUnlockDisplay
    }
}

// ============================================================================
// GoalUnlock::SetupObjectUnlockInfo
// Address: 0x800B859C, Size: 316 bytes
// NON_MATCHING - complex iterator with catalog lookup
//
// Populates the global object unlock table (g_objectUnlockTable) by
// iterating through all object definitions in the catalog. For each
// object that has a positive "unlock price" (field +0x0C > 0), stores
// its GUID and the price as the threshold.
//
// Uses:
//   - EQuickdataManager to get the object catalog resource
//   - Iterates over catalog entries (72 bytes each)
//   - For each entry, iterates its variant list
//   - Checks variant field +0x0C (price) > 0
//   - Stores GUID (from variant +0x1C) and price (from variant +0x0C)
//   - Clears remaining table entries after population
// ============================================================================
void GoalUnlock::SetupObjectUnlockInfo() {
    // Load quick data resource for object catalog
    // ... complex resource iteration ...
    // After populating, zeros remaining entries up to index 127
}

// ============================================================================
// GoalUnlock::DoStream
// Address: 0x800B84A8, Size: 104 bytes
// MATCHING
// Streams the unlock bitfield array. Size depends on save version:
//   version <= 16: stream 39 halfwords (78 bytes) — old smaller format
//   version > 16:  stream 64 halfwords (128 bytes) — full bitfield
// After reading old format, calls virtual SetupObjectUnlockInfo to
// rebuild the object unlock table (vtable offset +0x10/+0x14).
// ============================================================================
void GoalUnlock::DoStream(ReconBuffer* buf, int version) {
    if (version <= 16) {
        ReconBuffer_StreamHalfwords(buf, &m_unlockBits[0], 39);
        // Virtual call: SetupObjectUnlockInfo()
        SetupObjectUnlockInfo();
    } else {
        ReconBuffer_StreamHalfwords(buf, &m_unlockBits[0], 64);
    }
}


// ============================================================================
// WANT/FEAR SYSTEM
// ============================================================================
//
// WantFear data structures (from assembly analysis):
//
// WantFear::Event (36 bytes per event):
//   +0x00: u16  eventId
//   +0x02: u8   type          (0x01=platinum, 0x80=fear, others=normal want)
//   +0x03: u8   category
//   ... remaining fields for text, parameters, targets ...
//
// WantFear::Node (32 bytes per node):
//   +0x00: u16  eventRef      (index into events array)
//   +0x02: u8   flags         (bit 0=hidden, bit 1=target override)
//   +0x04: s16  defaultTarget
//   +0x06: s16  field_06
//   +0x08: s16  field_08
//   +0x0A: u8   numBranches
//   +0x0B: u8   firstChildIndex
//   +0x0C: u32  field_0C
//   +0x10: u8   adData[8]     (advertisement data)
//   +0x18: u32  field_18      (reward data)
//   +0x1C: u8   field_1C
//   +0x1D: u8   field_1D
//   +0x1E: ...
//
// WantFear::Tree:
//   +0x00: u16  treeId
//   +0x02: u8   storyFlag     (bit 0 = is story tree)
//   +0x04: void* childIndexData  (pointer to child index array)
//   +0x08: Node* nodes        (pointer to node array)
//   ... additional tree metadata ...
//
// WantFear::Bookmark (12 bytes, stored inline in Neighbor):
//   +0x00: u16  treeId
//   +0x02: u16  countdown     (or target if node flag bit 1)
//   +0x04: Node* node         (pointer to current position in tree)
//   +0x08: u16  adIndex
//   +0x0A: u16  _pad
//
// WantFear::Notification (passed to Neighbor::Notify):
//   +0x00: u16  eventType
//   +0x02: s16  target
//   ... additional notification parameters ...
//
// Neighbor WantFear storage (within Neighbor object):
//   +0x194: Bookmark* m_activeBookmarks  (pointer to array of 20 bookmarks)
//   +0x198: Icon*     m_wantFearIcons[7] (display icons)
//
// Active bookmark iteration in Notify: 20 slots, 12 bytes each (0x0C stride)
// First checks node pointer != null, then calls SatisfiedBy

// ============================================================================
// WantFear Constants (from .sdata2)
// ============================================================================
// kWantFearVersion          = *(u32*)0x80500634   (4 bytes)
// kGenericParam             = *(u16*)0x80500638
// kNoActiveIndex            = *(u16*)0x8050063A   = 0xFFFF
// kNoBookmarkIndex          = *(u16*)0x8050063C   = 0xFFFF
// kNoTarget                 = *(u16*)0x8050063E   = 0xFFFF
// kMaxAdMax                 = *(u32*)0x80500640   = 4
// kEventBuildBuyCategory    = *(u16*)0x80500644
// kEventBuildBuyWorth       = *(u16*)0x80500646
// kEventFamilyFundsOfX      = *(u16*)0x80500648
// kEventFamilyFundsPlat     = *(u16*)0x8050064A
// kEventBuildBuyWorthPlatinum= *(u16*)0x8050064C
// kEventAddARoom            = *(u16*)0x8050064E
// kEventBuildWalls          = *(u16*)0x80500650
// kEventBuyXLights          = *(u16*)0x80500652
// kEventBuyXChairs          = *(u16*)0x80500654

// ============================================================================
// Neighbor::Notify
// Address: 0x800CAD10, Size: 452 bytes
// NON_MATCHING - complex bookmark iteration with reward application
//
// Core want/fear satisfaction loop. Called when a game event occurs.
// Iterates through 20 active bookmark slots (12 bytes each) at
// neighbor+0x194 (indirected). For each active bookmark:
//   1. Checks if bookmark's node is non-null
//   2. Calls Bookmark::SatisfiedBy(notification) to check match
//   3. If satisfied and countdown > 0: decrements countdown
//   4. If countdown reaches 0: copies bookmark, applies reward,
//      checks for fear (IsPlatinum), notifies neighborhood,
//      shuffles replacement want/fear
//
// Return values: 0 = nothing happened, 1 = countdown decremented,
//                2 = want/fear fully satisfied
// ============================================================================
int Neighbor::Notify(WantFear::Notification& notification, bool broadcastFears) {
    // Check global lock flag (at 0x80475C74)
    // if locked: return 0

    int result = 0;
    // Iterate 20 bookmark slots
    for (int slotIdx = 0; slotIdx <= 19; slotIdx++) {
        WantFear::Bookmark* bookmark = &m_activeBookmarks[slotIdx];

        // Check if slot is active (node != null)
        if (bookmark->m_node == nullptr) continue;

        // Check if this notification satisfies this bookmark
        if (!bookmark->SatisfiedBy(notification)) continue;

        // Decrement countdown
        if (bookmark->m_countdown > 0) {
            bookmark->m_countdown--;
            if (bookmark->m_countdown != 0) continue;
        }

        // Bookmark satisfied! Copy notification target to bookmark
        bookmark->m_countdown = notification.m_target;  // store for display

        result = 2;

        // Find active slot index for UI update (stub -- actual function uses r13)
        int activeIdx = -1; // FindActiveSlotIndex(*bookmark)

        // Save bookmark copy for reward processing
        WantFear::Bookmark saved = *bookmark;

        // Clear the active bookmark slot icon
        if (activeIdx != -1 && activeIdx < 7) {
            m_wantFearIcons[activeIdx] = NULL;
        }

        // Apply reward (aspiration points)
        // saved.ApplyReward(this);  -- TODO

        // If this was a platinum want fulfilled and broadcasting is enabled,
        // notify the entire neighborhood
        if (broadcastFears) {
            // TODO: saved.IsPlatinum()
            // g_pNeighborhoodImpl->NotifyAllPersons(notification, this)
        }

        // Pick replacement want/fear
        ReplaceBookmark(slotIdx);
        RefreshBookmarkIcon(slotIdx, 1);

        // If the old bookmark was NOT a fear, shuffle a new random want
        if (!saved.IsFear()) {
            int randomSlot = GetRandomEmptySlot(3);  // type 3 = any
            ShuffleWantFear(randomSlot);
        }
    }
    return result;
}

// ============================================================================
// Neighbor::ShuffleWantFear
// Address: 0x800CC554, Size: 128 bytes
// MATCHING
// Replaces a want/fear in the given slot (or all slots if slotIdx == -1).
// For each slot: clears the old bookmark, then picks a new root using
// WantFearManager::PickNewRoot and installs it.
// ============================================================================
void Neighbor::ShuffleWantFear(int slotIdx) {
    if (slotIdx == -1) {
        // Shuffle all 7 display slots
        for (int i = 0; i <= 6; i++) {
            ReplaceBookmark(i);
            RefreshBookmarkIcon(i, 2);
        }
    } else {
        // Shuffle single slot
        ReplaceBookmark(slotIdx);
        RefreshBookmarkIcon(slotIdx, 2);
    }
}

// ============================================================================
// WantFearManager::WantFearManager
// Address: 0x8014BC6C, Size: 76 bytes
// NON_MATCHING - init sequence
// ============================================================================
WantFearManager::WantFearManager() {
    m_eventCount = 0;
    m_events = nullptr;
    m_treeCount = 0;
    m_trees = nullptr;
    m_categoryShaderCount = 0;
    m_categoryShaders = nullptr;
    // Zero remaining fields
}

// ============================================================================
// WantFearManager::~WantFearManager
// Address: 0x8014BCB8, Size: 76 bytes
// NON_MATCHING - cleanup codegen
// ============================================================================
WantFearManager::~WantFearManager() {
    if (m_events != nullptr) {
        operator_delete_fn(m_events);
        m_events = nullptr;
    }
    if (m_trees != nullptr) {
        operator_delete_fn(m_trees);
        m_trees = nullptr;
    }
}

// ============================================================================
// WantFearManager::GetEventByIndex
// Address: 0x8014BF20, Size: 16 bytes
// MATCHING
// Direct indexed access. Events are 36 bytes each.
// ============================================================================
const WantFear::Event* WantFearManager::GetEventByIndex(int index) const {
    return (const WantFear::Event*)((u8*)m_events + index * 36);
}

// ============================================================================
// WantFearManager::GetTreeByIndex
// Address: 0x8014BFBC, Size: 16 bytes
// MATCHING
// Returns tree pointer at given index
// ============================================================================
const WantFear::Tree* WantFearManager::GetTreeByIndex(int index) const {
    return &m_trees[index];
}

// ============================================================================
// WantFearManager::GetEvent
// Address: 0x8014BF30, Size: 140 bytes
// NON_MATCHING - linear search loop
// Searches events by ID. Returns null if not found.
// ============================================================================
const WantFear::Event* WantFearManager::GetEvent(unsigned short eventId) const {
    if (m_events == nullptr) return nullptr;

    for (int i = 0; i < m_eventCount; i++) {
        const WantFear::Event* event = GetEventByIndex(i);
        if (event->m_eventId == eventId) {
            return event;
        }
    }
    return nullptr;
}

// ============================================================================
// WantFearManager::GetTree
// Address: 0x8014BFCC, Size: 152 bytes
// NON_MATCHING - linear search loop
// Searches trees by ID. Returns null if not found.
// ============================================================================
const WantFear::Tree* WantFearManager::GetTree(unsigned short treeId) const {
    if (m_trees == nullptr) return nullptr;

    for (int i = 0; i < m_treeCount; i++) {
        const WantFear::Tree* tree = GetTreeByIndex(i);
        if (tree->m_treeId == treeId) {
            return tree;
        }
    }
    return nullptr;
}

// ============================================================================
// WantFearManager::Lottery
// Address: 0x8014C3B8, Size: 140 bytes
// MATCHING
// Weighted random selection. Sums all weights, picks random value in
// [0, total), returns index where cumulative sum exceeds pick.
// ============================================================================
int WantFearManager::Lottery(unsigned int* weights, unsigned int count) const {
    if (count == 0) return -1;

    // Sum all weights
    unsigned int total = 0;
    for (unsigned int i = 0; i < count; i++) {
        total += weights[i];
    }
    if (total == 0) return -1;

    // Pick random value in [0, total)
    int pick = RandomInt(total);

    // Find which bucket
    unsigned int cumulative = 0;
    for (unsigned int i = 0; i < count; i++) {
        cumulative += weights[i];
        if ((unsigned int)pick < cumulative) {
            return (int)i;
        }
    }
    return (int)(count - 1);
}

// ============================================================================
// WantFearManager::PickNewRoot
// Address: 0x8014C1FC, Size: 444 bytes
// NON_MATCHING - complex tree selection with weighted lottery
//
// Selects a new root want/fear for a Neighbor. Process:
//   1. Build list of eligible root trees (filtered by neighbor's age,
//      aspiration type, current life stage)
//   2. Assign weight to each tree based on:
//      - Aspiration level alignment
//      - Current mood modifier
//      - Story progression state
//   3. Use Lottery() for weighted random selection
//   4. Create new Bookmark at selected tree's root node
//   5. Initialize countdown from tree's ad data
//
// Parameter 'isFear' selects fear trees (type 0x80) vs want trees
// ============================================================================
void WantFearManager::PickNewRoot(Neighbor* neighbor, bool isFear) {
    // Complex weighted selection - see assembly at 0x8014C1FC
    // Builds weight array, calls Lottery, creates bookmark
}

// ============================================================================
// WantFearManager::LoadWants
// Address: 0x8014BD08, Size: 536 bytes
// NON_MATCHING - resource loading, pointer fixup
//
// Loads want/fear data from the game's quick data resource system.
// Steps:
//   1. Get want/fear data resource from EQuickdataManager
//   2. Read event count, allocate event array (36 bytes each)
//   3. Read each event's fields (ID, type, category, parameters, text refs)
//   4. Read tree count, allocate tree pointer array
//   5. For each tree: read header, node count, allocate nodes (32 bytes each)
//   6. Fix up pointers via Tree::FixupPointers (convert offsets to addresses)
//   7. Build category shader table for UI display
//   8. Initialize story tree root indices
// ============================================================================
void WantFearManager::LoadWants() {
    // Resource loading - see assembly at 0x8014BD08
    // Allocates and fills m_events, m_trees, m_categoryShaders
}

// ============================================================================
// WantFearManager::GetStoryTreeRoot
// Address: 0x8014C064, Size: 256 bytes
// NON_MATCHING - tree search
// Finds the root node of a story tree matching given aspiration type
// and story chapter parameters.
// ============================================================================
const WantFear::Node* WantFearManager::GetStoryTreeRoot(short aspirationType, short chapter) const {
    if (m_trees == nullptr) return nullptr;
    // Search trees with storyFlag bit 0 set
    // Match aspiration type and chapter
    return nullptr;
}

// ============================================================================
// WantFearManager::GetCategoryShader
// Address: 0x8014C164, Size: 152 bytes
// NON_MATCHING - shader database lookup
// Maps a want/fear target type and parameter to a UI shader for display.
// Used by the wants/fears panel to show appropriate icons.
// ============================================================================
u32 WantFearManager::GetCategoryShader(WantFear::TargetType type, short param) {
    // Linear search through category shader table
    return 0;
}

// ============================================================================
// WantFearManager::CaptureLog
// Address: 0x8014BD04, Size: 4 bytes
// MATCHING
// Empty stub (no-op in release build, likely #ifdef'd out logging)
// ============================================================================
void WantFearManager::CaptureLog(bool enable) {
    // no-op
}


// ============================================================================
// INTERACTION BETWEEN SYSTEMS
// ============================================================================
//
// The three systems interact as follows:
//
// 1. INVENTORY -> GOALS:
//    When items are purchased/placed via INVTarget, the system checks
//    GoalUnlock to determine which items are available for purchase.
//    INVTarget::BuildLotShopDB() and Cheat_BuildCatalogDB() filter
//    the catalog by consulting GoalUnlock::IsUnlocked().
//    See: PCTTarget::cCellInfo::Init(ObjSelector*, IGoalUnlock*)
//
// 2. GOALS -> WANTS:
//    Completing goals (unlocking content) can trigger want/fear events.
//    GoalUnlock::GrantObjectUnlocks calls into the CUnlockDisplay
//    system which can spawn notifications that feed into the want/fear
//    system via Neighbor::Notify.
//
// 3. WANTS -> INVENTORY:
//    Want/fear events related to buying/building (kEventBuildBuyCategory,
//    kEventBuildBuyWorth, kEventBuyXLights, etc.) are triggered when
//    the player makes purchases through the inventory system.
//    INVTarget::CommittChangesToInventory and the various Place/Grab
//    callbacks emit notifications that Neighbor::Notify processes.
//
// 4. MONEY -> GOALS -> INVENTORY:
//    When family funds increase, GoalUnlock::GrantObjectUnlocks is
//    called with the new amount. Objects whose simoleon threshold
//    (amount / 42) is met get automatically unlocked, expanding the
//    available inventory in the shop.
//
// ============================================================================
