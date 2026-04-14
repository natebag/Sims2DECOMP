// 0x801ac9b0 E2ETarget::SaveGame (92B)

extern void UIObjectBase_AptViewer_CallFunction(char*, char*, char*, int, char**);
extern void UIDB_UIDBSetInt(char*, int);
extern void UIObjectBase_UIRouter_FlowGoto(char*);

extern const char E2E_savegame_callfunc[];
extern const char E2E_savegame_dbint[];
extern const char E2E_savegame_flowgoto[];

class E2ETarget {
public:
    char pad[0xE0];
    int m_field_224;      // 0xE0

    void SaveGame(void);
};

void E2ETarget::SaveGame(void) {
    m_field_224 = 1;
    UIObjectBase_AptViewer_CallFunction((char*)E2E_savegame_callfunc, 0, 0, 0, 0);
    UIDB_UIDBSetInt((char*)E2E_savegame_dbint, 3);
    UIObjectBase_UIRouter_FlowGoto((char*)E2E_savegame_flowgoto);
}
