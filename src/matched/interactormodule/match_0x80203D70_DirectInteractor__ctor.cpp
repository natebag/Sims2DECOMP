// 0x80203D70 InteractorModule::DirectInteractor::DirectInteractor(void) (96B)

extern const float kDIInitFloat;  // SDA r13-23848

namespace InteractorModule {

class Interactor {
public:
    char pad_base[0x5C];
    Interactor();
};

class DirectInteractor : public Interactor {
public:
    void* m_vt_at_5C;    // 0x5C (set by this ctor)
    char p1[0x64 - 0x60];
    int m_flag;          // 0x64
    char p2[0x70 - 0x68];
    int m_field_70;      // 0x70
    float m_field_74;    // 0x74
    int m_field_78;      // 0x78
    int m_field_7C;      // 0x7C
    int m_field_80;      // 0x80

    DirectInteractor();
};

extern char vt_DirectInteractor[];

DirectInteractor::DirectInteractor() {
    m_vt_at_5C = vt_DirectInteractor;
    m_flag = 1;
    m_field_74 = kDIInitFloat;
    m_field_70 = 0;
    m_field_78 = 0;
    m_field_7C = 0;
    m_field_80 = 0;
}

}
