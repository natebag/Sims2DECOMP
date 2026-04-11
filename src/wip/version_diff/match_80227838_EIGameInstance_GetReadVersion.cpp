/* EIGameInstance::GetReadVersion(void) - 0x80227838 (12 bytes) */
// TU: e_igameinstance

extern unsigned int EIGameInstance_readVersion;

struct EIGameInstance {
    static unsigned int GetReadVersion();
};

unsigned int EIGameInstance::GetReadVersion() {
    return EIGameInstance_readVersion;
}
