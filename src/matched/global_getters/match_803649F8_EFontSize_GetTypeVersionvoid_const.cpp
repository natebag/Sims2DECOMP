// 0x803649F8 (12 bytes)
class EFontSize {
public:
    short GetTypeVersion() const;
};

extern char gEFontSizeData[];

short EFontSize::GetTypeVersion() const {
    return *(short*)(gEFontSizeData + 0);
}
