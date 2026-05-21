// 0x8015EAB8 (104B) CasClothingUnlocks::~CasClothingUnlocks()

struct ClothEntry {
    char m_data;
    ~ClothEntry() {}
};
struct TattooEntry {
    char m_data;
    ~TattooEntry() {}
};

class CasClothingUnlocks {
public:
    ClothEntry m_data1[2560];
    TattooEntry m_data2[480];
    ~CasClothingUnlocks();
};

CasClothingUnlocks::~CasClothingUnlocks() {
}
