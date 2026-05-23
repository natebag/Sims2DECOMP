// FLAGS: -fno-schedule-insns
// 0x80071460 SimModel::FlushLoadingModels(void) (100 bytes)
// beq skips only the CollapseDelRef call; flag clear + resId clear always happen

class EResourceManager {
    char m_pad[16];
};

extern EResourceManager g_modelman;

class EResLoaderMsgQueue {
public:
    static void CollapseDelRef(EResourceManager* mgr, unsigned int id);
};

class SimModel {
public:
    int m_partFlags[26];
    void* m_models[26];
    unsigned int m_resourceIDs[26];

    void FlushLoadingModels();
};

void SimModel::FlushLoadingModels() {
    int* p = (int*)this;
    int* pEnd = p + 25;
    do {
        unsigned int resId = (unsigned int)p[52];
        if (resId != 0) {
            EResLoaderMsgQueue::CollapseDelRef(&g_modelman, resId);
        }
        p[52] = 0;
        *p &= ~0x20;
        p++;
    } while (p <= pEnd);
}
