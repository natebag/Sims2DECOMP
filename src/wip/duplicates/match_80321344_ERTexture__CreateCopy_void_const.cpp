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
