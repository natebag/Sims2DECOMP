// 0x80053D7C ISimsObjectModel::CreateCopy (32B)

class EStorable {
public:
    virtual EStorable* CreateCopy(void) const;
};

class ISimsObjectModel : public EStorable {
public:
    EStorable* CreateCopy(void) const;
};

EStorable* ISimsObjectModel::CreateCopy(void) const {
    return EStorable::CreateCopy();
}
