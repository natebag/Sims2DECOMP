// 0x800B1698 CareersImpl::GetNumCareers(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0x8(r3); lwz r3,0xc(r9); blr

struct CareerData {
    char _pad[0xC];
    int m_numCareers; // 0xC
};

struct CareersImpl {
    char _pad[0x8];
    CareerData* m_data; // 0x8

    int GetNumCareers();
};

int CareersImpl::GetNumCareers() {
    return m_data->m_numCareers;
}
