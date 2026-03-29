class iResFile {
public:
    int m_next;
    int m_prev;
    int m_fileData;
    iResFile(void);
    virtual ~iResFile(void);
    virtual void* _dyncastimpl(int);
    virtual int Create(int);
    virtual int Delete(int);
    virtual int Open(int);
    virtual int CloseForReopen(void);
    virtual int Reopen(void);
    virtual int Close(void);
    virtual void Update(void);
    virtual int Writable(void);
    virtual void GetFileName(int);
    virtual int ValidFile(void);
    virtual int CountTypes(void);
    virtual int GetIndType(short);
    virtual int Count(int);
    virtual int GetByID(int, short, void*);
    virtual int GetByName(int, int, void*);
    virtual int GetByIndex(int, short, void*);
    virtual int GetByIDAndLanguage(int, short, char, void*);
    virtual void GetName(int, int);
    virtual int GetResType(int);
    virtual void GetID2(int, short*);
    virtual void GetIndex2(int, short*);
    virtual int GetLanguage(int);
    virtual void FindUniqueName(int, int);
    virtual int FindUniqueID(int);
    virtual void Detach(int);
    virtual void Load(int);
    virtual int IsLittleEndian(int);
    virtual void SetID(int, short);
    virtual void Add(int, int, short, int, int);
    virtual void AddWithLanguage(int, int, short, int, char, int);
    virtual void Write(int);
    virtual void Remove(int);
    virtual void SetInfo(int, short, int, char);
    virtual void GetString(int, short, short);
};

class QuickResFile : public iResFile {
public:
    QuickResFile(void);
};

QuickResFile::QuickResFile(void) : iResFile() {
}
