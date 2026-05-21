// 0x801BBF0C INGTarget::get_total_cost(unsigned int*) const (96B)
// TRIAGE

struct Item {
    char pad[2];
    short price;
};

struct Slot {
    Item* item_ptr;
    int qty;
};

class INGTarget {
public:
    char pad_000[480];
    Slot m_slots[4];
    unsigned int get_total_cost(unsigned int* count_out) const;
};

unsigned int INGTarget::get_total_cost(unsigned int* count_out) const {
    Slot* slots = (Slot*)((char*)this + 480);
    int count = 0;
    int total = 0;
    for (int i = 0; i < 4; i++) {
        if (slots != 0) {
            int qty = slots->qty;
            if (qty != 0) {
                Item* item = slots->item_ptr;
                if (item != 0) {
                    short price = item->price;
                    count++;
                    total += (int)price * qty;
                }
            }
        }
        slots = (Slot*)((char*)slots + 8);
    }
    if (count_out != 0) *count_out = count;
    return total;
}
