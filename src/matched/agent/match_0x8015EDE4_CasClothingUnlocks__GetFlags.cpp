// 0x8015EDE4 CasClothingUnlocks::GetFlags (104B)
typedef unsigned int uint;

struct CasClothingUnlocks {
    unsigned char m_bodyPartUnlocks[2][32][40];
    unsigned char m_tattooUnlocks[8][8][30];
};

extern int CasClothingUnlocks__CheckBodyIndex(void *self, uint index);

int CasClothingUnlocks__GetFlags(void *self, bool layer, uint bodyPart, uint idx) {
    if (CasClothingUnlocks__CheckBodyIndex(self, idx))
        return ((CasClothingUnlocks*)self)->m_bodyPartUnlocks[layer][bodyPart][idx];
    return 0;
}
