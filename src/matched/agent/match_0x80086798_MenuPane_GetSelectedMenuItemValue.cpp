// 0x80086798 (56B) MenuPane::GetSelectedMenuItemValue()
// Get selected item (force=true), return ->value or -1 if null.

struct MenuItemMP {
    int unk0;
    int unk4;
    int value;
};

class MenuPane {
public:
    int GetSelectedMenuItemValue();
    MenuItemMP* GetSelectedMenuItem(int);
};

int MenuPane::GetSelectedMenuItemValue() {
    MenuItemMP* item = GetSelectedMenuItem(1);
    if (!item) return -1;
    return item->value;
}
