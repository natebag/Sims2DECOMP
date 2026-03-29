// 0x803649E0 (12 bytes)
class EFontSize {
public:
    const char* GetTypeName() const;
};

extern char gEFontSizeData[];

const char* EFontSize::GetTypeName() const {
    return *(const char**)(gEFontSizeData + 0);
}
