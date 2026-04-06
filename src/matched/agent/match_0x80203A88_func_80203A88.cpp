// FLAGS: -fno-elide-constructors

extern int VT1_80203A88[];
extern int VT2_80203A88[];
extern int init_80203A88(void*);

struct S_80203A88 { void* m_param; int m_result; int* m_vt; };

S_80203A88* func_80203A88(S_80203A88* self, void* param) {
    self->m_vt = VT1_80203A88;
    self->m_param = param;
    self->m_result = init_80203A88(param);
    self->m_vt = VT2_80203A88;
    return self;
}
