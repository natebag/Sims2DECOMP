// 0x80364B60 (12 bytes)
class EFontData {
public:
    short GetTypeVersion() const;
};

extern char gEFontDataData[];

short EFontData::GetTypeVersion() const {
    return *(short*)(gEFontDataData + 0);
}
