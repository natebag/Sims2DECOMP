struct ETypeInfo;
struct EStorable;
typedef EStorable* (*NewFunc)(void);
typedef void (*ConstructFunc)(void*);
typedef void (*DestructFunc)(void*);

extern ETypeInfo gTypeInfo_ERFlash;
extern ETypeInfo gTypeInfo_ERFlash_parent;
extern char gpResName_ERFlash[];
extern ETypeInfo* gpRegistered_ERFlash;

extern ETypeInfo* ETypeInfo__Register(ETypeInfo*, NewFunc, ConstructFunc, DestructFunc, unsigned short, char*, ETypeInfo*);

struct ERFlash {
    static EStorable* New(void);
    static void Construct(void*);
    static void Destruct(void*);
};

void __static_initialization_and_destruction_0_ERFlash(int initialize, int priority) {
    if (priority != 0xFFFF) return;
    if (initialize != 0) {
        gpRegistered_ERFlash = ETypeInfo__Register(&gTypeInfo_ERFlash, (NewFunc)ERFlash::New, (ConstructFunc)ERFlash::Construct, (DestructFunc)ERFlash::Destruct, 0, gpResName_ERFlash, &gTypeInfo_ERFlash_parent);
    }
}
