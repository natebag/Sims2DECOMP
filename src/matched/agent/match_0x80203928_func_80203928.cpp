// FLAGS: -fno-elide-constructors

extern int VT1_80203928[];
extern int VT2_80203928[];
extern int init_80203928(void*);

struct S_80203928 { void* m_param; int m_result; int* m_vt; };

S_80203928* func_80203928(S_80203928* self, void* param) {
    self->m_vt = VT1_80203928;
    self->m_param = param;
    self->m_result = init_80203928(param);
    self->m_vt = VT2_80203928;
    return self;
}
