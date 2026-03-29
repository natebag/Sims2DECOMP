/* ISimsCounterTopObject::GetTypeVersion(void) const - 0x800542A4 (12 bytes) */
// TU: iobject

extern unsigned int ISimsCounterTopObject_typeInfo_version;

struct ISimsCounterTopObject {
    unsigned int GetTypeVersion() const;
};

unsigned int ISimsCounterTopObject::GetTypeVersion() const {
    return ISimsCounterTopObject_typeInfo_version;
}
