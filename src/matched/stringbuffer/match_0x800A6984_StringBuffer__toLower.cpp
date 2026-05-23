// 0x800A6984 StringBuffer::toLower(void) (96B)
struct StringBuffer {
    char* m_buffer;
};

extern int StringBuffer__length(StringBuffer* self);

void StringBuffer__toLower(StringBuffer* self) {
    int len = StringBuffer__length(self);
    for (int i = 0; i < len; i++) {
        char* buf = self->m_buffer;
        unsigned char c = buf[i];
        if ((unsigned char)(c - 'A') <= 25) {
            buf[i] = c + 32;
        }
    }
}
