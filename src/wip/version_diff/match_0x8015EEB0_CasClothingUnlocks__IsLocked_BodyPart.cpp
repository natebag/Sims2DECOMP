// 0x8015EEB0 CasClothingUnlocks::IsLocked(bool, eBodyPartS2C, uint) const (108B)
typedef unsigned int uint;

struct CasClothingUnlocks {
    unsigned char m_bodyPartUnlocks[2][32][40];
};

extern int CasClothingUnlocks__CheckBodyIndex(void *self, uint index);

int CasClothingUnlocks__IsLocked_BodyPart(void *self, bool layer, uint bodyPart, uint idx) {
    if (CasClothingUnlocks__CheckBodyIndex(self, idx)) {
        unsigned char byte = ((CasClothingUnlocks*)self)->m_bodyPartUnlocks[layer][bodyPart][idx];
        return -(int)(byte & 1) & 0x80000000;
    }
    return 0;
}
