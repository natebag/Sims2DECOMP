// 0x80034908 (68 bytes)
/* ESim::GetScaler(void) */

extern const float lbl_803D120C[3];  /* 3-elem forces lis+lfs (not sda21) */

struct ESimScalerHolder {
    char pad[0x120];
    void *m_obj;
};

struct ESimScalerObj {
    char pad[0x88];
    float m_v;
};

struct ESimModelBase {
    void *p[4];
};

struct ESimModel {
    char pad[0x68];
    ESimModelBase b;
};

struct ESim_GS {
    char pad[0x63C];
    ESimModel *m;
    float GetScaler(void);
};

float ESim_GS::GetScaler(void) {
    ESimModelBase *base = &m->b;
    ESimScalerHolder *p2 = (ESimScalerHolder *)base->p[2];
    if (p2 != 0) {
        return ((ESimScalerObj *)p2->m_obj)->m_v;
    }
    ESimScalerHolder *p3 = (ESimScalerHolder *)base->p[3];
    if (p3 == 0) {
        goto no_p3;
    }
    return ((ESimScalerObj *)p3->m_obj)->m_v;
no_p3:
    return lbl_803D120C[0];
}
