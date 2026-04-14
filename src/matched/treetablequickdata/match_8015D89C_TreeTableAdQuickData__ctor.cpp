/* TreeTableAdQuickData::TreeTableAdQuickData(TreeTableAd *) - 0x8015D89C - 32 bytes */
/* Store vtable, parameter, and zero refcount */

extern int __vt_20TreeTableAdQuickData[];

struct TreeTableAd;

class TreeTableAdQuickData {
public:
    int* m_vtable;
    TreeTableAd* m_data;
    int m_refCount;

    TreeTableAdQuickData(TreeTableAd* data);
};

TreeTableAdQuickData::TreeTableAdQuickData(TreeTableAd* data) {
    m_vtable = __vt_20TreeTableAdQuickData;
    m_data = data;
    m_refCount = 0;
}