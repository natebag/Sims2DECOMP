// FLAGS: -fno-elide-constructors

extern int VT1_80203C34[];
extern int VT2_80203C34[];
extern int init_80203C34(void*);

struct S_80203C34 { void* m_param; int m_result; int* m_vt; };

S_80203C34* func_80203C34(S_80203C34* self, void* param) {
    self->m_vt = VT1_80203C34;
    self->m_param = param;
    self->m_result = init_80203C34(param);
    self->m_vt = VT2_80203C34;
    return self;
}
