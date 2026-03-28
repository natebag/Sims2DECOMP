struct CareerList {
    char pad[0x0C];
    int m_numCareers;
};

class CareersImpl {
public:
    void *vtable;
    void *pad_04;
    CareerList *m_careerList;

    int GetNumCareers(void);
};

int CareersImpl::GetNumCareers(void) {
    return m_careerList->m_numCareers;
}
