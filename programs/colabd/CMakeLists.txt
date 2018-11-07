add_executable( colabd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling colabd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( COLAB_STATIC_BUILD )
   target_link_libraries( colabd PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      colab_utilities
      colab_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( COLAB_STATIC_BUILD )
   target_link_libraries( colabd PRIVATE
      appbase
      colab_utilities
      colab_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( COLAB_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      colabd PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   colabd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
