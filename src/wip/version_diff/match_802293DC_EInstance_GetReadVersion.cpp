/* EInstance::GetReadVersion(void) - 0x802293DC (12 bytes) */
// TU: e_instance

extern unsigned int EInstance_readVersion;

struct EInstance {
    static unsigned int GetReadVersion();
};

unsigned int EInstance::GetReadVersion() {
    return EInstance_readVersion;
}
