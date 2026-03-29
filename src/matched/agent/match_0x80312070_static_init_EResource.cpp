struct ETypeInfo;
struct EStorable;
typedef EStorable* (*NewFunc)(void);
typedef void (*ConstructFunc)(void*);
typedef void (*DestructFunc)(void*);
extern ETypeInfo gTypeInfo_EResource;
extern ETypeInfo gTypeInfo_EStorable;
extern char gpResName_empty[];
extern ETypeInfo* gpRegistered_EResource;

extern ETypeInfo* ETypeInfo__Register(ETypeInfo*, NewFunc, ConstructFunc, DestructFunc, unsigned short, char*, ETypeInfo*);

struct EResource {
    static EStorable* New();
    static void Construct(void*);
    static void Destruct(void*);
};

void __static_initialization_and_destruction_0_EResource(int initialize, int priority) {
    if (priority != 0xFFFF) return;
    if (initialize != 0) {
        gpRegistered_EResource = ETypeInfo__Register(&gTypeInfo_EResource, (NewFunc)EResource::New, (ConstructFunc)EResource::Construct, (DestructFunc)EResource::Destruct, 0, gpResName_empty, &gTypeInfo_EStorable);
    }
}
