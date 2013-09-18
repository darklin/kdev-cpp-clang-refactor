include_directories(${KDE4_INCLUDES})
add_subdirectory(gmock-1.6.0)
set( TEST_LIBRARIES ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES} )
set( TESTS_SRC refactorTester.cpp SourceModificationApplierTester.cpp)
qt4_automoc( ${TESTS_SRC} )

add_executable( refactorTester refactorTester.cpp )
target_link_libraries( refactorTester ${TEST_LIBRARIES} )
add_test(refactorTester refactorTester)

add_executable( SourceModificationApplierTester SourceModificationApplierTester.cpp ../sourcemodificationsapplier.cpp)
target_link_libraries( SourceModificationApplierTester ${TEST_LIBRARIES} gmock ktexteditor)
add_test(SourceModificationApplierTester SourceModificationApplierTester)