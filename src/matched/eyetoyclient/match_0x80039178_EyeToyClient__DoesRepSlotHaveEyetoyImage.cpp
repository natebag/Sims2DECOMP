// 0x80039178 EyeToyClient::DoesRepSlotHaveEyetoyImage (36B)

struct EyeToyRepSlot {
    int val;
    int pad1;
    int pad2;
};

struct EyeToyRepSlotTable {
    int header1;
    int header2;
    EyeToyRepSlot slots[1];
};

extern char gEyeToyRepSlotTable[];

class EyeToyClient {
public:
    static int DoesRepSlotHaveEyetoyImage(int slot);
};

int EyeToyClient::DoesRepSlotHaveEyetoyImage(int slot) {
    EyeToyRepSlotTable* table = (EyeToyRepSlotTable*)gEyeToyRepSlotTable;
    int v = table->slots[slot].val;
    v ^= 1;
    return v == 0;
}
