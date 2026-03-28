struct EASData {
    char pad[0x08];
    char m_str;
};
struct EAStringC_CS {
    EASData* m_data;
    char* c_str() const;
};
char* EAStringC_CS::c_str() const {
    return &m_data->m_str;
}
