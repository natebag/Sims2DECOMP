struct DoPtrVectorStreamHelper {
    char pad_00[0xD0];
    int m_streamVersion;

    int GetVersion();
    void InitStreamVersion();
};

void DoPtrVectorStreamHelper::InitStreamVersion() {
    m_streamVersion = GetVersion();
}
