// FLAGS: -fno-elide-constructors

extern int VT1_802037D8[];
extern int VT2_802037D8[];
extern int init_802037D8(void*);

struct S_802037D8 { void* m_param; int m_result; int* m_vt; };

S_802037D8* func_802037D8(S_802037D8* self, void* param) {
    self->m_vt = VT1_802037D8;
    self->m_param = param;
    self->m_result = init_802037D8(param);
    self->m_vt = VT2_802037D8;
    return self;
}
