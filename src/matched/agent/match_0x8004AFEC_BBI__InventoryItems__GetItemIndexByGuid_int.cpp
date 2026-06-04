// 0x8004AFEC BBI::InventoryItems::GetItemIndexByGuid(int, unsigned char) const (140 B)

namespace BBI {

struct InventoryItem {
    int GetItemGuid() const;
    int GetItemColorIndex() const;
};

struct InventoryItems {
    InventoryItem* m_items[36];
    int GetContainerSize() const;
    int GetItemIndexByGuid(int guid, unsigned char color) const;
};

int InventoryItems::GetItemIndexByGuid(int guid, unsigned char color) const {
    int count = GetContainerSize();
    int i = 0;
    if (i < count) {
        int offset = 0;
        unsigned int base = (unsigned int)this;
        do {
            InventoryItem* item = *(InventoryItem**)(offset + base);
            if (item != 0 && item->GetItemGuid() == guid && (*(InventoryItem**)(offset + base))->GetItemColorIndex() == color) {
                return i;
            }
            ++i;
            offset += 4;
        } while (i < count);
    }
    return -1;
}

}
