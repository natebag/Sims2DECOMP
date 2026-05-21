// 0x8032CDC0 ENgcAudioSampleManager::CanCache(EResource *) (36B)

struct EResource {
    char pad[28];
    int m_type;
};

extern int ENgcAram__m_zeropage;

class ENgcAudioSampleManager {
public:
    bool CanCache(EResource* resource) const;
};

bool ENgcAudioSampleManager::CanCache(EResource* resource) const {
    if (resource && resource->m_type == ENgcAram__m_zeropage) return false;
    return true;
}
