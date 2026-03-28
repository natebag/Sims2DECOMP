// 0x80130580 (12 bytes)
// cXPortalImpl::ReconType(void)
// lis r3, 0x444F; ori r3, r3, 0x4F52; blr
// Returns FourCC 'DOOR' (0x444F4F52)
class cXPortalImpl {
public:
    unsigned int ReconType();
};

unsigned int cXPortalImpl::ReconType() {
    return 0x444F4F52; // 'DOOR'
}
