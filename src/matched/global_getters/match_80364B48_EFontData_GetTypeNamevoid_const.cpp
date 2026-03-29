// 0x80364B48 (12 bytes)
class EFontData {
public:
    const char* GetTypeName() const;
};

extern char gEFontDataData[];

const char* EFontData::GetTypeName() const {
    return *(const char**)(gEFontDataData + 0);
}
