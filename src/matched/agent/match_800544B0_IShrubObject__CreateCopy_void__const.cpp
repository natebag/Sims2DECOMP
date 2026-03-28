class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class IShrubObject : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* IShrubObject::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
