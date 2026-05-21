// 0x8016D41C CasSimPartsS2C::ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C) const (68B)

class CasSimPartsS2C {
public:
    int ConvertTattooTextureTypeToLocation(int type) const;
};

int CasSimPartsS2C::ConvertTattooTextureTypeToLocation(int type) const {
    switch (type) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        default: return 1;
    }
}
