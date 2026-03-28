#ifndef APT_XML_H
#define APT_XML_H

#include "types.h"
#include "ui/apt_value.h"

// Forward declarations
class IAptXmlNode;
class IAptXml;

// ============================================================================
// AptXmlNode - ActionScript XMLNode type
// Source: libaptz.a(AptXmlNode.cpp.obj)
// Layout:
//   0x24: IAptXmlNode* m_nativeNode (pointer to native XML node impl)
// ============================================================================
class AptXmlNode : public AptValueGC {
public:
    // 0x24: IAptXmlNode* m_nativeNode

    void PreDestroy();
    ~AptXmlNode();

    AptValue* objectMemberLookup(AptValue* obj, EAStringC* name) const;
    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);

    static AptValue* sMethod_appendChild(AptValue* thisObj, int argc);
    static AptValue* sMethod_cloneNode(AptValue* thisObj, int argc);
    static AptValue* sMethod_insertBefore(AptValue* thisObj, int argc);
    static AptValue* sMethod_removeNode(AptValue* thisObj, int argc);

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// AptXmlAttributes - ActionScript XML attributes collection
// Source: libaptz.a(AptXmlAttributes.cpp.obj)
// Layout:
//   0x24: IAptXmlNode* m_ownerNode (pointer to owning node)
// ============================================================================
class AptXmlAttributes : public AptValueGC {
public:
    void PreDestroy();
    ~AptXmlAttributes();

    AptXmlAttributes(AptVirtualFunctionTable_Indices vft, IAptXmlNode* node);

    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

#endif // APT_XML_H
