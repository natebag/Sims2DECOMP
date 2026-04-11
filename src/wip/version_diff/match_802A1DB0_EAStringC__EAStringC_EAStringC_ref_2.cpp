struct EAStringData_2 {
    unsigned short m_refCount;
};

struct EAStringC_CC2 {
    EAStringData_2* m_data;

    EAStringC_CC2(EAStringC_CC2& other);
};

EAStringC_CC2::EAStringC_CC2(EAStringC_CC2& other) {
    m_data = other.m_data;
    m_data->m_refCount++;
}
