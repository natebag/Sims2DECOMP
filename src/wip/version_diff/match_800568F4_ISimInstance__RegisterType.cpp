/* ISimInstance::RegisterType(unsigned short) at 0x800568F4 (84B) */

struct ETypeInfo;
struct EStorable;

void ETypeInfo_Register(ETypeInfo *info, EStorable *(*newFn)(void), void (*delFn)(void *), void (*dtorFn)(void *), unsigned short typeId, char *name, ETypeInfo *parent);

extern ETypeInfo ISimInstance_TypeInfo;
extern "C" EStorable *ISimInstance_NewFunc(void);
extern "C" void ISimInstance_DeleteFunc(void *);
extern "C" void ISimInstance_DtorFunc(void *);
extern char ISimInstance_TypeName[];
extern ETypeInfo ISimInstance_ParentTypeInfo;

void ISimInstance__RegisterType(unsigned short typeId) {
    ETypeInfo_Register(
        &ISimInstance_TypeInfo,
        ISimInstance_NewFunc,
        ISimInstance_DeleteFunc,
        ISimInstance_DtorFunc,
        typeId,
        ISimInstance_TypeName,
        &ISimInstance_ParentTypeInfo
    );
}
