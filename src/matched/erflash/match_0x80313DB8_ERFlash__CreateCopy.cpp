struct EStorable {
    EStorable* CreateCopy() const;
};

struct ERFlash : public EStorable {
    ERFlash* CreateCopy() const;
};

ERFlash* ERFlash::CreateCopy() const
{
    return (ERFlash*)EStorable::CreateCopy();
}
