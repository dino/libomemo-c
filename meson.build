project('libomemo-c', 'c', license: 'GPL-3.0', version: '0.5.1', meson_version: '>=1.1.0')

cc = meson.get_compiler('c')


c_args = []
if cc.has_function('SecureZeroMemory', prefix: '#include <Windows.h>')
    c_args += ['-DSECUREZEROMEMORY']
endif
if cc.get_id() == 'gcc' or cc.get_id() == 'clang'
    c_args += ['-fmessage-length=0', '-Wall', '-Wmissing-field-initializers', '-Wno-missing-braces', '-Wparentheses']
endif
if cc.get_id() == 'gcc'
    c_args += ['-Wsign-compare']
    if cc.has_argument('-Wsign-conversion')
        c_args += ['-Wsign-conversion']
    endif
endif
if cc.get_id() == 'clang'
    c_args += ['-Wswitch', '-Wunused-variable', '-Wunused-value', '-Wshadow', '-Wint-conversion',  '-Wpointer-sign', '-Wprotocol', '-Wshorten-64-to-32']
endif
if cc.has_function('memset_s', prefix: '#include <string.h>')
    c_args += ['-DHAVE_MEMSET_S']
endif

subdir('protobuf')
subdir('src')
if get_option('tests')
    subdir('tests')
endif