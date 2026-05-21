// 0x801D61BC PCTTarget::set_dialog_visible(bool) (92B)

class UIObjectBase {
public:
    static void AptViewer_CallFunction(char* widget, char* a, char* b, int n, char** args);
};

extern char s_pctVisibleShow[];   // 0x803EEB58
extern char s_pctVisibleHide[];   // 0x803EEB5C
extern char s_pctDialogWidget[];  // 0x803F4350

class PCTTarget {
public:
    int set_dialog_visible(bool b);
};

int PCTTarget::set_dialog_visible(bool b) {
    char* arg;
    if (b != false) {
        arg = s_pctVisibleShow;
    } else {
        arg = s_pctVisibleHide;
    }
    char* args[1];
    args[0] = arg;
    UIObjectBase::AptViewer_CallFunction(s_pctDialogWidget, 0, 0, 1, args);
    return 1;
}
