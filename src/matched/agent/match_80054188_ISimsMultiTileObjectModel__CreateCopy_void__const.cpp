class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class ISimsMultiTileObjectModel : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* ISimsMultiTileObjectModel::CreateCopy(void) const
{
    return EStorable::CreateCopy();
}
