// 0x80183250 (8 bytes)
class ActionMenu {
public:
    class MenuItem {
    public:
        int GetNextConst();
    };
};

int ActionMenu::MenuItem::GetNextConst() {
    return *(int*)((char*)this + 0x60);
}
