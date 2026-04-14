/* constructor with double vtable at 0x80203784 (84B) */
// FLAGS: -fno-elide-constructors

extern int VT1_80203784[];
extern int VT2_80203784[];
extern int init_80203784(void*);

struct S_80203784 { void* m_param; int m_result; int* m_vt; };

S_80203784* func_80203784(S_80203784* self, void* param) {
    self->m_vt = VT1_80203784;
    self->m_param = param;
    self->m_result = init_80203784(param);
    self->m_vt = VT2_80203784;
    return self;
}
