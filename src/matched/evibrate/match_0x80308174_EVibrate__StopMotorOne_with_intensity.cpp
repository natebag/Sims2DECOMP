// 0x80308174 EVibrate::StopMotorOne(unsigned char, float) (92B)

class EvSMVt2 {
public:
    char pad[0x60];
    short m_off;                       // 0x60
    char _p[2];
    int (*m_fn)(void*, float);         // 0x64
};

class EvSMObj2 {
public:
    char pad[0x208];
    EvSMVt2* m_vt;                     // 0x208
};

extern void* g_evibrate_globalA;       // SDA r13-26524

extern EvSMObj2* EVibrate_LookupCtrl3(void* g, unsigned char x);

class EVibrate {
public:
    int StopMotorOne(unsigned char x, float val);
};

int EVibrate::StopMotorOne(unsigned char x, float val) {
    EvSMObj2* c = EVibrate_LookupCtrl3(g_evibrate_globalA, x);
    int result;
    if (c == 0) {
        result = 0;
        goto end;
    }
    {
        EvSMVt2* vt = c->m_vt;
        short off = vt->m_off;
        int (*fn)(void*, float) = vt->m_fn;
        result = fn((char*)c + off, val);
    }
end:
    return result;
}
