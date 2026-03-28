// 0x8012503C (12 bytes)
// cXPersonImpl::ReconType(void)
// lis r3, 0x5045; ori r3, r3, 0x5253; blr
// Returns FourCC 'PERS' (0x50455253)
class cXPerson;

class cXPersonImpl {
public:
    unsigned int ReconType();
};

unsigned int cXPersonImpl::ReconType() {
    return 0x50455253; // 'PERS'
}
