// 0x8013476C (12 bytes)
// ReconObject::GetType(void)
// lis r3, 0x5263; ori r3, r3, 0x6F6E; blr
// Returns FourCC 'Rcon' (0x52636F6E)
class ReconObject {
public:
    unsigned int GetType();
};

unsigned int ReconObject::GetType() {
    return 0x52636F6E; // 'Rcon'
}
