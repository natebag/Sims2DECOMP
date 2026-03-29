/* ISimsCounterTopObject::GetTypeKey(void) const - 0x80054298 (12 bytes) */
// TU: iobject

extern unsigned int ISimsCounterTopObject_typeInfo_key;

struct ISimsCounterTopObject {
    unsigned int GetTypeKey() const;
};

unsigned int ISimsCounterTopObject::GetTypeKey() const {
    return ISimsCounterTopObject_typeInfo_key;
}
