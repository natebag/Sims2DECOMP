// 0x800A7128 StringBuffer2::toLower(void) (100B)
struct StringBuffer2 {
    unsigned short* m_buffer;
};

extern int StringBuffer2__length(StringBuffer2* self);

void StringBuffer2__toLower(StringBuffer2* self) {
    int len = StringBuffer2__length(self);
    for (int i = 0; i < len; i++) {
        unsigned short* buf = self->m_buffer;
        unsigned int c = buf[i];
        if ((c - 'A') <= 25) {
            buf[i] = c + 32;
        }
    }
}
