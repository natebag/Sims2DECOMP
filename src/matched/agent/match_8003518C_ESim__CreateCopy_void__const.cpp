class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class ESim : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* ESim::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
