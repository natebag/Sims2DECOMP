// 0x801BC228 INGTarget::set_done_button_state(bool) (92B)

class AptViewer {
public:
    void NewCallFunction(char* widget, char* a, char* b, int n, ...);
};

extern AptViewer* g_aptViewer;  // SDA -25136
extern char s_showStr[];        // 0x803EEB58
extern char s_hideStr[];        // 0x803EEB5C
extern char s_doneBtnWidget[];  // 0x803F19C4

class INGTarget {
public:
    int set_done_button_state(bool b);
};

int INGTarget::set_done_button_state(bool b) {
    AptViewer* viewer = g_aptViewer;
    char* arg;
    if (b != false) {
        arg = s_showStr;
    } else {
        arg = s_hideStr;
    }
    viewer->NewCallFunction(s_doneBtnWidget, 0, 0, 1, arg);
    return 1;
}
