// 0x801ae838 E2ETarget::OnSaveGameDialogClosed (84B)

extern void UIObjectBase_AptViewer_CallFunction(char*, char*, char*, int, char**);
extern const char E2E_savegame_flow[];

class E2ETarget {
public:
    char pad[0xE0];
    int m_field_224;      // 0xE0

    void SaveGame(void);
    void OnSaveGameDialogClosed(int);
};

void E2ETarget::OnSaveGameDialogClosed(int selection) {
    if (selection == 0) {
        SaveGame();
        return;
    }
    m_field_224 = 0;
    UIObjectBase_AptViewer_CallFunction((char*)E2E_savegame_flow, 0, 0, 0, 0);
}
