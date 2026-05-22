// 0x80177D54 UIObjectBase::AptViewer_CallFunction(char*, char*, char*, int, char**) (84B)

class AptViewer {
public:
    void NewCallFunction2(char* widget, char* a, char* b, int n, char** args);
};

extern char _globals_aptViewer[16];   // _globals.aptViewer at 0x80475E80, char[16] for HA/LO

class UIObjectBase {
public:
    static void AptViewer_CallFunction(char* widget, char* a, char* b, int n, char** args);
};

void UIObjectBase::AptViewer_CallFunction(char* widget, char* a, char* b, int n, char** args) {
    AptViewer* v = *(AptViewer**)_globals_aptViewer;
    v->NewCallFunction2(widget, a, b, n, args);
}
