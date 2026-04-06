// 0x8015F078 CasClothingUnlocks::ClearUnlocks (92b)

struct CasClothingUnlocks;

void memset(void* dst, int val, int size);
void CasClothingUnlocks_Clear(CasClothingUnlocks*);

struct CasClothingUnlocks {
    char field_0A00[2560];
    char field_1400[480];

    void ClearUnlocks();
};

void CasClothingUnlocks::ClearUnlocks() {
    memset(field_0A00, 2, 2560);
    memset(field_1400, 2, 480);
    CasClothingUnlocks_Clear(this);
}
