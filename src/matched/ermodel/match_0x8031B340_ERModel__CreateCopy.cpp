struct EStorable {
    EStorable* CreateCopy() const;
};

struct ERModel : public EStorable {
    ERModel* CreateCopy() const;
};

ERModel* ERModel::CreateCopy() const
{
    return (ERModel*)EStorable::CreateCopy();
}
