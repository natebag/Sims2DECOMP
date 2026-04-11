// FLAGS: -msdata=eabi -G 8
#include "types.h"
// Commander TU — game command system

// SDA globals for linked list — small types for r13-relative addressing
extern void* g_CommanderHead;      // At -32076(r13)
extern int g_CommanderCount;       // At -32072(r13)

// VTable extern — generates lis/addi
extern int Commander_vtable[];

class Commander {
public:
    Commander* m_next;
    int m_field4;
    Commander* m_prev;
    int* m_vtable;
    
    Commander(void);
    ~Commander(void);
    virtual bool DoCommand(short, int);
    virtual short GetType(void);
    virtual Commander* GetNext(void);
};

// 0x800B4214 (60 bytes)
// Commander::Commander(void) — leaf constructor with linked list insertion
Commander::Commander(void) {
    // Get current head from SDA
    Commander* head = (Commander*)g_CommanderHead;
    
    // Store vtable
    this->m_vtable = Commander_vtable;
    
    // Initialize field4 to 0
    this->m_field4 = 0;
    
    // Linked list insertion at head
    this->m_next = head;
    this->m_prev = 0;
    
    // Update SDA head pointer
    g_CommanderHead = this;
    
    // Increment SDA counter
    g_CommanderCount++;
}

// 0x800B4250 (100 bytes)
// Commander::~Commander(void)
__attribute__((noreturn))
Commander::~Commander(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lis	9,-32698\n"
        "addi	11,13,-32076\n"
        "addi	9,9,-5144\n"
        "stw	9,12(3)\n"
        "b	.L_800B428C\n"
        ".L_800B4270:\n"
        "lwz	0,0(11)\n"
        "cmpw	0,3\n"
        "bne	.L_800B4288\n"
        "lwz	0,0(3)\n"
        "stw	0,0(11)\n"
        "b	.L_800B4298\n"
        ".L_800B4288:\n"
        "mr	11,0\n"
        ".L_800B428C:\n"
        "lwz	0,0(11)\n"
        "cmpwi	0,0\n"
        "bne	.L_800B4270\n"
        ".L_800B4298:\n"
        "andi.	0,4,1\n"
        "beq	.L_800B42A4\n"
        ".long 0x4821cf81\t/* bl __builtin_delete */\n"
        ".L_800B42A4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x800B42B4 (8 bytes)
// Commander::DoCommand(short, int)
bool Commander::DoCommand(short, int) {
    return false;
}

// 0x800B42BC (120 bytes)
// GlobalDispatch(short, int)
__attribute__((noreturn))
int GlobalDispatch(short cmd, int param) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	28,8(1)\n"
        "stw	0,28(1)\n"
        "lwz	11,-32076(13)\n"
        "mr	28,3\n"
        "mr	29,4\n"
        "li	30,0\n"
        "cmpwi	11,0\n"
        "beq-	0f\n"
        "lwz	9,12(11)\n"
        "mr	4,28\n"
        "mr	5,29\n"
        "lwz	31,0(11)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq-	1f\n"
        "li	30,1\n"
        "mr.	11,31\n"
        "bne+	2b\n"
        "mr	3,30\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	28,8(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x800B4334 (168 bytes)
// TypedDispatch(int, short, int, bool)
__attribute__((noreturn))
int TypedDispatch(int type, short cmd, int param, bool flag) {
    __asm__ __volatile__(
        "stwu	1,-32(1)\n"
        "mflr	0\n"
        "mfcr	12\n"
        "stmw	27,12(1)\n"
        "stw	0,36(1)\n"
        "stw	12,8(1)\n"
        // ... (complex function)
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x800B43DC (8 bytes)
// Commander::GetType(void)
short Commander::GetType(void) {
    return 0;
}

// 0x800B43E4 (8 bytes)
// Commander::GetNext(void)
Commander* Commander::GetNext(void) {
    return this->m_next;
}
