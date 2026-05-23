/* 0x80233B44 (88 bytes) - ERLevel::FixInstanceList(TNodeList<EInstance*>&) */
class EInstance {
public:
    virtual ~EInstance() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void Fix() = 0;
};

struct ListNode {
    EInstance* data;
    int m_4;
    ListNode* next;
};

template<class T>
struct TNodeList {
    ListNode* head;
};

class ERLevel {
public:
    void FixInstanceList(TNodeList<EInstance*>& list);
};

void ERLevel::FixInstanceList(TNodeList<EInstance*>& list) {
    ListNode* node = list.head;
    if (node == 0) return;
    do {
        node->data->Fix();
        node = node->next;
    } while (node != 0);
}
