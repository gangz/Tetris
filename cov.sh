#!/bin/bash

if [ ! $# == 1 ]; then
  echo "Usage: $0 executable path"
  exit
fi
lcov -c -i -b . -d obj -o app_base.info
$1
lcov -c -b . -d obj -o app_test.info
lcov -a app_base.info -a app_test.info -o app_total.info
mkdir -p gcov-html
cd gcov-html
genhtml ../app_test.info
cd ..
