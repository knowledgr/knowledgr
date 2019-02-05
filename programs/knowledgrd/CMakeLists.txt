add_executable( knowledgrd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling knowledgrd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( KNOWLEDGR_STATIC_BUILD )
   target_link_libraries( knowledgrd PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      knowledgr_utilities
      knowledgr_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( KNOWLEDGR_STATIC_BUILD )
   target_link_libraries( knowledgrd PRIVATE
      appbase
      knowledgr_utilities
      knowledgr_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( KNOWLEDGR_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      knowledgrd PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   knowledgrd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
