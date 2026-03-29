struct EStorable {
    EStorable* CreateCopy() const;
};

struct ERFont : public EStorable {
    ERFont* CreateCopy() const;
};

ERFont* ERFont::CreateCopy() const
{
    return (ERFont*)EStorable::CreateCopy();
}
