// 0x801F7E4C (100 bytes)
// INVTarget::IsPackagedItem(BBI::InventoryItem *)

class INVTarget { public: void IsPackagedItem(BBI::InventoryItem *); };

__attribute__((naked))
void INVTarget::IsPackagedItem(BBI::InventoryItem *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3BC00000\n.long 0x7C7F1B79\n.long 0x41820034\n.long 0x7FE3FB78\n.long 0x4BE5228D\n.long 0x2C030002\n.long 0x40820024\n.long 0x7FE3FB78\n.long 0x4BE522BD\n.long 0x2C030005\n.long 0x41810014\n.long 0x2F830002\n.long 0x4FFEEB82\n.long 0x7FC00026\n.long 0x57DE07FE\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
