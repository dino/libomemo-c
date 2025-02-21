protoc_gen_c_src = files(
    'c_bytes_field.cc',
    'c_enum.cc',
    'c_enum_field.cc',
    'c_extension.cc',
    'c_field.cc',
    'c_file.cc',
    'c_generator.cc',
    'c_helpers.cc',
    'c_message.cc',
    'c_message_field.cc',
    'c_primitive_field.cc',
    'c_service.cc',
    'c_string_field.cc',
    'main.cc',
)

protoc_gen_c = executable(
    'protoc-gen-c',
    protoc_gen_c_src,
    cpp_args: '-DPACKAGE_STRING="protobuf-c"',
    dependencies: [libprotobuf_c_dep, protobuf_dep, protoc_dep, protobuf_c_pb_dep],
)

meson.override_find_program('protoc-gen-c', protoc_gen_c)
