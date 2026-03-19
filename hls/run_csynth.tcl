open_project -reset myproject_prj

set_top myproject

add_files firmware/myproject.cpp -cflags "-Ifirmware -std=c++14"
add_files myproject_test.cpp -tb -cflags "-Ifirmware -std=c++14"

open_solution -reset solution1 -flow_target vivado

set_part {xc7z020clg400-1}
create_clock -period 10 -name default

csynth_design

exit
