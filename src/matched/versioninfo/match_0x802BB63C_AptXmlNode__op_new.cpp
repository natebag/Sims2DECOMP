/* AptXmlNode::operator new(unsigned int) at 0x802BB63C (40B) */
// FLAGS: -fno-elide-constructors

extern void *g_aptHeap;
extern void *aptAlloc(void *, unsigned int);

void *AptXmlNode_op_new(unsigned int size) {
    return aptAlloc(g_aptHeap, size);
}
