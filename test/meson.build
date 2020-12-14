all_test_deps = []
all_test_dep_libs = []
project_test_sources = []

test_main = files('main_tests.cpp')

test_deps = []

test_dep_libs = []

subdir('img')

# This executable contains all the tests
project_test_sources += test_main
all_test_deps += test_deps
all_test_dep_libs += test_dep_libs

all_tests = executable('all_tests', 
    project_test_sources, 
    include_directories : inc, 
    dependencies : all_test_deps, 
    link_with : all_test_dep_libs
)