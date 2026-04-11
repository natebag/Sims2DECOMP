// 0x802E7EF4 (76 bytes)
/* EAnimController::Init(char *, eAnimatedObjectType, unsigned int) */

// Forward declarations for external functions
extern unsigned int EAnimController_HashName(char* name);  /* 0x80327534 */
extern void EAnimController_InitInternal(void* self, unsigned int hash, int type, unsigned int flags);  /* 0x802E7AC8 */

struct EAnimController_Init {
    void Init(char* name, int objectType, unsigned int flags);
};

void EAnimController_Init::Init(char* name, int objectType, unsigned int flags) {
    unsigned int hash = EAnimController_HashName(name);
    EAnimController_InitInternal(this, hash, objectType, flags);
}
