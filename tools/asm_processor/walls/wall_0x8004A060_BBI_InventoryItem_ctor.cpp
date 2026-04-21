// asm-processor input: 0x8004A060 BBI::InventoryItem::InventoryItem (48B).
// Cat 2 wall: LIFO-vs-FIFO store order + multi-zero-reg reuse + vtable
// construction style (lis+addi vs lis+ori).
//
// DOL construction of the vtable pointer is lis+addi (implies HA/LO relocation
// via an externally-named symbol). Using a bare numeric literal `0x8045B920`
// in source makes GCC emit lis+ori (positive immediate), which permanently
// locks us out of a byte match. Switching to `extern char VT[]` forces
// ADDR16_HA/LO relocations → lis+addi.
//
// Field-store order in the source is intentionally aligned with the DOL
// emission order (vtable, field3, field4, field0[0], field0[1], field0[2]).
// GCC-2.95 is still likely to schedule the bytes however it wants, so a
// post-asm reordering may still be needed — this source is the starting
// baseline for that diagnosis.
//
// (no directive yet — capture baseline first)

extern char VT_BBI_InventoryItem[];       // resolves to 0x8045B920

struct BBI_InventoryItem {
    char field0[3];
    char field3;
    int field4;
    void** vtable;
    BBI_InventoryItem();
};

BBI_InventoryItem::BBI_InventoryItem() {
    // DOL order: vtable, field3, field4, field0[0..2] — with field3 using
    // one zero-reg and field4 using a different zero-reg. GCC 2.95 coalesces
    // them unless we give it distinct store-value sources to work with.
    vtable = (void**)VT_BBI_InventoryItem;
    field3 = 0;
    field4 = 0;
    field0[0] = 0;
    field0[1] = 0;
    field0[2] = 0;
}
