/* FLAGS: -fno-schedule-insns */
/* 0x802C8E18 EHashTable::Find(unsigned, unsigned) (52 B) */
/* lwz 9,0x8(3); rlwinm 4,4,2,0,29; lwzx 3,4,9; cmpwi 3,0; beq 1f; 0:; lwz 0,0xc(3); cmpw 0,5; beqlr; lwz 3,0x8(3); cmpwi 3,0; bne 0b; 1:; li 3,0 */
/* DOL uses do-while-with-prolog (dual null-check): goto forces that vs compiler's while(top) */
struct EHashNode {
    int pad0;
    int pad1;
    EHashNode* next;     /* offset 0x08 */
    unsigned int key;    /* offset 0x0c */
};

struct EHashTable {
    int pad0;
    int pad1;
    EHashNode** buckets; /* offset 0x08 */

    EHashNode* Find(unsigned int hash, unsigned int key);
};

EHashNode* EHashTable::Find(unsigned int hash, unsigned int key) {
    EHashNode* node = buckets[hash];
    if (!node) goto done;
again:
    if (node->key == key) return node;
    node = node->next;
    if (node) goto again;
done:
    return (EHashNode*)0;
}
