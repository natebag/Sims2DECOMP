/* StringBuffer::c_str(void) const at 0x800A6718 (8B) */

struct StringBuffer {
    char* m_buffer;

    char* c_str(void) const;
};

char* StringBuffer::c_str(void) const {
    return m_buffer;
}
