project(
  'mSDK-template',
  'cpp',
  version: '0.1.0',
  default_options: [
    'warning_level=0',  # TODO: Cleanup Fusion headers so no warnings are shown when compiling with warning_level=3
    'cpp_std=c++17'
  ],
  license: 'MIT'
)


files = files(
  'src/General.cpp',
  'src/Main.cpp',
  'src/Runtime.cpp',
  'src/Edittime.cpp',
)



SDK = subproject('mSDK-core', required: true)
mmfs2 = dependency('SDK', fallback: 'mSDK-core')


res = import('windows').compile_resources(
  'src/Ext.rc',
  args: ['/DEDITOR'],
  include_directories: include_directories('subprojects/mSDK-core/inc')
)


extension_edittime_unicode = shared_library(
  'extension_edittime_unicode',
  files,
  res,
  cpp_args: SDK.get_variable('edititme_args') + SDK.get_variable('unicode_args'),
  dependencies: mmfs2,
  name_suffix: 'mfx',
  vs_module_defs: 'src/Ext.def',
)

extension_runtime_unicode = shared_library(
  'extension_runtime_unicode',
  files,
  res,
  cpp_args: SDK.get_variable('runtime_args') + SDK.get_variable('unicode_args'),
  dependencies: mmfs2,
  name_suffix: 'mfx',
  vs_module_defs: 'src/Ext.def',
)

