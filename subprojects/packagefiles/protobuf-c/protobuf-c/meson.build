api = []
exp = []
if get_option('default_library') != 'static'
    api += '-DPROTOBUF_C_USE_SHARED_LIB'
    exp += '-DPROTOBUF_C_EXPORT'
endif

protobuf_c_lib = library(
    'protobuf-c',
    files('protobuf-c.c'),
    c_args: [api, exp],
    install: true,
)

protobuf_c_pb_sources = custom_target(
    'protobuf_c_pb_sources',
    command: [protoc, '--proto_path=@CURRENT_SOURCE_DIR@', '--cpp_out=@OUTDIR@', '@INPUT@'],
    input: files('protobuf-c.proto'),
    output: ['protobuf-c.pb.cc', 'protobuf-c.pb.h']
)

install_headers('protobuf-c.h')

pkgconfig = import('pkgconfig')
pkgconfig.generate(
    protobuf_c_lib,
    name: 'protobuf-c',
    description: 'Protocol Buffers implementation in C',
    url: 'https://github.com/protobuf-c/protobuf-c',
)

libprotobuf_c_dep = declare_dependency(
    compile_args: api,
    include_directories: [incdir, include_directories('.')],
    link_with: protobuf_c_lib
)

protobuf_c_pb_dep = declare_dependency(
    sources: protobuf_c_pb_sources
)