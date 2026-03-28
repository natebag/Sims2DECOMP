struct EAStringData_3 {
    unsigned short m_refCount;
};

struct EAStringC_CC3 {
    EAStringData_3* m_data;

    EAStringC_CC3(EAStringC_CC3& other);
};

EAStringC_CC3::EAStringC_CC3(EAStringC_CC3& other) {
    m_data = other.m_data;
    m_data->m_refCount++;
}
