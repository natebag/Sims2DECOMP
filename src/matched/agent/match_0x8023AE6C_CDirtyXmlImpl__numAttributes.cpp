extern int CDirtyXmlNode_numAttributes(void *self);

struct CDirtyXmlImpl {
    int numAttributes();
};

int CDirtyXmlImpl::numAttributes() {
    return CDirtyXmlNode_numAttributes(this);
}
