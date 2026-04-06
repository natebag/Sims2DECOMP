// FLAGS: -fno-elide-constructors

extern int VT1_80203ADC[];
extern int VT2_80203ADC[];
extern int init_80203ADC(void*);

struct S_80203ADC { void* m_param; int m_result; int* m_vt; };

S_80203ADC* func_80203ADC(S_80203ADC* self, void* param) {
    self->m_vt = VT1_80203ADC;
    self->m_param = param;
    self->m_result = init_80203ADC(param);
    self->m_vt = VT2_80203ADC;
    return self;
}
