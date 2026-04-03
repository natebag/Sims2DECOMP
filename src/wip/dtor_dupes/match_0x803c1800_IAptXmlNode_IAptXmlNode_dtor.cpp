extern int VT_IAptXmlNode_IAptXmlNode[];
void del_IAptXmlNode_IAptXmlNode(void *);
void dtor_IAptXmlNode_IAptXmlNode(char *self, int __in_chrg) {
    *(int **)self = VT_IAptXmlNode_IAptXmlNode;
    if (__in_chrg & 1) {
        del_IAptXmlNode_IAptXmlNode(self);
    }
}
