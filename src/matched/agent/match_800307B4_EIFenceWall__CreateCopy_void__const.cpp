class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class EIFenceWall : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* EIFenceWall::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
