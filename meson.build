# Based on https://github.com/tiernemi/meson-sample-project

project('fart', 'cpp',
    version: '0.alpha',
    license: 'GPL3+',
    meson_version : '>= 0.50.0',
    default_options : [ 'warning_level=3', 'cpp_std=c++17' ]
)

# Variables tracking sources and libraries
library_path = []
project_sources = []
project_header_files = []
project_test_sources = []
project_benchmark_sources = []

inc = [include_directories('include')]
subdir('include')

subdir('src')

# external precompiled libs
fart_bin_deps = [
    # meson.get_compiler('cpp').find_library('img', required: true, dirs: library_path)
]

fart_bin_dep_libs = [
    img_lib,
    utils_lib
]

fart_bin = executable('fart',
    main_source,
    include_directories: inc,
    dependencies: fart_bin_deps,
    link_with: fart_bin_dep_libs)

# will need to implement some testing library
# gtest = subproject('gtest')

if get_option('enable-tests')
    subdir('test')
endif

if get_option('enable-docs')
    subdir('docs')
endif

# This adds the clang format file to the build directory
configure_file(
    input: '.clang-format',
    output: '.cl0ang-format',
	copy: true
)
run_target('format', command: [
    'clang-format',
    '-i',
    '-style=file',
    project_sources,
    project_test_sources,
    project_header_files
])

regex = '^((?!(third_party|tests|benchmarks|gtest)).)*$'
configure_file(
    input : '.clang-tidy',
    output : '.clang-tidy',
    copy : true
)
run_target('tidy', command: [
    'run-clang-tidy.py',
    '-fix',
    '-j' ,
    '8',
    'files',
    regex ,
    '-format',
    '-p=' + meson.build_root()
])