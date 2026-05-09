// InLevelBaseState::dialog_selection_callback(int) @ 0x8008B55C (80B)

namespace UIObjectBase {
    void UIRouter_FlowGoto(char* dest);
}

extern char gInLevelDialogFlag[];

struct InLevelDSC {
    void dialog_selection_callback(int selection);
};

void InLevelDSC::dialog_selection_callback(int selection) {
    if (!*(int*)gInLevelDialogFlag)
        return;
    if (selection == 0)
        UIObjectBase::UIRouter_FlowGoto("MainMenu");
    else
        UIObjectBase::UIRouter_FlowGoto("Pause");
}
