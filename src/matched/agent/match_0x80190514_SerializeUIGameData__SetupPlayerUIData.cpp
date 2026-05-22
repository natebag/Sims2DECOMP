// 0x80190514 SerializeUIGameData::SetupPlayerUIData() (96B)

extern char SerializeUIGameData__m_pLoadBuffers[16];

class SerializeUIGameData {
public:
    enum eUIGameData_Direction { kLoad = 2 };
    static void SerializeUIData(int player, void* buf, int dir, bool flag);
    static void SetupPlayerUIData();
};

void SerializeUIGameData::SetupPlayerUIData() {
    if (*(void**)SerializeUIGameData__m_pLoadBuffers != 0) {
        SerializeUIData(0, *(void**)SerializeUIGameData__m_pLoadBuffers, 2, false);
    }
    if (*(void**)SerializeUIGameData__m_pLoadBuffers != 0) {
        SerializeUIData(1, *(void**)SerializeUIGameData__m_pLoadBuffers, 2, false);
    }
}
