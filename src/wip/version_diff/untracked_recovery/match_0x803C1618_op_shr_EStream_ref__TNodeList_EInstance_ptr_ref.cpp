class EStream {
public:
    char pad[0x18];
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void Filler3() = 0;
    virtual void Filler4() = 0;
    virtual void Filler5() = 0;
    virtual void Read(void* data, int size) = 0;
    virtual void Write(void* data, int size) = 0;
};

template<class T>
class TNodeList {
public:
    void RemoveAll();
    void AddTail(T item);
};

class EInstance;
EStream& operator>>(EStream& s, EInstance*& ptr);

EStream& operator>>(EStream& s, TNodeList<EInstance*>& list) {
    list.RemoveAll();
    int count;
    s.Read(&count, 4);
    int i = count;
    goto test;
body:
    {
        EInstance* ptr;
        s >> ptr;
        list.AddTail(ptr);
    }
test:
    if (--i != -1) goto body;
    return s;
}
