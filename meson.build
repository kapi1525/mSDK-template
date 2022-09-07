project(
  'mSDK-template',
  'cpp',
  version: '0.1.0',
  default_options: [
    'warning_level=3',  # TODO: Cleanup Fusion headers so no warnings are shown when compiling with warning_level=3
    'cpp_std=c++17'
  ],
  license: 'MIT'
)


files = files(
  'src/General.cpp',
  'src/Edittime.cpp',
  'src/Properties.cpp',
  'src/Runtime.cpp',
  'src/Debuger.cpp',
  'src/ACE/Actions.cpp',
  'src/ACE/Conditions.cpp',
  'src/ACE/Expressions.cpp',
)



mSDK_core   = subproject('mSDK-core', required: true)
mSDK_dep    = dependency('mSDK', fallback: 'mSDK-core')

# Used only by resources
mSDK_inc    = mSDK_core.get_variable('mSDK_include')

# Compiler arguments
common      = mSDK_core.get_variable('common')
edittime    = mSDK_core.get_variable('edittime')
runtime     = mSDK_core.get_variable('runtime')
unicode     = mSDK_core.get_variable('unicode')



resources_edittime = import('windows').compile_resources(
  'src/Ext.rc',
  args: edittime,
  include_directories: mSDK_inc,
)

resources_runtime = import('windows').compile_resources(
  'src/../src/Ext.rc',    # This dumb workaround is required to stop meson from complaining about 2 targets with same name
  args: runtime,
  include_directories: mSDK_inc,
)


extension_edittime_unicode = shared_library(
  'extension_edittime_unicode',
  files, resources_edittime,
  cpp_args: common + edittime + unicode,
  dependencies: mSDK_dep,
  name_suffix: 'mfx',
)

extension_runtime_unicode = shared_library(
  'extension_runtime_unicode',
  files, resources_runtime,
  cpp_args: common + runtime + unicode,
  dependencies: mSDK_dep,
  name_suffix: 'mfx',
)
