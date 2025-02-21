subdir('curve25519')

libomemo_c_include_directories = [
    'curve25519/ed25519/nacl_includes',
    'curve25519/ed25519/additions',
    'curve25519/ed25519/additions/generalized',
    'curve25519/ed25519/tests',
    'curve25519/ed25519',
    'curve25519',
    '.',
]

libomemo_c_sources = files([
    'vpool.c',
    'vpool.h',
    'signal_protocol.c',
    'signal_protocol.h',
    'signal_protocol_types.h',
    'signal_protocol_internal.h',
    'curve.c',
    'curve.h',
    'hkdf.c',
    'hkdf.h',
    'ratchet.c',
    'ratchet.h',
    'protocol.c',
    'protocol.h',
    'session_state.c',
    'session_state.h',
    'session_record.c',
    'session_record.h',
    'session_pre_key.c',
    'session_pre_key.h',
    'session_builder.c',
    'session_builder.h',
    'session_builder_internal.h',
    'session_cipher.c',
    'session_cipher.h',
    'key_helper.c',
    'key_helper.h',
    'sender_key.c',
    'sender_key.h',
    'sender_key_state.c',
    'sender_key_state.h',
    'sender_key_record.c',
    'sender_key_record.h',
])

libomemo_c_headers = files([
    'signal_protocol.h',
    'signal_protocol_types.h',
    'curve.h',
    'hkdf.h',
    'ratchet.h',
    'protocol.h',
    'session_state.h',
    'session_record.h',
    'session_pre_key.h',
    'session_builder.h',
    'session_cipher.h',
    'key_helper.h',
    'sender_key.h',
    'sender_key_state.h',
    'sender_key_record.h',
])

libomemo_c_lib = library(
    'libomemo-c',
    libomemo_c_sources,
    include_directories: libomemo_c_include_directories,
    c_args: c_args,
    dependencies: [protobuf_dep, curve25519_dep],
    vs_module_defs: 'libomemo-c.def',
    install: true,
    version: meson.project_version(),
    name_prefix: '',
)
libomemo_c_dep = declare_dependency(link_with: libomemo_c_lib, include_directories: include_directories('.'))

install_headers(libomemo_c_headers, subdir: 'omemo')

import('pkgconfig').generate(libomemo_c_lib, description: 'OMEMO C Library', subdirs: 'omemo')
