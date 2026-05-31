// 0x802CBC1C EMutex::operator++(void) (72 B)
// FLAGS:
//
// EMutex overloads prefix operator++ as "acquire": it virtually dispatches
// Lock(-1) (ESyncObject vtable slot 2, infinite timeout) and returns *this.
// Virtual call uses the GCC2 {adjustor,fnptr} vtable entry at vt+0x10/+0x14.

struct ESyncObject {
    virtual ~ESyncObject();
    virtual void Lock(int timeout);
    virtual void Unlock();
};

struct EMutex : ESyncObject {
    EMutex& operator++();
};

EMutex& EMutex::operator++()
{
    Lock(-1);
    return *this;
}
