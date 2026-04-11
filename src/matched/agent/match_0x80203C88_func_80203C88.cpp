// FLAGS: -fno-elide-constructors

extern int VT1_80203C88[];
extern int VT2_80203C88[];
extern int init_80203C88(void*);

struct S_80203C88 { void* m_param; int m_result; int* m_vt; };

S_80203C88* func_80203C88(S_80203C88* self, void* param) {
    self->m_vt = VT1_80203C88;
    self->m_param = param;
    self->m_result = init_80203C88(param);
    self->m_vt = VT2_80203C88;
    return self;
}
