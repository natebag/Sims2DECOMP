void operator delete(void*);

class EAHeap {
public:
    void Free(void*);
};

EAHeap* MainHeap(void);

class WidgetScreenFormat {
public:
    char _pad[0x10];
    void* m_data;

    ~WidgetScreenFormat(void);
};

WidgetScreenFormat::~WidgetScreenFormat(void) {
    if (m_data != 0) {
        MainHeap()->Free(m_data);
    }
}
