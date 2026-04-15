/* ObjTestSim::ObjTestSim(cXPerson *, cXObject *) - 0x80112060 (68 bytes) */

struct cXPerson;
struct cXObject;

class ObjTestSim {
public:
    cXPerson* m_person;       // +0
    cXObject* m_stackObject;  // +4
    char pad[16];
    int m_state;              // +24

    ObjTestSim(cXPerson* person, cXObject* obj);
    void SetStackObject(cXObject* obj);
};

ObjTestSim::ObjTestSim(cXPerson* person, cXObject* obj) {
    m_person = person;
    m_stackObject = 0;
    m_state = 0;
    SetStackObject(obj);
}
