// FLAGS: -fno-elide-constructors
// 0x8023AC64 CDirtyXml::getFirstAttribute (52b)

void* CDirtyXml_getFirstAttribute(void* self) {
    xml_getfirstattr_impl(self);
    return self;
}
