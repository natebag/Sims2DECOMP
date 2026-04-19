/* EFontData::CreateCopy(void) at 0x80364BD8 (32B) */
// 0x80364BD8 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class EFontData : public EStorable {
public:
    EFontData* CreateCopy() const;
};
EFontData* EFontData::CreateCopy() const {
    return (EFontData*)EStorable::CreateCopy();
}
