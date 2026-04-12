// 0x802B9548 AptXml::AptXml(IAptXmlNode*) (68b)

struct IAptXmlNode;

extern char AptXml_vtable[];
extern void AptXml_base_ctor(void*, int, IAptXmlNode*);

struct AptXml {
    char pad[8];      // 0x00-0x07
    void* vtable;     // 0x08
    
    AptXml(IAptXmlNode* node);
};

AptXml::AptXml(IAptXmlNode* node) {
    AptXml_base_ctor(this, 33, node);
    *(int**)((char*)this + 8) = (int*)AptXml_vtable;
}
