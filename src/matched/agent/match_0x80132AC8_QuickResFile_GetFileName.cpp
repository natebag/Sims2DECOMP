class StringBuffer {
public:
    void erase(void);
    void copy(char *);
};

class ERQuickdata {
public:
    void* findRow(void *, unsigned int *);
};

struct QDRow {
    int field_0;
    int field_4;
    char** m_strings;
};

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
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual ERQuickdata* GetObjectsDatabase(void);
};

class Globs {
public:
    static ObjectFolder* pObjectFolder;
};

class QuickResFile {
public:
    int m_next;
    int m_prev;
    void* m_fileData;
    void GetFileName(StringBuffer &);
};

void QuickResFile::GetFileName(StringBuffer &output) {
    output.erase();
    if (m_fileData == 0) return;

    ERQuickdata* db = Globs::pObjectFolder->GetObjectsDatabase();
    if (db == 0) return;

    unsigned int rowIdx;
    QDRow* row = (QDRow*)db->findRow(m_fileData, &rowIdx);

    char* name;
    if (row != 0 && row->m_strings != 0) {
        name = row->m_strings[rowIdx];
    } else {
        name = 0;
    }

    if (name != 0) {
        output.copy(name);
    }
}
