// 0x80182F40 ActionMenu::MenuItem::MenuItem(void) (92B)
// FLAGS: -fno-schedule-insns

extern void Interaction_ctor(void* self);
extern void BString2_ctor(void* self);

class ActionMenu {
public:
    struct MenuItem {
        int  m_field0;
        char m_inter[68];   // 4..72 (Interaction at +4)
        char m_str[20];     // 72..92 (BString2 at +72)
        int  m_field92;
        int  m_field96;
        MenuItem();
    };
};

ActionMenu::MenuItem::MenuItem() {
    char* self = (char*)this;
    Interaction_ctor(self + 4);
    BString2_ctor(self + 72);
    *(int*)(self + 96) = 0;
    *(int*)(self + 0) = 0;
    *(int*)(self + 76) = 0;
    *(int*)(self + 80) = 0;
    *(int*)(self + 84) = 0;
    *(int*)(self + 88) = 0;
    *(int*)(self + 92) = 0;
}
