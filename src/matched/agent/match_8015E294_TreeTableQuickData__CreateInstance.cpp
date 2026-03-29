/* TreeTableQuickData::CreateInstance(void) - 0x8015E294 - 40 bytes */
/* new(0x24) + TreeTableQuickData constructor */

class TreeTableQuickData {
public:
    char _data[0x24];
    TreeTableQuickData();
    static TreeTableQuickData* CreateInstance();
};

void* operator new(unsigned int size);

TreeTableQuickData* TreeTableQuickData::CreateInstance() {
    return new TreeTableQuickData();
}