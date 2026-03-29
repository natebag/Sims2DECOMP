/* ISimsCounterTopObject::GetReadVersion(void) - 0x800542BC (12 bytes) */
// TU: iobject

extern unsigned int ISimsCounterTopObject_readVersion;

struct ISimsCounterTopObject {
    static unsigned int GetReadVersion();
};

unsigned int ISimsCounterTopObject::GetReadVersion() {
    return ISimsCounterTopObject_readVersion;
}
