struct EStorable {
    EStorable* CreateCopy() const;
};

struct EResource : public EStorable {
    EResource* CreateCopy() const;
};

EResource* EResource::CreateCopy() const
{
    return (EResource*)EStorable::CreateCopy();
}
