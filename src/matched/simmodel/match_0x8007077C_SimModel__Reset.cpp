// 0x8007077C SimModel::Reset(void) (140B)

struct SimModel {
    char pad[312];
    void* m_f312;         // offset 312
    void* m_f316;         // offset 316
    char pad2[16];
    int m_f336;            // offset 336
    char pad3[0];
    int m_f340;            // offset 340
    void Reset(void);
};

extern "C" void SM_Fn1(void);                           // 0x80071460
extern "C" void SM_Fn2(SimModel* self);                 // 0x80070808
extern "C" void SM_Fn3(SimModel* self);                 // 0x8007096c
extern "C" void SM_VDtor(void* p, int flag);            // 0x8016a8f8
extern "C" void SM_OpDelete(void* p);                   // 0x802d1220

void SimModel::Reset(void) {
    SM_Fn1();
    SM_Fn2(this);
    SM_Fn3(this);
    void* p = m_f312;
    if (p != 0) {
        SM_VDtor(p, 3);
    }
    int f340 = m_f340;
    m_f312 = 0;
    m_f336 = 1;
    if (f340 != 0) {
        void* q = m_f316;
        if (q != 0) {
            SM_OpDelete(q);
            m_f316 = 0;
        }
    }
    m_f316 = 0;
    m_f340 = 0;
}
