class SomeObj;

// External function at 0x80086988
extern "C" void sub_80086988(SomeObj*);

class InnerStruct {
    char pad[152];
public:
    SomeObj* m_obj;  // offset 152
};

class MUStatesDisplay {
    char pad[8];
    InnerStruct* m_inner;  // offset 8
public:
    void Shutdown();
};

void MUStatesDisplay::Shutdown() {
    sub_80086988(this->m_inner->m_obj);
}
