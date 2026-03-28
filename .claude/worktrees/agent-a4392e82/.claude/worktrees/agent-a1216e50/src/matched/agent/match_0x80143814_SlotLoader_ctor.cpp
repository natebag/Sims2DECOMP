/* SlotLoader::SlotLoader(unsigned int) - 0x80143814 - 20 bytes */
/* mr r9, r3; li r0, 0; stw r4, 0(r9); sth r0, 4(r9); blr */

class SlotLoader {
public:
    unsigned int m_resourceId;
    unsigned short m_field4;

    SlotLoader(unsigned int id);
};

SlotLoader::SlotLoader(unsigned int id) {
    m_resourceId = id;
    m_field4 = 0;
}
