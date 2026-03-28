// 0x800C7F9C (112 bytes)
// NamespaceSelector::FlushCacheItem(short, list<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache> > &)

class NamespaceSelector { public: void FlushCacheItem(short, list<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache> > &); };

__attribute__((naked))
void NamespaceSelector::FlushCacheItem(short, list<NamespaceSelector::DataCache, allocator<NamespaceSelector::DataCache> > &) {
    asm volatile(".long 0x9421FFE0\n.long 0x81250004\n.long 0x39400000\n.long 0x80090000\n.long 0x48000030\n.long 0xA0090008\n.long 0x39690008\n.long 0x7C002000\n.long 0x40820014\n.long 0x914B0008\n.long 0x81210008\n.long 0xB1490008\n.long 0x48000038\n.long 0x91210018\n.long 0x80090000\n.long 0x91210010\n.long 0x90010008\n.long 0x80050004\n.long 0x39600001\n.long 0x81210008\n.long 0x90010010\n.long 0x7C090000\n.long 0x40820008\n.long 0x39600000\n.long 0x2C0B0000\n.long 0x4082FFB0\n.long 0x38210020\n.long 0x4E800020");
}
