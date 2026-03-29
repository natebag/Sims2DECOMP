struct EAStringData {
    char pad[8];
    char m_str;
};

struct EAStringC_eq {
    EAStringData* m_data;
};

extern int strcmp_func(void* a, void* b);

int EAStringC_op_eq(EAStringC_eq* self, void* other) {
    return strcmp_func(&self->m_data->m_str, other) == 0;
}
