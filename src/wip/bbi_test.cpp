// 0x8004A060 BBI::InventoryItem::InventoryItem (48b)

namespace BBI {

extern int InventoryItem_vtable[];

struct InventoryItem {
    char m_category;
    char m_count;
    char m_colorIndex;
    char m_subcategory;
    int m_guid;
    int* m_vtable;

    InventoryItem();
};

InventoryItem::InventoryItem() {
    // DOL order: li r0,0; addi r11; li r10; stw r11; stb r10; stb r0; stw r0; stb r0; stb r0
    *(volatile int**)&m_vtable = (int*)InventoryItem_vtable;
    *(volatile char*)&m_subcategory = 0;
    *(volatile char*)&m_colorIndex = 0;
    *(volatile int*)&m_guid = 0;
    *(volatile char*)&m_category = 0;
    *(volatile char*)&m_count = 0;
}

}
