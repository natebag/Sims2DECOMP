class Interaction {
public:
    char _data[0x44];
    ~Interaction(void);
};

class BString2 {
public:
    char _data[4];
    ~BString2(void);
};

void operator delete(void*);

class ActionMenu {
public:
    class MenuItem {
    public:
        int m_field_00;
        Interaction m_interaction;
        BString2 m_name;
        int m_field_4C;
        int m_field_50;
        int m_field_54;
        int m_field_58;
        int m_field_5C;
        MenuItem* m_next;

        void ClearMenu(void);
        ~MenuItem(void);
    };
};

ActionMenu::MenuItem::~MenuItem(void) {
    ClearMenu();
}
