// 0x8030821C EVibrate::StopMotorTwo(unsigned char, float) (92B)

class EvSMVt3 {
public:
    char pad[0x70];
    short m_off;                       // 0x70
    char _p[2];
    int (*m_fn)(void*, float);         // 0x74
};

class EvSMObj3 {
public:
    char pad[0x208];
    EvSMVt3* m_vt;                     // 0x208
};

extern void* g_evibrate_globalA;       // SDA r13-26524

extern EvSMObj3* EVibrate_LookupCtrl4(void* g, unsigned char x);

class EVibrate {
public:
    int StopMotorTwo(unsigned char x, float val);
};

int EVibrate::StopMotorTwo(unsigned char x, float val) {
    EvSMObj3* c = EVibrate_LookupCtrl4(g_evibrate_globalA, x);
    int result;
    if (c == 0) {
        result = 0;
        goto end;
    }
    {
        EvSMVt3* vt = c->m_vt;
        short off = vt->m_off;
        int (*fn)(void*, float) = vt->m_fn;
        result = fn((char*)c + off, val);
    }
end:
    return result;
}
