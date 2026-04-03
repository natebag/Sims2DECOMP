/* CareersImpl::GetNumCareers(void) at 0x800B1698 (12B) */

struct CareersData {
    char pad[0x0C];
    int m_numCareers;
};

struct CareersImpl {
    char pad[0x08];
    CareersData* m_data;

    int GetNumCareers(void);
};

int CareersImpl::GetNumCareers(void) {
    return m_data->m_numCareers;
}
