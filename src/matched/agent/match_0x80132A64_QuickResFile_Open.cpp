class StringBuffer;

class ObjectFolder {
public:
    virtual ~ObjectFolder();
    virtual void* _dyncastimpl(int);
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void CreatingResFile(void *);
};

class Globs {
public:
    static ObjectFolder* pObjectFolder;
};

class QuickResFile {
public:
    int Open(StringBuffer &);
};

int QuickResFile::Open(StringBuffer &) {
    Globs::pObjectFolder->CreatingResFile(this);
    return 0;
}
