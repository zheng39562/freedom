include ../../make/config.mk

PROJECT_NAME=world
PROJECT_OBJECTS= \
	./$(OUTPUT_TEMPORARY_PATH)/./world.pb.o \
	./$(OUTPUT_TEMPORARY_PATH)/./world_server.o

all : ${PROJECT_OBJECTS}
	mkdir -p ${BUILD_LIBRARY_PATH}
	mkdir -p ${BUILD_INCLUDE_PATH}/${PROJECT_NAME}
	g++ ${COMMON_CFLAGS} ${COMMON_LIBRARY} ${PROJECT_OBJECTS} ${PUBLIC_COMMON_LIBRARY} -fPIC -shared -o ${BUILD_LIBRARY_PATH}/lib${PROJECT_NAME}.so
	cp -rf *.h ${BUILD_INCLUDE_PATH}/${PROJECT_NAME}

install:
	cp ${BUILD_LIBRARY_PATH}/lib${PROJECT_NAME}.so ${OUTPUT_LIB_PATH}
	cp -rf ${BUILD_INCLUDE_PATH}/${PROJECT_NAME} ${OUTPUT_INCLUDE_PATH}/

clean :
	rm -rf ${OUTPUT_TEMPORARY_PATH}/*.o
	rm -f ${BUILD_LIBRARY_PATH}/lib${PROJECT_NAME}.so
	rm -rf ${BUILD_INCLUDE_PATH}/${PROJECT_NAME}

proto : 
	protoc --proto_path=./ --cpp_out=./ world.proto	

