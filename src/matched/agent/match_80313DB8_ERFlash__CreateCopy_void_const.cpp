class EStorable {
public:
    EStorable* CreateCopy() const;
};

class ERFlash : public EStorable {
public:
    ERFlash* CreateCopy() const;
};

ERFlash* ERFlash::CreateCopy() const {
    return (ERFlash*)EStorable::CreateCopy();
}
