// 0x80188E34 HUDTarget::CloseMenu(int) (44B)

class ActionMenu {
public:
    void CloseMenu();
};

class HUDTarget {
public:
    void CloseMenu(int player);
};

void HUDTarget::CloseMenu(int player) {
    int offset = player * 180 + 0x740;
    ((ActionMenu*)((char*)this + offset))->CloseMenu();
}
