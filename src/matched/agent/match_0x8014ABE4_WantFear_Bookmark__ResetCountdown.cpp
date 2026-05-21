// 0x8014ABE4 WantFear::Bookmark::ResetCountdown() (80B)

namespace WantFear {

class EventThing {
public:
    char pad[11];
    char type;
};

class Node {
public:
    EventThing* GetEvent() const;
};

class Bookmark {
public:
    int m_0;
    Node* m_4;
    short m_8;
    void ResetCountdown();
};

}

void WantFear::Bookmark::ResetCountdown() {
    WantFear::EventThing* e = m_4->GetEvent();
    if (e->type == 2) {
        m_8 = *(short*)((char*)m_4 + 8);
    } else {
        m_8 = 0;
    }
}
