/* AptValueGC_PoolManager::VerifyList(void) - 0x802B54EC (72B) */

struct AptValue;

class AptValueGC_PoolManager {
public:
    AptValue* GetFirstAptValue(void);
    AptValue* GetNextAptValue(AptValue* prev);
    void VerifyList(void);
};

void AptValueGC_PoolManager::VerifyList(void) {
    AptValue* v = GetFirstAptValue();
    while (v != 0) {
        v = GetNextAptValue(v);
    }
}
