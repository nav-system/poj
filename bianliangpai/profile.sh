# !/bin/bash

Id="$1"

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

if [ -f conf/${Id}_console_input.txt ]; then
  echo "running target program with console input"
  out/${Id}_profile < conf/${Id}_console_input.txt
else
  echo "running target program without console input"
  out/${Id}_profile
fi

echo ""
echo ""
echo "================================================="
echo "===          profiling result display         ==="
echo "================================================="
echo ""

gprof out/${Id}_profile gmon.out > profile_result.txt
head -n 20 profile_result.txt