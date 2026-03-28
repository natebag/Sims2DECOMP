struct IAptXmlNode;

extern void AptXmlNode_ctor(void *, int, IAptXmlNode *);

extern int AptXml_vtable[];

struct AptXml {
    char pad[0x0C];
    AptXml(IAptXmlNode *node);
};

AptXml::AptXml(IAptXmlNode *node)
{
    AptXmlNode_ctor(this, 0x21, node);
    *(int*)((char*)this + 8) = (int)AptXml_vtable;
}
