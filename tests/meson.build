threads_dep = dependency('threads')
glib_dep = dependency('glib-2.0', required: host_machine.system() == 'windows', default_options: ['tests=false'])
tests_dependencies = [libomemo_c_dep, threads_dep, glib_dep]
tests_dependencies += dependency('check')
if host_machine.system() != 'darwin'
    tests_dependencies += dependency('openssl')
endif

tests_c_args = c_args
if cc.get_id() == 'gcc' or cc.get_id() == 'clang'
    tests_c_args += ['-Wno-unused-function']
endif
if cc.get_id() == 'gcc'
    tests_c_args += ['-Wno-sign-compare']
    if cc.has_argument('-Wno-sign-conversion')
        tests_c_args += ['-Wno-sign-conversion']
    endif
endif
if cc.get_id() == 'clang'
    tests_c_args += ['-Wno-invalid-source-encoding', '-Wno-shorten-64-to-32']
endif

common_test_sources = files(['test_common.c'])
if host_machine.system() == 'darwin'
    common_test_sources += files(['test_common_ccrypto.c'])
else
    common_test_sources += files(['test_common_openssl.c'])
endif
if glib_dep.found()
    common_test_sources += files(['test_common_glib.c'])
else
    common_test_sources += files(['test_common_pthread.c'])
endif

tests = [
    'test_curve25519',
    'test_hkdf',
    'test_ratchet',
    'test_protocol',
    'test_session_record',
    'test_session_cipher',
    'test_session_builder',
    'test_key_helper',
    'test_simultaneous_initiate',
    'test_sender_key_record',
]

foreach name : tests
    test(name, executable(name, name + '.c', common_test_sources, c_args: tests_c_args, dependencies: tests_dependencies))
endforeach