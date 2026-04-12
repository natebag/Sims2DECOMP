// 0x80364A10 (12 bytes)
class EFontSize {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gEFontSizeData[];

unsigned short EFontSize::GetReadVersion() const {
    return gEFontSizeData[1];
}
