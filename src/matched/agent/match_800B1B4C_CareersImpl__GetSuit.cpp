struct Job {
    char pad[0x68];
    int m_suit;
};

class CareersImpl {
public:
    int GetSuit(Job &job, bool);
};

int CareersImpl::GetSuit(Job &job, bool) {
    return job.m_suit;
}
