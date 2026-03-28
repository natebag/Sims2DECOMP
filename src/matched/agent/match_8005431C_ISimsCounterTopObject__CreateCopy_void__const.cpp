class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class ISimsCounterTopObject : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* ISimsCounterTopObject::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
