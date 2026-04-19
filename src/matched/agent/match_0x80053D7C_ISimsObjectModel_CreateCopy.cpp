// 0x80053D7C (32B) ISimsObjectModel::CreateCopy(void) const
// Thunk to EStorable::CreateCopy(void) const

class EStorable {
public:
    static void CreateCopy(void);
};

class ISimsObjectModel {
public:
    void CreateCopy(void) const;
};

void ISimsObjectModel::CreateCopy(void) const {
    EStorable::CreateCopy();
}
