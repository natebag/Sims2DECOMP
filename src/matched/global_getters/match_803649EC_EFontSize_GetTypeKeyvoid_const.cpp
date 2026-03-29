// 0x803649EC (12 bytes)
class EFontSize {
public:
    const char* GetTypeKey() const;
};

extern char gEFontSizeData[];

const char* EFontSize::GetTypeKey() const {
    return *(const char**)(gEFontSizeData + 0);
}
