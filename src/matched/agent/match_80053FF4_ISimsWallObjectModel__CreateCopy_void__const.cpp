class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class ISimsWallObjectModel : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* ISimsWallObjectModel::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
