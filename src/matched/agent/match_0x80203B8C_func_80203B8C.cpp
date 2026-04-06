// FLAGS: -fno-elide-constructors

extern int VT1_80203B8C[];
extern int VT2_80203B8C[];
extern int init_80203B8C(void*);

struct S_80203B8C { void* m_param; int m_result; int* m_vt; };

S_80203B8C* func_80203B8C(S_80203B8C* self, void* param) {
    self->m_vt = VT1_80203B8C;
    self->m_param = param;
    self->m_result = init_80203B8C(param);
    self->m_vt = VT2_80203B8C;
    return self;
}
