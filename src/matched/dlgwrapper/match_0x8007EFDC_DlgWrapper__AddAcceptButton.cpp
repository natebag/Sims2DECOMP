/* DlgWrapper::AddAcceptButton(unsigned wchar_t *) - 0x8007EFDC (48B) */

struct Panel {
    int AddButton(int type, int selectable, unsigned short* text);
};

class DlgWrapper {
public:
    char pad[172];
    Panel* m_panel;

    void AddAcceptButton(unsigned short* text);
};

void DlgWrapper::AddAcceptButton(unsigned short* text) {
    m_panel->AddButton(0, 1, text);
}
