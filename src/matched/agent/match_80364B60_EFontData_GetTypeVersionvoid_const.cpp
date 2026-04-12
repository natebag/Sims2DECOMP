// 0x80364B60 (12 bytes)
class EFontData {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gEFontDataData[];

unsigned short EFontData::GetTypeVersion() const {
    return gEFontDataData[0];
}
