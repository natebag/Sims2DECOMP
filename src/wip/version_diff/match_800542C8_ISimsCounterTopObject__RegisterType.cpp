/* ISimsCounterTopObject::RegisterType(unsigned short) at 0x800542C8 (84B) */

struct ETypeInfo;
struct EStorable;

void ETypeInfo_Register(ETypeInfo *info, EStorable *(*newFn)(void), void (*delFn)(void *), void (*dtorFn)(void *), unsigned short typeId, char *name, ETypeInfo *parent);

extern ETypeInfo ISimsCounterTopObject_TypeInfo;
extern "C" EStorable *ISimsCounterTopObject_NewFunc(void);
extern "C" void ISimsCounterTopObject_DeleteFunc(void *);
extern "C" void ISimsCounterTopObject_DtorFunc(void *);
extern char ISimsCounterTopObject_TypeName[];
extern ETypeInfo ISimsCounterTopObject_ParentTypeInfo;

void ISimsCounterTopObject__RegisterType(unsigned short typeId) {
    ETypeInfo_Register(
        &ISimsCounterTopObject_TypeInfo,
        ISimsCounterTopObject_NewFunc,
        ISimsCounterTopObject_DeleteFunc,
        ISimsCounterTopObject_DtorFunc,
        typeId,
        ISimsCounterTopObject_TypeName,
        &ISimsCounterTopObject_ParentTypeInfo
    );
}
