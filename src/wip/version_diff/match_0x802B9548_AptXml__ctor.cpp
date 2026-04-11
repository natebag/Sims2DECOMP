/* AptXml::AptXml(IAptXmlNode *) at 0x802B9548 (68B) */

struct IAptXmlNode;

extern void* AptXml_vtable;
extern void AptXml_base_ctor(void*, int, IAptXmlNode*);

struct AptXml {
    char pad[8];      // 0x00-0x07
    void* vtable;     // 0x08
    
    AptXml(IAptXmlNode* node);
};

AptXml::AptXml(IAptXmlNode* node) {
    AptXml_base_ctor(this, 33, node);
    vtable = &AptXml_vtable;
}
