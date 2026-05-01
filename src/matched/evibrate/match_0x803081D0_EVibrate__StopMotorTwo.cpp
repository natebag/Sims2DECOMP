// 0x803081D0 EVibrate::StopMotorTwo(unsigned char) (76B)

class EvSM2Vt {
public:
    char pad[0x68];
    short m_off;                       // 0x68
    char _p[2];
    int (*m_fn)(void*);                // 0x6C
};

class EvSM2Obj {
public:
    char pad[0x208];
    EvSM2Vt* m_vt;                     // 0x208
};

extern void* g_evibrate_globalA;       // SDA r13-26524

extern EvSM2Obj* EVibrate_LookupCtrl2(void* g, unsigned char x);

class EVibrate {
public:
    int StopMotorTwo(unsigned char x);
};

int EVibrate::StopMotorTwo(unsigned char x) {
    EvSM2Obj* c = EVibrate_LookupCtrl2(g_evibrate_globalA, x);
    int result;
    if (c == 0) {
        result = 0;
        goto end;
    }
    {
        EvSM2Vt* vt = c->m_vt;
        short off = vt->m_off;
        int (*fn)(void*) = vt->m_fn;
        result = fn((char*)c + off);
    }
end:
    return result;
}
