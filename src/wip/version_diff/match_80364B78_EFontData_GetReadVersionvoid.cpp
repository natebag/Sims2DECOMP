// 0x80364B78 (12 bytes)
class EFontData {
public:
    short GetReadVersion() const;
};

extern char gEFontDataData[];

short EFontData::GetReadVersion() const {
    return *(short*)(gEFontDataData + 0);
}
