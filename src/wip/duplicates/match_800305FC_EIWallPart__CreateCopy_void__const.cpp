class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class EIWallPart : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* EIWallPart::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
