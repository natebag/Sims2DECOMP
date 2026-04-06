// FLAGS: -fno-elide-constructors

extern int VT1_802038D4[];
extern int VT2_802038D4[];
extern int init_802038D4(void*);

struct S_802038D4 { void* m_param; int m_result; int* m_vt; };

S_802038D4* func_802038D4(S_802038D4* self, void* param) {
    self->m_vt = VT1_802038D4;
    self->m_param = param;
    self->m_result = init_802038D4(param);
    self->m_vt = VT2_802038D4;
    return self;
}
