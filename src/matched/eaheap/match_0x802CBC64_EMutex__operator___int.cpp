// 0x802CBC64 EMutex::operator++(int) (72 B)
// FLAGS:
//
// EMutex overloads postfix operator++ as "acquire": same body as the prefix
// form — virtually dispatch Lock(-1) (ESyncObject vtable slot 2) and return
// *this. The dummy int distinguishes the postfix signature and is unused.

struct ESyncObject {
    virtual ~ESyncObject();
    virtual void Lock(int timeout);
    virtual void Unlock();
};

struct EMutex : ESyncObject {
    EMutex& operator++(int);
};

EMutex& EMutex::operator++(int)
{
    Lock(-1);
    return *this;
}
