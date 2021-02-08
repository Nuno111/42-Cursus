#!bin/bash

pwd=`pwd`

echo "Downloading files:"

[ -d 42cursus_gnl_tests ] || git clone https://github.com/mrjvs/42cursus_gnl_tests.git
[ -d get-next-line-testing-tools ] || git clone https://github.com/TinfoilPancakes/get-next-line-testing-tools.git
[ -d 42TESTERS-GNL ] || git clone https://github.com/Mazoise/42TESTERS-GNL.git

echo "Download complete."
echo "Running tests:"

cd $pwd/42cursus_gnl_tests
if [ ! -f ".altered" ]; then
	sed -i 's/.\/get_next_line/../' Makefile
	sed -i 's/BONUS=no/BONUS=yes/' Makefile
	touch .altered
fi
make

echo -e '\u001b[0m'

cd $pwd/get-next-line-testing-tools
if [ ! -f ".altered" ]; then
	sed -i 's/GNL_SOURCE_DIR = ..\/get_next_line/GNL_SOURCE_DIR = ../' Makefile
	sed -i 's/int\tdiff_file_size;/int\tdiff_file_size;\n\tchar\tt[11];/' moulitest_files/get_next_line_tests/tests/41_hard_test_large_file.spec.c
	sed -i 's/read(fd3, NULL, 10);/read(fd3, \&t, 10);/' moulitest_files/get_next_line_tests/tests/41_hard_test_large_file.spec.c
	sed -i 's/int\tdiff_file_size;/int\tdiff_file_size;\n\tchar\tt[11];/' moulitest_files/get_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c
	sed -i 's/read(fd3, NULL, 10);/read(fd3, \&t, 10);/' moulitest_files/get_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c
	sed -i 's/..\/..\/..\/..\/get_next_line/..\/..\/..\/../' moulitest_files/testframework/v3/Makefile
	touch .altered
fi
make mtest_all

echo -e '\u001b[0m'

cd $pwd/42TESTERS-GNL
bash ./all_tests_with_bonus.sh

echo -e '\u001b[0m'
