/* 0x800A6474 (64 bytes) - MemFile::SetFileName(StringBuffer &) */

class StringBuffer {
public:
    void erase(void);
    void append(StringBuffer &sb, int len);
};

class MemFile : public StringBuffer {
public:
    void SetFileName(StringBuffer &name);
};

void MemFile::SetFileName(StringBuffer &name)
{
    erase();
    append(name, -1);
}
