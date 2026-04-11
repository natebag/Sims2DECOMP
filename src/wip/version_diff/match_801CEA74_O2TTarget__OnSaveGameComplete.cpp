/* O2TTarget::OnSaveGameComplete(bool) at 0x801CEA74 (76B) */

typedef char* CharPtr;

struct UIObjectBase {
    static void AptViewer_CallFunction(char*, CharPtr, CharPtr, int, CharPtr*);
};

extern char s_o2tCallbackStr[];

struct O2TTarget {
    char pad_000[0x90];
    int m_field90;

    void OnSaveGameComplete(int success);
};

void O2TTarget::OnSaveGameComplete(int success) {
    UIObjectBase::AptViewer_CallFunction(s_o2tCallbackStr, (CharPtr)0, (CharPtr)0, 0, (CharPtr*)0);
    m_field90 = 0;
}
