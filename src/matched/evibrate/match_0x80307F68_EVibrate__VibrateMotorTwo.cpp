// 0x80307F68 EVibrate::VibrateMotorTwo(unsigned char, float) (92B)

class EvVM2Vt {
public:
    char pad[0x38];
    short m_off;                       // 0x38
    char _p[2];
    int (*m_fn)(void*, float);         // 0x3C
};

class EvVM2Obj {
public:
    char pad[0x208];
    EvVM2Vt* m_vt;                     // 0x208
};

extern void* g_evibrate_globalA;       // SDA r13-26524

extern EvVM2Obj* EVibrate_LookupCtrl2(void* g, unsigned char x);

class EVibrate {
public:
    int VibrateMotorTwo(unsigned char x, float val);
};

int EVibrate::VibrateMotorTwo(unsigned char x, float val) {
    EvVM2Obj* c = EVibrate_LookupCtrl2(g_evibrate_globalA, x);
    int result;
    if (c == 0) {
        result = 0;
        goto end;
    }
    {
        EvVM2Vt* vt = c->m_vt;
        short off = vt->m_off;
        int (*fn)(void*, float) = vt->m_fn;
        result = fn((char*)c + off, val);
    }
end:
    return result;
}
