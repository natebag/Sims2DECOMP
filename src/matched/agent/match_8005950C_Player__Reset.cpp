typedef unsigned int size_t;

struct FlashPiMenu {
    char _pad[16];
    FlashPiMenu(int);
};

struct ESimsCam {
    void Init(void);
    ESimsCam(int);
};

struct EAHeap {
    void* MallocAligned(size_t size, size_t align, size_t a3, int a4);
};

EAHeap* MainHeap(void);
void* memset(void*, int, size_t);
inline void* operator new(size_t, void* p) { return p; }

class Player {
public:
    int m_field_000;
    int m_pad_004;
    FlashPiMenu* m_field_008;
    ESimsCam* m_field_00C;

    void Reset(int);
};

void Player::Reset(int arg) {
    int old_flash = (int)m_field_008;
    m_field_000 = arg;
    if (old_flash == 0) {
        FlashPiMenu* pm = new FlashPiMenu(m_field_000);
        m_field_008 = pm;
    }
    if ((int)m_field_00C == 0) {
        EAHeap* heap = MainHeap();
        void* buf = heap->MallocAligned(1392, 16, 0, 0);
        memset(buf, 0, 1392);
        ESimsCam* cam = new((ESimsCam*)buf) ESimsCam(m_field_000);
        m_field_00C = cam;
        if ((int)cam == 0) {
            return;
        }
    }
    m_field_00C->Init();
}
