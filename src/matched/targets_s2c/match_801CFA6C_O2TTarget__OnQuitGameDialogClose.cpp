/* O2TTarget::OnQuitGameDialogClose(int) at 0x801CFA6C (124B) */

typedef char* CharPtr;

struct UIObjectBase {
    static void UIRouter_FlowGoto(char*);
    static void AptViewer_CallFunction(char*, CharPtr, CharPtr, int, CharPtr*);
};

extern char s_quitFlowStr[];
extern char s_quitNoFlowStr[];
extern char s_o2tCallbackStr2[];

struct O2TTarget {
    char pad_000[0x250];
    int m_field250;

    void OnQuitGameDialogClose(int result);
};

void O2TTarget::OnQuitGameDialogClose(int result) {
    if (result == 1) {
        UIObjectBase::UIRouter_FlowGoto(s_quitFlowStr);
    } else if (result == 0) {
        UIObjectBase::UIRouter_FlowGoto(s_quitNoFlowStr);
    } else {
        UIObjectBase::AptViewer_CallFunction(s_o2tCallbackStr2, (CharPtr)0, (CharPtr)0, 0, (CharPtr*)0);
        m_field250 = 0;
    }
}
