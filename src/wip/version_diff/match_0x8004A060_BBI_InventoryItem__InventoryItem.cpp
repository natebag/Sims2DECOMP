/* BBI::InventoryItem::InventoryItem(void) at 0x8004A060 (48B) */
/* VERSION_DIFF: Preamble (lis r11, mr r9, li r0, addi r11, li r10, stw vtable) matches
 * but SN ProDG assigns r0 to byte stores and r10 to the word store (m_e),
 * while GCC assigns r10 to the first byte store and r0 to the word store.
 * GCC's scheduler also pulls m_c@2 adjacent to m_d@3, reordering stores.
 * Constructor store ordering 3,4,0,1,2 (DOL) vs 3,2,4,0,1 (GCC).
 * May be fixable via TU-level or explicit store-ordering in future.
 */

struct BBI_InventoryItem_Base {
    char m_a; // 0
    char m_b; // 1
    char m_c; // 2
    char m_d; // 3
    int  m_e; // 4
};

struct BBI_InventoryItem_II : BBI_InventoryItem_Base {
    virtual ~BBI_InventoryItem_II() {}
    BBI_InventoryItem_II();
};

BBI_InventoryItem_II::BBI_InventoryItem_II() {
    register BBI_InventoryItem_II* self asm("r9") = this;
    self->m_d = 0;
    self->m_e = 0;
    self->m_a = 0;
    self->m_b = 0;
    self->m_c = 0;
}
