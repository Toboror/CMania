For compiling on MacOS: 

    gcc main.c systemEssentials.c cJSON/cJSON.c \
        -I./cJSON \
        -lcurl \
        -o myprogram

For compiling on Windows:

    gcc main.c systemEssentials.c \
    cJSON/cJSON.c \
    -I./cJSON \
    -I./curl-8.15.0_4-win64-mingw/include \
    -L./curl-8.15.0_4-win64-mingw/lib \
    -lcurl \
    -o myprogram

PS! Remember to get cJSON and curl libraries and place them in the correct directories. Will probably automate it later.