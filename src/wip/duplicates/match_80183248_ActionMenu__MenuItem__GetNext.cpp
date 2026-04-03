// 0x80183248 (8 bytes)
class ActionMenu {
public:
    class MenuItem {
    public:
        int GetNext();
    };
};

int ActionMenu::MenuItem::GetNext() {
    return *(int*)((char*)this + 0x60);
}
