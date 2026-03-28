/* cXObjectImpl::GetTemp(int) - 16 bytes */

class cXObjectImpl {
public:
    char pad[0x16];
    short m_temps[1];

    short GetTemp(int index);
};

short cXObjectImpl::GetTemp(int index) {
    return m_temps[index];
}
