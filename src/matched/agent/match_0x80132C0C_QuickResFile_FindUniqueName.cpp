class StringBuffer {
public:
    void erase(void);
};

class QuickResFile {
public:
    void FindUniqueName(int, StringBuffer &);
};

void QuickResFile::FindUniqueName(int, StringBuffer &name) {
    name.erase();
}
