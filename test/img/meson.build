imgtest_sources = [
    'PPM_test.ccp'
]

imgtest_deps = []

imgtest_lib_deps = [
    img_lib
]

imgtest = executable('imgtest',
    [imgtest_sources, test_main],
    include_directories: inc,
    dependencies: [imgtest_deps, test_deps],
    link_with: [imgtest_lib_deps, test_dep_libs]
)

test('img test', imgtest)

all_test_deps += imgtest_deps
all_test_dep_libs += imgtest_lib_deps