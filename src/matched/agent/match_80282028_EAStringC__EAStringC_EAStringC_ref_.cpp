struct EAStringData {
    unsigned short m_refCount;
};

struct EAStringC {
    EAStringData* m_data;

    EAStringC(EAStringC& other);
};

EAStringC::EAStringC(EAStringC& other) {
    m_data = other.m_data;
    m_data->m_refCount++;
}
