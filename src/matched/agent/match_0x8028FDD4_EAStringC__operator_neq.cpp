// 0x8028FDD4 EAStringC::operator!=(char*) const (52B)

struct EAStringData {
    char pad[8];
    char m_str;
};

struct EAStringC {
    EAStringData* m_data;
};

extern int strcmp_func(void* a, void* b);

int EAStringC__operator_neq(EAStringC* self, void* other) {
    int eq = strcmp_func(&self->m_data->m_str, other) == 0;
    return eq ^ 1;
}
