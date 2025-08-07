#!/bin/bash

echo "🔧 Building program.exe..."

x86_64-w64-mingw32-gcc main.c systemEssentials.c cJSON/cJSON.c \
  -o program.exe \
  -I./curl-8.15.0_4-win64-mingw/include \
  -L./curl-8.15.0_4-win64-mingw/lib \
  -DCURL_STATICLIB \
  -lcurl -lws2_32 -lssl -lcrypto -lz -static

if [[ $? -eq 0 ]]; then
  echo "✅ Build successful. Output: program.exe"
else
  echo "❌ Build failed."
fi
