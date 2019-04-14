# !/bin/bash
Id="$1"
Excutable=./out/${Id}_profile

echo ""
echo ""
echo "================================================="
echo "===      cleaning last profiling result       ==="
echo "================================================="
echo ""

rm gmon.out
rm profile_result.txt

echo ""
echo ""
echo "================================================="
echo "===          compiling target program         ==="
echo "================================================="
echo ""

make profile ID=${Id}

echo ""
echo ""
echo "================================================="
echo "===          executing target program         ==="
echo "================================================="
echo ""

${Excutable}
gprof ${Excutable} gmon.out > profile_result.txt

echo ""
echo ""
echo "================================================="
echo "===          profiling result display         ==="
echo "================================================="
echo ""

head -n 20 profile_result.txt