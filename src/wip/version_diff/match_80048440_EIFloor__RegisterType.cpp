/* EIFloor::RegisterType(unsigned short) at 0x80048440 (84B) */

struct ETypeInfo;
struct EStorable;

void ETypeInfo_Register(ETypeInfo *info, EStorable *(*newFn)(void), void (*delFn)(void *), void (*dtorFn)(void *), unsigned short typeId, char *name, ETypeInfo *parent);

extern ETypeInfo EIFloor_TypeInfo;
extern "C" EStorable *EIFloor_NewFunc(void);
extern "C" void EIFloor_DeleteFunc(void *);
extern "C" void EIFloor_DtorFunc(void *);
extern char EIFloor_TypeName[];
extern ETypeInfo EIFloor_ParentTypeInfo;

void EIFloor__RegisterType(unsigned short typeId) {
    ETypeInfo_Register(
        &EIFloor_TypeInfo,
        EIFloor_NewFunc,
        EIFloor_DeleteFunc,
        EIFloor_DtorFunc,
        typeId,
        EIFloor_TypeName,
        &EIFloor_ParentTypeInfo
    );
}
