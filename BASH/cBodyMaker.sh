#!/bin/bash

out="usage: ./cBodyMaker.sh [-c|-cpp]\n"

if [ "$1" == "-c" ]; then

printf "#include <stdio.h>\n#include <stdlib.h>\n\nint main(int argc, char** argv)\n{\n"
printf "    //TODO: Code goes here\n"
printf "    return 0;\n}\n"
out=""
fi

if [ "$1" == "-cpp" ]; then
printf "#include <iostream>\n#include <stdlib.h>\nusing std::cout;\nusing std::cin;\nusing std::endl;\n\nint main(int argc, char**"
printf " argv)\n{\n"
printf "    //TODO: Main code\n"
printf "    return 0;\n}\n"
out=""
fi

printf "$out"
