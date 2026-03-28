/* cXObjectImpl::GetType(void) - 12 bytes */

struct ObjDef {
    char pad[0x12];
    short m_type;
};

class cXObjectImpl {
public:
    char pad[0x88];
    ObjDef* m_def;

    short GetType(void);
};

short cXObjectImpl::GetType(void) {
    return m_def->m_type;
}
