struct EASData2 {
    char pad[0x08];
    char m_str;
};
struct EAStringC_OCP {
    EASData2* m_data;
    char* operator_char_ptr() const;
};
char* EAStringC_OCP::operator_char_ptr() const {
    return &m_data->m_str;
}
