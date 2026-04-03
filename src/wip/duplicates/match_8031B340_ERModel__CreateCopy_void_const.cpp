class EStorable {
public:
    EStorable* CreateCopy() const;
};

class ERModel : public EStorable {
public:
    ERModel* CreateCopy() const;
};

ERModel* ERModel::CreateCopy() const {
    return (ERModel*)EStorable::CreateCopy();
}
