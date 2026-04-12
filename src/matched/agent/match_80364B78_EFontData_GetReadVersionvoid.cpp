// 0x80364B78 (12 bytes)
class EFontData {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gEFontDataData[];

unsigned short EFontData::GetReadVersion() const {
    return gEFontDataData[1];
}
