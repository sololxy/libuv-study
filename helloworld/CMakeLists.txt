
set(TARGET_NAME "helloworld")

SET(SRCS "${TARGET_NAME}.c")

add_executable(${TARGET_NAME} ${SRCS})
target_link_libraries(${TARGET_NAME} "libuv.lib")
if(WIN32)
    target_link_libraries(${TARGET_NAME} "ws2_32.lib")      # 网络相关api
    target_link_libraries(${TARGET_NAME} "psapi.lib")       # 进程相关api
    target_link_libraries(${TARGET_NAME} "IPHLPAPI.lib")    # 进程相关api
    target_link_libraries(${TARGET_NAME} "Userenv.lib")     # 用户相关api
endif(WIN32)
