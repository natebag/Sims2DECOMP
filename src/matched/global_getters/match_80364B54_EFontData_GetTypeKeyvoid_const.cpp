// 0x80364B54 (12 bytes)
class EFontData {
public:
    const char* GetTypeKey() const;
};

extern char gEFontDataData[];

const char* EFontData::GetTypeKey() const {
    return *(const char**)(gEFontDataData + 0);
}
