/* ERTexture::CreateCopy(void) at 0x80321344 (32B) */
// 0x80321344 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERTexture : public EStorable {
public:
    ERTexture* CreateCopy() const;
};
ERTexture* ERTexture::CreateCopy() const {
    return (ERTexture*)EStorable::CreateCopy();
}
