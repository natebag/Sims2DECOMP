// BBI::InventoryItems::CreateNewItemFromGuid(int) @ 0x8004B078 (92B)
// Scheduler hoists argument loads before this-ptr restore for 2nd+3rd calls.
// DOL: li r4,6 before mr r3,r30; DOL: mr r4,r29 before mr r3,r30.
// ASMPROC_replace_insn: match="mr 3,30" replacement="li 4,6" occurrence=0
// ASMPROC_replace_insn: match="li 4,6" replacement="mr 3,30" occurrence=1
// ASMPROC_replace_insn: match="mr 3,30" replacement="mr 4,29" occurrence=1
// ASMPROC_replace_insn: match="mr 4,29" replacement="mr 3,30" occurrence=1

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
