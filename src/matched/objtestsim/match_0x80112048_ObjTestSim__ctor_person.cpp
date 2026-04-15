/* ObjTestSim::ObjTestSim(cXPerson *) - 0x80112048 (24 bytes) */

struct cXPerson;
struct cXObject;

class ObjTestSim {
public:
    cXPerson* m_person;       // +0
    cXObject* m_stackObject;  // +4
    char pad[16];
    int m_state;              // +24

    ObjTestSim(cXPerson* person);
};

ObjTestSim::ObjTestSim(cXPerson* person) {
    m_person = person;
    m_stackObject = 0;
    m_state = 0;
}
