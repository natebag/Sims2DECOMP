class EStorable {
public:
    EStorable* CreateCopy() const;
};

class ERFont : public EStorable {
public:
    ERFont* CreateCopy() const;
};

ERFont* ERFont::CreateCopy() const {
    return (ERFont*)EStorable::CreateCopy();
}
