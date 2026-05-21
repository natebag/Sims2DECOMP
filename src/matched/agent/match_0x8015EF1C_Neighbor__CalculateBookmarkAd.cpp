// 0x8015EF1C (104B) Neighbor::CalculateBookmarkAd
typedef unsigned int uint;
typedef unsigned char uchar;

int CasClothingUnlocks__CheckTextureIndex(void *self, uint idx);

struct Neighbor {
    int CalculateBookmarkAd(int a, int b, uint idx);
};

int Neighbor::CalculateBookmarkAd(int a, int b, uint idx) {
    if (CasClothingUnlocks__CheckTextureIndex(this, idx)) {
        int p = a * 240 + (int)(char*)this;
        return ((*(uchar*)(b * 30 + p + (int)idx + 2560)) >> 1) & 1;
    }
    return 0;
}
