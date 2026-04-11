// FLAGS: -fno-elide-constructors

extern int VT1_80203CDC[];
extern int VT2_80203CDC[];
extern int init_80203CDC(void*);

struct S_80203CDC { void* m_param; int m_result; int* m_vt; };

S_80203CDC* func_80203CDC(S_80203CDC* self, void* param) {
    self->m_vt = VT1_80203CDC;
    self->m_param = param;
    self->m_result = init_80203CDC(param);
    self->m_vt = VT2_80203CDC;
    return self;
}
