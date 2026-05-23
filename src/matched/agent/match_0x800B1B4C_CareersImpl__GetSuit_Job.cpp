// 0x800B1B4C CareersImpl::GetSuit(Job) (8 B)
struct Job { char _pad[0x68]; unsigned m_suit; };
struct CareersImpl { unsigned GetSuit(Job*); };
unsigned CareersImpl::GetSuit(Job* job) { return job->m_suit; }
