// 0x80183258 (8 bytes)
class ActionMenu {
public:
    class MenuItem {
    public:
        int GetSubMenu();
    };
};

int ActionMenu::MenuItem::GetSubMenu() {
    return *(int*)((char*)this + 0x5C);
}
