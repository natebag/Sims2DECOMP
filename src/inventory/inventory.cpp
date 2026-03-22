// inventory.cpp - BBI::InventoryItems and IngredientManager system
// Object file: inventory.obj
// 17 small functions (<=64 bytes) + 1 bonus (SetItemCount, 80 bytes) decompiled
//
// All functions are NON_MATCHING due to GCC vs SN Systems compiler differences:
//   - GCC places vtable at offset 0; SN Systems places it at offset 8 in InventoryItem
//   - GCC inlines trivial getter calls that SN kept as bl instructions
//   - GCC uses stw/lwz; SN uses stmw/lmw for register save/restore
//   - GCC uses different register allocation (r31/r30 vs r29/r30)
//   - GCC generates D0/D1 destructors; SN uses a single destructor with delete flag
//   - GCC tail-call optimizes more aggressively than SN
//   - GCC uses branchless arithmetic where SN uses conditional branches
//
// Struct layouts (from original SN Systems compiler):
//   InventoryItem (12 bytes, SN layout):
//     +0x00: s8  m_category (eItemCategory)
//     +0x01: s8  m_count (clamped 0-99)
//     +0x02: u8  m_colorIndex
//     +0x03: s8  m_subcategory (eItemSubcategory)
//     +0x04: int m_guid
//     +0x08: vtable pointer
//   InventoryItems (144 bytes):
//     +0x00: InventoryItem* m_items[36]

#include "inventory/inventory.h"

// External runtime functions
extern "C" void* memset(void* s, int c, unsigned int n);

// Static singleton pointer for IngredientManager
// Map symbol: spIngredientManager.2190 @ 0x804fda3c
static IngredientManager* spIngredientManager;

