// 0x80364A10 (12 bytes)
class EFontSize {
public:
    short GetReadVersion() const;
};

extern char gEFontSizeData[];

short EFontSize::GetReadVersion() const {
    return *(short*)(gEFontSizeData + 0);
}
