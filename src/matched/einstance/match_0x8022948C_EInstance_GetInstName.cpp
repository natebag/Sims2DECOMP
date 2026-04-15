// 0x8022948C EInstance::GetInstName(EInstance::InstType&) (20B)
// Zero arg, return static string pointer

extern char g_einstanceDefaultName[16];  // non-SDA string at HA=-32704, LO=-6332

struct EInstance {
    struct InstType;
    char* GetInstName(InstType& t);
};

char* EInstance::GetInstName(EInstance::InstType& t) {
    *(int*)&t = 0;
    return g_einstanceDefaultName;
}
