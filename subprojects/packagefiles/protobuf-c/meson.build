project(
  'protobuf-c',
  'c', 'cpp',
  version: '1.5.1',
  license: 'BSD-2',
  meson_version: '>=0.49.0',
  default_options: ['cpp_std=c++17'],
)

protoc_dep = dependency('protoc')
protobuf_dep = dependency('protobuf', version: '>= 3.0.0')
protoc = find_program('protoc')

incdir = include_directories('.')

subdir('protobuf-c')
subdir('protoc-gen-c')
