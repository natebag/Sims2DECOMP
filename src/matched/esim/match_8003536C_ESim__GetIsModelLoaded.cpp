// 0x8003536C (8 bytes) — lwz r3, 0x638(r3); blr

class ESim {
public:
    char _pad[0x638];
    int m_isModelLoaded;

    int GetIsModelLoaded();
};

int ESim::GetIsModelLoaded() {
    return m_isModelLoaded;
}
