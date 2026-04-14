// 0x802AEC6C AptString::cpy (72b)
// FLAGS: -fno-schedule-insns

struct EAStringC {
    char _data[8];
    EAStringC(char *str);
    ~EAStringC(void);
    EAStringC &operator=(EAStringC &other);
};

struct AptString {
    char _pad[12];
    EAStringC m_str;
};

void AptString__cpy(AptString *self, char *str) {
    EAStringC *dst = &self->m_str;
    EAStringC tmp(str);
    *dst = tmp;
}
