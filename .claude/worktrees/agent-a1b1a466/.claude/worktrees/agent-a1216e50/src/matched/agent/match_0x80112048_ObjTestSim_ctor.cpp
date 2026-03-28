/* ObjTestSim::ObjTestSim(cXPerson *) - 0x80112048 - 24 bytes */

class cXPerson;

class ObjTestSim {
public:
    cXPerson* m_person;
    int m_field4;
    char _pad[0x10];
    int m_field18;

    ObjTestSim(cXPerson *);
};

ObjTestSim::ObjTestSim(cXPerson *person) : m_person(person), m_field18(0), m_field4(0) {
}
