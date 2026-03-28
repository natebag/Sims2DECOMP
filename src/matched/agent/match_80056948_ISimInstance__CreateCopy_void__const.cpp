class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class ISimInstance : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* ISimInstance::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
