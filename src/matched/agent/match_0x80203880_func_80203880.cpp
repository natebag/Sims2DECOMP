// FLAGS: -fno-elide-constructors

extern int VT1_80203880[];
extern int VT2_80203880[];
extern int init_80203880(void*);

struct S_80203880 { void* m_param; int m_result; int* m_vt; };

S_80203880* func_80203880(S_80203880* self, void* param) {
    self->m_vt = VT1_80203880;
    self->m_param = param;
    self->m_result = init_80203880(param);
    self->m_vt = VT2_80203880;
    return self;
}
