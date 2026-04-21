// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 48B: ctor LIFO-vs-FIFO store wall (multi-zero-reg). Parked by SonnetWorker2 S12.
// Original path: src/matched/bbi/match_0x8004A060_BBI__InventoryItem__InventoryItem.cpp
//
// 0x8004A060 BBI::InventoryItem::InventoryItem (48B)

struct BBI_InventoryItem {
    char field0[3];
    char field3;
    int field4;
    void** vtable;
    BBI_InventoryItem();
};

BBI_InventoryItem::BBI_InventoryItem() {
    field0[2] = 0;
    field0[1] = 0;
    field0[0] = 0;
    field4 = 0;
    field3 = 0;
    vtable = (void**)((char*)0x80460000 - 0x46E0);
}
