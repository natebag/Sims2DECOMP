// 0x800105D8 (104B) AptViewer::Init(UIObjectBase*)

class UIObjectBase;

struct AptViewer {
    char pad1[0x3A0];
    int m_field_3A0;      // +0x3A0 = 928
    char pad2[0xAC];      // to 0x450
    int m_field_450;      // +0x450 = 1104
    int m_field_454;      // +0x454 = 1108

    void Init(UIObjectBase* obj);
};

extern void AptViewer_InitHelper();
extern void AptViewer_InitHelper2(UIObjectBase* obj);

void AptViewer::Init(UIObjectBase* obj) {
    if (m_field_3A0 == 0) {
        AptViewer_InitHelper();
    }
    m_field_3A0 = 1;
    AptViewer_InitHelper2(obj);
    int* base = &m_field_450;
    for (int i = 1; i >= 0; i--) {
        base[i] = 0;
    }
}
