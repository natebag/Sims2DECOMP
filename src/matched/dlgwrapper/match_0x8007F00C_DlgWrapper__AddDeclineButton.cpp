/* DlgWrapper::AddDeclineButton(unsigned wchar_t *) - 0x8007F00C (48B) */

struct Panel {
    int AddButton(int type, int selectable, unsigned short* text);
};

class DlgWrapper {
public:
    char pad[172];
    Panel* m_panel;

    void AddDeclineButton(unsigned short* text);
};

void DlgWrapper::AddDeclineButton(unsigned short* text) {
    m_panel->AddButton(1, 1, text);
}
