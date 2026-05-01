// 0x80307EA0 EVibrate::VibrateMotorOne(unsigned char, float) (92B)

class EvVMVt {
public:
    char pad[0x28];
    short m_off;                       // 0x28
    char _p[2];
    int (*m_fn)(void*, float);         // 0x2C
};

class EvVMObj {
public:
    char pad[0x208];
    EvVMVt* m_vt;                      // 0x208
};

extern void* g_evibrate_globalA;       // SDA r13-26524

extern EvVMObj* EVibrate_LookupCtrl(void* g, unsigned char x);

class EVibrate {
public:
    int VibrateMotorOne(unsigned char x, float val);
};

int EVibrate::VibrateMotorOne(unsigned char x, float val) {
    EvVMObj* c = EVibrate_LookupCtrl(g_evibrate_globalA, x);
    int result;
    if (c == 0) {
        result = 0;
        goto end;
    }
    {
        EvVMVt* vt = c->m_vt;
        short off = vt->m_off;
        int (*fn)(void*, float) = vt->m_fn;
        result = fn((char*)c + off, val);
    }
end:
    return result;
}
