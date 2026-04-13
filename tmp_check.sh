#!/bin/bash
for addr in 800dd408 800dd49c 800eaa00 800eaa80 800eaf44 800eb004 800eb080 800eb688 800eb89c; do
    found=$(find src/matched -name "*${addr}*" 2>/dev/null)
    if [ -n "$found" ]; then
        echo "$addr: MATCHED"
    else
        echo "$addr: unclaimed"
    fi
done