namespace BBI {

// ============================================================================
// InventoryItem
// ============================================================================

// NON_MATCHING: GCC vtable at offset 0 vs SN at offset 8; store order differs
// BBI::InventoryItem::InventoryItem(void) @ 0x8004a060, 48 bytes
InventoryItem::InventoryItem() {
    m_subcategory = 0;
    m_guid = 0;
    m_category = 0;
    m_count = 0;
    m_colorIndex = 0;
}

// NON_MATCHING: GCC D0/D1 destructor split vs SN single destructor with delete flag
// BBI::InventoryItem::~InventoryItem(void) @ 0x8004a090, 52 bytes
InventoryItem::~InventoryItem() {
}

// NON_MATCHING: GCC inlines GetItemCategory(); SN calls it with bl; stmw/lmw vs stw/lwz
// BBI::InventoryItem::SetItemCategory(BBI::InventoryItem::eItemCategory) @ 0x8004a0c4, 52 bytes
void InventoryItem::SetItemCategory(eItemCategory category) {
    GetItemCategory(); // original calls getter before storing (validation?)
    m_category = (s8)category;
}

// NON_MATCHING: member offset differs (GCC +0x04 vs SN +0x00)
// BBI::InventoryItem::GetItemCategory(void) const @ 0x8004a0f8, 12 bytes
// Original: lbz r3,0(r3); extsb r3,r3; blr
int InventoryItem::GetItemCategory() const {
    return (eItemCategory)(s8)m_category;
}

// NON_MATCHING: GCC inlines GetItemSubcategory(); SN calls it with bl; stmw/lmw vs stw/lwz
// BBI::InventoryItem::SetItemSubcategory(BBI::InventoryItem::eItemSubcategory) @ 0x8004a104, 52 bytes
void InventoryItem::SetItemSubcategory(eItemSubcategory subcategory) {
    GetItemSubcategory(); // original calls getter before storing
    m_subcategory = (s8)subcategory;
}

// NON_MATCHING: member offset differs (GCC +0x07 vs SN +0x03)
// BBI::InventoryItem::GetItemSubcategory(void) const @ 0x8004a138, 12 bytes
// Original: lbz r3,3(r3); extsb r3,r3; blr
int InventoryItem::GetItemSubcategory() const {
    return (eItemSubcategory)(s8)m_subcategory;
}

// NON_MATCHING: member offset differs (GCC +0x08 vs SN +0x04)
// BBI::InventoryItem::GetItemGuid(void) const @ 0x8004a20c, 8 bytes
// Original: lwz r3,4(r3); blr
int InventoryItem::GetItemGuid() const {
    return m_guid;
}

// NON_MATCHING: GCC inlines GetItemGuid(); SN calls it with bl; stmw/lmw vs stw/lwz
// BBI::InventoryItem::SetItemGuid(int) @ 0x8004a214, 52 bytes
void InventoryItem::SetItemGuid(int guid) {
    GetItemGuid(); // original calls getter before storing
    m_guid = guid;
}

// NON_MATCHING: GCC uses branchless clamp (not+srawi+and); SN uses bge/ble branches
// BBI::InventoryItem::SetItemCount(int) @ 0x8004a248, 80 bytes (bonus: over 64-byte limit)
// Clamps count to range [0, 99]
void InventoryItem::SetItemCount(int count) {
    GetItemCount(); // original calls getter before storing
    if (count < 0) {
        count = 0;
    } else if (count > 99) {
        count = 99;
    }
    m_count = (s8)count;
}

// NON_MATCHING: member offset differs (GCC +0x05 vs SN +0x01)
// BBI::InventoryItem::GetItemCount(void) const @ 0x8004a298, 12 bytes
// Original: lbz r3,1(r3); extsb r3,r3; blr
int InventoryItem::GetItemCount() const {
    return (int)(s8)m_count;
}

// NON_MATCHING: GCC inlines GetItemColorIndex(); SN calls it with bl; stmw/lmw vs stw/lwz
// BBI::InventoryItem::SetItemColorIndex(unsigned char) @ 0x8004a2a4, 52 bytes
void InventoryItem::SetItemColorIndex(unsigned char colorIndex) {
    GetItemColorIndex(); // original calls getter before storing
    m_colorIndex = colorIndex;
}

// NON_MATCHING: member offset differs (GCC +0x06 vs SN +0x02)
// BBI::InventoryItem::GetItemColorIndex(void) const @ 0x8004a2d8, 8 bytes
// Original: lbz r3,2(r3); blr
unsigned char InventoryItem::GetItemColorIndex() const {
    return m_colorIndex;
}

// NON_MATCHING: member offsets differ; GCC copies different bytes due to vtable position
// BBI::InventoryItem::CopyTo(BBI::InventoryItem *) const @ 0x8004a2e0, 60 bytes
// Original copies raw bytes at offsets 0-7 (members only), saves vtable on stack
// Returns 1 on success, 0 if dest is null
int InventoryItem::CopyTo(InventoryItem* dest) const {
    if (dest != 0) {
        // Copy member data (category/count/colorIndex/subcategory + guid)
        // Original: lwz from this+0, this+4; stw to dest+0, dest+4
        // Also loads dest vtable (this+8) to stack as temp but doesn't write it back
        *(int*)&dest->m_category = *(const int*)&m_category;
        dest->m_guid = m_guid;
        return 1;
    }
    return 0;
}

// ============================================================================
// InventoryItems
// ============================================================================

// NON_MATCHING: GCC unrolls loop 4x with stwu; SN uses simple bdnz with single stw
// BBI::InventoryItems::InventoryItems(void) @ 0x8004a31c, 32 bytes
// Original: li r11,36; mtctr; addi r9,r3,0x8c; stw 0,0(r9); addi r9,-4; bdnz
InventoryItems::InventoryItems() {
    for (int i = 0; i < kContainerSize; i++) {
        m_items[i] = 0;
    }
}

// NON_MATCHING: GCC tail-calls Clear(); SN uses stack frame with bl + conditional delete
// BBI::InventoryItems::~InventoryItems(void) @ 0x8004a33c, 64 bytes
// Original: saves LR, calls Clear(), checks delete flag, conditionally calls __builtin_delete
InventoryItems::~InventoryItems() {
    Clear();
}

// BBI::InventoryItems::GetContainerSize(void) const @ 0x8004aa5c, 8 bytes
// Original: li r3,36; blr
// MATCHES (identical codegen)
int InventoryItems::GetContainerSize() const {
    return kContainerSize;
}

// NON_MATCHING: register allocation differs (r4 vs r0 for shifted index)
// BBI::InventoryItems::GetItemAtIndex(int) const @ 0x8004aa64, 28 bytes
// Original: cmpwi r4,35; bgt null; slwi r0,r4,2; lwzx r3,r3,r0; blr; li r3,0; blr
InventoryItem* InventoryItems::GetItemAtIndex(int index) const {
    if (index > 35) {
        return 0;
    }
    return m_items[index];
}

} // namespace BBI

// ============================================================================
// IngredientManager
// ============================================================================

// NON_MATCHING: GCC D0/D1 destructor split vs SN single destructor with delete flag
// IngredientManager::~IngredientManager(void) @ 0x8004b308, 40 bytes
// Original: stack frame, checks r4 bit 0, conditionally calls __builtin_delete
IngredientManager::~IngredientManager() {
}

// NON_MATCHING: register allocation differs (r10/r9 vs r9/r0); branch reordering
// less_int16_t(void *, void *) @ 0x8004b598, 36 bytes
// Comparison function for qsort: returns -1, 0, or 1
// Original: lha r9,0(r3); lha r0,0(r4); cmpw r9,r0; li r3,0; beqlr; li r3,1; bgelr; li r3,-1; blr
int less_int16_t(void* a, void* b) {
    short va = *(short*)a;
    short vb = *(short*)b;
    if (va == vb) return 0;
    if (va >= vb) return 1;
    return -1;
}

// NON_MATCHING: GCC reorders early-return check; uses r10/r9 vs r13-relative addressing
// GetIngredientManager(void) @ 0x8004b260, 60 bytes
// Lazy singleton: allocates with __builtin_new(1), constructs, stores to spIngredientManager
// Original uses r13-relative addressing (lwz r0,-32484(r13)) for the static pointer
IngredientManager* GetIngredientManager() {
    if (spIngredientManager == 0) {
        spIngredientManager = new IngredientManager();
    }
    return spIngredientManager;
}
