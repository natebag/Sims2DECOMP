// 0x801A6188 CRDTarget::HidePhoto(void) (72B)

class UIReflow {
public:
    char pad[20];  // size 20 to force 32B frame
    UIReflow();
    ~UIReflow();
    void ResetVisibility(char* name, bool a, int b);
    void SomeFinalize(int);
};

extern char s_photoWidgetId[];  // 0x803EE154

class CRDTarget {
public:
    void HidePhoto();
};

void CRDTarget::HidePhoto() {
    UIReflow r;
    r.ResetVisibility(s_photoWidgetId, false, 0);
    // dtor inlined with arg 2
}
