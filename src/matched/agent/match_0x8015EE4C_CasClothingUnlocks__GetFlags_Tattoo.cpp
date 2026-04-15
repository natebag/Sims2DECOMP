// 0x8015EE4C CasClothingUnlocks::GetFlags(bool, eTattooTextureTypeS2C, uint) const (100B)
typedef unsigned int uint;

struct CasClothingUnlocks {
    char pad[2560];
    unsigned char m_tattooUnlocks[2][8][30];
};

extern int CasClothingUnlocks__CheckTextureIndex(void *self, uint index);

int CasClothingUnlocks__GetFlags_Tattoo(void *self, bool layer, uint type, uint idx) {
    if (CasClothingUnlocks__CheckTextureIndex(self, idx))
        return ((CasClothingUnlocks*)self)->m_tattooUnlocks[layer][type][idx];
    return 0;
}
