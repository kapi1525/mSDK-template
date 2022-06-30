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
  'src/ACE/actions.cpp',
  'src/ACE/conditions.cpp',
  'src/ACE/expressions.cpp',
  'src/Runtime.cpp',
  'src/Edittime.cpp',
)



mSDK_core   = subproject('mSDK-core', required: true)
mSDK_dep    = dependency('mSDK', fallback: 'mSDK-core')

mSDK_inc    = mSDK_core.get_variable('mSDK_include')

common      = mSDK_core.get_variable('common')
edittime    = mSDK_core.get_variable('edittime')
runtime     = mSDK_core.get_variable('runtime')
unicode     = mSDK_core.get_variable('unicode')

edittime_rc = mSDK_core.get_variable('edittime_rc')
runtime_rc  = mSDK_core.get_variable('runtime_rc')



extension_res = import('windows').compile_resources(
  'src/Ext.rc',
  args: edittime_rc,
  include_directories: mSDK_inc,
)

extension_edittime_unicode = shared_library(
  'extension_edittime_unicode',
  files, extension_res,
  cpp_args: common + edittime + unicode,
  dependencies: mSDK_dep,
  name_suffix: 'mfx',
)



extension_runtime_unicode = shared_library(
  'extension_runtime_unicode',
  files, extension_res,
  cpp_args: common + runtime + unicode,
  dependencies: mSDK_dep,
  name_suffix: 'mfx',
)
