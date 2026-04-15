/* DlgWrapper::AddAlt1Button(unsigned wchar_t *) - 0x8007F03C (48B) */

struct Panel {
    int AddButton(int type, int selectable, unsigned short* text);
};

class DlgWrapper {
public:
    char pad[172];
    Panel* m_panel;

    void AddAlt1Button(unsigned short* text);
};

void DlgWrapper::AddAlt1Button(unsigned short* text) {
    m_panel->AddButton(2, 1, text);
}
