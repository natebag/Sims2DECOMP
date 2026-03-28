#ifndef APTVALUE_H
#define APTVALUE_H

#include "types.h"

// AptValue - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1F28 (7976 bytes)
// 13 known fields (1 named), 198 methods

class AptValue {
public:
    // Static members (from map file)
    // static ??? MAX_REFCOUNT;
    // static ??? MAX_GCROOT;

    // Constructors / Destructors
    AptValue(AptVirtualFunctionTable_Indices)  // 0x80701134
    AptValue(AptVirtualFunctionTable_Indices, AptValue::CIH_ONLY)  // 0x80701234
    ~AptValue(void);  // 0x807012F8

    // Methods
    void getVtblIndex(void);  // 0x80701450 (128B)
    void setGCRoot(unsigned int);  // 0x80701730 (140B)
    void toString(char *);  // 0x80704140 (132B)
    void isCIH(bool);  // 0x807036B0 (212B)
    void c_cih(bool);  // 0x80701E98 (144B)
    void isLookup(void);  // 0x80702C70 (172B)
    void c_lookup(void);  // 0x80701A2C (136B)
    void isRegister(void);  // 0x80702F38 (172B)
    void c_register(void);  // 0x80701B3C (136B)
    void isInteger(void);  // 0x80702E8C (172B)
    void isFloat(void);  // 0x80702FE4 (172B)
    void isString(void);  // 0x80702D1C (196B)
    void toString(EAStringC &);  // 0x807041C4 (1880B)
    void isUndefined(void);  // 0x80702B94 (220B)
    void isNone(void);  // 0x80702AB0 (228B)
    void c_string(void);  // 0x80701C4C (180B)
    void findChild(EAStringC *, AptValue *);  // 0x80706BFC (2996B)
    void isScriptFunction(void);  // 0x8070313C (192B)
    void isNativeFunction(void);  // 0x80703090 (172B)
    void isObject(void);  // 0x80703784 (172B)
    void toFloat(void);  // 0x80703D48 (428B)
    void toInteger(void);  // 0x80703B8C (444B)
    void isBoolean(void);  // 0x80702DE0 (172B)
    void c_boolean(void);  // 0x80701D00 (136B)
    void c_nativefunction(void);  // 0x80701E10 (136B)
    void c_scriptfunction(void);  // 0x80701D88 (136B)
    bool CanCreateScriptObject(void);  // 0x807079B4 (204B)
    void getRefCount(void);  // 0x80701420 (48B)
    void c_integer(void);  // 0x80701AB4 (136B)
    void toBool(void);  // 0x80703EF4 (588B)
    void isArray(void);  // 0x80703354 (172B)
    void c_array(void);  // 0x80701F28 (136B)
    void getIsDefined(void);  // 0x80701534 (52B)
    void isExtern(void);  // 0x807031FC (172B)
    void isPrototype(void);  // 0x80703830 (172B)
    void c_prototype(void);  // 0x80702258 (136B)
    void c_object(void);  // 0x807021D0 (136B)
    void isMCInParentChain(void);  // 0x807077B0 (516B)
    void AddRef(char *, char *, int);  // 0x80707A80 (280B)
    void Release(char *, char *, int);  // 0x80707B98 (644B)
    void ForceDelete(void);  // 0x80707F20 (196B)
    void objectMemberSet(AptValue *, EAStringC *, AptValue *);  // 0x807080B4 (52B)
    void DeleteThis(void);  // 0x80708160 (108B)
    void PreDestroy(void);  // 0x807081CC (32B)
    /* ? */ GetNativeHashVirtual(void);  // 0x80707FE4 (40B)
    void ContainsNativeHashVirtual(void);  // 0x8070800C (40B)
    void getHasClass(void);  // 0x80708034 (40B)
    void setHasClass(int);  // 0x8070805C (40B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x80708084 (48B)
    void DestroyGCPointers(void);  // 0x807081EC (56B)
    void isTextFormat(void);  // 0x80703988 (172B)
    void c_textformat(void);  // 0x80702368 (136B)
    void c_float(void);  // 0x80701BC4 (136B)
    void setIsDefined(bool);  // 0x807016A0 (72B)
    void urlEncodeCustomRender(void);  // 0x80706974 (648B)
    void SetAllowDelayedDeletion(bool);  // 0x807080E8 (68B)
    void c_date(void);  // 0x807022E0 (136B)
    void getGCMark(void);  // 0x807014D0 (52B)
    void setGCMark(bool);  // 0x807016E8 (72B)
    void getGCRoot(void);  // 0x80701504 (48B)
    void SetDestroyedGC(void);  // 0x80701914 (44B)
    /* ? */ GetUniqueID(void);  // 0x80708224 (44B)
    void setVtblIndex(AptVirtualFunctionTable_Indices);  // 0x807015CC (212B)
    void isKey(void);  // 0x807034AC (172B)
    void c_loadvars(void);  // 0x80702610 (136B)
    void urlEncode(void);  // 0x80706774 (512B)
    void isSound(void);  // 0x80703400 (172B)
    void c_sound(void);  // 0x80701FB0 (136B)
    void SetReleaseAtEnd(void);  // 0x807019A0 (44B)
    void setRefCount(unsigned int);  // 0x80701568 (100B)
    void ClearDestroyedGC(void);  // 0x80701940 (44B)
    void ClearReleaseAtEnd(void);  // 0x807019CC (44B)
    void SetMaxRefCountHit(bool);  // 0x807013D8 (72B)
    bool IsDestroyedGC(void);  // 0x8070196C (52B)
    /* ? */ GetMaxRefCountHit(void);  // 0x807013A4 (52B)
    void incGCRoot(void);  // 0x807017BC (172B)
    void decGCRoot(void);  // 0x80701868 (172B)
    bool IsReleaseAtEnd(void);  // 0x807019F8 (52B)
    void c_key(void);  // 0x80702038 (136B)
    void c_math(void);  // 0x807020C0 (136B)
    void isMath(void);  // 0x80703558 (172B)
    void c_scriptcolour(void);  // 0x80702148 (136B)
    void isScriptColour(void);  // 0x80703604 (172B)
    void isDate(void);  // 0x807038DC (172B)
    void c_movieClip(void);  // 0x807023F0 (136B)
    void isMovieClip(void);  // 0x80703A34 (172B)
    void c_xmlnode(void);  // 0x80702478 (136B)
    void isXmlNode(void);  // 0x80702720 (228B)
    void c_xml(void);  // 0x80702500 (136B)
    void isXml(void);  // 0x80702804 (228B)
    void c_xmlattributes(void);  // 0x80702588 (136B)
    void isXmlAttributes(void);  // 0x807028E8 (228B)
    void isLoadVars(void);  // 0x807029CC (228B)
    void c_stage(void);  // 0x80702698 (136B)
    void isStage(void);  // 0x80703AE0 (172B)
    void isFrameStack(void);  // 0x807032A8 (172B)
    /* ? */ GetAllowDelayedDeletion(void);  // 0x8070812C (52B)
    void c_global(void);  // 0x80708A48 (136B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRef, AptValue, CanCreateScriptObject, ...)
    u8 m_field_001;  // 0x001 [R] (toBool, toInteger)
    u16 m_field_002;  // 0x002 [R] (findChild, toBool, toInteger, ...)
    u32 m_field_004;  // 0x004 [R/W] (AptValue, findChild)
    u8 m_field_008;  // 0x008 [R/W] (AptValue, ForceDelete, Release, ...)
    u8 _pad_009[3];  // 0x009
    f32 m_field_00C;  // 0x00C [R] (isMCInParentChain, toBool, toFloat, ...)
    u8 _pad_010[0x10];  // 0x010
    u32 m_field_020;  // 0x020 [R] (findChild)
    u32 m_field_024;  // 0x024 [R] (toBool, toFloat, toInteger, ...)
    u8 _pad_028[0x20];  // 0x028
    u32 m_field_048;  // 0x048 [R] (findChild)
    u8 _pad_04C[0x84];  // 0x04C
    u32 m_field_0D0;  // 0x0D0 [R] (toString)
    u8 _pad_0D4[0x1CC];  // 0x0D4
    u32 m_field_2A0;  // 0x2A0 [R] (toString)
    u8 _pad_2A4[0x1C7C];  // 0x2A4
    f32 m_field_1F20;  // 0x1F20 [R] (toFloat)
    f32 m_field_1F24;  // 0x1F24 [R] (toFloat)
};

#endif // APTVALUE_H
