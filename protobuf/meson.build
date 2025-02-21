protoc_c = find_program('protoc-c', required: false)
if protoc_c.found()
    protoc_gen_c = find_program('protoc-gen-c', required: false)
    if protoc_gen_c.found()
        protoc = find_program('protoc', required: false)
    else
        protoc = disabler()
    endif
else
    protoc_gen_c = find_program('protoc-gen-c')
    protoc = find_program('protoc')
endif

protoc_depends = []
if protoc.found() and protoc_gen_c.found()
    protoc_depends += custom_target(
        command: [protoc_gen_c],
        capture: true,
        output: ['protoc_gen_c.stamp']
    )
    protoc_command = [protoc, '--plugin=protoc-gen-c=' + protoc_gen_c.full_path(), '--proto_path=@CURRENT_SOURCE_DIR@', '--c_out=@OUTDIR@', '@INPUT@']
else # protoc-c is available
    protoc_command = [protoc_c, '--proto_path=@CURRENT_SOURCE_DIR@', '--c_out=@OUTDIR@', '@INPUT@']
endif

protobuf_proto_names = [
    'LocalStorageProtocol',
    'WhisperTextProtocol',
    'OMEMO',
]

protobuf_proto_sources = []
protobuf_c_sources = []
protobuf_c_headers = []
foreach name : protobuf_proto_names
    protobuf_proto_sources += files(name + '.proto')
    protobuf_c_sources += [name + '.pb-c.c']
    protobuf_c_headers += [name + '.pb-c.h']
endforeach

protobuf_c_sources = custom_target(
    'protobuf_c_sources',
    command: protoc_command,
    input: protobuf_proto_sources,
    output: [protobuf_c_sources, protobuf_c_headers],
    depends: protoc_depends,
)

libprotobuf_c_dep = dependency('libprotobuf-c')
protobuf_dep = declare_dependency(dependencies: libprotobuf_c_dep, sources: protobuf_c_sources, include_directories: include_directories('.'))