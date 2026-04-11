// FLAGS: -fno-elide-constructors

extern int VT1_80203BE0[];
extern int VT2_80203BE0[];
extern int init_80203BE0(void*);

struct S_80203BE0 { void* m_param; int m_result; int* m_vt; };

S_80203BE0* func_80203BE0(S_80203BE0* self, void* param) {
    self->m_vt = VT1_80203BE0;
    self->m_param = param;
    self->m_result = init_80203BE0(param);
    self->m_vt = VT2_80203BE0;
    return self;
}
