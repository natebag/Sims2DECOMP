// 0x80086808 (56B) MenuDialogPane::GetSelectedMenuItemValue()
// Get selected item (force=true), return ->value or -1 if null.

struct MenuItemMDP {
    int unk0;
    int unk4;
    int value;
};

class MenuDialogPane {
public:
    int GetSelectedMenuItemValue();
    MenuItemMDP* GetSelectedMenuItem(int);
};

int MenuDialogPane::GetSelectedMenuItemValue() {
    MenuItemMDP* item = GetSelectedMenuItem(1);
    if (!item) return -1;
    return item->value;
}
