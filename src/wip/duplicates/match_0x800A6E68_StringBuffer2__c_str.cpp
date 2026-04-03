/* StringBuffer2::c_str(void) const at 0x800A6E68 (8B) */

struct StringBuffer2 {
    unsigned short* m_buffer;

    unsigned short* c_str(void) const;
};

unsigned short* StringBuffer2::c_str(void) const {
    return m_buffer;
}
