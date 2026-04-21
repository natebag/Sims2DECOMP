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
// DOL order: vtable, field3 (byte, via r0), field4 (word, via r10),
// field0[0..2] (bytes, via r0). r0 is the "byte zero reg", r10 is the
// "word zero reg". GCC 2.95 picks the opposite polarity (r10 for first
// byte, r0 for everything else) unless we force its hand.
//
// Attempt: use explicit-typed zero locals so GCC keeps the int-typed zero
// and the char-typed zero in separate live ranges, and do the word store
// in an inner block so it doesn't bleed into the byte-store scheduling.
// (Prior variants noted in manifest — parked pending a selective-reorder
// mutator if source tricks continue to fall short.)

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
