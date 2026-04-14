// 0x801ae598 E2ETarget::OnSaveGameComplete (72B)

extern void UIObjectBase_AptViewer_CallFunction(char*, char*, char*, int, char**);
extern const char E2E_savegame_flow[];

class E2ETarget {
public:
    char pad[0xE0];
    int m_field_224;      // 0xE0
    char pad2[0x1A0];
    int m_field_644;      // 0x284

    void OnSaveGameComplete(bool);
};

void E2ETarget::OnSaveGameComplete(bool) {
    m_field_224 = 0;
    m_field_644 = 0;
    UIObjectBase_AptViewer_CallFunction((char*)E2E_savegame_flow, 0, 0, 0, 0);
}
