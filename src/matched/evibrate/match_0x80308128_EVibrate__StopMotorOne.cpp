// 0x80308128 EVibrate::StopMotorOne(unsigned char) (76B)

class EvSMVt {
public:
    char pad[0x58];
    short m_off;                       // 0x58
    char _p[2];
    int (*m_fn)(void*);                // 0x5C
};

class EvSMObj {
public:
    char pad[0x208];
    EvSMVt* m_vt;                      // 0x208
};

extern void* g_evibrate_globalA;       // SDA r13-26524

extern EvSMObj* EVibrate_LookupCtrl(void* g, unsigned char x);

class EVibrate {
public:
    int StopMotorOne(unsigned char x);
};

int EVibrate::StopMotorOne(unsigned char x) {
    EvSMObj* c = EVibrate_LookupCtrl(g_evibrate_globalA, x);
    int result;
    if (c == 0) {
        result = 0;
        goto end;
    }
    {
        EvSMVt* vt = c->m_vt;
        short off = vt->m_off;
        int (*fn)(void*) = vt->m_fn;
        result = fn((char*)c + off);
    }
end:
    return result;
}
