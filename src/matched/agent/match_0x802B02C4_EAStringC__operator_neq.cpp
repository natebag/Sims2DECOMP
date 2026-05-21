// 0x802B02C4 EAStringC::operator!=(char*) const (52B)

struct EAStringData {
    char pad[8];
    char m_str;
};

struct EAStringC_B {
    EAStringData* m_data;
};

extern int strcmp_func_B(void* a, void* b);

int EAStringC__operator_neq_B(EAStringC_B* self, void* other) {
    int eq = strcmp_func_B(&self->m_data->m_str, other) == 0;
    return eq ^ 1;
}
