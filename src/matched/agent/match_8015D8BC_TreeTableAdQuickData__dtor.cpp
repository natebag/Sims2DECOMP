/* TreeTableAdQuickData::~TreeTableAdQuickData(void) - 0x8015D8BC - 60 bytes */
/* Sets vtable, clears m_data, conditionally deletes */

extern int __vt_20TreeTableAdQuickData[];
extern void __builtin_delete(void*);

class TreeTableAdQuickData {
public:
    int* m_vtable;
    void* m_data;
    int m_refCount;

    ~TreeTableAdQuickData();
};

TreeTableAdQuickData::~TreeTableAdQuickData() {
    m_vtable = __vt_20TreeTableAdQuickData;
    m_data = 0;
}