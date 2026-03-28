class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class EIFloor : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* EIFloor::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
