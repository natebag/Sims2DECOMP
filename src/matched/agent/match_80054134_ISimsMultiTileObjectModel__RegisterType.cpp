/* ISimsMultiTileObjectModel::RegisterType(unsigned short) at 0x80054134 (84B) */

struct ETypeInfo;
struct EStorable;

void ETypeInfo_Register(ETypeInfo *info, EStorable *(*newFn)(void), void (*delFn)(void *), void (*dtorFn)(void *), unsigned short typeId, char *name, ETypeInfo *parent);

extern ETypeInfo ISimsMultiTileObjectModel_TypeInfo;
extern "C" EStorable *ISimsMultiTileObjectModel_NewFunc(void);
extern "C" void ISimsMultiTileObjectModel_DeleteFunc(void *);
extern "C" void ISimsMultiTileObjectModel_DtorFunc(void *);
extern char ISimsMultiTileObjectModel_TypeName[];
extern ETypeInfo ISimsMultiTileObjectModel_ParentTypeInfo;

void ISimsMultiTileObjectModel__RegisterType(unsigned short typeId) {
    ETypeInfo_Register(
        &ISimsMultiTileObjectModel_TypeInfo,
        ISimsMultiTileObjectModel_NewFunc,
        ISimsMultiTileObjectModel_DeleteFunc,
        ISimsMultiTileObjectModel_DtorFunc,
        typeId,
        ISimsMultiTileObjectModel_TypeName,
        &ISimsMultiTileObjectModel_ParentTypeInfo
    );
}
