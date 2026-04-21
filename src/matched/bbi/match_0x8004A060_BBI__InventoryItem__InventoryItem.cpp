// 0x8004A060 BBI::InventoryItem::InventoryItem (48B)
//
// Matched 2026-04-21 (S13 Track I Phase 2) source-side after two insights:
//   (a) `extern char VT[]` for the vtable pointer forces lis+addi with
//       HA/LO relocations, matching DOL's vtable construction. Using a
//       bare numeric literal produces lis+ori (positive immediate) and
//       locks out the byte match permanently.
//   (b) Writing the field0[0..2] byte stores BEFORE field3 + field4 in
//       source lets GCC reorder them into the DOL's preferred emission:
//       stw vtable, stb field3 (via r0), stw field4 (via r10), stb
//       field0[0..2] (via r0). Byte zeros coalesce into r0, the word zero
//       sits in r10.
// Source order matters here — field3/field4 first or interleaved inverts
// the zero-register polarity and breaks the match.

extern char VT_BBI_InventoryItem[];       // resolves to 0x8045B920

struct BBI_InventoryItem {
    char field0[3];
    char field3;
    int field4;
    void** vtable;
    BBI_InventoryItem();
};

BBI_InventoryItem::BBI_InventoryItem() {
    vtable = (void**)VT_BBI_InventoryItem;
    field0[0] = 0;
    field0[1] = 0;
    field0[2] = 0;
    field3 = 0;
    field4 = 0;
}
