/* CareersImpl::GetSuit(Job &, bool) at 0x800B1B4C (8B) */

struct Job {
    char pad[0x68];
    int m_suit;
};

struct CareersImpl {
    int GetSuit(Job* job, int isFemale);
};

int CareersImpl::GetSuit(Job* job, int isFemale) {
    return job->m_suit;
}
