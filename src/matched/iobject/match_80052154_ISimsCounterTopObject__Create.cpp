/* ISimsCounterTopObject::Create(cXObject *, EHouse *) at 0x80052154 (60B) */

struct cXObject;
struct EHouse;

struct ISimsObjectModel {
    void SetInitalObjectState(void);
};

struct ISimsCounterTopObject : ISimsObjectModel {
    char pad_04[0x324];
    cXObject *m_xobj;
    char pad_32C[0x9C];
    EHouse *m_house;

    void SetObjOrient(void);
    void Create(cXObject *obj, EHouse *house);
};

void ISimsCounterTopObject::Create(cXObject *obj, EHouse *house) {
    m_xobj = obj;
    m_house = house;
    SetObjOrient();
    SetInitalObjectState();
}
