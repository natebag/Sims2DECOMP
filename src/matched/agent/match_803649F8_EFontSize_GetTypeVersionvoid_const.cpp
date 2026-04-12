// 0x803649F8 (12 bytes)
class EFontSize {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gEFontSizeData[];

unsigned short EFontSize::GetTypeVersion() const {
    return gEFontSizeData[0];
}
