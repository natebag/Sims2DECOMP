// FLAGS: -fno-elide-constructors

extern int VT1_8020382C[];
extern int VT2_8020382C[];
extern int init_8020382C(void*);

struct S_8020382C { void* m_param; int m_result; int* m_vt; };

S_8020382C* func_8020382C(S_8020382C* self, void* param) {
    self->m_vt = VT1_8020382C;
    self->m_param = param;
    self->m_result = init_8020382C(param);
    self->m_vt = VT2_8020382C;
    return self;
}
