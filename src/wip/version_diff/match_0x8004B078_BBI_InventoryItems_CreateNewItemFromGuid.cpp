// 0x8004B078 (80B) BBI::InventoryItems::CreateNewItemFromGuid(int) const

namespace BBI {

struct InventoryItem {
    char data[12];  // size is 12 bytes
    InventoryItem();
    void SetItemCategory(int);
    void SetItemSubcategory(int);
    void SetItemGuid(int);
};

struct InventoryItems {
    InventoryItem* CreateNewItemFromGuid(int guid) const;
};

InventoryItem* InventoryItems::CreateNewItemFromGuid(int guid) const {
    InventoryItem* item = new InventoryItem();
    item->SetItemCategory(1);
    item->SetItemSubcategory(6);
    item->SetItemGuid(guid);
    return item;
}

}
