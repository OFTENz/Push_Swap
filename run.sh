#!/bin/sh

STRING_TO_REMOVE=""

find . -type f | while read -r file; do
    if grep -Iq . "$file"; then
        sed -i '' "s/$STRING_TO_REMOVE//g" "$file"
    fi
done

