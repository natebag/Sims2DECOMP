// FLAGS: -fno-elide-constructors

extern int VT1_802039D8[];
extern int VT2_802039D8[];
extern int init_802039D8(void*);

struct S_802039D8 { void* m_param; int m_result; int* m_vt; };

S_802039D8* func_802039D8(S_802039D8* self, void* param) {
    self->m_vt = VT1_802039D8;
    self->m_param = param;
    self->m_result = init_802039D8(param);
    self->m_vt = VT2_802039D8;
    return self;
}
